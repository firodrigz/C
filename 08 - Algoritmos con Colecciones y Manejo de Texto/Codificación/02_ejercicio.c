/* Una empresa debe registrar los pedidos recibidos de cada uno sus 10 productos a lo largo del día. Cada
producto está identificado por un código de 4 cifras. Los códigos deben ingresarse al inicio del programa mediante
la función IngresaCódigos.
Por cada pedido se recibe:
• Código de producto
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
 La carga de pedidos finaliza cuando se ingresa un producto igual a 0
Al finalizar se debe:
a) Emitir un listado con código y cantidad de unidades solicitadas de cada producto.
b) El / los productos del cual se solicitaron mayor cantidad de unidades.
c) El / los productos del cual se solicitaron menos cantidad de unidades.
*/

#include <stdio.h>
#include <locale.h>
#define TAM 10

// vector pedidos acumula la cantidad de unidades, una función búsqueda tiene que comprobar que exista el código en vectorProductos

int validar(int, int, int);
int busqueda(int [], int, int);
void ingresaCodigos(int [], int);
int cargaIncompletaPedidos(int [], int [],int);
void mostrarDatos(int [], int [], int);
void productoMasSolicitado(int [], int [], int);
void productoMenosSolicitado(int [], int [], int);

int main(){
	int vectorProductos[TAM];
	int vectorPedidos[TAM]={0};
	int ingreso;
	
	setlocale(LC_ALL,"spanish");
	
	ingresaCodigos(vectorProductos, TAM);
	ingreso = cargaIncompletaPedidos(vectorProductos, vectorPedidos, TAM);
	
	if(ingreso!=0){
		mostrarDatos(vectorProductos,vectorPedidos,TAM);
		productoMasSolicitado(vectorProductos,vectorPedidos,TAM);
		productoMenosSolicitado(vectorProductos,vectorPedidos,TAM);
	}else{
		printf("\nNo se ingresaron datos!");
	}	
	
	return 0;
}

int validar(int LI, int LS, int exc){
	int nro, band=0;
	
	do{
		if(band==0){
			printf("Ingrese valor entre %d y %d: ", LI, LS);
			band++;
		}
		else{
			printf("Valor fuera de rango, porfavor ingrese un valor válido: ");
		}
		scanf("%d", &nro);
	}while((nro<LI || nro>LS) && nro!=exc);
	
	return nro;
}

int busqueda(int vector[], int nro, int ce){
	int encuentra=-1, i=0;
	
	while(encuentra==-1 && i<ce){
		if(vector[i]==nro){
			encuentra=i;
		}
		else{
			i++;
		}
	}
	
	return encuentra;
	
}

void ingresaCodigos(int vector[], int ce){
	int i, aux, band;
	
	for(i=0;i<ce;i++){
		band=0;
		do{			
			if(band==0){
				printf("Ingrese códigos únicos de productos\n");
				band++;			
			}else{
				printf("\nError, seleccione un código único\n");
			}
			aux=validar(1000,9999,9999);
		}while(busqueda(vector,aux,i)!=-1);
		vector[i]=aux;
	}
}

int cargaIncompletaPedidos(int vectorCodigo[], int vectorProducto[], int ce){
	int i=0, codProducto, encuentra, cantComprada;
	
	printf("Ingrese código de producto\n");
	codProducto= validar(1000,9999,0);
	
	while(codProducto!=0){
		
		encuentra= busqueda(vectorCodigo,codProducto,ce);
		
		if(encuentra!=-1){
			printf("\nCódigo encontrado...\nIngrese cantidad a comprar\n");
			cantComprada= validar(0,99999,99999);
			vectorProducto[encuentra]+=cantComprada;			
			i++;
		}
		else{
			printf("\nError, código de producto no encontrado, porfavor ingrese otro\n");
		}
		
		printf("\nIngrese código de producto\n ");
		codProducto= validar(1000,9999,0);		
	}
	
	return i;
}

void mostrarDatos(int vectorCodigo[], int vectorProducto[], int ce){
	int i;
	
	printf("\nCódigo\tCantidad de unidades solicitadas\n");	
	for(i=0;i<ce;i++){
		printf("%d\t\t%d\n",vectorCodigo[i],vectorProducto[i]);
	}
}


void productoMasSolicitado(int vectorCodigo[], int vectorProducto[], int ce){
	int mayor, i;
	
	mayor= vectorProducto[i];
	for(i=1;i<ce;i++){
		if(vectorProducto[i] > mayor){
			mayor= vectorProducto[i];		
		}
	}
	
	printf("\nEl /los productos más solicidado tuvo una cantidad total de %d ventas\n", mayor);
	for(i=0;i<ce;i++){
		if(vectorProducto[i] == mayor){
			printf("Producto con código: %d \n", vectorCodigo[i]);
		}
	}
}

void productoMenosSolicitado(int vectorCodigo[], int vectorProducto[], int ce){
	int menor, i;
	
	menor= vectorProducto[i];
	for(i=1;i<ce;i++){
		if(vectorProducto[i] < menor){
			menor= vectorProducto[i];		
		}
	}
	
	printf("\nEl /los productos menos solicidado tuvo una cantidad total de %d ventas\n", menor);
	for(i=0;i<ce;i++){
		if(vectorProducto[i] == menor){
			printf("Producto con código: %d \n", vectorCodigo[i]);
		}
	}
}
