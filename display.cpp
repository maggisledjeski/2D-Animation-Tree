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
    treePoints = (struct vertex *) malloc((10000)*sizeof(struct vertex));
	//treePants = (struct vertex *) malloc((1000000)*sizeof(struct vertex));
	drawTree();	//draws og tree
	p = p + 5;
	treePants = (struct vertex *) malloc((p)*sizeof(struct vertex));
	treePants = treePoints;
	
	vertex temp, copy;
  	int count = 0;
	//this prints out all of treePants to show that it has all of treePoints
 	cout << p << endl;
	while(count < p)
 	{
 	temp = *(treePants + count);
 	cout << count << " " << temp.x << " " << temp.y << endl;
 	count++;
	}
	cout << "treePants done" << endl;

	
	int num = p+10000;
	
	Rotate(p);
	Scale(p);
	Reflect(p);
	
	

	struct vertex *in = (struct vertex *) malloc((p)*sizeof(struct vertex));
    struct vertex *out = (struct vertex *) malloc((num)*sizeof(struct vertex));
    in = treePants;
	//this prints out all of the *in to show that it has all of treePants
	cout << p << endl;
	count = 0;
	while(count < p)
    {
temp = *(in + count);
		cout << count << " " << temp.x << " " << temp.y << endl;
		    
    count++;
    }
    cout << "in done" << endl;

	//Clip(in, out);

    glColor3f(1.0, 0.0, 0.0);
	drawTTree(p);	//draws the transformed tree
		
	glutSwapBuffers();
}
