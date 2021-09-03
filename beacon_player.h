#ifndef Player_X
#define Player_X
#include <stdio.h>
#include <iostream>
#include "jpeg.h"
FILE* file1 = nullptr;
string infilename_1;
void Construct_Player() {

	for (int i = 0; i < 128; i++) {
		fprintf(file1,"setblock %d 2 0 minecraft:beacon\n",i);
	}

}

void construct_video() {

	for (int asdasdasd = 1; asdasdasd < 6602; asdasdasd++) {
		infilename_1 = to_string(asdasdasd);//读取的文件名
		

		wstring infilename_2 = strToStdWString(infilename_1.c_str());


		Get_Image_pixel_RGB(infilename_2);//调用RGB函数
		
		for (int y = 0; y < 96; y++) {
			for (int x = 0; x < 128; x++) {
				if (y > 0) {
					if (loaded_Image_pixel_data[y][x].IPDR > 150 && loaded_Image_pixel_data[y][x].IPDG > 150 && loaded_Image_pixel_data[y][x].IPDB > 150 && loaded_Image_pixel_data[y - 1][x].IPDR < 150 && loaded_Image_pixel_data[y - 1][x].IPDG < 150 && loaded_Image_pixel_data[y - 1][x].IPDB < 150) {
						fprintf(file1, "execute if score NaruseShiroha Timer matches %d run setblock %d %d 0 minecraft:gray_stained_glass\n", asdasdasd, x, y+4);
					}//白色
					else if (loaded_Image_pixel_data[y][x].IPDR < 150 && loaded_Image_pixel_data[y][x].IPDG < 150 && loaded_Image_pixel_data[y][x].IPDB < 150 && loaded_Image_pixel_data[y - 1][x].IPDR > 150 && loaded_Image_pixel_data[y - 1][x].IPDG > 150 && loaded_Image_pixel_data[y - 1][x].IPDB > 150) {
						fprintf(file1, "execute if score NaruseShiroha Timer matches %d run setblock %d %d 0 minecraft:white_stained_glass\n", asdasdasd, x, y+4);
					}//黑色
				}
				else {
					if ((loaded_Image_pixel_data[y][x].IPDR > 150 && loaded_Image_pixel_data[y][x].IPDG > 150 && loaded_Image_pixel_data[y][x].IPDB > 150 && L_loaded_Image_pixel_data[y][x].IPDR <= 150 && L_loaded_Image_pixel_data[y][x].IPDG <= 150 && L_loaded_Image_pixel_data[y][x].IPDB <= 150) || (loaded_Image_pixel_data[y][x].IPDR <= 150 && loaded_Image_pixel_data[y][x].IPDG <= 150 && loaded_Image_pixel_data[y][x].IPDB <= 150 && L_loaded_Image_pixel_data[y][x].IPDR > 150 && L_loaded_Image_pixel_data[y][x].IPDG > 150 && L_loaded_Image_pixel_data[y][x].IPDB > 150)) {
						if (loaded_Image_pixel_data[y][x].IPDR > 150 && loaded_Image_pixel_data[y][x].IPDG > 150 && loaded_Image_pixel_data[y][x].IPDB > 150) {
							fprintf(file1, "execute if score NaruseShiroha Timer matches %d run setblock %d %d 0 minecraft:gray_stained_glass\n", asdasdasd, x, y+4);
						}//白色
						else if (loaded_Image_pixel_data[y][x].IPDR < 150 && loaded_Image_pixel_data[y][x].IPDG < 150 && loaded_Image_pixel_data[y][x].IPDB < 150) {
							fprintf(file1, "execute if score NaruseShiroha Timer matches %d run setblock %d %d 0 minecraft:white_stained_glass\n", asdasdasd, x, y+4);
						}//黑色
					}
					
				}
			}
		}
		L_loaded_Image_pixel_data = loaded_Image_pixel_data;
		std::cout << asdasdasd << endl;
	}

}












#endif
