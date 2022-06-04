#include <iostream>
struct Quads
{
    int x1, y1, z1;
    int x2, y2, z2;
    int x3, y3, z3;
    int x4, y4, z4;
    float red, green, blue;
    int state, total;
    static void addQuads();
    static void drawQuads();
};
Quads Q[100];