#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

int main()
{
	char color = '0'; // Цвет шрифта
	char colorBackground = '0'; // Цвет фона

	HKEY hKey = NULL;
	if (RegOpenKeyW(HKEY_CURRENT_USER, NULL, &hKey) != ERROR_SUCCESS)
	{
		MessageBox(NULL, L"В работе программы возникла проблема", L"Информация", MB_OK);
		return 0;
	}

	HKEY tmp = NULL;
	if (RegOpenKeyW(hKey, L"MyKey", &tmp) == ERROR_SUCCESS)
	{
		MessageBox(NULL, L"Ключ успешно открыт", L"Информация", MB_OK);
		LPDWORD DataType = NULL;
		LPDWORD Datalen = 512;
		LPWSTR StrValue = malloc(512);
		char* cT = calloc(100, 1);
		char* cB = calloc(100, 1);
		cB = "0";
		if (RegGetValueW(hKey, L"MyKey", L"Color", RRF_RT_ANY, &DataType, StrValue, &Datalen) == ERROR_SUCCESS)
		{
			char* changeColor = calloc(100, 1);
			//(color, StrValue[0]);
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
	}
	else
	{
		if (RegCreateKey(hKey, L"MyKey", &tmp) == ERROR_SUCCESS)
		{
			MessageBox(NULL, L"Ключ успешно создан", L"Информация", MB_OK);
		}
	}

	while (1)
	{
		system("chcp 1251>null");
		printf("Выбирите что вы хотите сменить:\n");
		printf("1 - размер шрифта\n");
		printf("2 - цвет шрифта\n");
		printf("3 - цвет фона\n");
		printf("4 - тип шрифта\n");
		printf("5 - настройки по умолчанию\n");

		int a = 0;
		scanf("%d", &a);
		switch (a)
		{
		case(1):

			break;
		case(2):
			// Изменение цвета шрифта
			system("cls");
			printf("0 - Черный\n1 - Синий\n2 - Зеленый\n3 - Аквамарин\n4 - Красный\n5 - Сиреневый\n6 - Желтый\n7 - Белый\n8 - Серый\n9 - Светло - синий\nA - светло - зеленый\nB - Светло - голубой\nC - Светло - красный\nD - Светло - фиолетовый\nE - Светло - желтый\nF - Светлое белое\n");
			printf("Введите символ для смена цвета шрифта: ");
			scanf_s(" %c", &color);
			char* changeColor = calloc(100, 1);
			sprintf(changeColor, "color %c%c", colorBackground, color);
			system(changeColor);
			LPSTR str = calloc(100, 1);
			sprintf(str, "%c", color);
			DWORD StrParamLen = wcslen(str);
			if (RegSetValueExA(tmp, "Color", NULL, REG_SZ, str, StrParamLen * sizeof(WCHAR)) != ERROR_SUCCESS)
			{
				MessageBoxA(NULL, "При записи цвета шрифта в реестр возникла ошибка", "Информация", MB_OK);
			}
			system("cls");
			break;
		case(3):
			// Изменение цвета фона
			system("cls");
			printf("0 - Черный\n1 - Синий\n2 - Зеленый\n3 - Аквамарин\n4 - Красный\n5 - Сиреневый\n6 - Желтый\n7 - Белый\n8 - Серый\n9 - Светло - синий\nA - светло - зеленый\nB - Светло - голубой\nC - Светло - красный\nD - Светло - фиолетовый\nE - Светло - желтый\nF - Светлое белое\n");
			printf("Введите символ для смена цвета фона: ");
			scanf_s(" %c", &colorBackground);
			char* changeColorBackground = calloc(100, 1);
			sprintf(changeColorBackground, "color %c%c", colorBackground, color);
			system(changeColorBackground);
			LPSTR str1 = calloc(100, 1);
			sprintf(str1, "%c", colorBackground);
			DWORD StrParamLen1 = wcslen(str1);
			if (RegSetValueExA(tmp, "ColorBackground", NULL, REG_SZ, str1, StrParamLen1 * sizeof(WCHAR)) != ERROR_SUCCESS)
			{
				MessageBoxA(NULL, "При записи цвета фона в реестр возникла ошибка", "Информация", MB_OK);
			}
			system("cls");
			break;
		case(4):
			
			break;
		case(5):
			system("color 07");
			system("cls");
			if (RegSetValueExA(tmp, "Color", NULL, REG_SZ, "7", 1 * sizeof(WCHAR)) != ERROR_SUCCESS)
			{
				MessageBoxA(NULL, "При записи цвета шрифта в реестр возникла ошибка", "Информация", MB_OK);
			}
			if (RegSetValueExA(tmp, "ColorBackground", NULL, REG_SZ, "0", 1 * sizeof(WCHAR)) != ERROR_SUCCESS)
			{
				MessageBoxA(NULL, "При записи цвета фона в реестр возникла ошибка", "Информация", MB_OK);
			}
			break;
		default:
			return 0;
			break;
		}
	}
}