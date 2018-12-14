#include "stdafx.h"
#include "tetris.h"
#include <windows.h>
#include <mmsystem.h>//����windows�����ý���йصĴ�����ӿ�
#pragma comment(lib, "WINMM.LIB")//����winmm�⣺WINMM.LIB��Windows��ý�����Ӧ�ó���ӿ�
#define MAX_LOADSTRING 100 

// �˴���ģ���а����ĺ�����ǰ������: 
ATOM                MyRegisterClass(HINSTANCE hInstance);//
BOOL                InitInstance(HINSTANCE, int);//
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);//
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// ȫ�ֱ���: 
HINSTANCE hInst;                               // �洢ʵ�����
WCHAR szTitle[MAX_LOADSTRING];                  // �������ַ�������
WCHAR szWindowClass[MAX_LOADSTRING];            // ���������ַ�������
HMENU diff;// �ѶȲ˵����
HMENU lay;// ���ֲ˵����

int APIENTRY wWinMain(HINSTANCE hInstance,// ʵ�����
	HINSTANCE hPrevInstance,// ��ǰʵ�����
	LPWSTR    lpCmdLine,// ָ��Ӧ�ó��������е��ַ�����ָ��
	int       nCmdShow)// ָ�����������ʾ�ķ�ʽ
{
	init_game();// ��Ϸ��ʼ��
	UNREFERENCED_PARAMETER(hPrevInstance);// ����hPrevInstance�������þ���
	UNREFERENCED_PARAMETER(lpCmdLine);// ����lpCmdLine�������þ���

									  // ��ʼ��ȫ���ַ���
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_TETRIS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);// ע�ᴰ����

							   // ����ʼ��ʧ�ܣ����ش���
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TETRIS));// ����Դ����ؿ�ݼ�

	MSG msg;

	// ��Ϣ����: 
	while (1)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))// ����߳���Ϣ����ͷ��������ͷ����Ϣ��Ϣ��������ڣ��Ƴ���
		{
			TranslateMessage(&msg);// ���������Ϣת�����ַ���Ϣ������������������Ҫ
			DispatchMessage(&msg);// �ѵ�ǰ����Ϣ���͵���Ӧ�Ĵ��ڹ�����ȥ
			if (msg.message == WM_QUIT)// �˳���Ϣ����ѭ��
			{
				break;
			}
		}
		else
		{
			if ((GAME_STATE & 2) != 0)
			{
				tCur = GetTickCount();// ��ȡ��ǰ��ʱ��
				if (tCur - tPre>g_speed)// ����ǰʱ������ǰʱ��������Ϸ�ٶ�
				{
					int flag = CheckValide(curPosX, curPosY + 1, bCurTeris);// �������Ƿ�Ϸ�
					if (flag == 1)// ��ǰש��λ�úϷ�
					{
						curPosY++;// ש������һ��
						tPre = tCur;// ����֮ǰʱ��
						HWND hWnd = GetActiveWindow();
						//�������ε���ʵ����˫��������ã��������Ӿ�Ч��
						InvalidateRect(hWnd, &rc_left, FALSE);// ש���ƶ����ͼ�����
						InvalidateRect(hWnd, &rc_right_top, FALSE);//ϵͳ�����񴰿ڷ���WM_PAINT��Ϣ�����ػ�
					}
					else if (flag == -2)// ��ǰש��λ�õ���ײ�
					{
						g_speed = t_speed;// ������Ϸ�ٶ�
						fillBlock();// ���ײ�ש���������ש�����
						checkComplite(); // ����Ƿ��ܹ���ȥ
						setRandomT();// �������ש��
						curPosX = (NUM_X - 4) >> 1;// ����ש��X����λ�ø���
						curPosY = 0;// ����ש��Y����λ�ø���(λ�ڶ���)
						HWND hWnd = GetActiveWindow();// ��ǰ���ڼ���
						InvalidateRect(hWnd, &rc_main, FALSE);// ש���ƶ����ͼ�����
					}
					else if (flag == -3)// ��ǰש���Ѿ����ﶥ��(���)
					{
						HWND hWnd = GetActiveWindow();// ��ǰ���ڼ���
						if (MessageBox(hWnd, L"ʤ���˱��ҳ��£��˼�����������", L":ʱ���", MB_YESNO) == IDYES)// ��ǰ��Ϸʧ��
						{
							init_game();// �����������������³�ʼ����Ϸ
						}
						else
						{
							break;// ������Ϸ�������˳�
						}
					}
				}
			}
		}
	}

	return (int)msg.wParam;
}



//
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
//  ע��:
//
//    ����ϣ��
//    �˴�������ӵ� Windows 95 �еġ�RegisterClassEx��
//    ����֮ǰ�� Win32 ϵͳ����ʱ������Ҫ�˺��������÷������ô˺���ʮ����Ҫ��
//    ����Ӧ�ó���Ϳ��Ի�ù�����
//    ����ʽ��ȷ�ġ�Сͼ�ꡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;// ���崰����ṹ�����

	wcex.cbSize = sizeof(WNDCLASSEX);// ������ṹ�����Ĵ�С
	wcex.style = CS_HREDRAW | CS_VREDRAW;// ���ڷ��
	wcex.lpfnWndProc = WndProc;// ���ڵ���Ϣ�������Ĵ��ڹ��̺���
	wcex.cbClsExtra = 0;// �����������ṹ֮��Ķ����ֽ���
	wcex.cbWndExtra = 0;// ���������ʵ��֮��Ķ����ֽ���
	wcex.hInstance = hInstance;// ���ڹ��̶�Ӧ��ʵ�����
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TETRIS));// ����ͼ��
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);// �������ָ��
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);// ���ڱ�����ˢ
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_TETRIS);// ���ڲ˵���Դ����
	wcex.lpszClassName = szWindowClass;// ����������
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));// ���ڱ�����ͼ��

	return RegisterClassExW(&wcex);// ����ע��Ĵ�����ṹ�����
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // ��ʼ��ʵ�����
	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
	// �������������ʵ�����
	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);// ��ʾ����
	UpdateWindow(hWnd);// ���´���

	return TRUE;
}

//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND  - ����Ӧ�ó���˵�
//  WM_PAINT    - ����������
//  WM_DESTROY  - �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;//����ĳӦ�ó���������������ӵ�еĴ��ڿͻ�������Ҫ����Ϣ
	HDC hdc;// �����豸��������
	int nWinx, nWiny, nClientX, nClientY;
	int posX, posY;
	RECT rect;// �����������
	HMENU hSysmenu;// �����˵����
	switch (message)
	{
	case WM_CREATE:// ���յ����ڴ�����Ϣ
		GetWindowRect(hWnd, &rect);
		//��ȡ���ھ���ĳߴ�
		nWinx = 530;// ���ô���X����
		nWiny = 680;// ���ô���Y����
		posX = GetSystemMetrics(SM_CXSCREEN);// ��ȡϵͳ�ֱ���X
		posY = GetSystemMetrics(SM_CYSCREEN);// ��ȡϵͳ�ֱ���Y
		posX = (posX - nWinx) >> 1;// ����Xλ������
		posY = (posY - nWiny) >> 1;// ����Yλ������
		GetClientRect(hWnd, &rect);// ȡ�ô��ڵĿͻ������С
		nClientX = rect.right - rect.left;// ���¿ͻ�������򳤶�
		nClientY = rect.bottom - rect.top;// ���¿ͻ��������򳤶�

		MoveWindow(hWnd, posX, posY, 530, 680, TRUE);// �ƶ�����λ�õ�����ָ������
		hSysmenu = GetMenu(hWnd);// ���²˵����
		AppendMenu(hSysmenu, MF_SEPARATOR, 0, NULL);// ׷�Ӳ˵���
													//�˴��Ĳ˵����Ҫȫ����ǰ��ʼ��
		diff = CreatePopupMenu();// �����ѶȲ˵�
		AppendMenu(hSysmenu, MF_POPUP, (UINT_PTR)diff, L"�Ѷ�ѡ��");// ׷�Ӳ˵�����Ϊ���Ѷ�ѡ��
		AppendMenu(diff, MF_STRING, ID_dif1, L"�Ѷ�1");// ׷�Ӳ˵�����Ϊ���Ѷ�1��
		AppendMenu(diff, MF_STRING, ID_dif2, L"�Ѷ�2");// ׷�Ӳ˵�����Ϊ���Ѷ�2��
		AppendMenu(diff, MF_STRING, ID_dif3, L"�Ѷ�3");// ׷�Ӳ˵�����Ϊ���Ѷ�3��
		lay = CreatePopupMenu();// �������ֲ˵�
		AppendMenu(hSysmenu, MF_POPUP, (UINT_PTR)lay, L"����ѡ��");// ׷�Ӳ˵�����Ϊ������ѡ��
		AppendMenu(lay, MF_STRING, ID_LAYOUT1, L"����1");// ׷�Ӳ˵�����Ϊ������1��
		AppendMenu(lay, MF_STRING, ID_LAYOUT2, L"����2");// ׷�Ӳ˵�����Ϊ������2��
		SetMenu(hWnd, hSysmenu);// �����²˵�hSysmenu������
		SetMenu(hWnd, diff);// �����²˵�diff������
		SetMenu(hWnd, lay);// �����²˵�lay������
		break;
	case WM_COMMAND:// ���յ��˵�������Ϣ
		wmId = LOWORD(wParam);// ȡ��λ
		wmEvent = HIWORD(wParam);// ȡ��λ
								 // ����˵�������Ϣ
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);// ����about�Ի���
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);// �˳��������ٴ���
			break;
		case ID_dif1:
			selectDiffculty(hWnd, 1);// ����ѡ���Ѷ�1����
			break;
		case ID_dif2:
			selectDiffculty(hWnd, 2);// ����ѡ���Ѷ�2����
			break;
		case ID_dif3:
			selectDiffculty(hWnd, 3);// ����ѡ���Ѷ�3����
			break;
		case ID_LAYOUT1:
			selectLayOut(hWnd, 1);// ����ѡ�񲼾�1����
			break;
		case ID_LAYOUT2:
			selectLayOut(hWnd, 2);// ����ѡ�񲼾�2����
			break;
		default://�ú�������ȱʡ�Ĵ��ڹ�����ΪӦ�ó���û�д�����κδ����ṩȱʡ�Ĵ���,�ú���ȷ��ÿһ����Ϣ�õ�����
			return DefWindowProc(hWnd, message, wParam, lParam);//����ȱʡ�Ĵ��ڹ�����ΪӦ�ó���û�д�����κδ�����Ϣ�ṩȱʡ�Ĵ���
		}
		break;
	case WM_KEYDOWN://������Ϣ
		hdc = GetDC(hWnd);
		InvalidateRect(hWnd, NULL, false);
		switch (wParam)
		{
		case VK_LEFT:
			curPosX--;
			if (CheckValide(curPosX, curPosY, bCurTeris) != 1)
			{
				curPosX++;// ���ѵ�����߽磬��������
			}
			break;
		case VK_RIGHT:
			curPosX++;
			if (CheckValide(curPosX, curPosY, bCurTeris) != 1)
			{
				curPosX--;// ���ѵ����ұ߽磬��������
			}
			break;
		case VK_UP:
			RotateTeris(bCurTeris);// ������ת����ש�麯��
			break;
		case VK_DOWN:// ���������ٶ�
			if (g_speed == t_speed)
				g_speed = 10;
			else
				g_speed = t_speed;
			//outPutBoxInt(g_speed);
			break;
		case 'W'://ͬ VK_UP
			RotateTeris(bCurTeris);
			break;
		case 'A'://ͬ VK_LEFT
			curPosX--;
			if (CheckValide(curPosX, curPosY, bCurTeris) != 1)
			{
				curPosX++;
			}
			break;
		case 'D'://ͬ VK_RIGHT
			curPosX++;
			if (CheckValide(curPosX, curPosY, bCurTeris) != 1)
			{
				curPosX--;
			}
			break;

		case 'S'://ͬ VK_DOWN
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
		DrawBackGround(hdc);// ��Ϸ�������
		EndPaint(hWnd, &ps);// �������
		break;
	case WM_DESTROY:// ��������
		PostQuitMessage(0);
		break;
	default:
		//��������ȱʡ�Ĵ��ڹ�����ΪӦ�ó���û�д�����κδ�����Ϣ�ṩȱʡ�Ĵ����ú���ȷ��ÿһ����Ϣ�õ�����
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// �����ڡ������Ϣ�������
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
			EndDialog(hDlg, LOWORD(wParam));//�ú������һ��ģ̬�Ի���,��ʹϵͳ��ֹ�ԶԻ�����κδ���
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

void drawBlocked(HDC mdc)//���Ƶ�ǰ�Ѿ�����ש�������
{
	int i, j;
	//����i, j��Ϊ�������
	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 0));// ������ɫ��ˢ���

	SelectObject(mdc, hBrush);// �ѻ�ɫ��ˢѡ�뵽�Ѵ���ש���������������

	for (i = 0; i<NUM_Y; i++)
	{
		for (j = 0; j<NUM_X; j++)
		{
			if (g_hasBlocked[i][j])
			{
				Rectangle(mdc, BORDER_X + j*BLOCK_SIZE, BORDER_Y + i*BLOCK_SIZE,
					BORDER_X + (j + 1)*BLOCK_SIZE, BORDER_Y + (i + 1)*BLOCK_SIZE
				);//���������Ϳɫ
			}
		}
	}
	DeleteObject(hBrush);// ɾ�����
}

int CheckValide(int startX, int startY, BOOL bTemp[4][4])//����һ�����󣬲鿴�Ƿ�Ϸ�
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
	//MessageBox(NULL,L"����",L"as",MB_OK);
	//outPutBoxInt(curPosY);
	return 1;
}

void checkComplite()//�鿴һ���Ƿ�����ȥ
{
	int i, j, k, count = 0;
	for (i = 0; i<NUM_Y; i++)
	{
		bool flag = true;
		for (j = 0; j<NUM_X; j++)
		{
			if (!g_hasBlocked[i][j])
			{
				flag = false;//��һ��Ϊ��ʱ��������ȥ
			}
		}
		if (flag)
		{
			count++;
			for (j = i; j >= 1; j--)//�������°�ÿ������
			{
				for (k = 0; k<NUM_X; k++)
				{
					g_hasBlocked[j][k] = g_hasBlocked[j - 1][k];
				}

			}
			drawCompleteParticle(i);// ����һ������
			Sleep(300);//��ͣ300ms

			PlaySound(_T("coin.wav"), NULL, SND_FILENAME | SND_ASYNC);//��ȥһ��ʱ����ϵͳ�Դ���ʾ��
		}
	}
	GAME_SCORE += int(count*1.5);//����+1�֣�����+3�֣�����+4�֣�����6�֣��Դ�����
}

VOID outPutBoxInt(int num)//�Զ���ĵ�������  ���ڵ��ԣ��Ѿ���ע�͵���
{
	TCHAR szBuf[1024];
	LPCTSTR str = TEXT("%d");
	wsprintf(szBuf, str, num);// ����ֵ���뵽������
	MessageBox(NULL, szBuf, L"aasa", MB_OK);// ��Ϣ����
}

VOID outPutBoxString(TCHAR str[1024])//�Զ���ĵ�������  ���ڵ��ԣ��Ѿ���ע�͵���
{
	TCHAR szBuf[1024];
	LPCTSTR cstr = TEXT("%s");
	wsprintf(szBuf, cstr, str);
	MessageBox(NULL, szBuf, L"aasa", MB_OK);
}



//�������������״
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

//��Ϸ��ʼ��
void init_game()
{
	GAME_SCORE = 0;
	setRandomT();// �������ש��
	curPosX = (NUM_X - 4) >> 1;//���ó�ʼ����
	curPosY = 0;
	//memset���Ǽ���������еĺ����������ǽ�s��ָ���ĳһ���ڴ��е�ÿ���ֽڵ�����ȫ������Ϊchָ����ASCIIֵ�����������
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

void fillBlock()//����ײ���������
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
		{//��ת�Ƕ�
			//bNewTeris[x][y] = bTeris[3 - y][x];
			//��ʱ�룺
			bNewTeris[x][y] = bTeris[y][3-x];
		}
	}
	if (CheckValide(curPosX, curPosY, bNewTeris) == 1)
	{
		memcpy(bTeris, bNewTeris, sizeof(bNewTeris));//�ɹ��򽫱任�����״����
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
	HPEN hPen = (HPEN)GetStockObject(BLACK_PEN);// ��ȡ��ɫ������Ϣ
	HBRUSH hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
	SelectObject(mdc, hPen);//SelectObject�Ǽ����������Ժ������ú���ѡ��һ����ָ�����豸�����Ļ����У��¶����滻��ǰ����ͬ���͵Ķ���
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

VOID DrawBackGround(HDC hdc)//���Ʊ���
{

	HBRUSH hBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
	//������֧�ֹ�դ�������豸��Ӧ�ó������ͨ������GetDeviceCaps������ȷ��һ���豸�Ƿ�֧����Щ����
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

void drawNext(HDC hdc)//������һ����Ҫ����ķ���
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
	HFONT hFont = CreateFont(30, 0, 0, 0, FW_THIN, 0, 0, 0, UNICODE, 0, 0, 0, 0, L"΢���ź�");
	SelectObject(hdc, hFont);
	SetBkMode(hdc, TRANSPARENT);
	SetBkColor(hdc, RGB(255, 255, 0));
	SetTextColor(hdc, RGB(152, 206, 0));
	RECT rect;
	rect.left = rc_right_top.left + 40;
	rect.top = rc_right_top.bottom - 150;
	rect.right = rc_right_top.right;
	rect.bottom = rc_right_top.bottom;
	DrawTextW(hdc, TEXT("��һ��"), _tcslen(TEXT("��һ��")), &rect, 0);
	DeleteObject(hFont);
	DeleteObject(hBrush);
}

void drawScore(HDC hdc)
{
	HFONT hFont = CreateFont(30, 0, 0, 0, FW_THIN, 0, 0, 0, UNICODE, 0, 0, 0, 0, L"΢���ź�");
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
	LPCTSTR cstr = TEXT("��ǰ�Ѷȣ�%d");
	wsprintf(szBuf, cstr, GAME_DIFF);
	DrawTextW(hdc, szBuf, _tcslen(szBuf), &rect, DT_CENTER | DT_VCENTER);

	RECT rect2;
	rect2.left = rc_right_bottom.left;
	rect2.top = rc_right_bottom.bottom / 2 + 100;
	rect2.right = rc_right_bottom.right;
	rect2.bottom = rc_right_bottom.bottom;
	TCHAR szBuf2[30];
	LPCTSTR cstr2 = TEXT("�÷֣�%d");
	wsprintf(szBuf2, cstr2, GAME_SCORE);
	//outPutBoxInt(sizeof(szBuf));
	SetTextColor(hdc, RGB(15, 0, 150));
	DrawTextW(hdc, szBuf2, _tcslen(szBuf2), &rect2, DT_CENTER | DT_VCENTER);

	DeleteObject(hFont);
}

int selectDiffculty(HWND hWnd, int diff)
{
	TCHAR szBuf2[30];
	LPCTSTR cstr2 = TEXT("ȷ��ѡ���Ѷ� %d ��");
	wsprintf(szBuf2, cstr2, diff);
	if (MessageBox(hWnd, szBuf2, L"�Ѷ�ѡ��", MB_YESNO) == IDYES)
	{
		GAME_DIFF = diff;
		InvalidateRect(hWnd, &rc_right_bottom, false);
		GAME_STATE |= 2;
		init_game();
		return GAME_DIFF;
	}
	return -1;
}

int selectLayOut(HWND hWnd, int layout)//ѡ�񲼾�
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