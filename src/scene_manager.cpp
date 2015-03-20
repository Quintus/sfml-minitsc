#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>
#include "scenes/scene.hpp"
#include "scene_manager.hpp"

SceneManager::SceneManager()
{
  m_end_play = false;
}

void SceneManager::push_scene(Scene* p_scene)
{
  m_scenes_stack.push(p_scene);
}

Scene* SceneManager::pop_scene()
{
  Scene* p_scene = m_scenes_stack.top();
  m_scenes_stack.pop();
  return p_scene;
}

void SceneManager::play(sf::RenderWindow& stage)
{
  // Main loop
  while (!m_end_play) {
    Scene* p_scene = m_scenes_stack.top();

    // Event handling
    sf::Event evt;
    while (stage.pollEvent(evt)) {
      if (!handle_global_event(evt)) {
	p_scene->handle_event(evt);
      }
    }

    // Clear screen
    stage.clear();

    // Moving and other updates
    p_scene->update();

    // Draw everything where it is now
    p_scene->draw(stage);

    // Show it
    stage.display();
  }

  // Wipe all scenes that still exist.
  while (!m_scenes_stack.empty())
    delete pop_scene();

  // Applause!
  stage.close();
}

/**
 * Global events that apply to any scene.
 * Returns true if this method handled the event,
 * false otherwise.
 */
bool SceneManager::handle_global_event(sf::Event& evt)
{
  switch(evt.type) {
  case sf::Event::Closed:
    m_end_play = true;
    return true;
  default:
    return false;
  }
}
