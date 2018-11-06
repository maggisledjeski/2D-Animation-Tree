#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"

void display( void )
{
    extern struct vertex *treePoints;
    extern struct vertex *treePants;	//what we transform
    extern struct vertex *treePants1;
	extern struct vertex *treePants2;

    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */

    glColor3f(1.0, 1.0, 1.0 );    /* Draw in Blue */
    
    glRecti(VIEWPORT_MIN, VIEWPORT_MIN, VIEWPORT_MAX, VIEWPORT_MAX);
    glColor3f(1.0, 0.0, 0.0);
	/*int arraySize = numPoints(200,600,450);
    treePoints = (struct vertex *) malloc((1000000)*sizeof(struct vertex));

	drawTree();	//draws og tree
	
	treePants = treePoints;
	
	int t = numPoints(200,600,450);
    int tp = (6*t)+5;
	    
    Rotate(tp);
	Scale(tp);
	Reflect();
	
	//glEnd();
    //glFlush();
    drawTTree(tp);	//draws the transformed tree
	*/
	treePants1 = (struct vertex *) malloc((6)*sizeof(struct vertex));
	treePants2 = (struct vertex *) malloc((6)*sizeof(struct vertex));
	struct vertex *pO = (struct vertex *) malloc((1000000)*sizeof(struct vertex));
	struct vertex *pI = (struct vertex *) malloc((1000000)*sizeof(struct vertex));
	//struct vertex pI, pO;
	
	drawBox();
	//pI = treePants1;
	/*treePants1 = treePants2;
	vertex min;
	min.x = VIEWPORT_MIN;
	min.y = VIEWPORT_MIN;
	vertex max;
	max.x = VIEWPORT_MAX;
	max.y = VIEWPORT_MAX;
	int num = 4;
	int c = clip(min, max, num, pI, pO);
	cout << c << endl;
	*///polygonClipSuthHodg(min, max, num, pI, pO);	
	//clip();
	drawTBox(5);
		
	glutSwapBuffers();
}
