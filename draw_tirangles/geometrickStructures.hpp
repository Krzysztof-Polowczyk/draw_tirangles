#pragma once
#include <vector>

typedef struct { int x; int y; } point2D;
typedef struct { int R; int G; int B; } triInt;
typedef struct { point2D a; point2D b; point2D c; triInt color; } triangle;
typedef std::vector<triangle> mesh;
