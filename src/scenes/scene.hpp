#ifndef MINITSC_SCENE_HPP
#define MINITSC_SCENE_HPP

class Scene
{
public:
  virtual ~Scene();
  virtual void handle_event(sf::Event& evt);
  virtual void update();
  virtual void draw(sf::RenderWindow& stage);
private:
};

#endif
