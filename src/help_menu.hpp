#ifndef HELP_MENU_H
#define HELP_MENU_H

#include "Utility/utility.hpp"
#include "Utility/program.hpp"
#include "Utility/texture.hpp"

// Singleton design pattern from https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
class HelpMenu {
public:
  HelpMenu(HelpMenu const&) = delete;
  void operator=(HelpMenu const&) = delete;
  static HelpMenu& getInstance()
  {
    static HelpMenu instance;
    return instance;
  }

  void init();
  void draw(glm::mat4 projection);
  bool showHelp = false;
  bool showTowerHelp = false;

private:
  HelpMenu();
  ~HelpMenu();

  GLuint VAO, VBO;
  shared_ptr<Program> program;
  const vec2 position = vec2(265.f, 115.f);
  const vec2 scale = vec2(730.f, 570.f);
  //shared_ptr<Texture> mainmenu_help_texture;
  shared_ptr<Texture> controls_texture;
  shared_ptr<Texture> tower_help_texture;
};

#endif