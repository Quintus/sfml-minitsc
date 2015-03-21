#include <stack>
#include <pathie.hpp>
#include <SFML/Graphics.hpp>
#include "scene.hpp"
#include "level_scene.hpp"
#include "../scene_manager.hpp"
#include "../texture_manager.hpp"
#include "../app.hpp"

LevelScene::LevelScene()
  : m_ground_texture(gp_app->get_texture_manager().get_texture(Pathie::Path("../data/ground/top.png"))),
    m_player_stand_texture(gp_app->get_texture_manager().get_texture(Pathie::Path("../data/player/stand_right.png"))),
    m_player_walk1_texture(gp_app->get_texture_manager().get_texture(Pathie::Path("../data/player/walk_right_1.png"))),
    m_player_walk2_texture(gp_app->get_texture_manager().get_texture(Pathie::Path("../data/player/walk_right_2.png")))
{
  for(int i=0; i < 10; i++) {
    sf::Sprite* p_sprite = new sf::Sprite;
    p_sprite->setTexture(m_ground_texture);
    p_sprite->setScale(0.25f, 0.25f); // 256 px image scaled down to 64 pixels
    p_sprite->setPosition(i * 64, 200);
    m_ground_sprites.push_back(p_sprite);
  }

  m_player_stand_texture.setSmooth(true);
  mp_player_sprite = new sf::Sprite;
  mp_player_sprite->setTexture(m_player_stand_texture);
  mp_player_sprite->setScale(0.13671875, 0.13671875); // 512 px image scaled down to 70 pixels
  mp_player_sprite->setPosition(10, 10);
}

LevelScene::~LevelScene()
{
  std::vector<sf::Sprite*>::iterator iter;
  for(iter = m_ground_sprites.begin(); iter != m_ground_sprites.end(); iter++) {
    delete *iter;
  }
  delete mp_player_sprite;
}

void LevelScene::handle_event(sf::Event& evt)
{
  Scene::handle_event(evt);
}

void LevelScene::update()
{
  Scene::update();
}

void LevelScene::draw(sf::RenderWindow& stage)
{
  Scene::draw(stage);

  std::vector<sf::Sprite*>::iterator iter;
  for(iter = m_ground_sprites.begin(); iter != m_ground_sprites.end(); iter++) {
    stage.draw(**iter);
  }

  stage.draw(*mp_player_sprite);
}
