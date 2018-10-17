#include "includes.h"
#include "constants.h"
//#include "structs.h"
//#include "prototypes.h"

void drawTree()
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	
    glVertex2i(200,500);
    glVertex2i(700,475);
    
    glVertex2i(200,500);
	glVertex2i(200,400);
	
	glVertex2i(200,400);
	glVertex2i(700,425);
	glEnd();
	glFlush();
}
