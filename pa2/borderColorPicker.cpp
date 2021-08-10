#include "borderColorPicker.h"

borderColorPicker::borderColorPicker(unsigned int borderSize, HSLAPixel fillColor, PNG &img, double tolerance)
{
    /* your code here */
    this->borderSize = borderSize; // Number of pixels to use for border
    this->fillColor = fillColor;     // Color used for the border
    this->img = img;                 // Image used in flood fill algorithm
    this->tolerance = tolerance; 

}

HSLAPixel borderColorPicker::operator()(point p)
{
//     /* your code here */
//     int minX = (0 <= p.x - borderSize) ? p.x - borderSize : 0;
//     int minY = (0 <= p.y - borderSize) ? p.y - borderSize : 0;
//     int maxX = (img.width() <= p.x - borderSize) ? p.x - borderSize : img.width();
//     int maxY = (img.height() <= p.y - borderSize) ? p.y - borderSize : img.height();
    

//     for(int i = minX; i < p.x + borderSize; i++) {
//         for (int j = minY; j < p.y + borderSize; j++)
//         {
//             /* code */
//             double distSq = ((p.x - i) * (p.x - i)) + ((p.y - j) * (p.y - j));
//             if ( /*pow(distSq, 0.5) < borderSize && */ p.c.color.dist() <= tolerance && p.c.color > tolerance) {
//                 return fillColor;
//             }



//         }

        
//     }
// return p.c.color;

//  int minX = (0 <= p.x - borderSize) ? p.x - borderSize : 0;
//     int minY = (0 <= p.y - borderSize) ? p.y - borderSize : 0;
//     int maxX = (img.width() <= p.x - borderSize) ? p.x - borderSize : img.width();
//     int maxY = (img.height() <= p.y - borderSize) ? p.y - borderSize : img.height();
    

//     for(int i = minX; i < p.x + borderSize; i++) {
//         for (int j = minY; j < p.y + borderSize; j++)
//         {
//             /* code */
            
//             if (p.c.color.dist() <= tolerance && p.c.color > tolerance) {
//                 return fillColor;
//             }



//         }

        
//     }
// return p.c.color;

// HSLAPixel defaultPixel = *(img.getPixel(p.x, p.y));

//      for (int i = p.x - borderSize; i < p.x + borderSize; ++i) {
//     	for (int j = p.y - borderSize; j < p.y + borderSize; ++j) {
 
//     		bool radialDist = i*2 + j*j <= borderSize*borderSize;

//     		if (radialDist) {
//     			if (i >= 0 && i < img.width() && j >= 0 && j < img.height()) {
//     				HSLAPixel q = *(img.getPixel(i, j));
//     				if (defaultPixel.dist(q) > tolerance) {
//     					return fillColor;
//     				}
//     			} else {
//     				return fillColor;
//     			}
//     		}
//     	}
//     }

//     return defaultPixel;

HSLAPixel defaultPixel = *(img.getPixel(p.x, p.y));

    for (int i = (int) p.x - (int) borderSize; i <= (int) p.x + (int) borderSize; ++i) {
    	for (int j = (int)p.y - (int)borderSize; j <= (int) p.y + (int) borderSize; ++j) {
 
    		bool radialDist = pow(i - (int) p.x, 2) + pow(j - (int) p.y, 2) <= pow(borderSize, 2);

    		if (radialDist) {
    			if (i >= 0 && i < (int) img.width() && j >= 0 && j < (int) img.height()) {
    				HSLAPixel q = *(img.getPixel(i, j));
    				if (q.dist(p.c.color) >= tolerance) {
    					return fillColor;
    				}
    			} else {
    				return fillColor;
    			}
    		}
    	}
    }

    return defaultPixel;



}