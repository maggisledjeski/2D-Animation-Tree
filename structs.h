#ifndef STRUCTS_H
#define STRUCTS_H

struct vertex {
    int x, y, z, w;
};

struct linseg {
    vertex one;
    vertex two;
};
struct triangle {
    vertex tone;
    vertex ttwo;
    vertex tthree;
};


enum Boundary { Left, Right, Bottom, Top };
/*struct Boundary {
	int Left = 0;
	int Right = 1;
	int Bottom = 2;
	int Top = 3;
};*/

#endif
