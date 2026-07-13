#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"
#include <assert.h>

typedef struct {
    
    // Héritage, doit être le premier élément de la struct
    Figure _parent;
    
    float _c;
} Square;

static inline Figure * Square_upcast(Square * self) {
    return (Figure *)self;
}

void Square_ctor(Square * self, float c);

#endif  