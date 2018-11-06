#include "includes.h"
#include "prototypes.h"
#include "constants.h"

void Reflect(void)
{
    float transMatrix[16];
    float *tmp = &transMatrix[0];



    buildTrans(-WINDOW_MAX/2, -WINDOW_MAX/2, 0.0,tmp);
    applyTrans1(tmp);

    buildReflect(tmp);
    applyTrans1(tmp);

    buildTrans(WINDOW_MAX/2, WINDOW_MAX/2, 0.0, tmp);
    applyTrans1(tmp);
	
    glutPostRedisplay();

}

void buildReflect(float *tmatrix)
{
    tmatrix[ 0] = -1.0; tmatrix[ 1] = 0.0; tmatrix[ 2] = 0.0; tmatrix[ 3] = 0.0;
    tmatrix[ 4] = 0.0;  tmatrix[ 5] = 1.0; tmatrix[ 6] = 0.0; tmatrix[ 7] = 0.0;
    tmatrix[ 8] = 0.0;  tmatrix[ 9] = 0.0; tmatrix[10] = 1.0; tmatrix[11] = 0.0;
    tmatrix[12] = 0.0;  tmatrix[13] = 0.0; tmatrix[14] = 0.0; tmatrix[15] = 1.0;
    
}

