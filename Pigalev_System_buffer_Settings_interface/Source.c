#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

int main()
{
	char color = '0'; // ���� ������
	char colorBackground = '0'; // ���� ����	
	HKEY hKey = NULL;
	if (RegOpenKeyW(HKEY_CURRENT_USER, NULL, &hKey) != ERROR_SUCCESS)
	{
		MessageBox(NULL, L"� ������ ��������� �������� ��������", L"����������", MB_OK);
		return 0;
	}

	HKEY tmp = NULL;
	if (RegOpenKeyW(hKey, L"MyKey", &tmp) == ERROR_SUCCESS)
	{
		MessageBox(NULL, L"���� ������� ������", L"����������", MB_OK);
		LPDWORD DataType = NULL;
		LPDWORD Datalen = 512;
		LPWSTR StrValue = malloc(512);
		char* cT = calloc(100, 1);
		char* cB = calloc(100, 1);
		cB = "0";
		if (RegGetValueW(hKey, L"MyKey", L"Color", RRF_RT_ANY, &DataType, StrValue, &Datalen) == ERROR_SUCCESS)
		{
			char* changeColor = calloc(100, 1);
			color = StrValue[0];
			sprintf(changeColor, "color %c%c", colorBackground, color);
			system(changeColor);
		}
		LPDWORD DataType1 = NULL;
		LPDWORD Datalen1 = 512;
		LPWSTR StrValue1 = malloc(512);
		if (RegGetValueW(hKey, L"MyKey", L"ColorBackground", RRF_RT_ANY, &DataType1, StrValue1, &Datalen1) == ERROR_SUCCESS)
		{
			char* changeColor = calloc(100, 1);
			colorBackground = StrValue1[0];
			sprintf(changeColor, "color %c%c", colorBackground, color);
			system(changeColor);
		}
		LPDWORD DataType3 = NULL;
		LPDWORD Datalen3 = 512;
		LPWSTR StrValue3 = malloc(512);
		if (RegGetValueW(hKey, L"MyKey", L"type", RRF_RT_ANY, &DataType3, StrValue3, &Datalen3) == ERROR_SUCCESS)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_FONT_INFOEX fontInfo;
			fontInfo.cbSize = sizeof(fontInfo);
			GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
			wcscpy(fontInfo.FaceName, StrValue3);
			SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
		}
		LPDWORD DataType2 = 0;
		LPDWORD Datalen2 = 512;
		DWORD DwordValue = 0;
		if (RegGetValueW(hKey, L"MyKey", L"razmer", RRF_RT_ANY, &DataType2, &DwordValue, &Datalen2) == ERROR_SUCCESS)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_FONT_INFOEX fontInfo;
			fontInfo.cbSize = sizeof(fontInfo);
			GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
			fontInfo.dwFontSize.Y = DwordValue;
			SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
		}
	}
	else
	{
		if (RegCreateKey(hKey, L"MyKey", &tmp) == ERROR_SUCCESS)
		{
			MessageBox(NULL, L"���� ������� ������", L"����������", MB_OK);
		}
	}

	while (1)
	{
		system("chcp 1251>null");
		printf("�������� ��� �� ������ �������:\n");
		printf("1 - ������ ������\n");
		printf("2 - ���� ������\n");
		printf("3 - ���� ����\n");
		printf("4 - ��� ������\n");
		printf("5 - ��������� �� ���������\n");

		int a = 0;
		scanf("%d", &a);

		if (a == 1) // ��������� ������� ������
		{
			system("cls");
			int razm;
			printf("������� ������ ������: ");
			scanf_s("%d", &razm);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_FONT_INFOEX fontInfo;
			fontInfo.cbSize = sizeof(fontInfo);
			GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
			fontInfo.dwFontSize.Y = razm;
			SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
			if (RegSetValueExA(tmp, "razmer", NULL, REG_DWORD, &razm, 4) != ERROR_SUCCESS)
			{
				MessageBoxA(NULL, "��� ������ ������� ������ � ������ �������� ������", "����������", MB_OK);
			}
			system("cls");
		}
		else if (a == 2) // ��������� ����� ������
		{
			system("cls");
			printf("0 - ������\n1 - �����\n2 - �������\n3 - ���������\n4 - �������\n5 - ���������\n6 - ������\n7 - �����\n8 - �����\n9 - ������ - �����\nA - ������ - �������\nB - ������ - �������\nC - ������ - �������\nD - ������ - ����������\nE - ������ - ������\nF - ������� �����\n");
			printf("������� ������ ��� ����� ����� ������: ");
			scanf_s(" %c", &color);
			char* changeColor = calloc(100, 1);
			sprintf(changeColor, "color %c%c", colorBackground, color);
			system(changeColor);
			LPSTR str = calloc(100, 1);
			sprintf(str, "%c", color);
			DWORD StrParamLen = wcslen(str);
			if (RegSetValueExA(tmp, "Color", NULL, REG_SZ, str, StrParamLen * sizeof(WCHAR)) != ERROR_SUCCESS)
			{
				MessageBoxA(NULL, "��� ������ ����� ������ � ������ �������� ������", "����������", MB_OK);
			}
			system("cls");
		}
		else if (a == 3) // ��������� ����� ����
		{
			system("cls");
			printf("0 - ������\n1 - �����\n2 - �������\n3 - ���������\n4 - �������\n5 - ���������\n6 - ������\n7 - �����\n8 - �����\n9 - ������ - �����\nA - ������ - �������\nB - ������ - �������\nC - ������ - �������\nD - ������ - ����������\nE - ������ - ������\nF - ������� �����\n");
			printf("������� ������ ��� ����� ����� ����: ");
			scanf_s(" %c", &colorBackground);
			char* changeColorBackground = calloc(100, 1);
			sprintf(changeColorBackground, "color %c%c", colorBackground, color);
			system(changeColorBackground);
			LPSTR str1 = calloc(100, 1);
			sprintf(str1, "%c", colorBackground);
			DWORD StrParamLen1 = wcslen(str1);
			if (RegSetValueExA(tmp, "ColorBackground", NULL, REG_SZ, str1, StrParamLen1 * sizeof(WCHAR)) != ERROR_SUCCESS)
			{
				MessageBoxA(NULL, "��� ������ ����� ���� � ������ �������� ������", "����������", MB_OK);
			}
			system("cls");
		}
		else if (a == 4) // ��������� ���� ������
		{
			system("cls");
			scanf_s(" ");
			printf("������� ��� ������: ");
			char* strType = calloc(200, 1);
			gets(strType);
			if (RegSetValueExA(tmp, "type", NULL, REG_SZ, strType, strlen(strType) * sizeof(WCHAR)) != ERROR_SUCCESS)
			{
				MessageBoxA(NULL, "��� ������ ���� ������ � ������ �������� ������", "����������", MB_OK);
			}
			LPDWORD DataType5 = NULL;
			LPDWORD Datalen5 = 512;
			LPWSTR StrValue5 = malloc(512);
			if (RegGetValueW(hKey, L"MyKey", L"type", RRF_RT_ANY, &DataType5, StrValue5, &Datalen5) == ERROR_SUCCESS)
			{
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				CONSOLE_FONT_INFOEX fontInfo;
				fontInfo.cbSize = sizeof(fontInfo);
				GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
				wcscpy(fontInfo.FaceName, StrValue5);
				SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
			}
			LPDWORD DataType2 = 0;
			LPDWORD Datalen2 = 512;
			DWORD DwordValue = 0;
			if (RegGetValueW(hKey, L"MyKey", L"razmer", RRF_RT_ANY, &DataType2, &DwordValue, &Datalen2) == ERROR_SUCCESS)
			{
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				CONSOLE_FONT_INFOEX fontInfo;
				fontInfo.cbSize = sizeof(fontInfo);
				GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
				fontInfo.dwFontSize.Y = DwordValue;
				SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
			}
			system("cls");
		}
		else if (a == 5) // ����������� ���������
		{
			DWORD razmer = 16;
			system("color 07");
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_FONT_INFOEX fontInfo;
			fontInfo.cbSize = sizeof(fontInfo);
			GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
			wcscpy(fontInfo.FaceName, L"Consolas");
			fontInfo.dwFontSize.Y = 16;
			SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
			system("cls");
			if (RegSetValueExA(tmp, "Color", NULL, REG_SZ, "7", 1 * sizeof(WCHAR)) != ERROR_SUCCESS)
			{
				MessageBoxA(NULL, "��� ������ ����� ������ � ������ �������� ������", "����������", MB_OK);
			}
			if (RegSetValueExA(tmp, "ColorBackground", NULL, REG_SZ, "0", 1 * sizeof(WCHAR)) != ERROR_SUCCESS)
			{
				MessageBoxA(NULL, "��� ������ ����� ���� � ������ �������� ������", "����������", MB_OK);
			}
			if (RegSetValueExA(tmp, "razmer", NULL, REG_DWORD, &razmer, 4) != ERROR_SUCCESS)
			{
				MessageBoxA(NULL, "��� ������ ������� ������ � ������ �������� ������", "����������", MB_OK);
			}
			if (RegSetValueExA(tmp, "type", NULL, REG_SZ, "Consolas", 9 * sizeof(WCHAR)) != ERROR_SUCCESS)
			{
				MessageBoxA(NULL, "��� ������ ���� ������ � ������ �������� ������", "����������", MB_OK);
			}
		}
		else
		{
			break;
		}
	}
}