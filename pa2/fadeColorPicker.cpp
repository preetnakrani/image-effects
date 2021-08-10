#include "fadeColorPicker.h"

fadeColorPicker::fadeColorPicker(double fade)
{
    /* your code here */
    fadeFactor = fade;
}

HSLAPixel fadeColorPicker::operator()(point p)
{
    /* your code here */
    // double distSq = ((p.c.x - p.x) * (p.c.x - p.x)) + ((p.c.y - p.y) * (p.c.y - p.y));
    // double newL = p.c.color.l * pow(fadeFactor, distSq); 

    // HSLAPixel ret;
    // ret.h = p.c.color.h;
    // ret.s = p.c.color.s;
    // ret.l = newL;
    // ret.a = p.c.color.a;
    // return ret;
    
    HSLAPixel ret;
    int distSq = pow((p.c.x - (int) p.x), 2) + pow((p.c.y - (int) p.y), 2); // check for type mismatch

    ret.h = p.c.color.h;
    ret.s = p.c.color.s;
    ret.l = p.c.color.l * pow(fadeFactor, sqrt(distSq));
    ret.a = p.c.color.a;

    return ret;

}
