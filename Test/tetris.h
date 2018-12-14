#pragma once

#include "resource.h"

//函数声明
void checkComplite();  // 查看一行是否能消去  
void drawBlocked(HDC hdc);      // 绘制当前已经存在砖块的区域
void DrawBackGround(HDC hdc);       // 绘制背景
void outPutBoxInt(int num);     // 自定义的弹窗函数  用于调试，已经被注释掉了
void outPutBoxString(TCHAR str[1024]);
void setRandomT();      // 设置随机方块形状
void init_game();       // 游戏初始化
void fillBlock();       // 到达底部后填充矩阵
void RotateTeris(BOOL bTeris[4][4]);        // 旋转方块图形
void DrawTeris(HDC mdc);    // 绘制方块图形
void drawNext(HDC hdc); // 绘制下一个将要掉落的方块
void drawScore(HDC hdc);    // 绘制分数
void drawCompleteParticle(int line);

int RandomInt(int _min, int _max);       // 生成随机数
int CheckValide(int curPosX, int curPosY, BOOL bCurTeris[4][4]);   // 给定一个矩阵，查看是否合法
int selectDiffculty(HWND hWnd, int dif);
int selectLayOut(HWND hWnd, int layout);

//常量声明
const int BORDER_X = 10;// 界面边框左上点X坐标
const int BORDER_Y = 10;// 界面边框左上点Y坐标
const int SCREEN_LEFT_X = 300 + BORDER_X;// 左界面边框右上点X坐标
const int SCREEN_Y = 600 + BORDER_Y;// 界面边框右下点Y坐标
const int SCREEN_RIGHT_X = 180 + BORDER_X * 2;// 右边界边框右上点X坐标
const int SCREEN_X = SCREEN_LEFT_X + SCREEN_RIGHT_X;// 界面边框右下点X坐标
const BOOL state_teris[][4][4] =
{
	{ { 1,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,1,0 },{ 0,1,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,1,1 },{ 0,0,0,1 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,1,0 },{ 0,0,1,1 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,0,0 },{ 1,1,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,1,1 },{ 0,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,1,0 },{ 1,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } }
};// 七种砖块形状



//全局变量声明
bool g_hasBlocked[50][50];// 矩阵填充情况，1为填充，0为空缺
RECT rc_left, rc_right, rc_right_top, rc_right_bottom, rc_main;// 下落砖块的坐标位置
int g_speed = 300;// 当前下落速度
int t_speed = 300;// 最大下落速度
BOOL bCurTeris[4][4];// 下落砖块的形状矩阵
BOOL bNextCurTeris[4][4];// 下一个下落砖块的形状矩阵
int curPosX, curPosY;// 当前位置
int rd_seed = 1995421;// 随机数种子
int tPre = 0, tCur;// 时间
int GAME_STATE = 0;// 游戏状态
int GAME_SCORE = 0;// 游戏得分
int GAME_DIFF = 1;// 游戏难度
int NUM_X = 10;// 布局最大X坐标
int NUM_Y = 20;// 布局最大Y坐标
int BLOCK_SIZE = 30;// 砖块大小