#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"

void display( void )
{
    extern vertex *treePoints;
    extern vertex *treePants;	//what we transform
    extern bool tess_flag;
    extern int p;
	extern vertex *treePants1;
	extern vertex *treePants2;

    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */

    glColor3f(1.0, 1.0, 1.0 );    /* Draw in Blue */
    glRecti(VIEWPORT_MIN, VIEWPORT_MIN, VIEWPORT_MAX, VIEWPORT_MAX);

    glColor3f(1.0, 0.0, 0.0);
	
    treePoints = ( vertex *) malloc((10000)*sizeof(vertex));
	
	drawTree();	//draws og tree
	p = p + 5;
	treePants = (vertex *) malloc(p*sizeof( vertex));
	treePants = treePoints;
	
	vertex temp, copy;
  	int count = 0;

	while(count < p)
 	{
 	    temp = *(treePants + count);
     	count++;
	}
	
	int num = p*2;
	
	Rotate(p);
	Scale(p);
	Reflect(p);
	
	vertex *in = (vertex *) malloc((num)*sizeof( vertex));
    vertex *out = (vertex *) malloc((num)*sizeof( vertex));
    in = treePants;
    
    count = 0;
    while(count < p)
    {
        temp = *(in + count);
        cout << count << " " << temp.x << " " << temp.y << endl;

        count++;
    }
    
    Clip(in, out);
   
    treePants = in;
    if(tess_flag == true)
    {
        Tess();
    }
    glColor3f(1.0, 0.0, 0.0);
    drawTTree(p);	//draws the transformed tree

    glutSwapBuffers();
}
