#include "stdio.h"
#include "stdlib.h"
#include "math.h"


float function(float x)
{
	return x * x * x - 7 * x * x + 14 * x - 6;
}

float bisection(float A, float B, float tol)
{
	printf("\t\t    Range [%f,%f] | Tol %f\n\n", A, B, tol);
	float values[100][5];

	float AA, P, PP, BB;

	int i, k;

	for (i = 1; i <= 100; i++)
	{
		P = (A + B) / 2; 
		AA = function(A); 
		PP = function(P);
		values[i - 1][0] = A; 
		values[i - 1][1] = B; 
		values[i - 1][2] = P; 
		values[i - 1][3] = PP; 

		if (AA * PP < 0) 
			B = P; 
		else
			A = P; 

		values[i - 1][4] = B - A;
	}

	printf("ID\t   An\t\t   Bn\t\t   Pn\t\t  F(Pn)\t\t  TOL\n\n");
	for (k = 0; k < i - 1; k++) 
	{
		if (values[k][4] < tol) {
			printf("\n  Root of function is %f\n", values[k][2]);
			break;
		}
		printf("%d\t%f\t%f\t%f\t%f\t%f\n", k + 1, values[k][0], values[k][1], values[k][2], values[k][3], values[k][4]);
	}

	return 0.0;
}

int main()
{
	printf("\a\n\t\t\t\tBisection Method\n");
	bisection(0, 1, 0.000001);
	return 0;
}