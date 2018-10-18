#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"
using namespace std;

void drawTree()
{
	lineDDA(200,500,650,475);
    lineDDA(200,500,200,400);
	lineDDA(200,400,650,425);
	circle(250,500,500);
}

void lineDDA (int x0, int y0, int xEnd, int yEnd)
{
	int dx = xEnd - x0,  dy = yEnd - y0, steps, k, _x, _y;
	float xIncrement, yIncrement, x = x0, y = y0;
	if (fabs (dx) > fabs (dy))
	{
		steps = fabs (dx);
	}else
	{
		steps = fabs (dy);
	}
	xIncrement = float (dx) / float (steps);
	yIncrement = float (dy) / float (steps);
	_x = round(x);
	_y = round(y);
	for (k = 0; k < steps; k++) {
		x += xIncrement;
		y += yIncrement;
		glPointSize(1);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_POINTS);
		glVertex2f(round(x),round(y));
		glEnd();
		glFlush();
	}
}

void circle(int radius, int cx, int cy)
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
		pointPtr->x = x+cx;
        pointPtr->y = y+cy;
        pointPtr->z = 0;
        pointPtr++;
        count++;
	}
	glPointSize(1);
    glColor3f(0.0, 0.0, 0.0 );
    glBegin(GL_POINTS);
    pointPtr = points;
    int i = 0;
    while(i != count)
    {
        cout << pointPtr->x << " " << pointPtr->y << endl;
		glVertex2i(pointPtr->x, pointPtr->y);
        pointPtr++;
        i++;
    }
    
	pointPtr--;	//puts the pointer to the last point of the first segment
	//cout << pointPtr->x << " " << pointPtr->y << endl;
	cout << "flip" << endl;
	vertex points1[arrayPoints];
    vertex *pointPtr1 = NULL;
    pointPtr1 = points1;
	int r = i-1;
    while(r >= 0)
    {
        pointPtr1->x = pointPtr->y;
        pointPtr1->y = pointPtr->x;
        pointPtr1->z = 0;
		cout << pointPtr1->x << " " << pointPtr1->y << endl;
        pointPtr1++;
		glVertex2i(pointPtr->y, pointPtr->x);
		pointPtr--;
        r--;
    }
    glEnd();
    glFlush();

	/*vertex tree[numPoints];
	vertex *tp = NULL;
	tp = tree;
	int tc = 0;
	while(tc != numPoints)
	{
	*/	
}
