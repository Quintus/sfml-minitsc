#ifndef MINITSC_MENU_SCENE_HPP
#define MINITSC_MENU_SCENE_HPP

/**
 * Splash screen scene. Displays a message to start
 * the game, waiting for the user to press ENTER.
 */
class MenuScene: public Scene
{
public:
  MenuScene();
  virtual ~MenuScene();

  virtual void handle_event(sf::Event& evt);
  virtual void update();
  virtual void draw(sf::RenderWindow& stage);
private:
  sf::Text m_start_text;
};

#endif
