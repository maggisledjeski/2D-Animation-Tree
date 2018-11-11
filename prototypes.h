#include "structs.h"

using namespace std;
void myinit(void);
void display(void);
void drawTree();
void MidpointCircle(int, int, int);
void drawReverse(int, int, int);
int circumference(int);
int numPoints(int, int, int);
void drawTTree(int);
void circle(int, int, int);
void spinDisplay(void);
void buildRotZ(float*);
void buildRotX(float, float*);
void buildRotY(float, float*);
void mouse(int, int, int, int);
void keyboard(unsigned char, int, int);
void vmMult (int, float*, float*);
void applyTrans(int, float*);
void Rotate(int);
void Scale(int);
void Reflect(int);
void buildTrans(float, float, float, float*);
void buildScale(float*);
void buildReflect(float*);
void scaleDisplay(void);
void applyTrans1(float*);

void Tess(void);
void fillTessPolygon(void);
void drawLinSeg(vertex, vertex);
bool linIntersect(linseg, linseg);
vertex cp1(vertex, vertex, vertex);
bool AngleCheck(vertex, vertex, vertex, vertex, vertex, vertex);
void Pipe(void);

void Intersect(vertex, vertex, vertex*, vertex*);
bool Inside(vertex, vertex*);
void Output(vertex , int*, vertex*);
void shClip(vertex*, vertex*, int, int*, vertex*);
void Clip(vertex*, vertex*);
