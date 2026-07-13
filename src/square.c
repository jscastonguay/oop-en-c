#include "square.h"

static inline Square * downcast(Figure * self) {
    return (Square *)self;
}

static float getArea(Figure * self) {
    Square * p = downcast(self);
    return p->_c * p->_c;
}

void Square_ctor(Square * self, float c) {
    assert(c > 0);
    Figure_ctor(&self->_parent, "Carré");
    self->_c = c;
    self->_parent.getArea = getArea;
}