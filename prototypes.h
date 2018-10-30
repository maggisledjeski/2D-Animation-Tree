using namespace std;
void myinit(void);
void display(void);
void drawTree();
void MidpointCircle(int radius, int cx, int cy);
void drawReverse(int radius, int cx, int cy);
int circumference(int radius);
int numPoints(int radius, int cx, int cy);
void circle(int radius, int cx, int cy);
void spinDisplay(void);
void buildRotZ(float *matrix);
void buildRotX(float ang, float *matrix);
void buildRotY(float ang, float *matrix);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char key, int x, int y);

