#include <SFML/Graphics.hpp>
#include "../actors/actor.hpp"
#include "scene.hpp"

Scene::~Scene()
{
  std::vector<Actor*>::iterator iter;
  for(iter=m_actors.begin(); iter != m_actors.end(); iter++) {
    delete *iter;
  }
}

void Scene::handle_event(sf::Event& evt)
{
  // virtual
}

void Scene::update()
{
  std::vector<Actor*>::iterator iter;
  for(iter=m_actors.begin(); iter != m_actors.end(); iter++) {
    (*iter)->update();
  }
}

void Scene::draw(sf::RenderWindow& stage)
{
  std::vector<Actor*>::iterator iter;
  for(iter=m_actors.begin(); iter != m_actors.end(); iter++) {
    (*iter)->draw(stage);
  }
}
