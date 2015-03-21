#include <stack>
#include <SFML/Graphics.hpp>
#include <pathie.hpp>
#include "actor.hpp"
#include "player_actor.hpp"
#include "../scenes/scene.hpp"
#include "../scene_manager.hpp"
#include "../texture_manager.hpp"
#include "../app.hpp"

PlayerActor::PlayerActor()
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
}
