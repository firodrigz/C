/*****************************************************
Se dispone de una lista de números (MÁXIMO 10)
Fin de la carga número igual a cero)
INFORMAR LOS NUMEROS INGRESADOS.
*****************************************************/

#include<stdio.h>

int CARGA(int [],int);
void MOSTRAR(int [],int);
main()
{ int VEC[10],CANT;
  CANT = CARGA(VEC,10);
  MOSTRAR(VEC,CANT);
}
///////////////////////////////////////////
int CARGA(int V[],int N)
{ int I = 0, NRO;
  printf("\nINGRESAR ELEMENTO (TERMINA CON CERO) MAXIMO 10 ELEMENTOS ");
  scanf("%d",&NRO);
  while(NRO != 0  && I < N)
  {
     V[I] = NRO;
     I++;
    printf("\nINGRESAR ELEMENTO (TERMINA CON CERO) MAXIMO 10 ELEMENTOS ");
    scanf("%d",&NRO);
  }
  return (I);
}

////////////////////////////////////////////
void MOSTRAR(int V[],int N)
{ int I;
 printf("\n   POSICION     ELEMENTO");
 for(I=0;I<N;I++)
    printf("\n    %d   \t %4d  ",I+1, V[I]);
}
