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
	//cout << "arrayPoints: " << arrayPoints << endl;
    vertex points[arrayPoints];
    vertex *pointPtr = NULL;
    pointPtr = points;
    d = 5.0 / 4.0 - radius;
    pointPtr->x = x+cx;
    pointPtr->y = y+cy;
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
		pointPtr->x = x+cx;
        pointPtr->y = y+cy;
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
		//endPoint = pointPtr;
    }
    
	/*pointPtr--;	//puts the pointer to the last point of the first segment
	//cout << pointPtr->x << " " << pointPtr->y << endl;
	//cout << "flip" << endl;
	pointPtr--;
	vertex points1[arrayPoints];
    vertex *pointPtr1 = NULL;
    pointPtr1 = points1;
	int r = i-2;
    while(r >= 0)
    {
        pointPtr1->x = pointPtr->y;
        pointPtr1->y = pointPtr->x;
        pointPtr1->z = pointPtr->z;
		cout << pointPtr1->x << " " << pointPtr1->y << endl;
        pointPtr1++;
		glVertex2i(pointPtr->y, pointPtr->x);
		pointPtr--;
        r--;
    }*/
	//vertex *endPoint = pointPtr;
	pointPtr--;
	//pointPtr--;
	//endPoint = pointPtr;
	vertex *startPtr = NULL;
	startPtr = points;
	//cout << endPoint->x << " " << endPoint->y << endl;
	//cout << pointPtr->x << " " << pointPtr->y << endl;
	//endPoint--;
	//cout << endPoint->x << " " << endPoint->y << endl;
	int num = (4*count);
	vertex q1[num];
    //vertex *q1p = NULL;
    //q1p = q1;
    int c = 0;
	while(c != count)
	{
		//fourth segment
		q1[c].x = startPtr->x;
        q1[c].y = -y-radius+pointPtr->y;
        q1[c].z = startPtr->z;
		//third segment
		q1[c+count].x = pointPtr->y;
        q1[c+count].y = -x+startPtr->x;
        q1[c+count].z = startPtr->z;
		//adding the start of og points in order switching x and y (segment 2)
		q1[c+2*count].x = startPtr->y;
        q1[c+2*count].y = startPtr->x;
        q1[c+2*count].z = startPtr->z;
		//adding the end of og points in reverse but same x and y starting at count (segment 1)
		q1[c+3*count].x = pointPtr->x;
        q1[c+3*count].y = pointPtr->y;
        q1[c+3*count].z = pointPtr->z;
		startPtr++;
		pointPtr--;
		c++;
	}
	cout << "end, should start with 750 500" << endl;
	int f = 0;
	while(f != num)
	{
		cout << q1[f].x << " " << q1[f].y << endl;
		glVertex2i(q1[f].x, q1[f].y);
		f++;
	}
	/*vertex q2[num];
	vertex *q1p = q1;
	int g = 0;
	while(g != count)
	{
		q2[g].x = -y+q1p->y;
        q2[g].y = -x+q1p->x;
        q2[g].z = q1p->z;
		q1p++;
		g++;
	}
	cout << "second quater" << endl;
	f = 0;
    while(f != num)
    {
        cout << q2[f].x << " " << q2[f].y << endl;
        glVertex2i(q2[f].x, q2[f].y);
        f++;
    }*/
	glEnd();
    glFlush();
	/*cout << "end, should start with 750 500" << endl;
	int num = 2*count;
	vertex q1[num];
	vertex *q1p = NULL;
	q1p = q1;
	int c = count;
	//vertex *pointPtr1 = pointPtr;
	while(c != 0)
	{
		q1[c+count-1].x = pointPtr->x;
		q1[c+count-1].y = pointPtr->y;
		q1[c-count].x = pointPtr1->x;
		q1[c-count].y = pointPtr1->y;
		c--;
		q1p++;
		pointPtr++;
		pointPtr1++;
	} 
	int w = 0;
	while(w != num)
	{
		cout << q1p->x << " " << q1p->y << endl;
        glVertex2i(q1p->x, q1p->y);
        q1p++;
        w++;
	}*/
}
