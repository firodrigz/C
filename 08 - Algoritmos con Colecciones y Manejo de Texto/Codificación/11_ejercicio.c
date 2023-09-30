/* Se ingresan código y precio unitario de los productos que vende un negocio. No se sabe la cantidad
exacta de productos, pero sí se sabe que son menos de 50. El código es alfanumérico de 3 caracteres y
la carga de los datos de productos termina con un código igual al “FIN”. Luego se registran las ventas del
día y por cada venta se ingresa el código de producto y cantidad de unidades vendidas terminando con
una cantidad igual a 0. Se solicita:
c. Calcular la recaudación total del día y el producto del cual se vendió menor cantidad de unidades.
d. Mostrar el listado de productos con su precio ordenado en forma alfabética por código de
producto. */

#include <stdio.h>
#include <string.h>

int busquedaCodigo(char [][4], char [], int);
int cargaProductos(char [][4], float [], int);
int ventas(char [][4], int [], float [], int);
void ordenar(char [][4], float [], int);
void mostrarListado(char [][4], float [], int);


int main(){
	char codigo[50][4];
	float precioUnitario[50];
	int cantUnidadesVentas[50]={0};
	
	int ingresoProductos, ingresoVentas;
	
	ingresoProductos = cargaProductos(codigo, precioUnitario, 50);
	
	if(ingresoProductos!=0){
		ingresoVentas=ventas(codigo, cantUnidadesVentas, precioUnitario, ingresoProductos);
		if(ingresoVentas!=0){
			ordenar(codigo, precioUnitario, ingresoProductos);
			mostrarListado(codigo, precioUnitario, ingresoProductos);
		}else{
			printf("\nNo se registraron ventas!");
		}
	}else{
		printf("\nNo se registrara ingreso de productos!");
	}	
	return 0;
}

int busquedaCodigo(char codigo[][4], char aBuscar[], int cantElementos){
	int encuentra=-1, i=0;
	
	while(i<cantElementos && encuentra==-1){
		if(strcmpi(codigo[i],aBuscar)==0){
			encuentra=i;
		}else{
			i++;
		}
	}	
	
	return encuentra;	
}

int cargaProductos(char codigo[][4], float precioUnitario[], int cantElementos){
	int i=0, existe, band;
	char auxCodigo[4];
	float auxPrecioUnitario;
	
	printf("Carga de productos");
	printf("\nIngrese codigo de producto (termina con 'FIN'): ");
	fgets(auxCodigo, 4, stdin);
	auxCodigo[strlen(auxCodigo)-1]='\0';
	
	while(i<cantElementos && (strcmpi(auxCodigo, "FIN")!=0)){
		
		existe= busquedaCodigo(codigo, auxCodigo, i);
		
		if(existe!=-1){
			band=0;			
			do{
				if(band==0){
					printf("\nIngrese precio unitario: ");
					band++;
				}else{
					printf("Error, vuelva a ingresar un precio válido: ");
				}
				scanf("%.2f", &auxPrecioUnitario);
			}while(auxPrecioUnitario<0);
						
			precioUnitario[i]=auxPrecioUnitario;
			strcpy(codigo[i],auxCodigo);
			i++;
		}else{
			printf("Código ya existe en el vector, vuelva a intentarlo\n");
		}	
		
		printf("\nIngrese codigo de producto (termina con 'FIN'): ");
		fgets(auxCodigo, 4, stdin);
		auxCodigo[strlen(auxCodigo)-1]='\0';
	}
	
	return i;
}

int ventas(char codigo[][4], int cantVendidas[], float precioUnitario[], int cantProductos){
	int i=0, auxUnidadesVendidas, band, encuentra, j, menor;
	char codigoProducto[4];
	float acumuladorRecaudacion;
	
	printf("Carga de ventas");
	band=0;
	do{
		if(band==0){
			printf("\nIngrese cantidad de unidades vendidas (termina con 0): ");
			band++;
		}else{
			printf("\nError, intente nuevamente con un valor válido: ");
		}
		scanf("%d", &auxUnidadesVendidas);
		
	}while(auxUnidadesVendidas < 0);
	
	while(i<cantProductos && auxUnidadesVendidas != 0){
		printf("\nIngrese código de producto: ");
		fgets(codigoProducto, 4, stdin);
		codigoProducto[strlen(codigoProducto)-1]='\0';
		
		encuentra= busquedaCodigo(codigo, codigoProducto, cantProductos);
		
		if(encuentra!=-1){
			acumuladorRecaudacion+=precioUnitario[encuentra]*auxUnidadesVendidas;
			cantVendidas[encuentra]+=auxUnidadesVendidas;
			i++;			
		}else{
			printf("\nError, producto no encontrado, vuelta a ingresar cant unidades\n");
		}			
	}
	
	if(i!=0){
		printf("\nRecaudación total del día: %.2f", acumuladorRecaudacion);
		menor=cantVendidas[0];
		for(j=1; j<cantProductos; j++){
			if(cantVendidas[j] < menor){
				menor=cantVendidas[j];
			}
		}
		printf("Producto/s que se vendió menor cantidad de unidades (%d): ", menor);
		for(j=0;j<cantProductos;j++){
			if(cantVendidas[j] == menor){
				puts(codigo[j]);
			}
		}
	}
	
	return i;
}

void ordenar(char vn[][4], float precios[], int ce){
	int i,j;
	char aux[4];
	float auxP;
	
	for(i=0;i<ce-1;i++){
		for(j=0;j<ce-i-1;j++){
			if(strcmpi(vn[j],vn[j+1]) > 0){
				strcpy(aux,vn[j]);
				strcpy(vn[i],vn[j+1]);
				strcpy(vn[j+1],aux);
				
				auxP=precios[j];
				precios[j]=precios[j+1];
				precios[j+1]=auxP;
			}
		}
	}
}

void mostrarListado(char codigo[][4], float precios[], int ce){
	int i;
	
	for(i=0;i<ce;i++){
		printf("%.2f\t", precios[i]);
		puts(codigo[i]);
	}
}
