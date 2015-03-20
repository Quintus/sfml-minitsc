#include <iostream>
#include <stack>
#include <pathie.hpp>
#include <SFML/Graphics.hpp>
#include "texture_manager.hpp"
#include "scenes/scene.hpp"
#include "scene_manager.hpp"
#include "app.hpp"

int main(int argc, char* argv[])
{
  gp_app = new App;
  int result = gp_app->run();
  delete gp_app;

  return result;
}
