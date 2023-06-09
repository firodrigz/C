/*****************************************************************************************
A-) GUARDAR 5 NROS. ENTEROS DISTINTOS DE 3 CIFRAS  EN UN VECTOR
B-) MOSTRAR LOS DATOS DEL VECTOR
*****************************************************************************************/
#include<stdio.h>
#define TAM 5

int LeeControlRango(int,int);
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
  	    printf("\nINGRESAR NUMERO de 3 CIFRAS : ");
  	    NRO = LeeControlRango(100,999);
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
/**********************************************************************************/
int LeeControlRango(int LI ,int LS)
{
 int DATO, BANDERA=0;
 do{
 	if(BANDERA == 0)
        BANDERA = 1;
    else
 	    printf("\n ERROR, INGRESAR NUEVAMENTE ");
	scanf("%d",&DATO);
 }while(DATO<LI || DATO > LS);
 return (DATO);
}
