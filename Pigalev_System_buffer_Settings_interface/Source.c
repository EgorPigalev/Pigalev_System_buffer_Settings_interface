#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

int main()
{
	system("chcp 1251>null");

	// ��������� �����
	char* color = calloc(1, 1);
	printf("������� ������ ��� ����� ����� ������: ");
	gets(color);
	char* changeColor = calloc(100, 1);
	sprintf(changeColor, "color %s", color);
	system(changeColor);
	printf("�������� �����");
	return 0;
}