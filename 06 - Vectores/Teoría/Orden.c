














/***********************************************************************************
  ORDENAR EL VECTOR EN FORMA ASCENDENTE
*************************************************************************************/

#include <stdio.h>
void ORDEN(int[],int);
void INFORME(int[],int);

main()
{ int VECTOR[5]={92, 173, 45, 134, 16};
  printf("\n ANTES DEL ORDEN");
  INFORME(VECTOR,5);
  ORDEN(VECTOR,5);
  printf("\n DESPUES DEL ORDEN");
  INFORME(VECTOR,5);
}

/*************************************************************************************/
void ORDEN(int V[],int N)            // DESORDENADO !=0 VECTOR DESORDENADO    ***** DESORDENADO = 0 VECTOR ORDENADO
{ int I,DESORDENADO,COTA, AUX;
  COTA =N;
  DESORDENADO = 1; // vector desordenado
  while(DESORDENADO!=0)
   { DESORDENADO = 0;   // vector ordenado
     for(I=1;I<COTA;I++)
        if(V[I-1] < V[I])
          { AUX = V[I-1];
            V[I-1] = V[I];
            V[I] = AUX;
            DESORDENADO = I;
          }

      // INFORME(V,COTA);
     COTA=DESORDENADO;
    }
}

/*************************************************************************************/
void INFORME(int V[],int N)
{ int I;
  printf(" \n");
  for(I=0;I<N;I++)
    printf("\t %3d   ",V[I]);
}
/*************************************************************************************/
