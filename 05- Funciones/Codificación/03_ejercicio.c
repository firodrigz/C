/*Se realiz� un concurso de tiro al blanco. Por cada participante se ingresa un n�mero que lo identifica y el
resultado de los disparos efectuados. El ingreso finaliza con un n�mero de participante negativo.
Cada participante efect�a 5 disparos, registr�ndose las coordenadas X-Y de cada disparo. 

- No considere disparos sobre los ejes, pero s� en el centro (si es sobre los ejes las coordenadas
deber�n volver a ingresarse).
- Para determinar el cuadrante utilizar la funci�n CUADRANTE que reciba las dos coordenadas y
retorne el cuadrante al cual pertenece (1 a 4) y 0 para indicar un tiro en el centro.

Para calcular el puntaje utilizar la funci�n PUNTAJE que reciba 5 par�metros que representan la cantidad
disparos en cada cuadrante y en el centro. La funci�n debe retornar el puntaje obtenido seg�n la siguiente
escala:
- Cuadrantes 1 y 2: 50 puntos
- Cuadrantes 3 y 4: 40 puntos
- Centro: 100 puntos

Determinar:
a. El puntaje obtenido por cada participante, detallando cuantos disparos realiz� en cada cuadrante.
b. Mostrar el n�mero del participante ganador y el puntaje obtenido.
c. Calcular y mostrar la cantidad total de disparos en el centro (de todos los participantes)*/

#include <stdio.h>
#include <locale.h>

//Protocolo de funciones
int cuadrante(int,int);
int puntaje(int,int,int,int,int);

//main
int main(){
	
	int centro=0; //contador para tiros al centro de todos los participantes
	int puntGanador = 0; // variable inicializada en 0 para comparar priemra vuelta
	int ID, nro, punTotal, i, idGanador, X, Y;
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingrese la ID del participante: ");
	scanf("%d",&ID);
	
	while(ID>=0){
		
		int cont0 = 0, cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0;
		
		for(i=1;i<=5;i++){ 
		
			do{
				printf("\nIngrese coordenadas del disparo (X-Y)\n ");
				printf("X: ");
				scanf("%d",&X);
				printf("Y: ");
				scanf("%d",&Y);
			
				if((X!=0 && Y==0)||(Y!=0 && X==0)){
					printf("\nERROR, disparo sobre alguno de los ejes, vuelva a disparar\n\n ");
				}
				
			}while((X!=0 && Y==0)||(Y!=0 && X==0));
			
			nro=cuadrante(X,Y);  
			
			switch(nro){
				case 0: cont0++;
						centro++;
				break;
				
				case 1:cont1++;
				break;
				
				case 2:cont2++;
				break;
				
				case 3:cont3++;
				break;
				
				case 4:cont4++;
				break;
			}		
		}
		
		punTotal=puntaje(cont0,cont1,cont2,cont3,cont4); 
		
		printf("\nPuntaje obtenido por el participante %d : %d \n\nRealiz�: \n%d disparos en el cuadrante 1 \n%d disparos en el cuadrante 2 \n%d disparos en el cuadrante 3 \n%d disparos en el cuadrante 4 \n%d disparos en el cuadrante 0", ID,punTotal,cont1,cont2,cont3,cont4,cont0);
		
		if(punTotal>puntGanador){
			idGanador=ID;
			puntGanador=punTotal;
		}
		
		printf("\n\nIngrese la ID del participante: ");
		scanf("%d",&ID);
	}
	
	printf("\nParticipante ganador: %d, con un puntaje de: %d",idGanador,puntGanador);
	
	printf("\n\nCantidad total de disparos en el centro (de todos los participantes): %d, con un puntaje total de: %d ",centro,centro*100);
	
	return 0;
	
}

//Definici�n de funciones

int cuadrante(int x,int y){
	
	int nroCuadrante;
	
	if((x==0)&&(y==0)){
		nroCuadrante=0;
	}
	else{
		if(x>0&&y>0){
		nroCuadrante=1;
		}
		else{
			if(x<0&&y>0){
				nroCuadrante=2;
			}
			else{
				if(x<0&&y<0){
					nroCuadrante=3;
				}
				else{
					if(x>0&&y<0){
						nroCuadrante=4;
					}
				}
			}
		}
	}
	 		
	return nroCuadrante;	
}


int puntaje(int N0,int N1,int N2,int N3,int N4){
	
	int centro, cuadrante1Y2, cuadrante3Y4, total;
	
	centro=100*N0;
	cuadrante1Y2=50*N1 + 50*N2;
	cuadrante3Y4=40*N3 + 40*N4;
	
	total=centro+cuadrante1Y2+cuadrante3Y4;
	
	return total;
}

