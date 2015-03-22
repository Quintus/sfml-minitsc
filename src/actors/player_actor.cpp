#include <stack>
#include <SFML/Graphics.hpp>
#include <pathie.hpp>
#include "actor.hpp"
#include "static_actor.hpp"
#include "player_actor.hpp"
#include "../scenery.hpp"
#include "../scenes/scene.hpp"
#include "../scenes/level_scene.hpp"
#include "../scene_manager.hpp"
#include "../texture_manager.hpp"
#include "../app.hpp"

PlayerActor::PlayerActor()
  : mp_sprite(NULL), m_speed_x(0), m_speed_y(0)
{
  sf::Texture& stand_texture = gp_app->get_texture_manager().get_texture(Pathie::Path("../data/player/stand_right.png"));
  mp_sprite = new sf::Sprite;
  mp_sprite->setTexture(stand_texture);
  mp_sprite->setPosition(10, 10);
  mp_sprite->setScale(0.13671875, 0.13671875); // 512 px image scaled down to 70 pixels
}

PlayerActor::~PlayerActor()
{
  delete mp_sprite;
}

void PlayerActor::draw(sf::RenderWindow& stage)
{
  stage.draw(*mp_sprite);
}

void PlayerActor::update()
{
  int delta_x = 0;
  int delta_y = 0;

  if (m_speed_x > 0)
    delta_x = m_speed_x;

  // Apply gravity
  delta_y += gp_app->get_gravity_factor();

  // Find player bottom coordinate
  sf::FloatRect player_box = mp_sprite->getGlobalBounds();
  unsigned int player_bottom_y = player_box.top + player_box.height;
  // PlayerActor may only ever be used in LevelScene, so we can predict
  // that the current scene is a LevelScene instance.
  LevelScene& current_scene = static_cast<LevelScene&>(gp_app->get_scene_manager().current_scene());

  // Check for ground collision.
  // TODO: Should not check this on each frame. Set a bool if we are on ground
  // instead (performance and flickering reasons).
  if (current_scene.get_scenery().contains(sf::Vector2f(player_box.left, player_bottom_y))) {
    delta_y = 0;
  }

  // End game if the player touches the lower screen edge.
  if (player_bottom_y >= gp_app->get_renderwindow().getSize().x) {
    gp_app->get_scene_manager().end_play();
  }

  mp_sprite->move(delta_x, delta_y);
}

/**
 * Set the player’s speed. Set one of the arguments to -1 (default)
 * to keep the current speed in that direction.
 */
void PlayerActor::set_speed(int x, int y)
{
  if (x >= 0)
    m_speed_x = x;
  if (y >= 0)
    m_speed_y = y;
}
