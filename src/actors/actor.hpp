#ifndef MINITSC_ACTOR_HPP
#define MINITSC_ACTOR_HPP
/**
 * Actor class. An actor is an entity in the level that somehow
 * interacts with the player (or even does no interaction).
 * Basically every level object is an actor. Not actors are
 * graphics like the time display as they’re not level elements.
 *
 * This is an abstract class that is intended to be subclassed.
 */
class Actor
{
public:
  Actor();
  virtual ~Actor();
  virtual void draw(sf::RenderWindow& stage);
  virtual void update();
private:
};
#endif
