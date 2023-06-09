/*****************************************************************************************
A-) GUARDAR 5 NROS. ENTEROS DISTINTOS EN UN VECTOR
B-) MOSTRAR LOS DATOS DEL VECTOR
*****************************************************************************************/
#include<stdio.h>
#define TAM 5

int BUSQUEDA (int[], int, int);
void CARGA_SinRepetidos (int [], int );
void MOSTRAR (int [], int );

main()
{
  int VEC[TAM];

  CARGA_SinRepetidos(VEC,TAM);
  MOSTRAR(VEC,TAM);
 }

/************************ DEFINICION DE FUNCIONES **********************************/

void CARGA_SinRepetidos(int V[], int N)
{
  int I, POS, NRO;
  for(I=0;I<N;I++)
  {
    do{
  	    printf("\nINGRESAR NUMERO : ");
  	    scanf("%d",&NRO);
  	    POS = BUSQUEDA(V, NRO , I);
  	    if(POS !=-1)
            printf("\n ERROR, EL NRO YA EXISTE ");
     }while(POS != -1);
    V[I]= NRO;
  }
}

/**********************************************************************************/
void MOSTRAR(int V[], int N)
{
  int I;
  printf("\n NUMEROS GUADADOS EN EL VECTOR ");
  for(I=0;I<N;I++)
    	printf("\n   %5d ", V[I]);
}

/**********************************************************************************/
int BUSQUEDA(int V[], int DATO, int N)
{
 int I,POSI;
 I=0;
 POSI=-1;
 while((POSI == -1) && (I<N))
   if (V[I]==DATO)
      POSI = I;
   else
      I++;
 return (POSI);
}

