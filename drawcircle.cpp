//draws the circle woooo
#include "includes.h"
#include "constants.h"
#include "structs.h"
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
    float x, y;
    float d;

    x = 0;
    y = radius;
    int numPoints = circumference(radius);
    int arrayPoints = numPoints/8;
	vertex seg1 [arrayPoints];
	vertex *point = new vertex;
	d = 5.0 / 4.0 - radius;
    int count = 0;
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
        /*glPointSize(1);
        glBegin(GL_POINTS);
		//first quarter
        glVertex2i(x+cx,y+cy);	//segment 1
        */point->x = x+cx;
		point->y = y+cy;
		seg1[count].x = point->x;
		seg1[count].y = point->y;
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
	glPointSize(1);
	glColor3f(0.0, 0.0, 0.0 );
    glBegin(GL_POINTS);
	int i = 0;
	while(i != count)
	{
		vertex *p = new vertex;
			p->x = seg1[i].x;
			p->y = seg1[i].y;
		glVertex2i(p->x,p->y);
		i++;
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
