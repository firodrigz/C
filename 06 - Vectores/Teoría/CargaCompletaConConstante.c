#include<stdio.h>
#define N 5
/************************** DECLARACION DE FUNCIONES *****************/
void CARGA(int [],int);
void MOSTRAR(int [],int);

main()
{ int VEC[N];

  CARGA(VEC,N);  /***** LLAMADA A FUNCION *****/
  MOSTRAR(VEC,N);  /***** LLAMADA A FUNCION *****/
}
/********************  DEFINICION DE LAS FUNCIONES **********************/
///////////////////////////////////////////
void CARGA(int V[],int TAM)
{ int I;
  for(I=0;I<TAM;I++)
  {
  	printf("\nINGRESAR ELEMENTO EN  POSICION   %d  ", I+1);
  	scanf("%d",&V[I]);
  }
}
////////////////////////////////////////////
void MOSTRAR(int V[],int TAM)
{ int I;
 printf("\n   POSICION     ELEMENTO");
 for(I=0;I<TAM;I++)
    printf("\n    %d   \t %4d  ",I+1, V[I]);
}
