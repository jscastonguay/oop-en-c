#ifndef FIGURE_H
#define FIGURE_H

#include <assert.h>
#include <stdio.h>

typedef struct Figure Figure;
struct Figure {
    char * _name;
    float (*getArea)(Figure *);
};

static inline void Figure_ctor(Figure * self, char * name) {
    self->_name = name;
    self->getArea = NULL;
}

static inline float Figure_getArea(Figure * self) {
    assert(self->getArea);
    return self->getArea(self);
}

#endif