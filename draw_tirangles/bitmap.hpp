#include "geometrickStructures.hpp"

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))


 
int edgeCross(point2D a, point2D b, point2D p) {
    point2D ab = { b.x - a.x, b.y - a.y };
    point2D ap = { p.x - a.x, p.y - a.y };
    return ab.x * ap.y - ab.y * ap.x;
}

struct GameWindowBuffer
{
    unsigned char* memory = 0;
    int w = 0;
    int h = 0;

    void drawAtSafe(int x, int y, unsigned char r, unsigned char g, unsigned char b)
    {
        if (x >= w || y >= h || x < 0 || y < 0)
        {
            return;
        }

        memory[4 * (x + y * w) + 0] = b; // blue
        memory[4 * (x + y * w) + 1] = g; // green
        memory[4 * (x + y * w) + 2] = r; // red
        memory[4 * (x + y * w) + 3] = 0; // reserved for alignment
    }

    void clear(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0)
    {
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
            {
                memory[4 * (x + y * w) + 0] = b;
                memory[4 * (x + y * w) + 1] = g;
                memory[4 * (x + y * w) + 2] = r;
                memory[4 * (x + y * w) + 3] = 0;
            }
    }

    void draw_triangle(triangle tri)
    {
        int r = 255;
        int g = 255;
        int b = 255;

        // Finds the bounding box with all candidate pixels
        int x_min = fmin(fmin(tri.a.x, tri.b.x), tri.c.x);
        int y_min = fmin(fmin(tri.a.y, tri.b.y), tri.c.y);
        int x_max = fmax(fmax(tri.a.x, tri.b.x), tri.c.x);
        int y_max = fmax(fmax(tri.a.y, tri.b.y), tri.c.y);

        // Loop all candidate pixels inside the bounding box
        for (int y = y_min; y <= y_max; y++) {
            for (int x = x_min; x <= x_max; x++) {
                point2D p = { x, y };
                int cross1 = edgeCross(tri.b, tri.c, p);
                int cross2 = edgeCross(tri.c, tri.a, p);
                int cross3 = edgeCross(tri.a, tri.b, p);

                bool is_inside = cross1 <= 0 and cross2 <= 0 and cross3 <= 0;

                // TODO:
                if (is_inside) {
                    drawAtSafe(x, y, r, g, b);
                }
            }
        }

    }
};