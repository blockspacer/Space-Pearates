#include "enemy_factory.hpp"

EnemyFactory::EnemyFactory()
{
}

EnemyFactory::~EnemyFactory()
{
}

Entity EnemyFactory::build(glm::vec2 position, glm::vec2 scale)
{
  Program *program = new Program(shader_path("sprite.vert"), shader_path("sprite.frag"));
  SpriteComponent *sprite = new SpriteComponent(program, new Texture());
  TransformComponent *transform = new TransformComponent(position, scale, 0.0f);
  MovementComponent *move = new MovementComponent(glm::vec2(0.0, 0.0), glm::vec2(0.0, 1.0));
  ColorComponent *colour;
  colour = new ColorComponent(glm::vec4(0.0f, 1.0f, 0.6f, 1.0f));

  Entity e;
  e.setComponent<SpriteComponent>(sprite);
  e.setComponent<TransformComponent>(transform);
  e.setComponent<ColorComponent>(colour);
  e.setComponent<MovementComponent>(move);
  return e;
}
