/*****************************************************************************************
Se dispone de 5 números enteros distintos.
Se pide:
A-) Guardar los 5 Nros. en un vector VEC
B-) Ingresar un Nro. entero.
C-) Indicar en que posición se encuentra el Nro. ingresado en B-) en el vector VEC
*****************************************************************************************/
#include<stdio.h>
#define TAM 5

void CARGA (int [], int );
void MOSTRAR (int [], int );
int BUSQUEDA (int[], int, int);
main()
{
  int VEC[TAM], NRO, POS;

  CARGA(VEC,TAM);
  MOSTRAR(VEC,TAM);

  printf("\n\n INGRESAR NRO A BUSCAR: ");
  scanf("%d",&NRO);

  POS = BUSQUEDA(VEC, NRO , TAM);

  if (POS >= 0)
  	  printf("\n EL NRO %d SE ENCONTRO EN LA POSICION %d ",NRO, POS+1);
  else
	  printf("\nNO EXISTE %d EN EL VECTOR ",NRO);

}
///////////////////////////////////////////

void CARGA(int V[], int N)
{
  int I;
  for(I=0;I<N;I++)
  {
  	printf("\nINGRESAR NROS EN EL VECTOR  ");
  	scanf("%d",&V[I]);
  }
}

////////////////////////////////////////////
void MOSTRAR(int V[], int N)
{
  int I;
  printf("\n NUMEROS GUADADOS EN EL VECTOR ");
  for(I=0;I<N;I++)
    	printf("\n   %5d ", V[I]);
}


//////////////////////////////////////////
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

