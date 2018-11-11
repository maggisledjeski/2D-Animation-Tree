#include "structs.h"

#ifndef GLOBALS_H
#define GLOBALS_H

vertex *treePoints;
vertex *treePants;
vertex *tessPants;
triangle *triPants;
int p;
int *outputLength;
float spin = 0.0;
float deltaSpin = 0.0;
float sf = 1.0;
float dsf = 0.0;
float rf = 3.14159265358979323846;
bool tess_flag = false;
int tess_count;
#endif
