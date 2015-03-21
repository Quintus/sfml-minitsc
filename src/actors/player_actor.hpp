#ifndef MINITSC_PLAYER_ACTOR_HPP
#define MINITSC_PLAYER_ACTOR_HPP
class PlayerActor: public Actor
{
public:
  PlayerActor();
  virtual ~PlayerActor();
  virtual void update();
  virtual void draw(sf::RenderWindow& stage);

  void set_speed(int x = -1, int y = -1);
protected:
  sf::Sprite* mp_sprite;
  int m_speed_x;
  int m_speed_y;
};
#endif
