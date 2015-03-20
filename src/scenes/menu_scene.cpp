#include <SFML/Graphics.hpp>
#include "scene.hpp"
#include "menu_scene.hpp"

MenuScene::~MenuScene()
{
  //
}

void MenuScene::handle_event(sf::Event& evt)
{
  Scene::handle_event(evt);
}

void MenuScene::update()
{
  Scene::update();
}

void MenuScene::draw(sf::RenderWindow& stage)
{
  Scene::draw(stage);

  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  stage.draw(shape);
}
