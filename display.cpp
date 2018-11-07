#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"

void display( void )
{
    extern struct vertex *treePoints;
    extern struct vertex *treePants;	//what we transform
    extern int p;
	extern struct vertex *treePants1;
	extern struct vertex *treePants2;

    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */

    glColor3f(1.0, 1.0, 1.0 );    /* Draw in Blue */
    
    glRecti(VIEWPORT_MIN, VIEWPORT_MIN, VIEWPORT_MAX, VIEWPORT_MAX);
    glColor3f(1.0, 0.0, 0.0);
	//int arraySize = numPoints(200,600,450);
    treePoints = (struct vertex *) malloc((1000000)*sizeof(struct vertex));
	//treePants = (struct vertex *) malloc((1000000)*sizeof(struct vertex));
	drawTree();	//draws og tree
	p = p + 5;
	treePants = (struct vertex *) malloc((p)*sizeof(struct vertex));
	treePants = treePoints;
	
	/*vertex temp, copy;
	int count = 0;
	while(count < p)
	{
		temp = *(treePants + count);
		cout << temp.x << " " << temp.y << endl;
		//temp = *(treePoints + count);
		//copy.x = temp.x;
		//copy.y = temp.y;
		*(treePants + count) = copy;
		//cout << copy.x << " " << copy.y << endl;
		count++;
	}
	cout << "done" << endl;*/
	
	int num = p+100000000;
	//treePants = treePoints;
	//struct vertex *in = (struct vertex *) malloc((p)*sizeof(struct vertex));    
    //struct vertex *out = (struct vertex *) malloc((num)*sizeof(struct vertex));
	//in = treePants;
	
	Rotate(p);
	Scale(p);
	Reflect(p);
	
	//struct vertex *in = (struct vertex *) malloc((p)*sizeof(struct vertex));
    //struct vertex *out = (struct vertex *) malloc((num)*sizeof(struct vertex));
    //in = treePants;

	//Clip(in, out);	
	
    glColor3f(1.0, 0.0, 0.0);
	drawTTree(p);	//draws the transformed tree
	
	/*vertex min;
    min.x = VIEWPORT_MIN;
    min.y = VIEWPORT_MIN;
    vertex max;
    max.x = VIEWPORT_MAX;
    max.y = VIEWPORT_MAX;
    int num = 4;
	*/
	/*treePants1 = (struct vertex *) malloc((10)*sizeof(struct vertex));
	treePants2 = (struct vertex *) malloc((5)*sizeof(struct vertex));
	struct vertex *out = (struct vertex *) malloc((5)*sizeof(struct vertex));
	struct vertex *in = (struct vertex *) malloc((5)*sizeof(struct vertex));
	//struct vertex pI, pO;
//cout << "f" <<endl;	
	drawBox();
	in = treePants2;


//cout <<  << endl;
	//pI = treePants1;
	//treePants1 = treePants2;
	//int c = clip(min, max, num, pI, pO);
	//cout << c << endl;
	//polygonClipSuthHodg(min, max, num, pI, pO);	
	//clip();
	int p = 5;	
	//cout << "f2" << endl;
	Scale(p);
	//int c = clip(min, max, num, pI, pO);
	//cout << "f4" << endl;
	Clip(in, out);
	//cout << "f3" << endl;
	drawTBox(p);
//	cout << "f4" << endl;
	*/
	glFlush();	
	glutSwapBuffers();
}
