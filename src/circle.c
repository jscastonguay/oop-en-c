#include "circle.h"
#include <math.h>

static inline Circle * downcast(Figure * self) {
    return (Circle *)self;
}

static float getArea(Figure * self) {
    Circle * p = downcast(self);
    return M_PI * p->_r * p->_r;
}

void Circle_ctor(Circle * self, float r) {
    assert(r > 0);
    Figure_ctor((Figure *) self, "Cercle");
    self->_r = r;
    self->_parent.getArea = getArea;
}