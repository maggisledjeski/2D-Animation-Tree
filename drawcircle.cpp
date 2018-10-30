//draws the circle woooo
#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"
using namespace std;

int circumference(int radius)
{
    int ans = 2*M_PI*radius;
    //cout << ans << endl;
    return ans;
}

void MidpointCircle(int radius, int cx, int cy)
{
    int x, y;
    float d;

    x = 0;
    y = radius;
    int numPoints = circumference(radius);
    int arrayPoints = numPoints/8;

	vertex points[arrayPoints];
	vertex *pointPtr = NULL;
	pointPtr = points;
	d = 5.0 / 4.0 - radius;
    int count = 0;
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
        /*glPointSize(1);
        glBegin(GL_POINTS);
		//first quarter
        glVertex2i(x+cx,y+cy);	//segment 1
        */
		pointPtr->x = x+cx;
		pointPtr->y = y+cy;
		pointPtr->w = 0;
		pointPtr++;
		count++;
		/*glVertex2i(y+cy,x+cx);	//segment 2
        //second quarter
		glVertex2i(y+cy,-x+cx); //segment 3
		glVertex2i(x+cx,-y+cy);	//segment 4
        //third quarter
        glVertex2i(-x+cx,-y+cy);	//segment 5
        glVertex2i(-y+cy,-x+cx);	//segment 6
        //fourth quarter
		glVertex2i(-y+cy,x+cx);	//segment 7
		glVertex2i(-x+cx,y+cy);	//segment 8

        glEnd();
        glFlush();*/
    }
	//cout << count << endl;
	glPointSize(1);
	glColor3f(0.0, 0.0, 0.0 );
    glBegin(GL_POINTS);
	pointPtr = points;
	int i = 0;
	while(i != count)
	{
		glVertex2i(pointPtr->x, pointPtr->y);
		pointPtr++;
		i++;
	}
	glEnd();
	glFlush();
	glPointSize(1);
    glColor3f(0.0, 0.0, 0.0 );
    glBegin(GL_POINTS);
	int r = i;
	while(r != 0)
	{
		glVertex2i(pointPtr->y, pointPtr->x);
		pointPtr--;
        r--;
	}
	glEnd();
	glFlush();
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
