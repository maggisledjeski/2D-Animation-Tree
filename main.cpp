//this is my main file

#include "includes.h"
#include "constants.h"
#include "prototypes.h"
#include "structs.h"
#include "globals.h"

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_MAX,WINDOW_MAX);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Maggi's Tree = BEST Tree");
    myinit();
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMainLoop();
}

