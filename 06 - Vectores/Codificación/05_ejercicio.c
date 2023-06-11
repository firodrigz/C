/*Una empresa debe registrar los pedidos recibidos de cada uno de sus 10 productos a lo largo del d�a. Por
cada pedido se recibe:
- C�digo de producto (de 1 a 10)
- Cantidad de unidades solicitadas
Se puede recibir m�s de un pedido por producto.
La carga finaliza cuando se ingresa un producto con c�digo igual a cero.
Al finalizar se debe emitir un listado con c�digo y cantidad de unidades solicitadas de cada producto.*/

#include <stdio.h>
#include <locale.h>
#define TAM 10

//Prototipo de funciones
int validar(int, int);
int mostrar(int[], int);

//main
int main()
{
	int cantidad[TAM] = {0};
	int codProducto, unidades;
	int i = 1;
	
	setlocale(LC_ALL, "spanish");
	
	printf("PEDIDO Nro %d, INGRESO DE C�DIGO\n", i);
	codProducto = validar(0, TAM);
	
	while(codProducto != 0)
	{
		i++;
		
		printf("\nINGRESO DE CANTIDAD\n");
		unidades = validar(0, 9999999);
		cantidad[codProducto - 1] += unidades;
		
		printf("\nPEDIDO Nro %d, INGRESO DE C�DIGO\n", i);
		codProducto = validar(0, TAM);
	}
	
	if(i == 1)
		printf("No se ingres� ning�n pedido durante el d�a");
	else
		mostrar(cantidad, TAM);
	
	return 0;
}

//Definici�n de funciones

int validar(int LI, int LS)
{
	int band = 0;
	int nro;
	
	do
	{
		if(band == 1)
			printf("\nError, valor fuera de rango, vuelva a intentarlo\n\n");
			
		printf("Ingrese un valor: ");
		
		scanf("%d", &nro);
		
		band = 1;
	} while(nro < LI || nro > LS);
	
	return nro;
	
}

int mostrar(int v[],int ce)
{
	int i;
	
	printf("Muestra del vector");
	for(i = 0; i < ce; i++)
		printf("\n%4d", v[i]);
	
}
