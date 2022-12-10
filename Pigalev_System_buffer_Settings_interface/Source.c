#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

int main()
{
	system("chcp 1251>null");

	// Изменение цвета
	char* color = calloc(1, 1);
	printf("Введите символ для смена цвета шрифта: ");
	gets(color);
	char* changeColor = calloc(100, 1);
	sprintf(changeColor, "color %s", color);
	system(changeColor);
	printf("Проверка связи");
	return 0;
}