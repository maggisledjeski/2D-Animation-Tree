#include "includes.h"
#include "prototypes.h"
#include "structs.h"
#include "constants.h"

void Pipe()
{
	extern int p;
	extern float rf;
	float transMatrix[16];
    float *tmp = &transMatrix[0];

	int np = p;

    buildTrans(-WINDOW_MAX/2, -WINDOW_MAX/2, 0.0,tmp);
    applyTrans(np, tmp);

    buildRotZ(tmp);
    applyTrans(np, tmp);
	
	buildScale(tmp);
    applyTrans(np, tmp);

	buildReflect(tmp);
    applyTrans(np, tmp);
	
	rf = 0.0;		

    buildTrans(WINDOW_MAX/2, WINDOW_MAX/2, 0.0, tmp);
    applyTrans(np, tmp);
	//glutPostRedisplay();
}
