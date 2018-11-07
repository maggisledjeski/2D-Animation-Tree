#include "structs.h"

using namespace std;
void myinit(void);
void display(void);
void drawTree();
void MidpointCircle(int radius, int cx, int cy);
void drawReverse(int radius, int cx, int cy);
int circumference(int radius);
int numPoints(int radius, int cx, int cy);
void drawTTree(int nump);
void circle(int radius, int cx, int cy);
void spinDisplay(void);
void buildRotZ(float *matrix);
void buildRotX(float ang, float *matrix);
void buildRotY(float ang, float *matrix);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char key, int x, int y);
void vmMult (int SIZE, float *tmatrix, float *tvector);
void applyTrans(int nump, float *tmatrix);
void Rotate(int np);
void Scale(int np);
void Reflect(void);
void buildTrans(float x, float y, float z, float *tmatrix);
void buildScale(float *tmatrix);
void buildReflect(float *tmatrix);
void scaleDisplay(void);
void applyTrans1(float *tmatrix);


void drawBox();
void drawTBox(int nump);
void Intersect(vertex first, vertex second, vertex *clipBoundary, vertex *intersectPt);
bool Inside(vertex testVertex, vertex *clipBoundary);
void Output(vertex newVertex, int *outLength, vertex *outVertexArray);
void shClip(vertex *inVertexArray, vertex *outVertexArray, int inLength, int *outLength, vertex *clip_boundary);
void Clip(vertex *inArray, vertex *outArray);
