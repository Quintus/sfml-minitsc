#ifndef MINITSC_PLAYER_ACTOR_HPP
#define MINITSC_PLAYER_ACTOR_HPP
class PlayerActor: public Actor
{
public:
  PlayerActor();
  virtual ~PlayerActor();
  virtual void update();
  virtual void draw(sf::RenderWindow& stage);
protected:
  sf::Sprite* mp_sprite;
};
#endif
