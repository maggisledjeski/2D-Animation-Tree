#include "includes.h"
#include "prototypes.h"
#include "constants.h"

void Reflect(int num)
{
    extern float rf;
	
	float transMatrix[16];
    float *tmp = &transMatrix[0];



    buildTrans(-WINDOW_MAX/2, -WINDOW_MAX/2, 0.0,tmp);
    applyTrans(num, tmp);

    buildReflect(tmp);
    applyTrans(num, tmp);
	
	rf = 0.0;	//sets the reflection back to 0
    
	buildTrans(WINDOW_MAX/2, WINDOW_MAX/2, 0.0, tmp);
    applyTrans(num, tmp);
	
    glutPostRedisplay();

}

void buildReflect(float *tmatrix)
{
    extern float rf;

	tmatrix[ 0] =  cos(rf);	tmatrix[ 1] = sin(rf); tmatrix[ 2] = 0.0; tmatrix[ 3] = 0.0;
    tmatrix[ 4] = -sin(rf); tmatrix[ 5] = cos(rf); tmatrix[ 6] = 0.0; tmatrix[ 7] = 0.0;
    tmatrix[ 8] = 0.0;      tmatrix[ 9] = 0.0;     tmatrix[10] = 1.0; tmatrix[11] = 0.0;
    tmatrix[12] = 0.0;      tmatrix[13] = 0.0;     tmatrix[14] = 0.0; tmatrix[15] = 1.0;
	
}

