#include <iostream>
#include <vector>
#include <algorithm>>
#include <Windows.h>
#include "bitmap.hpp"
#include "Math.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <chrono>
#include <list>

//https://www.youtube.com/watch?v=k5wtuKWmV48
int count = 0;

Vec1x3 LookDir = {0,0,1};
double Yyawl = 0;
Vec1x3 cmaPos = { 0,0, -10 };

float fTheta = 0;

extern "C" {
    #define STB_IMAGE_IMPLEMENTATION
    #include "mylib.h"
}


void resetWindowBuffer(GameWindowBuffer* gameWindowBuffer, BITMAPINFO* bitmapInfo, HWND wind)
{
    RECT rect = {};
    GetClientRect(wind, &rect);
    gameWindowBuffer->h = rect.bottom;
    gameWindowBuffer->w = rect.right;

    if (gameWindowBuffer->memory)
    {
        VirtualFree(gameWindowBuffer->memory, 0, MEM_RELEASE);
    }

    gameWindowBuffer->memory =
        (unsigned char*)VirtualAlloc(0, 4 * gameWindowBuffer->w * gameWindowBuffer->h,
            MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    bitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFO);
    bitmapInfo->bmiHeader.biWidth = gameWindowBuffer->w;
    bitmapInfo->bmiHeader.biHeight = -gameWindowBuffer->h;
    bitmapInfo->bmiHeader.biPlanes = 1;
    bitmapInfo->bmiHeader.biBitCount = 32;
    bitmapInfo->bmiHeader.biCompression = BI_RGB;
}

struct WindowStuff
{
    bool running = true;
    BITMAPINFO bitmapInfo = {};
};

WindowStuff windowStuff;
GameWindowBuffer gameWindowBuffer = {};
static Color blue = { 0,0,255 };


// this is the function that will process all of the windows' messages.
LRESULT windProc(HWND wind, UINT msg, WPARAM wp, LPARAM lp)
{
    LRESULT rez = 0;

    switch (msg)
    {
    case WM_CLOSE:
        windowStuff.running = false;
        break;
    case WM_SIZE:
    {
        resetWindowBuffer(&gameWindowBuffer, &windowStuff.bitmapInfo, wind);
    } break;

    case WM_PAINT:
    {
        PAINTSTRUCT Paint;
        HDC DeviceContext = BeginPaint(wind, &Paint);

        HDC hdc = GetDC(wind);

        StretchDIBits(hdc,
            0, 0, gameWindowBuffer.w, gameWindowBuffer.h,
            0, 0, gameWindowBuffer.w, gameWindowBuffer.h,
            gameWindowBuffer.memory,
            &windowStuff.bitmapInfo,
            DIB_RGB_COLORS,
            SRCCOPY
        );

        ReleaseDC(wind, hdc);

        EndPaint(wind, &Paint);
        gameWindowBuffer.clear();
    } break;

    case WM_KEYDOWN: 
    {
        if (wp == VK_UP)
        {
            cmaPos.y += 0.3;
        }
        if (wp == VK_DOWN)
        {
            cmaPos.y -= 0.3;
        }
        if (wp == VK_LEFT)
            {
                cmaPos.x += 0.3;
            }
        if (wp == VK_RIGHT)
                {
                    cmaPos.x -= 0.3;
                }

        Vec1x3 vForward = Vecmath::mulVecbyNum(LookDir, 0.1);

        if (wp == 'W')
                {
                    cmaPos = Vecmath::addVec(cmaPos, vForward);
                }
        if (wp == 'S')
                {
                    cmaPos = Vecmath::subVecbyVec(cmaPos, vForward);
                }

        if (wp == 'A')
                {
                    Yyawl -= 0.2;
                }
        if (wp == 'D')
                {
                    Yyawl += 0.2;
                }
    } break;

    default:
        rez = DefWindowProc(wind, msg, wp, lp);
        break;
        }

        return rez;
    }

HWND createWindow() {
    WNDCLASS wc = { sizeof(WNDCLASS) };

    wc.hCursor = LoadCursor(0, IDC_ARROW);
    wc.hInstance = GetModuleHandle(0);
    wc.lpszClassName = L"EpicWindowClass";
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = windProc;

    if (!RegisterClass(&wc)) { return 0; };

    HWND wind = CreateWindowW(
        wc.lpszClassName,
        L"We have a Window!",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        0, 0, GetModuleHandle(0), 0
    );
}

void handle_entires(HWND wind) {
    MSG msg = {};
    while (PeekMessage(&msg, wind, 0, 0, PM_REMOVE) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

mesh read_mesh_from_file(std::string path) {
    mesh result = {};

    std::ifstream f(path); // why "//"?

    if (!f.is_open()) {
        std::cerr << "Error opening the file!";
    }

    std::string s;
    std::vector<std::vector<double>> verticies;

    while (getline(f, s)) {
        std::stringstream ss(s);
        std::string z;
        std::vector<std::string> ls;

        
        if (s[0] == 'v') {
            while (ss >> z) {
                ls.push_back(z);
            }
            verticies.push_back({ std::stod(ls[1]), std::stod(ls[2]), std::stod(ls[3]) });
        };
        if (s[0] == 'f') {
            while (ss >> z) {
                ls.push_back(z);
            }

            triangle tri = { 
                {verticies[std::stod(ls[1]) - 1][0], verticies[std::stod(ls[1]) - 1][1], verticies[std::stod(ls[1]) - 1][2]},
                {verticies[std::stod(ls[2]) - 1][0], verticies[std::stod(ls[2]) - 1][1], verticies[std::stod(ls[2]) - 1][2]},
                {verticies[std::stod(ls[3]) - 1][0], verticies[std::stod(ls[3]) - 1][1], verticies[std::stod(ls[3]) - 1][2]},
                blue };
            result.push_back(tri);
        };
    }

    // Close the file
    f.close();


    return result;
}

void run()
{
    std::cout << count << std::endl;

    count = 0;
}

void ThreadFunction()
{
    while (true) {
        run();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}


Texture reading_from_PNG() {
    std::string filename = "C:\\Users\\KrzysztofPolowczyk\\Desktop\\tunk.png";

    // ... x = width, y = height, n = # 8-bit components per pixel ...
    // ... replace '0' with '1'..'4' to force that many components per pixel
    // ... but 'n' will always be the number that it would have been if you said 0
    int x, y, n;
    unsigned char* data = stbi_load(filename.c_str(), &x, &y, &n, 0);
    unsigned char* pic = {};

    // ... process data if not NULL ..

    //stbi_image_free(data);
    return Texture{ x, y, data };
}

Vec1x3 text0 = { 0,0,0 };
Vec1x3 text1 = { 0,100,0 };
Vec1x3 text2 = { 100,0,0 };
Texture pic = reading_from_PNG();

int main()
{
    Vec1x3 lightDir;
    mesh cube = read_mesh_from_file("C:\\Users\\KrzysztofPolowczyk\\Desktop\\cube.txt");
    HWND wind = createWindow();
    resetWindowBuffer(&gameWindowBuffer, &windowStuff.bitmapInfo, wind);

    // main game loop
    std::thread t1(ThreadFunction);
    t1.detach();


    double fNear = 0.1;
    double fFar = 1000.0;
    double FOV = 90.0;
    int width = 0;
    int height = 0;
    RECT rect;
    double FOVRad = 1.0 / tanf(FOV * 0.5 / 180 * 3.14159);
    while (windowStuff.running){
        //fTheta += 0.01;

        if (GetWindowRect(wind, &rect))
        {
            width = rect.right - rect.left;
            height = rect.bottom - rect.top;
        }

        double aspectRatio = (double)height / (double)width;
        mat projection_matrix = {
            {aspectRatio * FOVRad, 0, 0, 0},
            {0,FOVRad,       0,            0},
            {0,  0, fFar / (fFar - fNear), 1},
            {0,0, (-fFar * fNear) / (fFar - fNear),0}
        };

        mat matRotZ = {
            {cosf(fTheta), sinf(fTheta), 0 ,0},
            {-sinf(fTheta), cosf(fTheta), 0 , 0},
            {0,0,1,0},
            {0,0,0,1}
        };
        
        mat matRotX = {
           {1,0 , 0 ,0},
           {0,cosf(fTheta * 0.5f), sinf(fTheta * 0.5f) , 0},
           {0,-sinf(fTheta * 0.5f),cosf(fTheta * 0.5f),0},
           {0,0,0,1}
        };

        // use this for handling user input
        handle_entires(wind);

        Vec1x3 vUp = { 0,1,0 };
        Vec1x3 vTarget = {0,0,1};
        mat Yrot = {
            {cosf(Yyawl * 0.5),0,sinf(Yyawl * 0.5),0},
            {0,1,0,0},
            {-sinf(Yyawl * 0.5),0,cosf(Yyawl * 0.5),0},
            {0,0,0,1}
        };

        LookDir = Vecmath::multiplyMat(vTarget, Yrot);
        vTarget = Vecmath::addVec(cmaPos, LookDir);


        mat matCamera = Vecmath::Matrix_PointAt(cmaPos, vTarget, vUp);

        mat matViev = Vecmath::Matrix_QuickInverse(matCamera);

        Vec1x3 temp = { 0,1,0 };//delete
        lightDir = Vecmath::getUnit(temp);

        std::vector<triangle> tirstris_for_rasteryztion = {};
        for (triangle &tri : cube) {
            triangle triProjected, triTrans, tirRotZ, triRotZX, triVievw;

            tirRotZ.a = Vecmath::multiplyMat(tri.a, matRotZ);
            tirRotZ.b = Vecmath::multiplyMat(tri.b, matRotZ);
            tirRotZ.c = Vecmath::multiplyMat(tri.c, matRotZ);

            triRotZX.a = Vecmath::multiplyMat(tirRotZ.a, matRotX);
            triRotZX.b = Vecmath::multiplyMat(tirRotZ.b, matRotX);
            triRotZX.c = Vecmath::multiplyMat(tirRotZ.c, matRotX);

            triTrans = triRotZX;

            Vec1x3 line1 = Vecmath::subVecbyVec(triTrans.b, triTrans.a);
            Vec1x3 line2 = Vecmath::subVecbyVec(triTrans.c, triTrans.a);
            Vec1x3 corss = Vecmath::mulVecbyVec(line1, line2);
            Vec1x3 normalCross = Vecmath::getUnit(corss);
            Vec1x3 me = Vecmath::subVecbyVec(triTrans.a, cmaPos);
            if (Vecmath::dot(normalCross, me) < 0) {

                double lightDot = Vecmath::dot(normalCross, lightDir);

                triVievw.a = Vecmath::multiplyMat(triTrans.a, matViev);
                triVievw.b = Vecmath::multiplyMat(triTrans.b, matViev);
                triVievw.c = Vecmath::multiplyMat(triTrans.c, matViev);

                int nClipped = 0;
                triangle clipped[2];
                nClipped = Vecmath::Triangle_ClipAgainstPlane({ 0,0,1.1 }, { 0,0,1 }, triVievw, clipped[0], clipped[1]);

                

                for (int n = 0; n < nClipped; n++) {
                    
                    triProjected.a = Vecmath::multiplyMat(clipped[n].a, projection_matrix);
                    triProjected.b = Vecmath::multiplyMat(clipped[n].b, projection_matrix);
                    triProjected.c = Vecmath::multiplyMat(clipped[n].c, projection_matrix);

                    triProjected.a.x *= -1.0; triProjected.a.y *= -1.0;
                    triProjected.b.x *= -1.0; triProjected.b.y *= -1.0;
                    triProjected.c.x *= -1.0; triProjected.c.y *= -1.0;

                    triProjected.a.x += 1.0; triProjected.a.y += 1.0;
                    triProjected.b.x += 1.0; triProjected.b.y += 1.0;
                    triProjected.c.x += 1.0; triProjected.c.y += 1.0;

                    triProjected.a.x *= 0.5f * width;
                    triProjected.a.y *= 0.5f * height;
                    triProjected.b.x *= 0.5f * width;
                    triProjected.b.y *= 0.5f * height;
                    triProjected.c.x *= 0.5f * width;
                    triProjected.c.y *= 0.5f * height;
                    triProjected.color = { int(255 * 1),int(255 * 1), int(255*1)};

                    //std::cout << clipped[0].color.B << " : " << clipped[1].color.B << std::endl;

                    tirstris_for_rasteryztion.push_back(triProjected);

                }
                
            }
        }
        std::sort(tirstris_for_rasteryztion.begin(), tirstris_for_rasteryztion.end(), [](const triangle& a, const triangle& b) -> bool {
            return (a.a.z + a.b.z + a.c.z) / 3 > (b.a.z + b.b.z + b.c.z) / 3;
            });

            // Draw the transformed, viewed, clipped, projected, sorted, clipped triangles
   
        for (auto& triToRaster : tirstris_for_rasteryztion)
            {
                // Clip triangles against all four screen edges, this could yield
                // a bunch of triangles, so create a queue that we traverse to 
                //  ensure we only test new triangles generated against planes
                triangle clipped[2];
                std::list<triangle> listTriangles;

                // Add initial triangle
                listTriangles.push_back(triToRaster);
                int nNewTriangles = 1;

                for (int p = 0; p < 4; p++)
                {
                    int nTrisToAdd = 0;
                    while (nNewTriangles > 0)
                    {
                        // Take triangle from front of queue
                        triangle test = listTriangles.front();
                        listTriangles.pop_front();
                        nNewTriangles--;

                        // Clip it against a plane. We only need to test each 
                        // subsequent plane, against subsequent new triangles
                        // as all triangles after a plane clip are guaranteed
                        // to lie on the inside of the plane. I like how this
                        // comment is almost completely and utterly justified
                        switch (p)
                        {
                        case 0:	nTrisToAdd = Vecmath::Triangle_ClipAgainstPlane({ 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, test, clipped[0], clipped[1]); break;
                        case 1:	nTrisToAdd = Vecmath::Triangle_ClipAgainstPlane({ 0.0f, (double)height - 1, 0.0f }, { 0.0f, -1.0f, 0.0f }, test, clipped[0], clipped[1]); break;
                        case 2:	nTrisToAdd = Vecmath::Triangle_ClipAgainstPlane({ 0.0f, 0.0f, 0.0f }, { 1.0f, 0.0f, 0.0f }, test, clipped[0], clipped[1]); break;
                        case 3:	nTrisToAdd = Vecmath::Triangle_ClipAgainstPlane({ (double)width - 1, 0.0f, 0.0f }, { -1.0f, 0.0f, 0.0f }, test, clipped[0], clipped[1]); break;
                        }

                        // Clipping may yield a variable number of triangles, so
                        // add these new ones to the back of the queue for subsequent
                        // clipping against next planes
                        for (int w = 0; w < nTrisToAdd; w++)
                            listTriangles.push_back(clipped[w]);
                    }
                    nNewTriangles = listTriangles.size();
                }

                // Draw the transformed, viewed, clipped, projected, sorted, clipped triangles
                for (auto& tri : listTriangles)
                {
                    gameWindowBuffer.triangle_fill(tri.a, tri.c, tri.b, text0, text1, text2, pic);
                    gameWindowBuffer.triangle_fill(tri.a, tri.b, tri.c, text0, text1, text2, pic);
                }// fix this idiot
            }
        InvalidateRect(wind, nullptr, FALSE);
        count += 1;
    }
}
