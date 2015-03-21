#ifndef MINITSC_STATIC_ACTOR_HPP
#define MINITSC_STATIC_ACTOR_HPP
class StaticActor: public Actor
{
public:
  StaticActor(const Pathie::Path& imagepath, int startx, int starty, float scale);
  virtual ~StaticActor();
  virtual void draw(sf::RenderWindow& stage);

  inline sf::FloatRect get_collision_rect(){return mp_sprite->getGlobalBounds();}
protected:
  sf::Sprite* mp_sprite;
};
#endif
