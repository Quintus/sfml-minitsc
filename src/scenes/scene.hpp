#ifndef MINITSC_SCENE_HPP
#define MINITSC_SCENE_HPP

/**
 * A scene defines what is currently happening. The splash
 * screen is a scene, and each level is a scene, and so on.
 * In each scene, there are actors (Actor instances) who play a role in this
 * scene.
 *
 * This is an abstract class intended to be subclassed. By default,
 * it just calls `update()` and `draw()` on each of the actors
 * in this sccene.
 */
class Scene
{
public:
  virtual ~Scene();
  virtual void handle_event(sf::Event& evt);
  virtual void update();
  virtual void draw(sf::RenderWindow& stage);

  inline std::vector<Actor*>::iterator begin_actors(){return m_actors.begin();}
  inline std::vector<Actor*>::iterator end_actors(){return m_actors.end();}
protected:
  std::vector<Actor*> m_actors;
};

#endif
