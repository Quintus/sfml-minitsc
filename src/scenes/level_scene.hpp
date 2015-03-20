#ifndef MINITSC_LEVEL_SCENE_HPP
#define MINITSC_LEVEL_SCENE_HPP

/**
 * Level screen scene. The user walks through the level.
 */
class LevelScene: public Scene
{
public:
  LevelScene();
  virtual ~LevelScene();

  virtual void handle_event(sf::Event& evt);
  virtual void update();
  virtual void draw(sf::RenderWindow& stage);
private:

};

#endif
