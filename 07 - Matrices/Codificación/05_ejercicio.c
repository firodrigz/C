/*Se desea desarrollar un sistema de reservas de entradas para un cine. La sala consta de 12 filas numeradas
de la 1 a la 12 y cada fila tiene 9 butacas numeradas a partir de la columna central, con las butacas impares a
la derecha y las pares a la izquierda, como en el siguiente esquema:
8 6 4 2 1 3 5 7 9

Para la carga, se debe mostrar al usuario un esquema con las butacas disponibles y reservadas, marcando
con la letra D las disponibles y con la letra R las reservadas.
Por cada reserva se debe solicitar la fila y número de butaca a reservar. Cada vez que se realice una
reserva se deberá actualizar el esquema que muestra las butacas. Si la butaca seleccionada ya estaba
ocupada se debe informar al usuario para que seleccione otra. El proceso de reserva finaliza con una fila
con un número negativo.
Al finalizar mostrar:
a. la cantidad de asientos disponibles y la cantidad de asientos reservados.
b. los números de filas que quedaron vacías.
c. la o las filas con mayor cantidad de espectadores.
d. un listado con la cantidad de personas que se sentaron en los mismos números de butacas en
todo el cine ordenado de mayor a menor. Por ejemplo:
Butaca Cantidad
1 20
3 15
2 10
 ..............*/
 
#include <stdio.h>
#include <stdlib.h>

int ValidarButaca(int, int, int);
void MostrarButacas(char[][9], int, int);
void ContarAsientos(char[][9], int, int);
void FilasVacias(char[][9], int, int);
void FilaMayorCant(char[][9], int, int);
void EncontrarButaca(char[][9], int, int);
void LlenarButacas(char[][9], int, int, char);
int ValidarFila(int, int, int);

int main(){
	char sala[12][9];
	int butaca, fila, verif, valid;
	
	LlenarButacas(sala,12,9,'D');
	MostrarButacas(sala,12,9);
	
	do{
		printf("Ingrese fila (1-12): ");
		scanf("%d",&fila);
		
		verif = ValidarFila(fila,1,12);
	}while(verif == 1);
	
	while(fila > 0){
		do{
		printf("Ingrese butaca a reservar (1-9): ");
		scanf("%d",&butaca);
		
		valid = ValidarButaca (1,9,butaca);
		}while(valid == 1);
		
		EncontrarButaca(sala, fila, butaca);
		MostrarButacas(sala,12,9);
		
		do{
			printf("Ingrese fila (1-12): ");
			scanf("%d",&fila);
			
			verif = ValidarFila(fila,1,12);
		}while(verif == 1);
	}
	
	ContarAsientos(sala,12,9);
	FilasVacias(sala,12,9);
	FilaMayorCant(sala,12,9);
}

void LlenarButacas(char sala[][9], int maxFilas, int maxCol, char car){
	int i,j;
	
	for(i= 0; i<maxFilas;i++){
		for(j = 0; j < maxCol; j++){
			sala[i][j] = car;
		}
	}
}

void MostrarButacas(char sala[][9], int maxFila, int maxCol){
	int i,j;
	
	printf("8 | 6 | 4 | 2 | 1 | 3 | 5 | 7 | 9\n");
	printf("=================================\n");
	
	for(i = 0; i < maxFila; i++){
		printf("%c | %c | %c | %c | %c | %c | %c | %c | %c\n", sala[i][7],sala[i][5],
		sala[i][3],sala[i][1],sala[i][0],sala[i][2],sala[i][4],sala[i][6],sala[i][8]);
	}
}

int ValidarFila(int nFila, int min, int max){
	int valid;
	
	if(nFila <= 12 && nFila != 0){
		valid = 0;
	}else{
		valid = 1;
	}
	
	return valid;
}

int ValidarButaca(int min, int max, int butaca){
	int valid;
	
	if(butaca >= min && butaca <= max){
		valid = 0;
	}else{
		valid = 1;
	}
	
	return valid;
}

void EncontrarButaca(char sala[][9], int fila, int butaca){

	if(sala[fila-1][butaca-1] == 'D'){
		sala[fila-1][butaca-1] = 'R';
	}else{
		printf("Esa butaca ya esta reservada. Intente otra por favor\n");
	}
}

void ContarAsientos(char sala[][9], int maxFila, int maxCol){
	int i, j, contDis =0, contRes = 0;
	
	for(i = 0; i < maxFila; i++){
		for(j = 0; j < maxCol; j++){
			if(sala[i][j] == 'D'){
				contDis++;
			}else{
				contRes++;
			}
		}
	}
	
	printf("Disponibles: %d | Reservados: %d\n", contDis, contRes);
}

void FilasVacias(char sala[][9], int maxFila, int maxCol){
	int i,j, contVacio = 0;
	
	for(i = 0; i < maxFila; i++){
		for (j = 0; j < maxCol; j++){
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

void FilaMayorCant(char sala[][9], int maxFila, int maxCol){
	int i,j, mayor = 0, band = 1, cont = 0, vEspec[maxFila];
	
	for(i = 0; i < maxFila; i++){
		for (j = 0; j < maxCol; j++){
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
	
	for (i = 0; i < maxFila;i++){
		if(vEspec[i] == mayor){
			printf("La fila %d tuvo la mayor cantidad de espectadores\n",i+1);
		}
	}
}

