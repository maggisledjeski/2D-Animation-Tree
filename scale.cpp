#include "includes.h"
#include "prototypes.h"
#include "constants.h"

void Scale(int np)
{
    float transMatrix[16];
    float *tmp = &transMatrix[0];

    buildTrans(-WINDOW_MAX/2, -WINDOW_MAX/2, 0.0,tmp);
    applyTrans(np, tmp);

    buildScale(tmp);
    applyTrans(np, tmp);

    buildTrans(WINDOW_MAX/2, WINDOW_MAX/2, 0.0, tmp);
    applyTrans(np, tmp);

}

void scaleDisplay(void)
{
    extern float sf;
    extern float dsf;

    sf = 1.0 + dsf;
    if(sf < 0.0)
	{
		sf = 0.0;
	}
	glutPostRedisplay();
}

void buildScale(float *tmatrix)
{
    extern float sf;
    tmatrix[ 0] = sf;  tmatrix[ 1] = 0.0; tmatrix[ 2] = 0.0; tmatrix[ 3] = 0.0;
    tmatrix[ 4] = 0.0; tmatrix[ 5] = sf;  tmatrix[ 6] = 0.0; tmatrix[ 7] = 0.0;
    tmatrix[ 8] = 0.0; tmatrix[ 9] = 0.0; tmatrix[10] = sf;  tmatrix[11] = 0.0;
    tmatrix[12] = 0.0; tmatrix[13] = 0.0; tmatrix[14] = 0.0; tmatrix[15] = 1.0;
}
