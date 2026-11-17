#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void task258();
void task265();
void task4();
void task41();
void task102();
void task193();
void task40();
void task209();
void task146();
void task137();

int main() {
	int K = 16;

	printf("Мої завдання: ");

	for (int N = 1; N < 11; N++) {
		int num = (N * N * N + K * K) % 280 + 1;
		printf("%d", num);

		if (N < 10) {
			printf(", ");
		}
		else {
			printf(".");
		}
	}

	task258();
	task265();
	task4();
	task41();
	task102();
	task193();
	task40();
	task209();
	task146();
	task137();

	return 0;
}

void task258() {
	printf("\n\nЗавдання 258: ");
	int x[] = { -5, -4, -3, -2, 0, 4, 7, 10 };
	int i = 0, a = 2, b = 4;

	while (i < 8) {
		if (1 + 2 * pow(cos(x[i] * x[i]), 3) < 0 || 4 * a * x[i] - b == 0) {
			printf("\nПри х = %d функція не має значень.", x[i]);
			i++;
		}
		else {
			double y = 3.2 * a * b * x[i] * x[i] - (5 * a * sqrt(1 + 2 * pow(cos(x[i] * x[i]), 3)) / (4 * a * x[i] - b));
			printf("\nПри х = %d функція має значення %.3f", x[i], y);
			i++;
		}
	}
}

void task265() {
	printf("\n\nЗавдання 265: ");
	double a = 3, b = 0.2, y;

	for (double x = -5.0; x <= 5.0; x += 0.5) {
		if (5 - 2 * pow(sin(4 * x), 3) < 0 || 0.3 * pow(tan(x), 3) == 2) {
			printf("\nПри х = %.1f функція не має значень.", x);
		}
		else {
			y = 2.05 * a * x * x - (3 * b * sqrt(5 - 2 * pow(sin(4 * x), 3))) / fabs(0.3 * pow(tan(x), 3) - 2);
			printf("\nПри х = %.1f функція приймає значення: %.2f", x, y);
		}
	}
}

void task4() {
	printf("\n\nЗавдання 4: Перевірити, чи існують натуральні числа a < 100, які мають такі властивості: а) а % 3 = 1; б) а % 4 = 2; в) а % 5 = 3; г) а % 6 = 4.");
	int count_a = 0, count_b = 0, count_c = 0, count_d = 0;
	for (int i = 1; i < 100; i++) {
		if (i % 3 == 1) {
			count_a++;
		}
		if (i % 4 == 2) {
			count_b++;
		}
		if (i % 5 == 3) {
			count_c++;
		}
		if (i % 6 == 4) {
			count_d++;
		}
	}
	if (count_a > 0) {
		printf("\nа) існують, всього таких чисел %d", count_a);
	}
	else {
		printf("\nа) таких чисел не існує");
	}
	if (count_b > 0) {
		printf("\nб) існують, всього таких чисел %d", count_b);
	}
	else {
		printf("\nб) таких чисел не існує");
	}
	if (count_c > 0) {
		printf("\nв) існують, всього таких чисел %d", count_c);
	}
	else {
		printf("\nв) таких чисел не існує");
	}
	if (count_d > 0) {
		printf("\nг) існують, всього таких чисел %d", count_d);
	}
	else {
		printf("г) таких чисел не існує");
	}
}

void task41() {
	printf("\n\nЗавдання 41: Дано натуральне число n. Обчислити b = 2 * 4 * 6 ... (2n)");
	int n; 
	unsigned long long b = 1;
	printf("\nВведіть натуральне значення для n: ");
	scanf_s("%d", &n);
	if (n < 1) {
		printf("\nВи ввели некорректне значення n.");
	}
	else {
		for (int i = 1; i < (n + 1); i++) {
			b *= 2 * i;
		}
		printf("При n = %d b = %llu", n, b);
	}
}

void task102() {
	printf("\n\nЗавдання 102: В області n районів. Відомі кількість жителів(у тис. чол.) та площа(в км^2) кожного району. Визначити середню щільність населення в області в цілому");
	int population[] = { 150, 30, 75, 89, 42, 69, 52, 500, 205, 100 };
	int area[] = { 100, 200, 300, 400, 150, 250, 95, 25, 48, 500 }, n;
	printf("\nВведіть кількість райноів(до 10): ");
	scanf_s("%d", &n);
	if (n > 10 || n < 1) {
		printf("Ви ввели некорректне значення");
	}
	else {
		double population_all = 0, area_all = 0;
		for (int i = 0; i < n; i++) {
			population_all += population[i];
			area_all += area[i];
		}
		double a = population_all / area_all;
		printf("Середня щільність населення %.2f.", a);
	}
}

void task193() {
	printf("\n\nЗавдання 193: З'ясувати, чи є задане число m членом геометричної прогресії, перший член якої дорівнює g, а знаменник - c.");
	double m, g, c;

	printf("\nВведіть число m: ");
	scanf_s("%lf", &m);

	printf("Введіть перший член прогресії g: ");
	scanf_s("%lf", &g);

	printf("Введіть знаменник с: ");
	scanf_s("%lf", &c);

	if (fabs(g - m) < 0.001) {
		printf("Число %.2f є членом прогресії.", m);
	}
	
	else if ((fabs(g) < fabs(m) && fabs(c) > 1 || fabs(g) > fabs(m) && fabs(c) < 1) && c != 0) {
		while (fabs(g) < fabs(m)) {
			g *= c;
		}
		while (fabs(g) > fabs(m)) {
			g *= c;
		}
		if (fabs(g - m) < 0.001) {
			printf("Число %.2f є членом прогресії.", m);
		}
		else {
			printf("Число %.2f не є членом прогресії.", m);
		}
	}
	else {
		printf("Число %.2f не є членом прогресії.", m);
	}
}

void task40() {
	printf("\n\nЗавдання 40: дано натуральне число n. Обчислити b = 1 * 3 * 5 ... (2n - 1)");
	int n;
	unsigned long long b = 1;
	printf("\nВведіть натуральне значення для n: ");
	scanf_s("%d", &n);
	if (n < 1) {
		printf("\nВи ввели некорректне значення n.");
	}
	else {
		for (int i = 1; i < (n + 1); i++) {
			b *= 2 * i - 1;
		}
		printf("При n = %d b = %llu", n, b);
	}
}

void task209() {
	printf("\n\nЗавдання 209: a(n) = 2^n / (n - 1)!");
	int n;

	printf("\nВведіть натуральне значення аргументу n: ");
	scanf_s("%d", &n);
	if (n > 0) {
		unsigned long long a = 1;
		for (int i = 1; i < n; i++) {
			a *= i;
		}
		double b = pow(2, n) / (a);
		printf("a(%d) = 2^%d / (%d - 1)! = %.2f", n, n, n, b);
	}
	else {
		printf("Ви ввели ненатуральне значення.");
	}
}

void task146() {
	printf("\n\nЗавдання146: Математик Християн Гольдбах висунув гіпотезу у тому, що будь-яке парне число, більше 2, представимо як суми двох простих чисел. Перевірте цю гіпотезу Гольдбаха всім парних чисел, які не перевищують число 50.");
	int primeNum[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
	int sum = 0;

	for (int n = 4; n < 51; n += 2) {
		int found = 0;
		for (int i = 0; i < 15; i++) {
			for (int a = 0; a < 15; a++) {
				if (primeNum[i] + primeNum[a] == n) {
					found = 1;
				}
			}
		}
		if (found == 1) {
			sum++;
		}
	}
	if (sum == 24) {
		printf("\nГіпотеза виконується для парних чисел від 4 до 50");
	}
	else {
		printf("\nГіпотеза виконується не для всіх парних чисел від 4 до 50, або взагалі не виконується");
	}
}

void task137() {
	printf("\n\nЗавдання 137: Знайдіть усі трицифрові натуральні числа, рівні сумі кубів своїх цифр\n");
	for (int i = 100; i < 1000; i++) {
		int a, b, c;
		a = i / 100;
		b = (i / 10) % 10;
		c = i % 10;
		int d = pow(a, 3) + pow(b, 3) + pow(c, 3);
		if(d == i) {
			printf("%d, ", d);
		}
	}
}