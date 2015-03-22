#include <pathie.hpp>
#include <SFML/Graphics.hpp>
#include "scenery.hpp"

Scenery::Scenery(Pathie::Path tileset_path, int edge_size)
{
  m_edge_size = edge_size;
  m_tileset.loadFromFile(tileset_path.native());
  m_vertices.setPrimitiveType(sf::Quads);
}

Scenery::~Scenery()
{
  //
}

void Scenery::add_scenery(int tileset_x, int tileset_y, int x, int y)
{
  unsigned int index = m_vertices.getVertexCount();
  m_vertices.resize(index + 4); // 4 corners for a new quad

  m_vertices[index    ].position = sf::Vector2f(x, y);
  m_vertices[index + 1].position = sf::Vector2f(x + m_edge_size, y);
  m_vertices[index + 2].position = sf::Vector2f(x + m_edge_size, y + m_edge_size);
  m_vertices[index + 3].position = sf::Vector2f(x, y + m_edge_size);

  m_vertices[index    ].texCoords = sf::Vector2f(tileset_x, tileset_y);
  m_vertices[index + 1].texCoords = sf::Vector2f(tileset_x + m_edge_size, tileset_y);
  m_vertices[index + 2].texCoords = sf::Vector2f(tileset_x + m_edge_size, tileset_y + m_edge_size);
  m_vertices[index + 3].texCoords = sf::Vector2f(tileset_x, tileset_y + m_edge_size);
}

void Scenery::draw(sf::RenderTarget& stage, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &m_tileset;
  stage.draw(m_vertices, states);
}
