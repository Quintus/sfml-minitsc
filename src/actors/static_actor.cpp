#include <stack>
#include <SFML/Graphics.hpp>
#include <pathie.hpp>
#include "actor.hpp"
#include "static_actor.hpp"
#include "../scenes/scene.hpp"
#include "../scene_manager.hpp"
#include "../texture_manager.hpp"
#include "../app.hpp"

StaticActor::StaticActor(const Pathie::Path& imagepath, int startx, int starty, float scale)
{
  sf::Texture& imgtexture = gp_app->get_texture_manager().get_texture(imagepath);
  mp_sprite = new sf::Sprite;
  mp_sprite->setTexture(imgtexture);
  mp_sprite->setPosition(startx, starty); // Default position
  mp_sprite->setScale(scale, scale);
}

StaticActor::~StaticActor()
{
  delete mp_sprite;
}

void StaticActor::draw(sf::RenderWindow& stage)
{
  stage.draw(*mp_sprite);
}
