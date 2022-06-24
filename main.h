//
// Created by camilo.r on 21/06/22.
//

#include <entt/entt.hpp>

#ifndef RAYLIBTEST_MAIN_H
#define RAYLIBTEST_MAIN_H

void update(entt::registry &registry);

struct position {
    b2Body* body;
};

struct velocity {
    int dx;
    int dy;
};

struct unit {
    Color cl;

    public:
    void draw_unit(b2Body* pos) const {
        DrawRectangle(pos->GetPosition().x, pos->GetPosition().y, 100, 100, this->cl);
    }
};

#endif //RAYLIBTEST_MAIN_H
