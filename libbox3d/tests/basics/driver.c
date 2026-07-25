/* Public API smoke test for libbox3d. */

#include <box3d/box3d.h>
#include <box3d/math_functions.h>

#undef NDEBUG
#include <assert.h>
#include <stdio.h>

int main (void)
{
  b3WorldDef world_def = b3DefaultWorldDef ();
  world_def.gravity = (b3Vec3){0.0f, -10.0f, 0.0f};

  b3WorldId world = b3CreateWorld (&world_def);
  assert (b3World_IsValid (world));

  b3BodyDef ground_def = b3DefaultBodyDef ();
  ground_def.position = (b3Pos){0.0f, -10.0f, 0.0f};
  b3BodyId ground = b3CreateBody (world, &ground_def);
  assert (b3Body_IsValid (ground));

  b3BoxHull ground_box = b3MakeBoxHull (50.0f, 10.0f, 50.0f);
  b3ShapeDef ground_shape_def = b3DefaultShapeDef ();
  b3CreateHullShape (ground, &ground_shape_def, &ground_box.base);

  b3BodyDef body_def = b3DefaultBodyDef ();
  body_def.type = b3_dynamicBody;
  body_def.position = (b3Pos){0.0f, 4.0f, 0.0f};
  b3BodyId body = b3CreateBody (world, &body_def);
  assert (b3Body_IsValid (body));

  b3BoxHull box = b3MakeCubeHull (1.0f);
  b3ShapeDef shape_def = b3DefaultShapeDef ();
  shape_def.density = 1.0f;
  b3CreateHullShape (body, &shape_def, &box.base);

  for (int i = 0; i < 60; ++i)
    b3World_Step (world, 1.0f / 60.0f, 4);

  b3Pos p = b3Body_GetPosition (body);
  printf ("smoke position: %f %f %f\n", (double)p.x, (double)p.y, (double)p.z);

  /* Dynamic body should have fallen toward the ground. */
  assert (p.y < 4.0f);

  b3DestroyWorld (world);
  return 0;
}
