#include "prototypes.h"
#include "includes.h"
#include "structs.h"

void vmMult(int SIZE, float *tmatrix, float *tvector)
{
    int i, j;
   float temp[4];

   for (i=0; i<SIZE; i++)
             temp[i] = 0.0;

   for (i=0; i < SIZE; i++)
     for (j = 0; j < SIZE; j++)
           temp[i] += *(tmatrix+(i*SIZE+j)) * *(tvector+j);

   for (i=0; i<SIZE; i++)
         *(tvector+i) = temp[i];
}

void applyTrans(int nump, float *tmatrix)
{
    extern struct vertex *treePants;
    float tempV[4];
    float *tmpV;
    int i;

    tmpV = &tempV[0];
    
	vertex spot;
    vertex ns;
	
    for (i=0;i<nump;i++)
    {
        spot = *(treePants + i);
		*(tmpV+0) = spot.x;
        *(tmpV+1) = spot.y;
        *(tmpV+2) = spot.z;
        *(tmpV+3) = spot.w;
        vmMult( 4, tmatrix, tmpV );
		ns.x = *(tmpV+0);
        ns.y = *(tmpV+1);
        ns.z = *(tmpV+2);
        ns.w = *(tmpV+3);
		*(treePants + i) = ns;
        }

}

void Rotate(int np)
{
	//extern struct vertex *treePants;
	
	float transMatrix[16];
	float *tmp = &transMatrix[0];
	
	buildRotZ(tmp);
	applyTrans(np, tmp);
}
