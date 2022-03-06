#include "stdio.h"
#include "stdlib.h"
#include "math.h"

float func(float x) {
	return x * x * x - 7 * x * x + 14 * x - 6;
}

float dfunc(float x) {
	return (3 * x * x - 14 * x + 14);
}

float nr(float Azero, float tol) {
	printf("\a   [X0 = %f , TOL = %f]\n",Azero,tol);
	float values[50];
	values[0] = Azero;
	int i;
	for (i = 1; i < 50; i++) {
		float d = func(values[i - 1]) / dfunc(values[i - 1]);
		values[i] = values[i - 1] - d;
	}
	printf("\nId\tXn\t\tXn-Xn-1\n");
	for (int x = 1; x < 50; x++) {
		float a = values[x] - values[x - 1];
		printf("\n%i.\t%f\t%f", x, values[x], a);
		if (a < tol) {
			printf("\n\nRoot is %f\n", values[x]);
			break;
		}
	}
	return 0.0;
}

int main()
{
	printf("\a\n\tNewton-Raphson Method\n");
	nr(0, 0.000001);
	return 0;
}