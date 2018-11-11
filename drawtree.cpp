#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"
using namespace std;

void drawTree()
{
	extern struct vertex *treePoints;
    //extern int p;
	vertex spot;
    //p = p + 6;
	//adding the trunk points to the treePoints array    
    spot.x = 458;//463;//458;
    spot.y = 641;//646;//642;
    spot.z = 0;
	spot.w = 1;
    *(treePoints + 0) = spot;
    spot.x = 650;
    spot.y = 525;
    spot.w = 1;
    *(treePoints + 1) = spot;
    spot.x = 200;
    spot.y = 550;
	spot.z = 0;
    spot.w = 1;
    *(treePoints + 2) = spot;
    spot.x = 200;
    spot.y = 450;
	spot.z = 0;
    spot.w = 1;
    *(treePoints + 3) = spot;
    spot.x = 650;
    spot.y = 475;
	spot.z = 0;
    spot.w = 1;
    *(treePoints + 4) = spot;
	
	circle(200,600,500);
	
}

void circle(int radius, int cx, int cy)
{
    extern struct vertex *treePoints;
    extern int p;
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
		pointPtr->z = 0;
        pointPtr->w = 1;
        pointPtr++;
        count++;
	}
	glPointSize(1);
    glColor3f(0.0, 0.0, 0.0 );
    glBegin(GL_POINTS);
    pointPtr = points;
    vertex *endPoint = NULL;
	int i = 0;
    while(i < count)
    {
        pointPtr++;
        i++;		
    }
	pointPtr--;
	int num = (6*count);
    p = num;
	vertex q1[num];
	vertex *startPtr = NULL;
    startPtr = points;
	int c = 0;
    while(c < count)
    {
		//fifth segment
		q1[c].x = cx-pointPtr->x;
        q1[c].y = cy-pointPtr->y;
		q1[c].z = 0;
        q1[c].w = startPtr->w;
		//fourth segment
		q1[c+count].x = cx+startPtr->x;
        q1[c+count].y = cy-startPtr->y;
		q1[c+count].z = 0;
        q1[c+count].w = startPtr->w;
		//third segment 
		q1[c+2*count].x = cx+pointPtr->y;
        q1[c+2*count].y = cy-pointPtr->x;
        q1[c+2*count].z = 0;
		q1[c+2*count].w = startPtr->w;
		//second segment
		q1[c+3*count].x = cx+startPtr->y;
        q1[c+3*count].y = cy+startPtr->x;
        q1[c+3*count].z = 0;
		q1[c+3*count].w = startPtr->w;
		//first segment 
		q1[c+4*count].x = cx+pointPtr->x;
        q1[c+4*count].y = cy+pointPtr->y;
        q1[c+4*count].z = 0;
		q1[c+4*count].w = pointPtr->w;
        //eighth segment put in last
        q1[c+5*count].x = cx-startPtr->x;
        q1[c+5*count].y = cy+startPtr->y;
        q1[c+5*count].z = 0;
		q1[c+5*count].w = startPtr->w;
		startPtr++;
        pointPtr--;
        c++;
	}	
	vertex spot;
	//adds the circle points to treePoints
	int f = 0;
	while(f != num)
	{
		spot.x = q1[f].x;
        spot.y = q1[f].y;
		spot.z = 0;
        spot.w = 1;
        *(treePoints + 5 + f) = spot;	
        f++;
	}
	glEnd();
	glFlush();	
	return ;
}

/*draws the transformed tree*/
void drawTTree(int nump)
{
	extern struct vertex *treePants;
    extern struct triangle *triPants;
    extern list <triangle> TList;
    extern bool tess_flag;
    extern int tess_count;

    if(tess_flag == true)
    {
        glBegin(GL_LINE_STRIP);
        triangle td;
        vertex ts1, ts2, ts3;
        int tcount = 0;
        while(tcount < tess_count)
        {
            td = *(triPants + tcount);
            ts1 = td.tone;
            ts2 = td.ttwo;
            ts3 = td.tthree;
            glVertex2f(ts1.x, ts1.y);
            glVertex2f(ts2.x, ts2.y);
            glVertex2f(ts3.x, ts3.y);
            tcount++;
        }
        glEnd();
        glFlush();
    
    } else
    {
	    int i;

        vertex spot;
        glBegin(GL_LINE_STRIP);
        for (i=0;i<nump;i++)
        {
            spot = *(treePants + i);
            glVertex2f(spot.x, spot.y);
        }
    }
    glEnd();
    glFlush();
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
	return count;
}


