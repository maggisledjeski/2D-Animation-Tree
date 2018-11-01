#include "prototypes.h"
#include "includes.h"
#include "structs.h"
#include "constants.h"

void vmMult(int SIZE, float *tmatrix, float *tvector)
{
    int i, j;
   float temp[4];

   for (i=0; i<SIZE; i++)
   {
        temp[i] = 0.0;
   }
   for (i=0; i < SIZE; i++)
   {
        for (j = 0; j < SIZE; j++)
        {
            temp[i] += *(tmatrix+(i*SIZE+j)) * *(tvector+j);
        }
   }

   for (i=0; i<SIZE; i++)
   {
        *(tvector+i) = temp[i];
   }
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

void applyTrans1(float *tmatrix)
{
    extern struct vertex *treePants;
    int t = numPoints(200,600,450);
    int tp = (6*t)+5;

    
    float tempV[4];
    float *tmpV;
    int i;

    tmpV = &tempV[0];

    vertex spot;
    vertex ns;

    for (i=0;i<tp;i++)
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

void buildTrans(float x, float y, float z, float *tmatrix)
{
    tmatrix[ 0] = 1.0; tmatrix[ 1] = 0.0; tmatrix[ 2] = 0.0; tmatrix[ 3] =   x;
    tmatrix[ 4] = 0.0; tmatrix[ 5] = 1.0; tmatrix[ 6] = 0.0; tmatrix[ 7] =   y;
    tmatrix[ 8] = 0.0; tmatrix[ 9] = 0.0; tmatrix[10] = 1.0; tmatrix[11] =   z;
    tmatrix[12] = 0.0; tmatrix[13] = 0.0; tmatrix[14] = 0.0; tmatrix[15] = 1.0;

}


