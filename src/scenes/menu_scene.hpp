#ifndef MINITSC_MENU_SCENE_HPP
#define MINITSC_MENU_SCENE_HPP
class MenuScene: public Scene
{
public:
  virtual ~MenuScene();

  virtual void handle_event(sf::Event& evt);
  virtual void update();
  virtual void draw(sf::RenderWindow& stage);
};

#endif
