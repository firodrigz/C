/*La librería Libreto S.A. desea analizar las ventas realizadas por cada una de sus sucursales.
Existen 7 sucursales codificadas con los números 10, 20, 30, 40, 50, 60 y 70.
No se sabe la cantidad de libros que vende la empresa pero sí se sabe que no son más de 100. Se debe
realizar una carga inicial solicitando al usuario que ingrese por teclado los códigos de libros disponibles (los códigos
son de 4 dígitos).
Luego se ingresan por teclado las ventas realizadas, ingresando por cada venta los siguientes datos:
• Código de sucursal (entero 10, 20, 30, 40, 50, 60 o 70)
• Código de libro (entero de 4 cifras)
• Cantidad Vendida (entero mayor a 0)
Puede ingresarse más de una venta por libro/sucursal. Si un libro no se vendió en la sucursal no se informa.
La carga de datos finaliza al ingresar un código de libro igual a 0.
1. Cargar los libros disponibles en la empresa mediante la función CargaLibros, esta función debe asegurar
que se ingresen código de 4 cifras y no debe permitir ingresar códigos repetidos.
2. Mostrar el detalle de cantidad de libros vendidas en cada sucursal con el siguiente formato:
Libro/Sucursal 10 20 30 40 50 60 70
xxxx 		   xx xx xx xx xx xx xx
xxxx 		   xx xx xx xx xx xx xx
xxxx 		   xx xx xx xx xx xx xx
…
xxxx 		   xx xx xx xx xx xx xx
3. Mostrar la o las sucursales que vendieron mayor cantidad de libros. Sumar por columnas 
4. Mostrar aquellos libros que NO fueron vendidos en ninguna sucursal*/


#include <stdio.h>
#include <locale.h>
#define CANTLIBROS 100
#define CANTSUCURSALES 7

int busqueda(int [], int, int);
int validar(int, int, int);
int cargaLibrosDisp(int [], int);
int ventas(int [][CANTSUCURSALES], int [], int, int);
void mostrarLibrosVendidos(int [][CANTSUCURSALES], int [], int, int);
void sumarPorColumnas(int [][CANTSUCURSALES], int [], int, int);
void sumarPorFilas(int [][CANTSUCURSALES], int[], int [], int, int);

int main(){
	int librosDisp[CANTLIBROS], disponibilidad, ventasRealizadas;
	int vectorVentas[CANTLIBROS][CANTSUCURSALES]={{0}};
	int vectorSumaSucursales[CANTSUCURSALES]={0};
	int vectorSumaLibros[CANTLIBROS]={0};
	
	setlocale(LC_ALL,"spanish");
	
	disponibilidad=cargaLibrosDisp(librosDisp, CANTLIBROS);
	
	if(disponibilidad!=0){
		ventasRealizadas=ventas(vectorVentas,librosDisp,disponibilidad,CANTSUCURSALES);
		if(ventasRealizadas!=0){
			mostrarLibrosVendidos(vectorVentas,librosDisp,disponibilidad,CANTSUCURSALES);
			sumarPorColumnas(vectorVentas, vectorSumaSucursales, disponibilidad,CANTSUCURSALES);
			sumarPorFilas(vectorVentas, librosDisp, vectorSumaLibros, disponibilidad, CANTSUCURSALES);
		}else{
			printf("\nNo se realizaron ventas!");
		}
	}else{
		printf("\nNo hay disponibilidad de libros!");
	}
	
	return 0;
}

int busqueda(int vector[], int nro, int ce){
	int encuentra=-1, i=0;
	
	while(encuentra==-1 && i<ce){
		if(vector[i]==nro){
			encuentra=i;
		}else{
			i++;
		}
	}
	
	return encuentra;
}

int validar(int LI, int LS, int exc){
	int band=0, nro;
	
	do{
		if(band==0){
			printf("\nValor válido entre %d y %d: ", LI,LS);
			band++;
		}else{
			printf("\nError, valor fuera de rango, vuelva a intentarlo, ingrese valor válido: ");
		}
		
		scanf("%d", &nro);
		
	}while((nro<LI||nro>LS)&&nro!=exc);
	
	return nro;
}

int cargaLibrosDisp(int vector[], int ce){
	int i=0, aux;
	
	printf("Carga de libros disponibles\n");
	printf("Ingrese código de libro (termina con 0): ");
	aux=validar(1000,9999,0);
	
	while(i<ce && aux!=0){
		if(busqueda(vector, aux, i)!=-1){
			printf("\nCódigo repetido!, intente nuevamente\n");
		}else{
			vector[i]=aux;
			i++;			
		}
		printf("\nIngrese código de libro (termina con 0): ");
		aux=validar(1000,9999,0);
	}		
}

int ventas(int matriz[][CANTSUCURSALES], int vector[], int cl, int cc){
	int codSucursal, codLibro, auxCodLibro, cantVendida, i=0;
	
	
	printf("\n\nIngrese código de libro que quiera registrar venta: ");
	auxCodLibro=validar(1000,9999,0);
	
	while(auxCodLibro!=0){
		codLibro=busqueda(vector,auxCodLibro,cl);
		if(codLibro!=-1){
			printf("\nIngrese sucursal: ");
			codSucursal=validar(10,70,70);
			printf("\nIngrese cantidad vendida: ");
			cantVendida=validar(0,99999,99999);
			matriz[codLibro][(codSucursal)/10]+=cantVendida;
			i++;
		}else{
			printf("\nCódigo de libro ingresado no pertenece a un libro disponible, intente nuevamente!");
		}
				
		printf("\n\nIngrese código de libro que quiera registrar venta: ");
		auxCodLibro=validar(1000,9999,0);			
	}
	
	return i;
}

void mostrarLibrosVendidos(int matriz[][CANTSUCURSALES], int vector[], int cf, int cc){
	int i, j;
	
	for(i=0;i<cf;i++){
		printf("%d\t", vector[i]);
		for(j=0;j<cc;j++){
			printf("%d\t",matriz[i][j]);
		}
		printf("\n");
	}
}

void sumarPorColumnas(int matriz[][CANTSUCURSALES], int vector[], int cf, int cc){
	int i, j, mayor;
	
	for(j=0;j<cc;j++){
		for(i=0;i<cf;i++){
			vector[j]+=matriz[i][j];
		}
	}
	
	mayor=vector[0];
	
	for(i=1;i<cc;i++){
		if(vector[i]>mayor){
			mayor=vector[i];
		}
	}
	
	printf("La o las sucursales que vendieron mayor cantidad de libros: \n");
	for(i=0;i<cc;i++){
		if(vector[i]==mayor){
			printf("%d\n",i+1);
		}
	}	
}

void sumarPorFilas(int matriz[][CANTSUCURSALES], int vector[], int vectorSuma[], int cf, int cc){
	printf("Libros que NO fueron vendidos en ninguna sucursal: \n");
	
	int i, j;
	
	for(i=0;i<cf;i++){
		for(j=0;j<cc;j++){
			vectorSuma[i]+=matriz[i][j];
		}
	}
	
	for(i=0;i<cf;i++){
		if(vectorSuma[i]==0){
			printf("%d", vector[i]);
		}
	}
}
