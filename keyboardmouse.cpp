#include "includes.h"
#include "prototypes.h"
#include "constants.h"

void mouse(int button, int state, int x, int y)
{
	extern float deltaSpin;
	extern float dsf;
	
    int y2 = WINDOW_MAX - y; 
	switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            {
                if((VIEWPORT_MIN < x) && (x < VIEWPORT_MAX) && (VIEWPORT_MIN < y2) && (y2 < VIEWPORT_MAX))
                {
                    deltaSpin = deltaSpin - 1.0;
                    glutIdleFunc(spinDisplay);
                    //cout << y << " " << y2 << endl;
                } else
                {
                	dsf = dsf + 0.05;
					scaleDisplay();
					//cout << "left-scale " << "x: " << x << "    " << "y: " << y << endl;
                }
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
            {
                if((VIEWPORT_MIN < x) && (x < VIEWPORT_MAX) && (VIEWPORT_MIN < y2) && (y2 < VIEWPORT_MAX))
                {
                    deltaSpin = deltaSpin + 1.0;
                    glutIdleFunc(spinDisplay);
                } else
                {
                	dsf = dsf - 0.05;
                    scaleDisplay();
					//cout << "right-scale " << "x: " << x << "    " << "y: " << y << endl;
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
	extern float sf;
    extern float rf;
	extern int p;

  	//exits the program if q or Q is clicked
	if(key == 'q' || key == 'Q') {
		exit(0);
    }
	//stops all animation and returns the original tree
	if(key == 'i' || key == 'I') {
        spin = 0.0;
		sf = 1.0;
        glutIdleFunc(display);
    }
	//stops all animation
    if(key == 's' || key == 'S') {
        glutIdleFunc(NULL);
    }
	if(key == 'r' || key == 'R') {
        rf = 3.14159265358979323846;	//sets rf to be PI
		spin = spin + 180;
        if(spin > 360.0)
        {
        	spin = spin - 360;
        }
        Reflect(p);
    }
	if(key == 'f' || key == 'F') {
        //fill tesselation
    }
	if(key == 't' || key == 'T') {
        //tess outline
		Tess();
    }
	if(key == 'l' || key == 'L') {
        //get rid of tess stuff
    }



	
}
