#ifndef Minecraft_video_player
#define Minecraft_video_player

#include <stdio.h>
#include <string>
using namespace std;


string entity_type = "minecraft:armor_stand";//实体类型声明（想要用其他实体就修改这里）


FILE* file1 = nullptr;
//构造显示器（盔甲架头盔）
void Player_construct() {
	int xlimit = 32;//横像素
	int ylimit = 24;//纵像素(修改分辨率)
	//打开文件
	file1 = fopen("你的MCfunction文件路径", "a+");
	for (int i = 0; i < ylimit; i++) {
		for (int j = 0; j < xlimit; j++) {//在相应（XY）坐标生成盔甲架，带有TAG：K<X坐标>_<Y坐标>
			fprintf(file1, "summon %s %.10f 4 %.10f {Tags:[k%d_%d],NoGravity:1,Invulnerable:1,Invisible:1,ArmorItems:[{},{},{},{id:\"minecraft:iron_helmet\",Count:1b}]}\n", entity_type.c_str(), (double)i + 1.5, (double)j + 1.5, j + 1, i + 1);
		}
	}
}




// summon minecraft : panda ~~~{Tags: [K1] }






#endif
