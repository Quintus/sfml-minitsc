#ifndef MINITSC_SCENE_MANAGER_HPP
#define MINITSC_SCENE_MANAGER_HPP

/**
 * Manage the scenes. The entire game is made up from
 * scenes; each scene is a clearly separate state.
 * The menu screen is a scene for example, and so is
 * the map. Each scene has full control over the entire
 * stage, erm, window.
 */
class SceneManager
{
public:
  SceneManager();

  void push_scene(Scene* p_scene);
  Scene* pop_scene();

  void play(sf::RenderWindow& stage);
  inline Scene& current_scene(){return *m_scenes_stack.top();}
  inline void end_play(){m_end_play = true;}
private:
  bool handle_global_event(sf::Event& evt);

  std::stack<Scene*> m_scenes_stack;
  bool m_end_play;
};

#endif
