#include <stdio.h>
#include <math.h>
#define N 1000

// Формирование массива времени t
void form_t(int n, float* t) {
	float tn = 0, tk = 2, dt;
	dt = (tk - tn) / (n-1);

	for (int i = 0; i < n; i++) {
	    t[i] = tn + i * dt;
	}
}

// Формирование массива Uvx
void form_Uvx(int n, float* Uvx, float* t) {
	float u0 = 5, u = 2;

	for (int i = 0; i < n; i++) {
		Uvx[i] = u0 - u * sin(t[i]);
	}
}

// Формирование массива Uvix
void form_Uvix(int n, float* Uvix, float* Uvx) {
	float a = 5, b = 0.5;

	for (int i = 0; i < n; i++) {
		Uvix[i] = a * exp(b * Uvx[i]);
	}
}

//Контрольный расчёт для n точек
void form_tabl(int n) {
	float t[N], Uvx[N], Uvix[N];

	form_t(n, t);
	form_Uvx(n, Uvx, t);
	form_Uvix(n, Uvix, Uvx);

	printf("№\tt\tUvx\tUvix\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t%6.3f\t%6.3f\t%6.3f\n", i+1, t[i], Uvx[i], Uvix[i]);
	}
}

//Запись данных в файл
void write_file(int n) {
	FILE *f1, *f2, *f3;
	float t[N], Uvx[N], Uvix[N];

	f1 = fopen("arr_t.txt", "w");
	f2 = fopen("arr_Uvx.txt", "w");
	f3 = fopen("arr_Uvix.txt", "w");

	form_t(n, t);
	form_Uvx(n, Uvx, t);
	form_Uvix(n, Uvix, Uvx);

	for (int i = 0; i < n; i++) {
		fprintf(f1, "%6.3f\n", t[i]);
		fprintf(f2, "%6.3f\n", Uvx[i]);
		fprintf(f3, "%6.3f\n", Uvix[i]);
	}

	fclose(f1);
	fclose(f2);
	fclose(f3);
}

//Заставка
void intro() {
	FILE *f = fopen("intro.txt","r");
	char ch;
	while (!feof(f)) {
		fscanf(f, "%c", &ch);
		printf("%c", ch);
	}
	fclose(f);
}

//Очистка консоли
void clear() {
	printf("\e[1;1H\e[2J");
}

//Ожидание ввода
void enter() {
	getchar();
	getchar();
}
