/*Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes
de sus productos. Para ello primeramente se ingresan la información de los productos formados por:
• Código (5 caracteres).
• Precio (real).
• Descripción (30 caracteres).
• Cantidad de unidades vendidas (al mes anterior, entero).
• Importe Total Vendido (al mes anterior, real).
Se sabe que la empresa no vende más de 50 productos. El ingreso de la carga de productos finaliza con un
producto con descripción “FIN”.
Luego ingresan las ventas del mes:
• Código de Producto (5 caracteres).
• Cantidad pedida.
El ingreso de datos de las ventas finaliza con una cantidad igual a 0. Se solicita:
a. Actualizar la información de los productos con las ventas realizadas en el mes.
b. Al finalizar, mostrar el listado de productos actualizado*/

#include <stdio.h>
#include <string.h>

struct neumaticos{
	char codigo[6];
	float precio;
	char desc[31];
	int cantVendidas;
	float importeTotal;
};

int buscarCodigo (struct neumaticos[], char [], int);
int cargaProductos(struct neumaticos[], int);
int ventas(struct neumaticos[], int);
void mostrarListado(struct neumaticos[], int);

int main(){
	
	struct neumaticos neums[50];
	int ingresaProducto, ingresaVentas;
	
	ingresaProducto = cargaProductos(neums,50);
	if(ingresaProducto!=0){
		ingresaVentas= ventas(neums, 50);
		if(ingresaVentas!=0){
			mostrarListado(neums, ingresaProducto);
		}else{
			printf("No se realizaron ventas!");
		}
	}else{
		printf("No se ingresaron productos");
	}
		
	return 0;
}

int buscarCodigo (struct neumaticos neums[], char aBuscar[], int hasta){
	int encuentra=-1, i=0;
	
	while(encuentra==-1 && i<hasta){
		if(strcmpi(neums[i].codigo, aBuscar)==0){
			encuentra=i;
		}else{
			i++;
		}
	}
	
	return encuentra;
}

int cargaProductos(struct neumaticos neums[], int cantElementos){
	int i=0, pos;
	char aux[31];
	
	printf("Carga de productos");
	printf("\nIngrese descripción del producto (finaliza con FIN): ");
	fgets(aux, 31, stdin);
	aux[strlen(aux)-1]= '\0';
	
	while(i<cantElementos && strcmpi(aux,"FIN")!=0){
		strcpy(neums[i].desc, aux);
		do{
			printf("\nIngrese código del producto: ");
			fgets(neums[i].codigo,6,stdin);
			neums[i].codigo[strlen(neums[i].codigo)-1]='\0';
			pos = buscarCodigo(neums,neums[i].codigo,cantElementos);
			if(pos!=-1){
				printf("Código existente, intente nuevamente\n");
			}
			fflush(stdin); //porque paso de texto a nro;
		}while(pos!=-1);
		
		do{
			printf("\nIngrese precio del producto: ");
			scanf("%.2f", &neums[i].precio);
		}while(neums[i].precio < 0);
		
		do{
			printf("\nIngrese cantidad vendida: ");
			scanf("%d", &neums[i].cantVendidas);	
		}while(neums[i].cantVendidas < 0);
		
		do{
			printf("\nIngrese importe total: ");
			scanf("%.2f", &neums[i].importeTotal);
		}while(neums[i].importeTotal < 0);	
		
		
		i++;
		
		printf("\nIngrese descripción del producto (finaliza con FIN): ");
		fgets(aux, 31, stdin);
		aux[strlen(aux)-1]= '\0';
		
	}	
	
	return i;
}

int ventas(struct neumaticos neums[], int cantElementos){
	int i=0, cantPedidas, pos;
	char aux[6];
	
	do{
		printf("\nIngrese cantidad pedidas: ");
		scanf("%d", &cantPedidas);	
	}while(cantPedidas < 0);	
	
	while(cantPedidas != 0){
	
	 do{
			printf("\nIngrese código del producto: ");
			fgets(aux,6,stdin);
			aux[strlen(aux)-1]='\0';
			pos = buscarCodigo(neums,aux,cantElementos);
			if(pos==-1){
				printf("Código no existente, intente nuevamente\n");
			}
			fflush(stdin); //porque paso de texto a nro;
		}while(pos==-1);
		
		neums[pos].cantVendidas+=cantPedidas;
		i++;		
				
		do{
			printf("\nIngrese cantidad pedidas: ");
			scanf("%d", &cantPedidas);	
		}while(cantPedidas < 0);
	}
	
	return i;
}

void mostrarListado(struct neumaticos neums[], int cantElementos){
	int i;
	
	for(i=0; i<cantElementos; i++){
		printf("%d|%.2f\n", neums[i].cantVendidas )
	}
}
