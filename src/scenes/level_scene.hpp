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
  sf::Texture& m_ground_texture;
  sf::Texture& m_player_stand_texture;
  sf::Texture& m_player_walk1_texture;
  sf::Texture& m_player_walk2_texture;
  std::vector<sf::Sprite*> m_ground_sprites;
  sf::Sprite* mp_player_sprite;
};

#endif
