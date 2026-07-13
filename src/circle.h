#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"
#include <assert.h>

typedef struct {
    
    // Héritage, doit être le premier élément de la struct
    Figure _parent;
    
    float _r;
} Circle;

static inline Figure * Circle_upcast(Circle * self) {
    return (Figure *)self;
}

void Circle_ctor(Circle * self, float r);

#endif  