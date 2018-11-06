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

//sh

int polygonClipSuthHodg(vertex wMin, vertex wMax, int n, vertex * pIn, vertex * pOut);
int inside(vertex p, Boundary b, vertex wMin, vertex wMax);
int cross(vertex p1, vertex p2, Boundary winEdge, vertex wMin, vertex wMax);
vertex intersect(vertex p1, vertex p2, Boundary winEdge, vertex wMin, vertex wMax);
void clipPoint(vertex p, Boundary winEdge, vertex wMin, vertex wMax, vertex * pOut, int * cnt, vertex * first[], vertex * s);
void closeClip(vertex wMin, vertex wMax, vertex * pOut, int * cnt, vertex * first [ ], vertex * s);


void drawBox();
void drawTBox(int nump);
int clip(vertex wMin, vertex wMax, int n, vertex * pIn, vertex * pOut);
