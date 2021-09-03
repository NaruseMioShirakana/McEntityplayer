#ifndef Jpeg_load_S
#define Jpeg_load_S
#define Xlimit 1920//定义像素（X）
#define Ylimit 1080//定义像素（Y）

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

using namespace std;
using namespace Gdiplus;

struct Image_pixel_data { //RGB通道存储（结构体）
    int IPDR;
    int IPDG;
    int IPDB;
};

wstring strToStdWString(const string& str) //将单字节字符串转换为二字节字符串（因为Gdiplus库仅支持二字节字符串文件名）
{
    wstring wStr;
    int len = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)str.c_str(), str.size(), NULL, 0);
    TCHAR* buffer = new TCHAR[len + 1];
    MultiByteToWideChar(CP_ACP, 0, (LPCSTR)str.c_str(), str.size(), buffer, len);
    buffer[len] = '\0';
    wStr.append(buffer);
    return wStr;
}
int init = 0; //初始化
vector <vector <Image_pixel_data>> loaded_Image_pixel_data; //本次数据
vector <vector <Image_pixel_data>> L_loaded_Image_pixel_data; //上一个数据

void Get_Image_pixel_RGB(wstring infilename) { //获取每个像素点的RGB值并存入上述容器
    GdiplusStartupInput gdiplusstartupinput;
    ULONG_PTR gdiplustoken;
    GdiplusStartup(&gdiplustoken, &gdiplusstartupinput, NULL);
    Bitmap* bmp = new Bitmap(infilename.c_str());
    UINT height = bmp->GetHeight();
    UINT width = bmp->GetWidth();
    cout << "width " << width << ", height " << height << endl;
    if (loaded_Image_pixel_data.size() == 0) {
        Image_pixel_data Image_pixel_data_i;
        vector <Image_pixel_data> loaded_Image_pixel_data_out;
        for (int i = 0; i < Xlimit; i++) {
           loaded_Image_pixel_data_out.push_back(Image_pixel_data_i);
        }
        for (int aaa = 0; aaa < Ylimit; aaa++) {
            loaded_Image_pixel_data.push_back(loaded_Image_pixel_data_out);
        }
    }
    Color color;
    for (UINT y = 0; y < Ylimit; y++) {
        for (UINT x = 0; x < Xlimit; x++) {
            bmp->GetPixel(x, y, &color);
            loaded_Image_pixel_data[y][x].IPDR = (int)color.GetRed();
            loaded_Image_pixel_data[y][x].IPDG = (int)color.GetGreen();
            loaded_Image_pixel_data[y][x].IPDB = (int)color.GetBlue();
        }
    }
    if (init == 0) {
        L_loaded_Image_pixel_data = loaded_Image_pixel_data; //保存上一次的结果用于下一次的比较
        init = 1;
    }
    delete bmp;
    GdiplusShutdown(gdiplustoken);
}

































#endif
