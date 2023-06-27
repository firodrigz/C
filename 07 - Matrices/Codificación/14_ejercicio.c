/*Una cadena de heladerías desea realizar una estadística anual de sus ventas. Posee sus negocios en
50 zonas del Gran Buenos Aires, identificadas con un número correlativo de 1 a 50.
En cada heladería se comercializa 30 productos, número correlativo de 1 a 30, cuyos precios se
conoce.
Cada vez que se realiza una venta, se tiene la siguiente información:
- Nro. de Factura
- Código de Producto
- Nro. de zona
- Nro. de mes
- Cantidad vendida
Esta información termina con Nro. de Factura igual a cero.
En todas las zonas en los meses de invierno (mes 6, 7,8) hay un descuento del 10% sobre el total de la
venta.
Utilizar función para leer y controlar, el Código de producto y reutilizarla para leer y controlar el número
de zona y el número de mes.

1) Listado, donde indique la cantidad de ventas según código producto en cada zona, con el formato. 
2) Listado, indicando la recaudación por zona
3) Indicar cantidad de zonas en las que la recaudación es inferior a $500000.
4) Recaudación anual total de la cadena de heladerías
*/

#include <stdio.h>
#include <locale.h>
#define PRODUCTOS 30
#define ZONAS 50

float validarFlotante(int);
void cargaPrecios(float [],int);
int valFactura(int);
int ingresaValida(int,int);
int cargaVenta(int [][ZONAS],float [],float [],int,int);
void mostrarMatriz(int [][ZONAS], int,int);
void mostrarVector(float [],int);

int main(){
	int matrizCantVentas[PRODUCTOS][ZONAS]={{0}};
	float precios[PRODUCTOS];
	float recaudacion[ZONAS]={0};
	int estado;
	
	cargaPrecios(precios,PRODUCTOS);
	estado=cargaVenta(matrizCantVentas,precios,recaudacion,PRODUCTOS,ZONAS);
	
	if(estado==0){
		printf("\nNo se ingresaron ventas"); 
	}
	else{
		printf("\nMatriz con cantidad de productos x zonas\n");
		mostrarMatriz(matrizCantVentas,PRODUCTOS,ZONAS);
		printf("\nListado de recaudación x zonas\n");
		mostrarVector(recaudacion,ZONAS);
		
	}	
	return 0;
}

float validarFlotante(int condicion){
	float nro;
	int band=0;
	
	do{
		if(band==0){
			printf("Ingrese valor mayor a %d: ", condicion);
		}
		else{
			printf("Error, vuelva a ingregar valor: ");
		}
				
		scanf("%f",&nro);		
	}while(nro<=condicion);
	
	return nro;
}

void cargaPrecios(float vPrecios[],int tam){
	int i;
	float nro;
	
	for(i=0;i<tam;i++){		
		printf("-- Precio del producto %d -- \n",i+1);
		nro=validarFlotante(0);
		vPrecios[i]=nro;	
	}	
}

int valFactura(int condicion){
	int nro, band=0;	
	
	do{
		if(band==0){
			printf("\nIngrese valor: ");
		}
		else{
			printf("Error, vuelva a ingregar valor: ");
		}
		
		scanf("%d",&nro);
	}while(nro<condicion);
	
	return nro;
}

int ingresaValida(int LI,int LS){
	int nro, band=0;
	
	do{
		if(band==0){
			printf("\nIngrese valor: ");
		}
		else{
			printf("Error, vuelva a ingregar valor: ");
		}
		
		scanf("%d",&nro);
		
	}while(nro<LI || nro>LS);
	
	return nro;
}

int cargaVenta(int matrizCantidad[][ZONAS],float vPrecios[],float vRecaudacion[],int cProductos,int cZonas){
	int estado=0,nroFactura,codProducto,codZona,mes,cantVendida;
	
	printf("\n-- Nro de factura -- ");
	nroFactura=valFactura(0);
	
	while(nroFactura!=0){
		
		printf("\n-- Código de producto -- ");
		codProducto=ingresaValida(1,cProductos);
		
		printf("\n-- Nro de zona --");
		codZona=ingresaValida(1,cZonas);
		
		printf("\n-- Nro de mes --");
		mes=ingresaValida(1,12);
		
		printf("\n-- Cantidad vendida --");
		cantVendida=valFactura(0);
		
		matrizCantidad[codProducto-1][codZona-1]+=cantVendida;
		
		if(mes==6||mes==7||mes==8){
			vRecaudacion[codZona-1]+=((vPrecios[codProducto-1])*cantVendida)-((vPrecios[codProducto-1])*0.10);
		}
		else{
			vRecaudacion[codZona-1]+=(vPrecios[codProducto-1])*cantVendida;
		}		
		
		estado++;
		
		printf("\n\n-- Nro de factura -- ");
		nroFactura=valFactura(0);		
	}
	
	return estado;
}

void mostrarMatriz(int matriz[][ZONAS],int cf,int cc){
	int f,c;
	
	for(f=0;f<cf;f++){
		for(c=0;c<cc;c++){
			printf("%d ",matriz[f][c]);
		}
		printf("\n");
	}	
}

void mostrarVector(float vector[],int tam){
	int i; 
	float acumulador=0;
	
	for(i=0;i<tam;i++){
		printf("%.2f ",vector[i]);
	}
	
	printf("\nZonas en las que la recaudación es inferior a $500000");
	
	for(i=0;i<tam;i++){
		if(vector[i]<500000){
			printf("\nZona %d: ",i+1);
			printf("%.2f ",vector[i]);
		}
	}
	
	/////////////////////////////////////////////////////////////////////////
	
	for(i=0;i<tam;i++){
		acumulador+=vector[i];
	}
	
	printf("\nRecaudación total: %.2f",acumulador);
	
}
