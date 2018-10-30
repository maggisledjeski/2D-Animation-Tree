#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"
using namespace std;

void drawTree()
{
	extern struct vertex *treePoints;
    vertex spot;
    //int arraySize = numPoints(200,600,450);
	//struct vertex * treePoints = (struct vertex *) malloc((numPoints+10)*sizeof(struct vertex));
	/*treePoints->x = 458;
	treePoints->y = 591;
	treePoints->w = 1;
	treePoints++;
	treePoints->x = 600;
    treePoints->y = 475;
    treePoints->w = 1;
	treePoints++;*/
    
    spot.x = 458;
    spot.y = 309;
    spot.w = 1;
    *(treePoints + 0) = spot;
    spot.x = 458;
    spot.y = 591;
    spot.w = 1;
    *(treePoints + 1) = spot;
    spot.x = 600;
    spot.y = 475;
    spot.w = 1;
    *(treePoints + 2) = spot;
    spot.x = 200;
    spot.y = 500;
    spot.w = 1;
    *(treePoints + 3) = spot;
    spot.x = 200;
    spot.y = 400;
    spot.w = 1;
    *(treePoints + 4) = spot;
    spot.x = 600;
    spot.y = 425;
    spot.w = 1;
    *(treePoints + 5) = spot;
    
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(458,591);
	glVertex2i(600,475);
	glVertex2i(600,475);
	glVertex2i(200,500);
    glVertex2i(200,500);
	glVertex2i(200,400);
	glVertex2i(200,400);
	glVertex2i(600,425);
	//this is the last line connecting the canopy to the tree
    glVertex2i(600,425);
    glVertex2i(458,309);
	glEnd();
	glFlush();
	
	circle(200,600,450);
	
}

void circle(int radius, int cx, int cy)
{
    extern struct vertex *treePoints;
    
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
    pointPtr->w = 1;
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
        pointPtr->w = 1;
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
    while(i < count)//!= count)
    {
        //cout << pointPtr->x << " " << pointPtr->y << endl;
		//glVertex2i(pointPtr->x, pointPtr->y);
        pointPtr++;
        i++;		
    }
	pointPtr--;

	int num = (6*count);
    vertex q1[num];
	vertex *startPtr = NULL;
    startPtr = points;
	int c = 0;
    while(c < count)//!= count)
    {
		/*//eighth segment
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
        q1[c+2*count].z = startPtr->z;*/
		//fifth segment
		q1[c].x = cx-pointPtr->x;
        q1[c].y = cy-pointPtr->y;
        q1[c].w = startPtr->w;
		//fourth segment
		q1[c+count].x = cx+startPtr->x;
        q1[c+count].y = cy-startPtr->y;
        q1[c+count].w = startPtr->w;
		//third segment 
		q1[c+2*count].x = cx+pointPtr->y;
        q1[c+2*count].y = cy-pointPtr->x;
        q1[c+2*count].w = startPtr->w;
		//second segment
		q1[c+3*count].x = cx+startPtr->y;
        q1[c+3*count].y = cy+startPtr->x;
        q1[c+3*count].w = startPtr->w;
		//first segment 
		q1[c+4*count].x = cx+pointPtr->x;
        q1[c+4*count].y = cy+pointPtr->y;
        q1[c+4*count].w = pointPtr->w;
        //eighth segment put in last
        q1[c+5*count].x = cx-startPtr->x;
        q1[c+5*count].y = cy+startPtr->y;
        q1[c+5*count].w = startPtr->w;
		startPtr++;
        pointPtr--;
        c++;
	}	
	vertex spot;
	//prints out the circle points
	int f = 0;
	while(f != num)
	{
		if(f%count==0)
		{
			cout << "new section" << endl;
		}
		cout << q1[f].x << " " << q1[f].y << endl;
        spot.x = q1[f].x;
        spot.y = q1[f].y;
        spot.w = 1;
        *(treePoints + 6 + f) = spot;	
        glVertex2i(spot.x, spot.y);
		f++;
	}
	glEnd();
    glFlush();	
	return ;
}

int numPoints(int radius, int cx, int cy)
{
    int x, y;
    float d;

    x = 0;
    y = radius;
    d = 5.0 / 4.0 - radius;
    
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
        count++;
    }
    cout << "count: " << count << endl;
	return count;
}
