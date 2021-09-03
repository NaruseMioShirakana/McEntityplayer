#ifndef Minecraft_video_player_1
#define Minecraft_video_player_1
#include <jpeg.h>

string infilename_1;
string filename="你的MC函数路径";
FILE* file1 = nullptr;

void badapple (int Minecraft_video_player_badapple_from ,int Minecraft_video_player_badapple_to) {
	for (int asdasdasd = Minecraft_video_player_badapple_from; asdasdasd <= Minecraft_video_player_badapple_to; asdasdasd++) {
		infilename_1 = to_string(asdasdasd);//读取的文件名（默认为数字编号）
		

		wstring infilename_2 = strToStdWString(infilename_1.c_str());
		Get_Image_pixel_RGB(infilename_2);//调用RGB函数
		for (int y = 0; y < Ylimit; y++) {
			for (int x = 0; x < Xlimit; x++) {
				//对比上次数据判断是否应该替换头盔
				if ((loaded_Image_pixel_data[y][x].IPDR > 150 && loaded_Image_pixel_data[y][x].IPDG > 150 && loaded_Image_pixel_data[y][x].IPDB > 150 && L_loaded_Image_pixel_data[y][x].IPDR <= 150 && L_loaded_Image_pixel_data[y][x].IPDG <= 150 && L_loaded_Image_pixel_data[y][x].IPDB <= 150)|| (loaded_Image_pixel_data[y][x].IPDR <= 150 && loaded_Image_pixel_data[y][x].IPDG <= 150 && loaded_Image_pixel_data[y][x].IPDB <= 150 && L_loaded_Image_pixel_data[y][x].IPDR > 150 && L_loaded_Image_pixel_data[y][x].IPDG > 150 && L_loaded_Image_pixel_data[y][x].IPDB > 150)) {
					if (loaded_Image_pixel_data[y][x].IPDR > 150 && loaded_Image_pixel_data[y][x].IPDG > 150 && loaded_Image_pixel_data[y][x].IPDB > 150) {
						fprintf(file1, "execute if score NaruseShiroha Timer matches %d run data merge entity @e[tag=k%d_%d,limit=1] {ArmorItems:[{},{},{},{id:\"minecraft:iron_helmet\",Count:1b}]}\n", asdasdasd, (x + 1), (y + 1));
					}//白色
					else{
						fprintf(file1, "execute if score NaruseShiroha Timer matches %d run data merge entity @e[tag=k%d_%d,limit=1] {ArmorItems:[{},{},{},{id:\"minecraft:netherite_helmet\",Count:1b}]}\n", asdasdasd, (x + 1), (y + 1));
					}//黑色
				}
			}
		}
		L_loaded_Image_pixel_data = loaded_Image_pixel_data;//覆盖上次数据
	}
}



// data merge entity @e[tag=k1_1,limit=1] {ArmorItems:[{},{},{},{id:"minecraft:netherite_helmet",Count:1b}]}
// data merge entity @e[tag=k1_1,limit=1] {ArmorItems:[{},{},{},{id:"minecraft:iron_helmet",Count:1b}]}
#endif
