//
// Created by camilo.r on 24/06/22.
//

#ifndef RAYLIBTEST_UTILS_H
#define RAYLIBTEST_UTILS_H

#include <box2d/box2d.h>

extern b2Vec2 gravity;
extern b2World world;

b2Body* create_dynamic_body(float x, float y);
b2Body* create_static_body(float x, float y);

#endif //RAYLIBTEST_UTILS_H
