#include "Math.hpp"
#include <iostream>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
 
int edgeCross(Vec1x3* a, Vec1x3* b, Vec1x3* p) {
    Vec1x3 ab = { b->x - a->x, b->y - a->y, 0.0f };
    Vec1x3 ap = { p->x - a->x, p->y - a->y, 0.0f };
    return Vecmath::mulVecbyVec(ab, ap).z;
}


struct Texture
{
public:

    int wight;
    int height;
    unsigned char *picture;
    Texture(int w, int h, unsigned char* picture);

    Color getColor(int x, int y) {
        if (4 * (x + y * wight) + 2 < 5000 || 4 * (x + y * wight) > 0) {
            return { (int)picture[4 * (x + y * wight) + 0], (int)picture[4 * (x + y * wight) + 1], (int)picture[4 * (x + y * wight) + 2] };
        }
        else {
            return { 160,32,204 };
        }
    }

private:



};

Texture::Texture(int w, int h, unsigned char* picture)
{
    this->wight = w;
    this->height = h;
    this->picture = picture;
};


struct GameWindowBuffer
{
    unsigned char* memory = 0;
    int w = 0;
    int h = 0;


    void drawAtSafe(int x, int y, Color* color)
    {
        if (x >= w || y >= h || x < 0 || y < 0)
        {
            return;
        }
        memory[4 * (x + y * w) + 0] = color->B; // blue
        memory[4 * (x + y * w) + 1] = color->G;// green
        memory[4 * (x + y * w) + 2] = color->R; // red
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

    void draw_triangle(triangle& tri)
    {
        // Finds the bounding box with all candidate pixels
        int x_min = fmin(fmin(tri.a.x, tri.b.x), tri.c.x);
        int y_min = fmin(fmin(tri.a.y, tri.b.y), tri.c.y);
        int x_max = fmax(fmax(tri.a.x, tri.b.x), tri.c.x);
        int y_max = fmax(fmax(tri.a.y, tri.b.y), tri.c.y);

        int baias1 = is_top_left(&tri.b, &tri.c) ? 0 : -1;
        int baias2 = is_top_left(&tri.c, &tri.a) ? 0 : -1;
        int baias3 = is_top_left(&tri.a, &tri.b) ? 0 : -1;

        // Loop all candidate pixels inside the bounding box
        for (int y = y_min; y <= y_max; y++) {
            for (int x = x_min; x <= x_max; x++) {
                Vec1x3 p = { x, y };
                int cross1 = edgeCross(&tri.b, &tri.c, &p) + baias1;
                int cross2 = edgeCross(&tri.c, &tri.a, &p) + baias2;
                int cross3 = edgeCross(&tri.a, &tri.b, &p) + baias3;

                bool is_inside = cross1 >= 0 and cross2 >= 0 and cross3 >= 0;

                if (is_inside) {
                    drawAtSafe(x, y, &tri.color);
                }
            }
        }
    }


    void triangle_fill(Vec1x3 &v0, Vec1x3 &v1, Vec1x3 &v2, Vec1x3 &text0, Vec1x3 &text1, Vec1x3 &text2, Texture &pic) {
        // Finds the bounding box with all candidate pixels
        int x_min = (int)MIN(MIN(v0.x, v1.x), v2.x);
        int y_min = (int)MIN(MIN(v0.y, v1.y), v2.y);
        int x_max = (int)MAX(MAX(v0.x, v1.x), v2.x);
        int y_max = (int)MAX(MAX(v0.y, v1.y), v2.y);

        // Compute the area of the entire triangle/parallelogram
        int area = edgeCross(&v0, &v1, &v2);

        // Compute the constant delta_s that will be used for the horizontal and vertical steps
        int delta_w0_col = v1.y - v2.y;
        int delta_w1_col = v2.y - v0.y;
        int delta_w2_col = v0.y - v1.y;
        int delta_w0_row = v2.x - v1.x;
        int delta_w1_row = v0.x - v2.x;
        int delta_w2_row = v1.x - v0.x;

        // Rasterization fill convention (top-left rule)
        int bias0 = is_top_left(&v1, &v2) ? 0 : -1;
        int bias1 = is_top_left(&v2, &v0) ? 0 : -1;
        int bias2 = is_top_left(&v0, &v1) ? 0 : -1;

        // Compute the edge functions for the fist (top-left) point
        Vec1x3 p0 = {
          (double)(x_min + 0.5f),
          (double)(y_min + 0.5f)
        };
        int w0_row = edgeCross(&v1, &v2, &p0) + bias0;
        int w1_row = edgeCross(&v2, &v0, &p0) + bias1;
        int w2_row = edgeCross(&v0, &v1, &p0) + bias2;

        int w0;
        int w1;
        int w2;
        bool is_inside;
        Color pixsal_color = { 255,255,255 };
        double alpha;
        double beta;
        double gamma;
        int xtext;
        int ytext;


        // Loop all candidate pixels inside the bounding box
        for (int y = y_min; y <= y_max; y++) {

            w0 = w0_row;
            w1 = w1_row;
            w2 = w2_row;

            for (int x = x_min; x <= x_max; x++) {
                is_inside = w0 >= 0 && w1 >= 0 && w2 >= 0;
                if (is_inside) {
                    alpha = (double)w0 / area;
                    beta = (double)w1 / area;
                    gamma = (double)w2 / area;

                    // Find the new RGB components interpolating vertex values using alpha, beta, and gamma
                    xtext = (alpha)*text0.x + (beta)*text1.x + (gamma)*text2.x;
                    ytext = (alpha)*text0.y + (beta)*text1.y + (gamma)*text2.y;
 
                   pixsal_color = pic.getColor(xtext, ytext);
                        //std::cout << pixsal_color.R << std::endl;
                        // Combine A, R, G, and B into one final 32-bit color
                        //std::cout << pic.height << " " << pic.wight << std::endl;
                        drawAtSafe(x, y, &pixsal_color);




                }
                // Increment one step to the right
                w0 += delta_w0_col;
                w1 += delta_w1_col;
                w2 += delta_w2_col;
            }
            // Increment one row step
            w0_row = w0_row + delta_w0_row;
            w1_row = w1_row + delta_w1_row;
            w2_row = w2_row + delta_w2_row;
        }
    }

    void draw_triangle_outline(triangle tri)
    {
        // Function to draw a line between two points
        auto draw_line = [this](Vec1x3 start, Vec1x3 end, Color col) {
            int x0 = static_cast<int>(std::round(start.x));
            int y0 = static_cast<int>(std::round(start.y));
            int x1 = static_cast<int>(std::round(end.x));
            int y1 = static_cast<int>(std::round(end.y));

            int dx = abs(x1 - x0);
            int dy = abs(y1 - y0);
            int sx = (x0 < x1) ? 1 : -1;
            int sy = (y0 < y1) ? 1 : -1;
            int err = dx - dy;

            while (true) {
                this->drawAtSafe(x0, y0, &col);

                if (x0 == x1 && y0 == y1) {
                    break;
                }

                int e2 = 2 * err;
                if (e2 > -dy) {
                    err -= dy;
                    x0 += sx;
                }
                if (e2 < dx) {
                    err += dx;
                    y0 += sy;
                }
            }
            };

        // Draw the three edges of the triangle
        draw_line(tri.a, tri.b, tri.color);
        draw_line(tri.b, tri.c, tri.color);
        draw_line(tri.c, tri.a, tri.color);
    }

    // -1.2517e-06 is approximately equal to -0.00000125 in decimal representation.





    private:
        bool is_top_left(Vec1x3* start, Vec1x3* end) {
            int y = end->x - start->x;
            int x = end->y - start->y;
            bool is_top_edge = y == 0 && x > 0;
            bool is_left_edge = y < 0;
            return is_left_edge || is_top_edge;
        }
};