#ifndef MINITSC_SCENERY_HPP
#define MINITSC_SCENERY_HPP
/**
 * The scenery is nonmoving stuff. It is most of what you see in a level,
 * and rendering each element of the scenery separately is a performance
 * hit. Hence, the entire scenery is treated as one single large object
 * that is uploaded onto the graphics card in one action if you use this
 * class to construct it. Much more performant, but there’s no way to
 * access the scenery’s separate elements anymore.
 */
class Scenery: public sf::Drawable, public sf::Transformable
{
public:
  Scenery(Pathie::Path tileset_path, int edge_size);
  virtual ~Scenery();

  void add_scenery(int tileset_x, int tileset_y, int x, int y);

  /**
   * Checks if the given point is withing any of the bounding boxes of
   * a scenery element.
   */
  template<typename T>
  bool contains(const sf::Vector2<T>& point)
  {
    std::vector<sf::FloatRect>::iterator iter;
    for(iter=m_bounding_boxes.begin(); iter != m_bounding_boxes.end(); iter++) {
      if ((*iter).contains(point)) {
	return true;
      }
    }

    return false;
  }
private:
  virtual void draw(sf::RenderTarget& stage, sf::RenderStates states) const;

  int m_width;
  int m_height;
  int m_edge_size;
  sf::Texture m_tileset;
  sf::VertexArray m_vertices;
  std::vector<sf::FloatRect> m_bounding_boxes;
};

#endif
