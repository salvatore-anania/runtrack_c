#ifndef manahttan_h
#define manhattan_h

typedef struct point{
    int x;
    int y;
} point;

#define ABS(x) ((x) < 0 ? -(x) : (x))

int manhattan(point a, point b);

#endif