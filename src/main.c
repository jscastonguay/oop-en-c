#include <stdio.h>
#include "square.h"
#include "circle.h"

#define NB_FIGURES 2

int main()
{
    
    Square carre;
    Square_ctor(&carre, 10);

    Circle cercle;
    Circle_ctor(&cercle, 5);

    Figure * f[NB_FIGURES];    
    f[0] = Square_upcast(&carre);
    f[1] = Circle_upcast(&cercle);
    
    printf("Aire du carré: %f\n", Figure_getArea(f[0]));
    printf("Aire du cercle: %f\n", Figure_getArea(f[1]));

    return 0;
}
