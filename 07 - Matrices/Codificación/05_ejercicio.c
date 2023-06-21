/*Se desea desarrollar un sistema de reservas de entradas para un cine. La sala consta de 12 filas numeradas
de la 1 a la 12 y cada fila tiene 9 butacas numeradas a partir de la columna central, con las butacas impares a
la derecha y las pares a la izquierda, como en el siguiente esquema:
8 6 4 2 1 3 5 7 9

Para la carga, se debe mostrar al usuario un esquema con las butacas disponibles y reservadas, marcando
con la letra D las disponibles y con la letra R las reservadas.
Por cada reserva se debe solicitar la fila y n�mero de butaca a reservar. Cada vez que se realice una
reserva se deber� actualizar el esquema que muestra las butacas. Si la butaca seleccionada ya estaba
ocupada se debe informar al usuario para que seleccione otra. El proceso de reserva finaliza con una fila
con un n�mero negativo.
Al finalizar mostrar:
a. la cantidad de asientos disponibles y la cantidad de asientos reservados.
b. los n�meros de filas que quedaron vac�as.
c. la o las filas con mayor cantidad de espectadores.
d. un listado con la cantidad de personas que se sentaron en los mismos n�meros de butacas en
todo el cine ordenado de mayor a menor. Por ejemplo:
Butaca Cantidad
1 20
3 15
2 10*/
 

#include <stdio.h>
#define FILAS 12
#define COLUMNAS 9

int validarIngreso(int,int);
void cargaMatriz(char[][COLUMNAS],int,int);
int busqueda(char[][COLUMNAS],int,int);
void mostrarMatriz(char[][COLUMNAS],int);
void contarAsientos(char[][COLUMNAS], int, int);
void filasVacias(char[][COLUMNAS], int, int);
void filaMayorCant(char[][COLUMNAS], int, int);


int main(){
	char sala[FILAS][COLUMNAS];
	int butacas, fila;
	
	cargaMatriz(sala,FILAS,COLUMNAS);
	mostrarMatriz(sala,FILAS);
	
	printf("\n-- Ingreso de fila --\n");
	fila=validarIngreso(1,FILAS);
	
	while(fila > 0){
		
		printf("\n-- Ingreso de butaca --\n");
		butacas=validarIngreso(1,COLUMNAS);
		
		busqueda(sala,fila,butacas);
		mostrarMatriz(sala,FILAS);
		
		printf("\n-- Ingreso de fila --\n");
		fila=validarIngreso(1,FILAS);
	}
	
	contarAsientos(sala,12,9);
	filasVacias(sala,12,9);
	filaMayorCant(sala,12,9);	
	
	return 0;
}

int validarIngreso(int LI, int LS){
	int nro;
	int band = 0;
	
	do{
		if(band==0){
			printf("Ingrese valor entre %d - %d : ", LI,LS);
			band++;
		}
		else{
			printf("Valor fuera de rango, porfavor ingrese valor entre %d - %d : ", LI,LS);
		}
		
		scanf("%d",&nro);
		
	}while(nro>LS);
	
	
	return nro;
}

void cargaMatriz(char sala[][COLUMNAS],int cf,int cc){
	int i, j;
	
	printf(" Disponibilidad total de la sala\n");
	
	for(i = 0; i < cf; i++){
		for(j = 0; j < cc; j++){
			sala[i][j] = 'D'; 
		}
	}	
}

int busqueda(char sala[][COLUMNAS],int fila,int butaca){
	int i,j;
	
	if(sala[fila-1][butaca-1] == 'D'){
		sala[fila-1][butaca-1] = 'R';
	}
	else{
		printf("ERROR! Esa butaca ya esta reservada. Intente otra por favor\n");
	}	
}

void mostrarMatriz(char sala[][COLUMNAS],int cf){
	int i,j;
	
	printf("\n     | 8 | 6 | 4 | 2 | 1 | 3 | 5 | 7 | 9 |\n");
	printf("-----|====================================\n");
	
	for(i = 0; i < cf; i++){
		printf("| %-2d | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", i+1,sala[i][7],sala[i][5],
		sala[i][3],sala[i][1],sala[i][0],sala[i][2],sala[i][4],sala[i][6],sala[i][8]);
	}
}

void contarAsientos(char sala[][COLUMNAS], int cf, int cc){
	int i, j, contDis =0, contRes = 0;
	
	for(i = 0; i < cf; i++){
		for(j = 0; j < cc; j++){
			if(sala[i][j] == 'D'){
				contDis++;
			}else{
				contRes++;
			}
		}
	}
	
	printf("Disponibles: %d | Reservados: %d\n", contDis, contRes);
}

void filasVacias(char sala[][COLUMNAS], int cf, int cc){
	int i,j, contVacio = 0;
	
	for(i = 0; i < cf; i++){
		for (j = 0; j < cc; j++){
			if(sala[i][j] == 'D'){
				contVacio++;
			}
		}
		if(contVacio == 9){
			printf("La fila %d quedo vacia\n",i+1);
		}
		contVacio = 0;
	}
}

void filaMayorCant(char sala[][COLUMNAS], int cf, int cc){
	int i,j, mayor = 0, band = 1, cont = 0, vEspec[cf];
	
	for(i = 0; i < cf; i++){
		for (j = 0; j < cc; j++){
			if(sala[i][j] == 'R'){
				cont++;
			}
		}
		if(band == 1 || cont > mayor){
			mayor = cont;
			band = 0;
		}
		vEspec[i] = cont;
		cont = 0;
	}
	
	for (i = 0; i < cf;i++){
		if(vEspec[i] == mayor){
			printf("La fila %d tuvo la mayor cantidad de espectadores\n",i+1);
		}
	}
}
