#include <raylib.h>
#include "utils/utils.h"
#include "main.h"


int main(int, char**) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib");
    SetTargetFPS(60);
    SetWindowPosition(2800, 400);

    entt::registry registry;
    const auto entity = registry.create();
    registry.emplace<unit>(entity, RED);
    registry.emplace<position>(entity, create_dynamic_body(100.0f, 100.0f));
    registry.emplace<velocity>(entity, 1, 1);

    const auto entity2 = registry.create();
    registry.emplace<unit>(entity2, BLUE);
    registry.emplace<position>(entity2, create_static_body(100.0f, 300.0f));
    registry.emplace<velocity>(entity2, 1, 1);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        update(registry);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void update(entt::registry &registry) {
    const auto view = registry.view<position, velocity, unit>();
    const float timeStep = 1.0f / 60.0f;
    const int32 velocityIterations = 6;
    const int32 positionIterations = 2;

    for (const entt::entity u : view) {
        unit un = view.get<unit>(u);
        b2Body* pos = view.get<position>(u).body;

        un.draw_unit(pos);
        world.Step(timeStep, velocityIterations, positionIterations);
    }
}

