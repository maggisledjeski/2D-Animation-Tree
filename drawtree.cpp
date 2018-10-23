#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"
using namespace std;

void drawTree()
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(200,500);
    glVertex2i(600,475);
    glVertex2i(200,500);
	glVertex2i(200,400);
	glVertex2i(200,400);
	glVertex2i(600,425);
	glEnd();
	glFlush();
	
	circle(200,600,450);
}

//not used
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
    pointPtr->x = x;
    pointPtr->y = y;
    pointPtr->z = 1;
    pointPtr++;
	int count = 1;
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
		pointPtr->x = x;
        pointPtr->y = y;
        pointPtr->z = 1;
        pointPtr++;
        count++;
	}
	cout << "count: " << count << endl;
	glPointSize(1);
    glColor3f(0.0, 0.0, 0.0 );
    glBegin(GL_POINTS);
    pointPtr = points;
    vertex *endPoint = NULL;
	int i = 0;
    while(i != count)
    {
        //cout << pointPtr->x << " " << pointPtr->y << endl;
		//glVertex2i(pointPtr->x, pointPtr->y);
        pointPtr++;
        i++;		
    }
	pointPtr--;

	int num = (8*count);
    vertex q1[num];
	vertex *startPtr = NULL;
    startPtr = points;
	int c = 0;
    while(c != count)
    {
		//eighth segment
		q1[c].x = cx-startPtr->x;
        q1[c].y = cy+startPtr->y;
        q1[c].z = startPtr->z;
		//seventh segment
		q1[c+count].x = cx-pointPtr->y;
        q1[c+count].y = cy+pointPtr->x;
        q1[c+count].z = startPtr->z;
		//sixth segment
		q1[c+2*count].x = cx-startPtr->y;
        q1[c+2*count].y = cy-startPtr->x;
        q1[c+2*count].z = startPtr->z;
		//fifth segment
		q1[c+3*count].x = cx-pointPtr->x;
        q1[c+3*count].y = cy-pointPtr->y;
        q1[c+3*count].z = startPtr->z;
		//fourth segment
		q1[c+4*count].x = cx+startPtr->x;
        q1[c+4*count].y = cy-startPtr->y;
        q1[c+4*count].z = startPtr->z;
		//third segment
		q1[c+5*count].x = cx+pointPtr->y;
        q1[c+5*count].y = cy-pointPtr->x;
        q1[c+5*count].z = startPtr->z;
		//second segment
		q1[c+6*count].x = cx+startPtr->y;
        q1[c+6*count].y = cy+startPtr->x;
        q1[c+6*count].z = startPtr->z;
		//first segment
		q1[c+7*count].x = cx+pointPtr->x;
        q1[c+7*count].y = cy+pointPtr->y;
        q1[c+7*count].z = pointPtr->z;
        startPtr++;
        pointPtr--;
        c++;
	}
	//prints out the circle points
	int f = 0;
	while(f != num)
	{
		cout << q1[f].x << " " << q1[f].y << endl;
		glVertex2i(q1[f].x, q1[f].y);
		f++;
	}
	glEnd();
    glFlush();	
}
