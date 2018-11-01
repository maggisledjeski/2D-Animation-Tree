#include "includes.h"
#include "prototypes.h"
#include "structs.h"
#include "constants.h"
using namespace std;

//this file is used to hold all of the functions that are needed for rotating

void Rotate(int np)
{
    float transMatrix[16];
    float *tmp = &transMatrix[0];

    buildTrans(-WINDOW_MAX/2, -WINDOW_MAX/2, 0.0,tmp);
    applyTrans(np, tmp);

    buildRotZ(tmp);
    applyTrans(np, tmp);

    buildTrans(WINDOW_MAX/2, WINDOW_MAX/2, 0.0, tmp);
    applyTrans(np, tmp);
}

void spinDisplay(void)
{
	extern float spin;
	extern float deltaSpin;
    //cout << "spinDisplay" << endl;
	spin = spin + deltaSpin;
	if(spin > 360.0)
	{
		spin = spin - 360.0;
	}
	glutPostRedisplay();
}

//builds a rotation matrix about the Z axis
void buildRotZ(float *matrix)	
{
	extern float spin;
	//converts degrees to radians
	float theta = spin * M_PI / 180.0;
	//cout << "rotZ" << endl;
	matrix[ 0] =  cos(theta); matrix[ 1] = sin(theta); matrix[ 2] = 0.0; matrix[ 3] = 0.0;
    matrix[ 4] = -sin(theta); matrix[ 5] = cos(theta); matrix[ 6] = 0.0; matrix[ 7] = 0.0;
    matrix[ 8] = 0.0;         matrix[ 9] = 0.0;        matrix[10] = 1.0; matrix[11] = 0.0;
    matrix[12] = 0.0;         matrix[13] = 0.0;        matrix[14] = 0.0; matrix[15] = 1.0;
}

void buildRotX(float ang, float *matrix)
{
	//converts degrees to radians
  	float theta = ang * M_PI / 180.0;
    
	matrix[ 0] = 1.0; matrix[ 1] = 0.0; 	   matrix[ 2] = 0.0; 		 matrix[ 3] = 0.0;
    matrix[ 4] = 0.0; matrix[ 5] = cos(theta); matrix[ 6] = -sin(theta); matrix[ 7] = 0.0;
    matrix[ 8] = 0.0; matrix[ 9] = sin(theta); matrix[10] = cos(theta);  matrix[11] = 0.0;
    matrix[12] = 0.0; matrix[13] = 0.0;        matrix[14] = 0.0; 		 matrix[15] = 1.0;
}

void buildRotY(float ang, float *matrix)
{
	//converts degrees to radians
	float theta = ang * M_PI / 180.0;
     
    matrix[ 0] = cos(theta);  matrix[ 1] = 0.0; matrix[ 2] = sin(theta);  matrix[ 3] = 0.0;
    matrix[ 4] = 0.0; 		  matrix[ 5] = 1.0; matrix[ 6] = 0.0; 		  matrix[ 7] = 0.0;
    matrix[ 8] = -sin(theta); matrix[ 9] = 0.0; matrix[10] = cos(theta);  matrix[11] = 0.0;
    matrix[12] = 0.0; 		  matrix[13] = 0.0; matrix[14] = 0.0;         matrix[15] = 1.0;
}
