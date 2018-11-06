#ifndef STRUCTS_H
#define STRUCTS_H

struct vertex {
    int x, y, z, w;
};

enum Boundary { Left, Right, Bottom, Top };
/*struct Boundary {
	int Left = 0;
	int Right = 1;
	int Bottom = 2;
	int Top = 3;
};*/

#endif
