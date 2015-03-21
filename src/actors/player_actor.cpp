#include <stack>
#include <SFML/Graphics.hpp>
#include <pathie.hpp>
#include "actor.hpp"
#include "static_actor.hpp"
#include "player_actor.hpp"
#include "../scenes/scene.hpp"
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

  // Check ground collision that stops falling.
  // Yes this is utterly unperformant. It’s just for the sake of example.
  sf::FloatRect player_box = mp_sprite->getGlobalBounds();
  int player_bottom_y = player_box.top + player_box.height;
  StaticActor* p_intersect_actor = NULL;
  std::vector<Actor*>::iterator iter;
  for(iter=gp_app->get_scene_manager().current_scene().begin_actors(); iter != gp_app->get_scene_manager().current_scene().end_actors(); iter++) {
    if ((p_intersect_actor = dynamic_cast<StaticActor*>(*iter))) { // Single = intended
      sf::FloatRect otherbox = p_intersect_actor->get_collision_rect();
      if (otherbox.contains(sf::Vector2f(player_box.left, player_bottom_y))) {
	delta_y = 0;
	break;
      }
    }
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
