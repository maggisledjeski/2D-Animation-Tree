#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"

void display( void )
{
    extern struct vertex *treePoints;
    extern struct vertex *treePants;	//what we transform

    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */

    glColor3f(1.0, 1.0, 1.0 );    /* Draw in Blue */
    
    glRecti(VIEWPORT_MIN, VIEWPORT_MIN, VIEWPORT_MAX, VIEWPORT_MAX);
    int arraySize = numPoints(200,600,450);
    treePoints = (struct vertex *) malloc((1000000)*sizeof(struct vertex));

	drawTree();
	
	treePants = treePoints;
	
	int t = numPoints(200,600,450);
    int tp = (6*t)+6;
	//cout << tp <<endl;
	Rotate(tp);
	    
    //glEnd();
    //glFlush();
    drawTTree(tp);
	glutSwapBuffers();
}
