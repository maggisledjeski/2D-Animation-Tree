#include "includes.h"
#include "prototypes.h"
#include "constants.h"

void mouse(int button, int state, int x, int y)
{
	extern float deltaSpin;
    int y2 = WINDOW_MAX - y; 
	switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            {
                if((VIEWPORT_MIN < x) && (x < VIEWPORT_MAX) && (VIEWPORT_MIN < y2) && (y2 < VIEWPORT_MAX))
                {
                    deltaSpin = deltaSpin - 1.0;
                    glutIdleFunc(spinDisplay);
                    cout << y << " " << y2 << endl;
                } else
                {
                cout << "left-scale " << "x: " << x << "    " << "y: " << y << endl;
                }
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
            {
                if((VIEWPORT_MIN < x) && (x < VIEWPORT_MAX) && (VIEWPORT_MIN < y) && (y < VIEWPORT_MAX))
                {
                    deltaSpin = deltaSpin + 1.0;
                    glutIdleFunc(spinDisplay);
                } else
                {
                cout << "right-scale " << "x: " << x << "    " << "y: " << y << endl;
                }
            }
            break;
        default:
            break;	
	}
}

void keyboard(unsigned char key, int x, int y)
{
    extern float spin;
  	//exits the program if q or Q is clicked
	if(key == 'q' || key == 'Q') {
		exit(0);
    }
	if ( key == 'c' || key == 'C') {
        spin = 0.0;
        glutIdleFunc(display);
    }
    if ( key == 'x' || key == 'X') {
        glutIdleFunc(NULL);
    }

}
