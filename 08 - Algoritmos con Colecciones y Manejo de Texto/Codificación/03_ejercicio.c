/* Se ingresan los códigos de 15 productos de una empresa (números de 3 dígitos). Luego se ingresan las
ventas realizadas durante el día. Por cada venta se ingresa código de vendedor, código de artículo y cantidad.
Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005. Se puede recibir más de una venta
de un mismo vendedor y artículo. El ingreso de datos finaliza con código de vendedor igual a 0. Se desea:
a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas de cada producto.
b. Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades).
*/

#include <stdio.h>
#define TAM 15

int validar(int, int, int);
int busqueda(int [], int, int);
void cargaCompletaProductos(int [], int);
int cargaIncompletaVenta(int [], int [],int [], int);
void ordenMayorMenor(int [], int [], int);
void mostrarPuntoA(int [], int [], int);
void menorCantidadVentas(int [], int);

int main(){
	int vectorCodigoProducto[TAM];
	int vectorVentas[TAM]={0};
	int vectorVendedores[5]={0};
	int cant;
	
	cargaCompletaProductos(vectorCodigoProducto,TAM);
	
	cant= cargaIncompletaVenta(vectorCodigoProducto,vectorVentas,vectorVendedores,TAM);
	if(cant!=0){
		ordenMayorMenor(vectorCodigoProducto,vectorVentas,TAM);
		mostrarPuntoA(vectorCodigoProducto,vectorVentas,TAM);
		menorCantidadVentas(vectorVendedores,5);
	}else{
		printf("No se ingresaron ventas!");
	}
	
	return 0;
}


int validar(int LI, int LS, int exc){
	int nro, band=0;
	
	do{
		if(band==0){
			printf("\nIngrese valor válido entre %d y %d: ", LI,LS);
			band++;
		}else{
			printf("\nError, valor fuera de rango, vuelva a intentarlo, ingrese valor válido: ");
		}
		scanf("%d",&nro);
		
	}while((nro<LI||nro>LS)&&nro!=exc);	
	
	return nro;
}

int busqueda(int vector[], int nro, int ce){
	int encontrado=-1, i=0;
	
	while(encontrado==-1 && i<ce){
		if(vector[i]==nro){
			encontrado=i;
		}else{
			i++;
		}
	}
	
	return encontrado;
}

void cargaCompletaProductos(int vector[], int ce){
	int i, ingreso,band;
	
	for(i=0;i<ce;i++){
		band=0;
		do{
			if(band==0){
				printf("\nCódigo de producto único\n");
				band++;
			}else{
				printf("Error, código ya ingresado, elija otro\n");
			}
			ingreso=validar(100,999,999);
			
		}while(busqueda(vector,ingreso,i)!=-1);
		vector[i]=ingreso;
	}
}

int cargaIncompletaVenta(int vectorCodigoProducto[], int vectorVenta[], int vectorVendedores[], int ce){
	int i=0, auxVendedor, auxCodigoProducto, cantidadVendida, buscar;
	
	printf("Ingrese código de vendedor (finaliza con 0): ");
	auxVendedor= validar(1001,1005,0);
	
	while(auxVendedor!=0){		
		
		auxCodigoProducto=validar(100,999,999);
		buscar=busqueda(vectorCodigoProducto,auxCodigoProducto,ce);
		if(buscar!=-1){
			vectorVendedores[auxVendedor-1001]++;  //importante porque solo tiene 5 elementos
			printf("\nIngrese cantidad a comprar:");
			cantidadVendida=validar(0,99999,99999);
			vectorVenta[buscar]+=cantidadVendida;
			i++;
		}else{
			printf("\nError, código de producto inexistente!\n\n");	
		}
		printf("\nIngrese código de vendedor (finaliza con 0): ");
		auxVendedor= validar(1001,1005,0);
	}
	return i;
}

void ordenMayorMenor(int vectorCodigoProducto[], int vectorVenta[], int ce){
	
	int i, j, aux;
	for(i=0;i<ce-1;i++){
		for(j=0;j<ce-1-i;j++){
			if(vectorVenta[j]<vectorVenta[j+1]){
				aux=vectorVenta[j];
				vectorVenta[j]=vectorVenta[j+1];
				vectorVenta[j+1]=aux;
				
				aux=vectorCodigoProducto[j];
				vectorCodigoProducto[j]=vectorCodigoProducto[j+1];
				vectorCodigoProducto[j+1]=aux;
			}
		}
	}	
}

void mostrarPuntoA(int vectorCodigoProducto[], int vectorVenta[], int ce){
	int i;
	
	printf("Listado ordenado de mayor a menor por cantidad de unidades vendidas de cada producto: \n");
	printf("Cantidad Unidades\tCódigo\n");
	
	for(i=0;i<ce;i++){
		printf("%d\t%d\n",vectorCodigoProducto[i],vectorVenta[i]);
	}	
}

void menorCantidadVentas(int vectorVendedores[], int ce){
	int i, menor;
	
	menor=vectorVendedores[0];
	for(i=1;i<ce;i++){
		if(vectorVendedores[i] < menor){
			menor= vectorVendedores[i];
		}
	}
	
	printf("Vendedores que realizaron menor cantidad de ventas:\n");
	for(i=0;i<ce;i++){
		if(vectorVendedores[i]==menor){
			printf("%d", i+1001);
		}
	}
}
