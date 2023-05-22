#include <stdio.h>
#include <locale.h>
#include "functions.h"

int main() {
	setlocale(LC_ALL, "Rus");

	int n = 50;
	while (1) {
		clear();
		intro();
		printf("1- контрольный расчет для n точек\
			  \n2- запись данных в файл\
			  \n3- изменить количество точек n = %d\
			  \n4- выйти из программы\n\nВведите команду: ", n);
		int sel;
		scanf("%d", &sel);
		clear();

		switch(sel) {
		case 1:
			form_tabl(n);
			enter();
			break;

		case 2:
			write_file(n);
			break;

		case 3:
			printf("Введите количество точек n: ");
			scanf("%d", &n);
			break;

		case 4:
			return 0;
		}
	}
}
