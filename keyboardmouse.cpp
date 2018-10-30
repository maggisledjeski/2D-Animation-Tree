#include "includes.h"
#include "prototypes.h"


void mouse(int button, int state, int x, int y)
{
	extern float deltaSpin;
 
	switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            {
                deltaSpin = deltaSpin - 1.0;
                glutIdleFunc(spinDisplay);
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
            {
                deltaSpin = deltaSpin + 1.0;
                glutIdleFunc(spinDisplay);
            }
            break;
        default:
            break;	
	}
}

void keyboard(unsigned char key, int x, int y)
{
	//exits the program if q or Q is clicked
	if(key == 'q' || key == 'Q') {
		exit(0);
    }
/*	if ( key == 'c' || key == 'C') {
        SPIN = 0.0;
        glutIdleFunc(display);
    }
    if ( key == 'x' || key == 'X') {
        glutIdleFunc(NULL);
    }
*/
}
