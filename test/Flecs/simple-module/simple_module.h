#ifndef SIMPLE_MODULE_H
#define SIMPLE_MODULE_H

#include <flecs.h>

#ifdef __cplusplus
extern "C" {
#endif

namespace simple {

struct Position {
    double x, y;
};

struct Velocity {
    double x, y;
};

struct module {
    module(flecs::world& world); // Ctor that loads the module
};

}

#ifdef __cplusplus
}
#endif

#endif

