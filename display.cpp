#include "includes.h"
#include "constants.h"
#include "structs.h"
#include "prototypes.h"

void display( void )
{
    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */

    glColor3f(1.0, 1.0, 1.0 );    /* Draw in Blue */
    
    glRecti(VIEWPORT_MIN, VIEWPORT_MIN, VIEWPORT_MAX, VIEWPORT_MAX);
    drawTree();
    MidpointCircle(200,400,400);
    //drawReverse(200,400,400);
    glFlush();
    
}
