#include <stack>
#include <pathie.hpp>
#include <SFML/Graphics.hpp>
#include "../actors/actor.hpp"
#include "../actors/static_actor.hpp"
#include "../actors/player_actor.hpp"
#include "scene.hpp"
#include "level_scene.hpp"
#include "../scene_manager.hpp"
#include "../texture_manager.hpp"
#include "../app.hpp"

LevelScene::LevelScene()
{
  for(int i=0; i < 10; i++) {
    StaticActor* p_actor = new StaticActor(Pathie::Path("../data/ground/top.png"),
					   i * 64,
					   200,
					   0.25f);
    m_actors.push_back(p_actor);
  }

  mp_player_actor = new PlayerActor();
  m_actors.push_back(mp_player_actor);
}

LevelScene::~LevelScene()
{
  // Do not delete mp_player_actor, the pointer is part of m_actors,
  // which is freed by Scene’s destructor already.
}

void LevelScene::handle_event(sf::Event& evt)
{
  Scene::handle_event(evt);

  switch(evt.type) {
  case sf::Event::KeyPressed:
    if (evt.key.code == sf::Keyboard::Right) {
      mp_player_actor->set_speed(5, -1);
    }
    break;
  case sf::Event::KeyReleased:
    if (evt.key.code == sf::Keyboard::Right) {
      mp_player_actor->set_speed(0, -1);
    }
    break;
  default:
    break; // Ignore
  }
}

void LevelScene::update()
{
  Scene::update();
}

void LevelScene::draw(sf::RenderWindow& stage)
{
  Scene::draw(stage);
}
