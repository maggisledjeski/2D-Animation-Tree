#include "prototypes.h"

void vmMult (int dim, float *tmatrix, float tvector)
{
    int i, j;
   float temp[4];

   for (i=0; i<SIZE; i++)
             temp[i] = 0.0;

   for (i=0; i < SIZE; i++)
     for (j = 0; j < SIZE; j++)
           temp[i] += *(pA+(i*SIZE+j)) * *(pB+j);

   for (i=0; i<SIZE; i++)
         *(pB+i) = temp[i];
}

void applyTrans(int nump, float *tmatrix)
{
    extern struct vertex *treePants;
    float temp[4];
    float *tmp;
        int i;

    tmp = &temp[0];
    vertex spot;
    n = *(treePants + i);
    
    for (i=0;i<nump;i++)
    {
        *(tmp+0)= *(vp+(i*4)+0);
        *(tmp+1)= *(vp+(i*4)+1);
        *(tmp+2)= *(vp+(i*4)+2);
        *(tmp+3)= *(vp+(i*4)+3);
        vmatm( 4, TM, tmp );
        *(vp+(i*4)+0) = *(tmp+0);
        *(vp+(i*4)+1) = *(tmp+1);
        *(vp+(i*4)+2) = *(tmp+2);
        *(vp+(i*4)+3) = *(tmp+3);
        }

}

