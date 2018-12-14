#include "stdafx.h"
#include "tetris.h"
#include <windows.h>
#include <mmsystem.h>//包含windows中与多媒体有关的大多数接口
#pragma comment(lib, "WINMM.LIB")//导入winmm库：WINMM.LIB是Windows多媒体相关应用程序接口
#define MAX_LOADSTRING 100 

// 此代码模块中包含的函数的前向声明: 
ATOM                MyRegisterClass(HINSTANCE hInstance);//
BOOL                InitInstance(HINSTANCE, int);//
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);//
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// 全局变量: 
HINSTANCE hInst;                               // 存储实例句柄
WCHAR szTitle[MAX_LOADSTRING];                  // 标题名字符串数组
WCHAR szWindowClass[MAX_LOADSTRING];            // 窗口类名字符串数组
HMENU diff;// 难度菜单句柄
HMENU lay;// 布局菜单句柄

int APIENTRY wWinMain(HINSTANCE hInstance,// 实例句柄
	HINSTANCE hPrevInstance,// 先前实例句柄
	LPWSTR    lpCmdLine,// 指向应用程序命令行的字符串的指针
	int       nCmdShow)// 指定程序最初显示的方式
{
	init_game();// 游戏初始化
	UNREFERENCED_PARAMETER(hPrevInstance);// 消除hPrevInstance参数调用警告
	UNREFERENCED_PARAMETER(lpCmdLine);// 消除lpCmdLine参数调用警告

									  // 初始化全局字符串
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_TETRIS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);// 注册窗口类

							   // 若初始化失败，返回错误
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TETRIS));// 从资源里加载快捷键

	MSG msg;

	// 消息处理: 
	while (1)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))// 检查线程消息队列头部，并将头部消息消息（如果存在）移除。
		{
			TranslateMessage(&msg);// 把虚拟键消息转换到字符消息，以满足键盘输入的需要
			DispatchMessage(&msg);// 把当前的消息发送到对应的窗口过程中去
			if (msg.message == WM_QUIT)// 退出消息处理循环
			{
				break;
			}
		}
		else
		{
			if ((GAME_STATE & 2) != 0)
			{
				tCur = GetTickCount();// 获取当前的时间
				if (tCur - tPre>g_speed)// 若当前时间与先前时间差大于游戏速度
				{
					int flag = CheckValide(curPosX, curPosY + 1, bCurTeris);// 检查矩阵是否合法
					if (flag == 1)// 当前砖块位置合法
					{
						curPosY++;// 砖块下移一格
						tPre = tCur;// 更新之前时间
						HWND hWnd = GetActiveWindow();
						//这里两次调用实现了双缓冲的作用，改善了视觉效果
						InvalidateRect(hWnd, &rc_left, FALSE);// 砖块移动后的图像更新
						InvalidateRect(hWnd, &rc_right_top, FALSE);//系统不会像窗口发送WM_PAINT消息，来重绘
					}
					else if (flag == -2)// 当前砖块位置到达底部
					{
						g_speed = t_speed;// 更新游戏速度
						fillBlock();// 填充底部砖块新下落的砖块矩阵
						checkComplite(); // 检查是否能够消去
						setRandomT();// 设置随机砖块
						curPosX = (NUM_X - 4) >> 1;// 下落砖块X坐标位置更新
						curPosY = 0;// 下落砖块Y坐标位置更新(位于顶部)
						HWND hWnd = GetActiveWindow();// 当前窗口激活
						InvalidateRect(hWnd, &rc_main, FALSE);// 砖块移动后的图像更新
					}
					else if (flag == -3)// 当前砖块已经到达顶部(溢出)
					{
						HWND hWnd = GetActiveWindow();// 当前窗口激活
						if (MessageBox(hWnd, L"胜败乃兵家常事，菜鸡请重新来过", L":时光机", MB_YESNO) == IDYES)// 当前游戏失败
						{
							init_game();// 若重新来过，则重新初始化游戏
						}
						else
						{
							break;// 结束游戏，程序退出
						}
					}
				}
			}
		}
	}

	return (int)msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
//  注释:
//
//    仅当希望
//    此代码与添加到 Windows 95 中的“RegisterClassEx”
//    函数之前的 Win32 系统兼容时，才需要此函数及其用法。调用此函数十分重要，
//    这样应用程序就可以获得关联的
//    “格式正确的”小图标。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;// 定义窗口类结构体对象

	wcex.cbSize = sizeof(WNDCLASSEX);// 窗口类结构体对象的大小
	wcex.style = CS_HREDRAW | CS_VREDRAW;// 窗口风格
	wcex.lpfnWndProc = WndProc;// 窗口的消息处理函数的窗口过程函数
	wcex.cbClsExtra = 0;// 分配给窗口类结构之后的额外字节数
	wcex.cbWndExtra = 0;// 分配给窗口实例之后的额外字节数
	wcex.hInstance = hInstance;// 窗口过程对应的实例句柄
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TETRIS));// 窗口图标
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);// 窗口鼠标指针
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);// 窗口背景面刷
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_TETRIS);// 窗口菜单资源名称
	wcex.lpszClassName = szWindowClass;// 窗口类名称
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));// 窗口标题栏图标

	return RegisterClassExW(&wcex);// 返回注册的窗口类结构体对象
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 初始化实例句柄
	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
	// 创建窗口类对象实例句柄
	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);// 显示窗口
	UpdateWindow(hWnd);// 更新窗口

	return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;//包含某应用程序用来绘制他所拥有的窗口客户区所需要的信息
	HDC hdc;// 创建设备描述表句柄
	int nWinx, nWiny, nClientX, nClientY;
	int posX, posY;
	RECT rect;// 创建矩阵对象
	HMENU hSysmenu;// 创建菜单句柄
	switch (message)
	{
	case WM_CREATE:// 接收到窗口创建消息
		GetWindowRect(hWnd, &rect);
		//获取窗口矩阵的尺寸
		nWinx = 530;// 设置窗口X坐标
		nWiny = 680;// 设置窗口Y坐标
		posX = GetSystemMetrics(SM_CXSCREEN);// 获取系统分辨率X
		posY = GetSystemMetrics(SM_CYSCREEN);// 获取系统分辨率Y
		posX = (posX - nWinx) >> 1;// 更新X位置坐标
		posY = (posY - nWiny) >> 1;// 更新Y位置坐标
		GetClientRect(hWnd, &rect);// 取得窗口的客户区域大小
		nClientX = rect.right - rect.left;// 更新客户区域横向长度
		nClientY = rect.bottom - rect.top;// 更新客户区域纵向长度

		MoveWindow(hWnd, posX, posY, 530, 680, TRUE);// 移动窗口位置到参数指定区域
		hSysmenu = GetMenu(hWnd);// 更新菜单句柄
		AppendMenu(hSysmenu, MF_SEPARATOR, 0, NULL);// 追加菜单项
													//此处的菜单句柄要全局向前初始化
		diff = CreatePopupMenu();// 创建难度菜单
		AppendMenu(hSysmenu, MF_POPUP, (UINT_PTR)diff, L"难度选择");// 追加菜单项名为“难度选择”
		AppendMenu(diff, MF_STRING, ID_dif1, L"难度1");// 追加菜单项名为“难度1”
		AppendMenu(diff, MF_STRING, ID_dif2, L"难度2");// 追加菜单项名为“难度2”
		AppendMenu(diff, MF_STRING, ID_dif3, L"难度3");// 追加菜单项名为“难度3”
		lay = CreatePopupMenu();// 创建布局菜单
		AppendMenu(hSysmenu, MF_POPUP, (UINT_PTR)lay, L"布局选择");// 追加菜单项名为“布局选择”
		AppendMenu(lay, MF_STRING, ID_LAYOUT1, L"布局1");// 追加菜单项名为“布局1”
		AppendMenu(lay, MF_STRING, ID_LAYOUT2, L"布局2");// 追加菜单项名为“布局2”
		SetMenu(hWnd, hSysmenu);// 分配新菜单hSysmenu到窗口
		SetMenu(hWnd, diff);// 分配新菜单diff到窗口
		SetMenu(hWnd, lay);// 分配新菜单lay到窗口
		break;
	case WM_COMMAND:// 接收到菜单程序消息
		wmId = LOWORD(wParam);// 取低位
		wmEvent = HIWORD(wParam);// 取高位
								 // 处理菜单程序消息
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);// 创建about对话框
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);// 退出程序，销毁窗口
			break;
		case ID_dif1:
			selectDiffculty(hWnd, 1);// 调用选择难度1函数
			break;
		case ID_dif2:
			selectDiffculty(hWnd, 2);// 调用选择难度2函数
			break;
		case ID_dif3:
			selectDiffculty(hWnd, 3);// 调用选择难度3函数
			break;
		case ID_LAYOUT1:
			selectLayOut(hWnd, 1);// 调用选择布局1函数
			break;
		case ID_LAYOUT2:
			selectLayOut(hWnd, 2);// 调用选择布局2函数
			break;
		default://该函数调用缺省的窗口过程来为应用程序没有处理的任何窗口提供缺省的处理,该函数确保每一个消息得到处理
			return DefWindowProc(hWnd, message, wParam, lParam);//调用缺省的窗口过程来为应用程序没有处理的任何窗口消息提供缺省的处理
		}
		break;
	case WM_KEYDOWN://键盘消息
		hdc = GetDC(hWnd);
		InvalidateRect(hWnd, NULL, false);
		switch (wParam)
		{
		case VK_LEFT:
			curPosX--;
			if (CheckValide(curPosX, curPosY, bCurTeris) != 1)
			{
				curPosX++;// 若已到达左边界，则不做处理
			}
			break;
		case VK_RIGHT:
			curPosX++;
			if (CheckValide(curPosX, curPosY, bCurTeris) != 1)
			{
				curPosX--;// 若已到达右边界，则不做处理
			}
			break;
		case VK_UP:
			RotateTeris(bCurTeris);// 调用旋转下落砖块函数
			break;
		case VK_DOWN:// 调整下落速度
			if (g_speed == t_speed)
				g_speed = 10;
			else
				g_speed = t_speed;
			//outPutBoxInt(g_speed);
			break;
		case 'W'://同 VK_UP
			RotateTeris(bCurTeris);
			break;
		case 'A'://同 VK_LEFT
			curPosX--;
			if (CheckValide(curPosX, curPosY, bCurTeris) != 1)
			{
				curPosX++;
			}
			break;
		case 'D'://同 VK_RIGHT
			curPosX++;
			if (CheckValide(curPosX, curPosY, bCurTeris) != 1)
			{
				curPosX--;
			}
			break;

		case 'S'://同 VK_DOWN
			if (g_speed == t_speed)
				g_speed = 10;
			else
				g_speed = t_speed;
			//outPutBoxInt(g_speed);
			break;
		default:
			break;
		}

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		DrawBackGround(hdc);// 游戏背景填充
		EndPaint(hWnd, &ps);// 结束填充
		break;
	case WM_DESTROY:// 窗口销毁
		PostQuitMessage(0);
		break;
	default:
		//函数调用缺省的窗口过程来为应用程序没有处理的任何窗口消息提供缺省的处理。该函数确保每一个消息得到处理
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));//该函数清除一个模态对话框,并使系统中止对对话框的任何处理
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

void drawBlocked(HDC mdc)//绘制当前已经存在砖块的区域
{
	int i, j;
	//设置i, j作为坐标参数
	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 0));// 创建黄色画刷句柄

	SelectObject(mdc, hBrush);// 把黄色画刷选入到已存在砖块区域的描述表中

	for (i = 0; i<NUM_Y; i++)
	{
		for (j = 0; j<NUM_X; j++)
		{
			if (g_hasBlocked[i][j])
			{
				Rectangle(mdc, BORDER_X + j*BLOCK_SIZE, BORDER_Y + i*BLOCK_SIZE,
					BORDER_X + (j + 1)*BLOCK_SIZE, BORDER_Y + (i + 1)*BLOCK_SIZE
				);//对区域进行涂色
			}
		}
	}
	DeleteObject(hBrush);// 删除句柄
}

int CheckValide(int startX, int startY, BOOL bTemp[4][4])//给定一个矩阵，查看是否合法
{
	int i, j;
	for (i = 3; i >= 0; i--)
	{
		for (j = 3; j >= 0; j--)
		{
			if (bTemp[i][j])
			{
				if (j + startX<0 || j + startX >= NUM_X)
				{
					return -1;
				}
				if (i + startY >= NUM_Y)
				{
					return -2;
				}
				if (g_hasBlocked[i + startY][j + startX])
				{
					//outPutBoxInt(j+startY);
					if (curPosY == 0)
					{
						return -3;
					}
					return -2;
				}
			}
		}
	}
	//MessageBox(NULL,L"这里",L"as",MB_OK);
	//outPutBoxInt(curPosY);
	return 1;
}

void checkComplite()//查看一行是否能消去
{
	int i, j, k, count = 0;
	for (i = 0; i<NUM_Y; i++)
	{
		bool flag = true;
		for (j = 0; j<NUM_X; j++)
		{
			if (!g_hasBlocked[i][j])
			{
				flag = false;//有一个为空时，不能消去
			}
		}
		if (flag)
		{
			count++;
			for (j = i; j >= 1; j--)//从上往下把每行下移
			{
				for (k = 0; k<NUM_X; k++)
				{
					g_hasBlocked[j][k] = g_hasBlocked[j - 1][k];
				}

			}
			drawCompleteParticle(i);// 绘制一行区域
			Sleep(300);//暂停300ms

			PlaySound(_T("coin.wav"), NULL, SND_FILENAME | SND_ASYNC);//消去一行时播放系统自带提示音
		}
	}
	GAME_SCORE += int(count*1.5);//单行+1分，两行+3分，三行+4分，四行6分，以此类推
}

VOID outPutBoxInt(int num)//自定义的弹窗函数  用于调试，已经被注释掉了
{
	TCHAR szBuf[1024];
	LPCTSTR str = TEXT("%d");
	wsprintf(szBuf, str, num);// 将数值加入到缓冲区
	MessageBox(NULL, szBuf, L"aasa", MB_OK);// 消息弹窗
}

VOID outPutBoxString(TCHAR str[1024])//自定义的弹窗函数  用于调试，已经被注释掉了
{
	TCHAR szBuf[1024];
	LPCTSTR cstr = TEXT("%s");
	wsprintf(szBuf, cstr, str);
	MessageBox(NULL, szBuf, L"aasa", MB_OK);
}



//设置随机方块形状
void setRandomT()
{
	int rd_start = RandomInt(0, sizeof(state_teris) / sizeof(state_teris[0]));
	int rd_next = RandomInt(0, sizeof(state_teris) / sizeof(state_teris[0]));
	//outPutBoxInt(rd_start);
	//outPutBoxInt(rd_next);
	//outPutBoxInt(rd_start);
	if (GAME_STATE == 0)
	{
		GAME_STATE = GAME_STATE | 0x0001;
		//outPutBoxInt(GAME_STATE);
		memcpy(bCurTeris, state_teris[rd_start], sizeof(state_teris[rd_start]));
		memcpy(bNextCurTeris, state_teris[rd_next], sizeof(state_teris[rd_next]));
	}
	else
	{
		memcpy(bCurTeris, bNextCurTeris, sizeof(bNextCurTeris));
		memcpy(bNextCurTeris, state_teris[rd_next], sizeof(state_teris[rd_next]));
	}

}

//游戏初始化
void init_game()
{
	GAME_SCORE = 0;
	setRandomT();// 设置随机砖块
	curPosX = (NUM_X - 4) >> 1;//设置初始坐标
	curPosY = 0;
	//memset，是计算机语言中的函数。起功能是将s所指向的某一块内存中的每个字节的内容全部设置为ch指定的ASCII值，最后行清零
	memset(g_hasBlocked, 0, sizeof(g_hasBlocked));
	rc_left.left = 0;
	rc_left.right = SCREEN_LEFT_X;
	rc_left.top = 0;
	rc_left.bottom = SCREEN_Y;

	rc_right.left = rc_left.right + BORDER_X;
	rc_right.right = 180 + rc_right.left;
	rc_right.top = 0;
	rc_right.bottom = SCREEN_Y;

	rc_main.left = 0;
	rc_main.right = SCREEN_X;
	rc_main.top = 0;
	rc_main.bottom = SCREEN_Y;

	rc_right_top.left = rc_right.left;
	rc_right_top.top = rc_right.top;
	rc_right_top.right = rc_right.right;
	rc_right_top.bottom = (rc_right.bottom) / 2;

	rc_right_bottom.left = rc_right.left;
	rc_right_bottom.top = rc_right_top.bottom + BORDER_Y;
	rc_right_bottom.right = rc_right.right;
	rc_right_bottom.bottom = rc_right.bottom;

	g_speed = t_speed = 1000 - GAME_DIFF * 280;
}

void fillBlock()//到达底部后填充矩阵
{
	int i, j;
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			if (bCurTeris[i][j])
			{
				g_hasBlocked[curPosY + i][curPosX + j] = 1;
			}
		}
	}
}

void RotateTeris(BOOL bTeris[4][4])
{
	BOOL bNewTeris[4][4];
	int x, y;
	for (x = 0; x<4; x++)
	{
		for (y = 0; y<4; y++)
		{//旋转角度
			//bNewTeris[x][y] = bTeris[3 - y][x];
			//逆时针：
			bNewTeris[x][y] = bTeris[y][3-x];
		}
	}
	if (CheckValide(curPosX, curPosY, bNewTeris) == 1)
	{
		memcpy(bTeris, bNewTeris, sizeof(bNewTeris));//成功则将变换后的形状保存
	}

}

int RandomInt(int _min, int _max)
{
	srand((rd_seed++) % 65532 + GetTickCount());
	return _min + rand() % (_max - _min);
}

VOID DrawTeris(HDC mdc)
{

	int i, j;
	HPEN hPen = (HPEN)GetStockObject(BLACK_PEN);// 获取调色板句柄信息
	HBRUSH hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
	SelectObject(mdc, hPen);//SelectObject是计算机编程语言函数，该函数选择一对象到指定的设备上下文环境中，新对象替换先前的相同类型的对象
	SelectObject(mdc, hBrush);
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			if (bCurTeris[i][j])
			{
				Rectangle(mdc, (j + curPosX)*BLOCK_SIZE + BORDER_X, (i + curPosY)*BLOCK_SIZE + BORDER_Y, (j + 1 + curPosX)*BLOCK_SIZE + BORDER_X, (i + 1 + curPosY)*BLOCK_SIZE + BORDER_Y);
			}
		}
	}
	drawBlocked(mdc);
	DeleteObject(hPen);
	DeleteObject(hBrush);
}

VOID DrawBackGround(HDC hdc)//绘制背景
{

	HBRUSH hBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
	//适用于支持光栅操作的设备，应用程序可以通过调用GetDeviceCaps函数来确定一个设备是否支持这些操作
	HDC mdc = CreateCompatibleDC(hdc);
	HBITMAP hBitmap = CreateCompatibleBitmap(hdc, SCREEN_X, SCREEN_Y);

	SelectObject(mdc, hBrush);
	SelectObject(mdc, hBitmap);

	HBRUSH hBrush2 = (HBRUSH)GetStockObject(WHITE_BRUSH);
	FillRect(mdc, &rc_main, hBrush2);
	Rectangle(mdc, rc_left.left + BORDER_X, rc_left.top + BORDER_Y, rc_left.right, rc_left.bottom);
	Rectangle(mdc, rc_right.left + BORDER_X, rc_right.top + BORDER_Y, rc_right.right, rc_right.bottom);
	DrawTeris(mdc);
	drawNext(mdc);
	drawScore(mdc);
	::BitBlt(hdc, 0, 0, SCREEN_X, SCREEN_Y, mdc, 0, 0, SRCCOPY);
	DeleteObject(hBrush);
	DeleteDC(mdc);
	DeleteObject(hBitmap);
	DeleteObject(hBrush2);


	//  int x,y;
	//  HPEN hPen = (HPEN)GetStockObject(NULL_PEN);
	//  HBRUSH hBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
	//  SelectObject(hdc,hPen);
	//  SelectObject(hdc,hBrush);
	//  for (x = 0;x<NUM_X;x++)
	//  {
	//      for(y=0;y<NUM_Y;y++)
	//      {
	//          Rectangle(hdc,BORDER_X+x*BLOCK_SIZE,BORDER_Y+y*BLOCK_SIZE,
	//              BORDER_X+(x+1)*BLOCK_SIZE,
	//              BORDER_Y+(y+1)*BLOCK_SIZE);
	//      }
	//  }
}

void drawNext(HDC hdc)//绘制下一个将要掉落的方块
{
	int i, j;
	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(RGB(188, 0, 0));
	HPEN hPen = (HPEN)CreatePen(PS_SOLID, 2, RGB(0, 0, 233));
	SelectObject(hdc, hBrush);
	SelectObject(hdc, hPen);
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			if (bNextCurTeris[i][j])
			{
				Rectangle(hdc, rc_right_top.left + BLOCK_SIZE*(j + 1), rc_right_top.top + BLOCK_SIZE*(i + 1), rc_right_top.left + BLOCK_SIZE*(j + 2), rc_right_top.top + BLOCK_SIZE*(i + 2));
			}
		}
	}
	HFONT hFont = CreateFont(30, 0, 0, 0, FW_THIN, 0, 0, 0, UNICODE, 0, 0, 0, 0, L"微软雅黑");
	SelectObject(hdc, hFont);
	SetBkMode(hdc, TRANSPARENT);
	SetBkColor(hdc, RGB(255, 255, 0));
	SetTextColor(hdc, RGB(152, 206, 0));
	RECT rect;
	rect.left = rc_right_top.left + 40;
	rect.top = rc_right_top.bottom - 150;
	rect.right = rc_right_top.right;
	rect.bottom = rc_right_top.bottom;
	DrawTextW(hdc, TEXT("下一个"), _tcslen(TEXT("下一个")), &rect, 0);
	DeleteObject(hFont);
	DeleteObject(hBrush);
}

void drawScore(HDC hdc)
{
	HFONT hFont = CreateFont(30, 0, 0, 0, FW_THIN, 0, 0, 0, UNICODE, 0, 0, 0, 0, L"微软雅黑");
	SelectObject(hdc, hFont);
	SetBkMode(hdc, TRANSPARENT);
	SetBkColor(hdc, RGB(255, 255, 0));
	SetTextColor(hdc, RGB(0, 200, 150));
	RECT rect;
	rect.left = rc_right_bottom.left;
	rect.top = rc_right_bottom.top;
	rect.right = rc_right_bottom.right;
	rect.bottom = rc_right_bottom.bottom;
	TCHAR szBuf[30];
	LPCTSTR cstr = TEXT("当前难度：%d");
	wsprintf(szBuf, cstr, GAME_DIFF);
	DrawTextW(hdc, szBuf, _tcslen(szBuf), &rect, DT_CENTER | DT_VCENTER);

	RECT rect2;
	rect2.left = rc_right_bottom.left;
	rect2.top = rc_right_bottom.bottom / 2 + 100;
	rect2.right = rc_right_bottom.right;
	rect2.bottom = rc_right_bottom.bottom;
	TCHAR szBuf2[30];
	LPCTSTR cstr2 = TEXT("得分：%d");
	wsprintf(szBuf2, cstr2, GAME_SCORE);
	//outPutBoxInt(sizeof(szBuf));
	SetTextColor(hdc, RGB(15, 0, 150));
	DrawTextW(hdc, szBuf2, _tcslen(szBuf2), &rect2, DT_CENTER | DT_VCENTER);

	DeleteObject(hFont);
}

int selectDiffculty(HWND hWnd, int diff)
{
	TCHAR szBuf2[30];
	LPCTSTR cstr2 = TEXT("确认选择难度 %d 吗？");
	wsprintf(szBuf2, cstr2, diff);
	if (MessageBox(hWnd, szBuf2, L"难度选择", MB_YESNO) == IDYES)
	{
		GAME_DIFF = diff;
		InvalidateRect(hWnd, &rc_right_bottom, false);
		GAME_STATE |= 2;
		init_game();
		return GAME_DIFF;
	}
	return -1;
}

int selectLayOut(HWND hWnd, int layout)//选择布局
{
	NUM_X = 10 * layout;
	NUM_Y = 20 * layout;
	BLOCK_SIZE = 30 / layout;
	GAME_STATE |= 2;
	InvalidateRect(hWnd, &rc_right_bottom, false);
	init_game();
	return layout;
}

void drawCompleteParticle(int line)
{
	HWND hWnd = GetActiveWindow();
	HDC hdc = GetDC(hWnd);
	HBRUSH hBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
	HPEN hPen = (HPEN)CreatePen(PS_DOT, 1, RGB(255, 255, 0));
	SelectObject(hdc, hBrush);
	SelectObject(hdc, hPen);
	Rectangle(hdc, BORDER_X,
		BORDER_Y + line*BLOCK_SIZE,
		BORDER_X + NUM_X*BLOCK_SIZE,
		BORDER_Y + BLOCK_SIZE*(1 + line));
	DeleteObject(hBrush);
	DeleteObject(hPen);
}