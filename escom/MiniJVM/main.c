#include <stdio.h>
#include <stdlib.h>

#define N 20
struct Pila
{
	float arreglo[N];
	int sp;
};
void inicializa_pila(struct Pila *p)
{
	int i;
	for (i = 0; i < N; i++)
		p->arreglo[i] = 0;
	p->sp = 3;
}
int pila_vacia(struct Pila *p)
{
	return p->sp == N - 1;
}
int pila_llena(struct Pila *p)
{
	return p->sp == -1;
}
int push(struct Pila *p, float valor)
{
	if (!pila_llena(p))
	{
		p->arreglo[p->sp] = valor;
		(p->sp)--;
		return 0;
	}
	else
		return -1;
}

int pop(struct Pila *p, float *valor)
{
	if (!pila_vacia(p))
	{
		(p->sp)++;
		*valor = p->arreglo[p->sp];
		p->arreglo[p->sp] = 0;
		return 0;
	}
	else
		return -1;
}

float CharToFloat(char *caracteres[])
{

	float num = 0;
	num = atof(caracteres);
	return num;
}

int main(int argc, char *argv[])
{
	printf("iniciando main\n");
	char *st1[] = {'5', '\0'};
	char *st2[] = {'8', '\0'};
	char *st3[] = {'+', '\0'};
	char *st4[] = {'1', '0', '\0'};
	char *st5[] = {'*', '\0'};
	char *st6[] = {'3', '\0'};
	char *st7[] = {'+', '\0'};

	char *instrucciones[7][3] = {{st1}, {st2}, {st3}, {'1', '0', '\0'}, {st5}, {st6}, {st7} , '\0'};
	printf("\nCadena: %s", &st4[0]);
	printf("\nCadena: %s", &st4[1]);

	printf("instrucciones cargadas\n");

	// no: printf("\nCadena: %s", &instrucciones[3]);
	printf("\nCadena: %s", *instrucciones[3]);

	printf("\nCadena: %s", instrucciones[4][0]);
	printf("\nCadena: %s", instrucciones[4][1]);

	printf("Se han cargado las instrucciones \n");
	struct Pila pila;

	inicializa_pila(&pila);
	printf("Se ha inicializado la pila \n");

	int longitud = sizeof(instrucciones) / sizeof(char *);
	int i;
	float A, B;
	for (i = 0; i < longitud; i++)
	{
		if (strcmp(instrucciones[i][0], "+") == 0)
		{
			printf("Hay una suma \n");
			pop(&pila, &A);
			printf("pop: %f \n", A);
			pop(&pila, &B);
			printf("pop: %f \n", B);
			push(&pila, (float)(A + B));
			printf("suma: %f \n", (A + B));
		}
		else if (strcmp(instrucciones[i][0], "*") == 0)
		{
			printf("Hay una multiplicacion \n");
			pop(&pila, &A);
			printf("pop: %f \n", A);
			pop(&pila, &B);
			printf("pop: %f \n", B);
			push(&pila, (int)(A + B));
			printf("suma: %f \n", (A * B));
		}
		else if (strcmp(instrucciones[i][0], "-") == 0)
		{
			printf("Hay una resta \n");
			/* code */
		}
		else if (strcmp(instrucciones[i][0], "/") == 0)
		{
			printf("Hay una división \n");
			/* code */
		}
		else
		{
			if (!pila_llena(&pila))
			{
				// int j;
				// char *cad[9];
				// for (j = 0; j < 10; j++)
				// {
				// 	printf("%s", &cad);
				// 	printf("%c", &instrucciones[i][j]);
				// 	strcat(&cad, &instrucciones[i][j]);
				// }
				
				int longitud = sizeof(*instrucciones) / sizeof(*instrucciones[i][0]);
				printf("Longitud arreglo: %i", longitud);
				push(&pila, CharToFloat(*instrucciones[i]));
				printf("Se ha agregado un numero a la pila: %f \n", CharToFloat(*instrucciones[i]));
			}
		}
	}
	return 0;
}
