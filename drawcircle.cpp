//draws the circle woooo
#include "includes.h"
#include "constants.h"
//#include "structs.h"
#include "prototypes.h" 
using namespace std;

int circumference(int radius)
{
    int ans = 2*M_PI*radius;
    cout << ans << endl;
    return ans;
}

void MidpointCircle(int radius, int cx, int cy)
{
    int x, y;
    float d;
    x = 0;
    y = radius;
    int numPoints = circumference(radius);
    d = 5.0 / 4.0 - radius;
    //WriteCircle(x,y);
    while (y>x) 
    {
        if ( d <= 0 ) 
        {        // Choose E
            d += x * 2.0 + 3;
            x++;
        }
        else 
        {                 // Choose SE
            d += (x-y)*2.0+5;
            x++;
            y--;
        }
        glPointSize(1);
        glBegin(GL_POINTS);
        glVertex2i(x+cx,y+cy);
        glEnd();
        glFlush();
        //WritePixel(x,y);
    }
}

void drawReverse(int radius, int cx, int cy)
{
    int x, y;
    float d;
    x = 0;
    y = radius;
    d = 5.0 / 4.0 - radius;
    while (y>x)
    {
        if ( d <= 0 )
        {
            d += x * 2.0 + 3;
            x++;
        }
        else
        { 
            d += (x-y)*2.0+5;
            x++;
            y--;
        }
        glPointSize(1);
        glBegin(GL_POINTS);
        glVertex2i(y+cy,x+cx);
        glEnd();
        glFlush();
    }
}
