#include <stack>
#include <pathie.hpp>
#include <SFML/Graphics.hpp>
#include "scene.hpp"
#include "level_scene.hpp"
#include "../scene_manager.hpp"
#include "../texture_manager.hpp"
#include "../app.hpp"

LevelScene::LevelScene()
{
}

LevelScene::~LevelScene()
{
  //
}

void LevelScene::handle_event(sf::Event& evt)
{
  Scene::handle_event(evt);
}

void LevelScene::update()
{
  Scene::update();
}

void LevelScene::draw(sf::RenderWindow& stage)
{
  Scene::draw(stage);
}
