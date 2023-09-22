/* Una empresa debe registrar los pedidos recibidos de cada uno sus 10 productos a lo largo del d�a. Cada
producto est� identificado por un c�digo de 4 cifras. Los c�digos deben ingresarse al inicio del programa mediante
la funci�n IngresaC�digos.
Por cada pedido se recibe:
� C�digo de producto
� Cantidad de unidades solicitadas
Se puede recibir m�s de un pedido por producto.
 La carga de pedidos finaliza cuando se ingresa un producto igual a 0
Al finalizar se debe:
a) Emitir un listado con c�digo y cantidad de unidades solicitadas de cada producto.
b) El / los productos del cual se solicitaron mayor cantidad de unidades.
c) El / los productos del cual se solicitaron menos cantidad de unidades.
*/

#include <stdio.h>
#include <locale.h>
#define TAM 10

// vector pedidos acumula la cantidad de unidades, una funci�n b�squeda tiene que comprobar que exista el c�digo en vectorProductos

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
			printf("Valor fuera de rango, porfavor ingrese un valor v�lido: ");
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
				printf("Ingrese c�digos �nicos de productos\n");
				band++;			
			}else{
				printf("\nError, seleccione un c�digo �nico\n");
			}
			aux=validar(1000,9999,9999);
		}while(busqueda(vector,aux,i)!=-1);
		vector[i]=aux;
	}
}

int cargaIncompletaPedidos(int vectorCodigo[], int vectorProducto[], int ce){
	int i=0, codProducto, encuentra, cantComprada;
	
	printf("Ingrese c�digo de producto\n");
	codProducto= validar(1000,9999,0);
	
	while(codProducto!=0){
		
		encuentra= busqueda(vectorCodigo,codProducto,ce);
		
		if(encuentra!=-1){
			printf("\nC�digo encontrado...\nIngrese cantidad a comprar\n");
			cantComprada= validar(0,99999,99999);
			vectorProducto[encuentra]+=cantComprada;			
			i++;
		}
		else{
			printf("\nError, c�digo de producto no encontrado, porfavor ingrese otro\n");
		}
		
		printf("\nIngrese c�digo de producto\n ");
		codProducto= validar(1000,9999,0);		
	}
	
	return i;
}

void mostrarDatos(int vectorCodigo[], int vectorProducto[], int ce){
	int i;
	
	printf("\nC�digo\tCantidad de unidades solicitadas\n");	
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
	
	printf("\nEl /los productos m�s solicidado tuvo una cantidad total de %d ventas\n", mayor);
	for(i=0;i<ce;i++){
		if(vectorProducto[i] == mayor){
			printf("Producto con c�digo: %d \n", vectorCodigo[i]);
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
			printf("Producto con c�digo: %d \n", vectorCodigo[i]);
		}
	}
}
