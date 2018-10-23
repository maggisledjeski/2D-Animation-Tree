#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"

void display( void )
{
    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */

    glColor3f(1.0, 1.0, 1.0 );    /* Draw in Blue */
    
    glRecti(VIEWPORT_MIN, VIEWPORT_MIN, VIEWPORT_MAX, VIEWPORT_MAX);
    //int numPoints(int radius, int cx, int cy)
	int arraySize = numPoints(200,600,450);
    struct vertex * treePoints = (struct vertex *) malloc((arraySize+10)*sizeof(struct vertex));
	drawTree(treePoints);
    //MidpointCircle(200,400,400);
    //drawReverse(200,400,400);
    glFlush();
    
}
