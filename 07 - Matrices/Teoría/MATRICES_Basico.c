/************************************************************************************
Dado un conjunto de valores enteros leerlos y luego:
a) Cargar una matriz M1 de 3 x 2 por filas y una matriz M2 de 3 x 4 por columnas.
b) La suma de los elementos de las columnas de M1.
c) La suma de los elementos de las filas de M1.
d) La suma total de los elementos de M1.
e) El valor promedio de M1.
f) Máximo valor de la matriz M1 y en que posición se encuentra.

NOTA: puede haber varios máximos o mínimos
*************************************************************************************/

#include <stdio.h>

void CARGAxFILAS(int[][2],int,int);
void CARGAxCOLUMNAS(int[][4],int,int);
void MOSTRAR_MATRIZ_1 (int[][2],int,int);
void SUMA_COLUMNAS(int[][2],int[],int,int);
void MOSTRAR_MATRIZ_2 (int[][4],int,int);
void SUMA_FILAS(int[][2],int[],int,int);
void MOSTAR_VECTOR(int[],int);
int SUMA_MATRIZ(int[][2],int,int);
int MAXIMO_MATRIZ (int[][2],int,int);
void INFORME_MAXIMO_MATRIZ(int[][2],int,int,int);
/************************************************************************************/
main()
{
  int M1[3][2], M2[3][4];
  int SC[2]= {0}, SF[3]= {0};
  int SUM, MAX;

  printf("\n CARGA DE LOS ELEMENTOS POR FILAS  MATRIZ M1 \n");
  CARGAxFILAS(M1, 3,2);

  printf("\n \nELEMENTOS DE LA MATRIZ M1 \n" );
  MOSTRAR_MATRIZ_1 (M1, 3, 2);

  printf("\n \nCARGA DE LOS ELEMENTOS POR COLUMNAS  MATRIZ M2\n");
  CARGAxCOLUMNAS(M2,3,4);

  printf("\n \nELEMENTOS DE LA MATRIZ M2 \n" );
  MOSTRAR_MATRIZ_2 (M2,3,4);

   // LLAMADA FUNCION PARA OBTENER LA SUMA DE LOS ELEMENTOS DE LAS COLUMNAS
  SUMA_COLUMNAS(M1, SC, 3, 2);
  printf("\n \n\n SUMA DE LOS ELEMENTOS DE LAS COLUMNAS DE LA MATRIZ M1 \n" );
  MOSTAR_VECTOR(SC,2);

  // LLAMADA FUNCION PARA OBTENER LA SUMA DE LOS ELEMENTOS DE LAS FILAS
  SUMA_FILAS(M1, SF, 3,2);
  printf("\n \n \n SUMA DE LOS ELEMENTOS DE LAS FILAS  DE LA MATRIZ M2 \n" );
  MOSTAR_VECTOR(SF,3);

  // LLAMADA FUNCION PARA OBTENER LA SUMA DE LOS ELEMENTOS DE LA MATRIZ
  SUM=SUMA_MATRIZ(M1, 3, 2);
  printf("\n\n \n LA SUMA DE LOS ELEMENTOS DE LA MATRIZ M1 ES %d ",SUM);

  printf ("\n \n \n VALOR PROMEDIO DE LA MATRIZ M1 %.2f",(float)SUM/(3*2));

  // LLAMADA A FUNCION PARA OBTENER EL VALOR MAXIMO DE LA MATRIZ
   MAX = MAXIMO_MATRIZ (M1, 3, 2);
  // LLAMADA A FUNCION PARA OBTENER POSICIONES (FILA COLUMNA) DONDE SE ENCUENTRAN LOS MAXIMOS
   INFORME_MAXIMO_MATRIZ(M1, MAX, 3, 2);
}
/************************************************************************************/
/**************************  DEFINICION DE  FUNCIONES *******************************/
/************************************************************************************/
void CARGAxFILAS(int M[][2],int F,int C)
{
  int I,J;
  for(I=0;I< F; I++)
      for(J=0;J< C; J++)
       {
        printf("\nINGRESAR ELEMENTO EN FILA %d COLUMNA %d : ",I+1,J+1);
        scanf("%d",&M[I][J]);
       }
}
/************************************************************************************/
void CARGAxCOLUMNAS(int M[][4],int F,int C)
{
  int I,J;
  for(J=0;J< C; J++)
      for(I=0;I< F; I++)
       {
        printf("\nINGRESAR ELEMENTO EN COLUMNA %d FILA %d : ",J+1, I+1);
        scanf("%d",&M[I][J]);
       }
}
/************************************************************************************/
void MOSTRAR_MATRIZ_1 (int M[][2],int F,int C)
{
  int I,J;
  for(J=0;J< C; J++)
       printf("\t%d",J+1);
  printf("\n\t**********");
  for(I=0;I< F; I++)
  {
    printf("\n%d",I+1);
     for(J=0;J< C; J++)
       printf ("\t%d",M[I][J]);
  }
}
/************************************************************************************/
void MOSTRAR_MATRIZ_2(int M[][4],int F,int C)
{
 int I,J;
  for(J=0;J< C; J++)
       printf("\t%d",J+1);
  printf("\n\t***************************");
  for(I=0;I< F; I++)
  {
    printf("\n%d",I+1);
     for(J=0;J< C; J++)
       printf ("\t%d",M[I][J]);
  }
}

/************************************************************************************/
void SUMA_COLUMNAS(int M[][2],int V[],int F,int C)
{
 int I,J;
 for(J=0;J< C; J++)
    for(I=0;I< F; I++)
      V[J] += M[I][J];
}
/************************************************************************************/
void SUMA_FILAS(int M[][2],int V[],int F,int C)
{
int I,J;
  for(I=0;I< F; I++)
   for(J=0;J< C; J++)
      V[I] += M[I][J];
}
/************************************************************************************/
void MOSTAR_VECTOR(int V[],int N)
{int I;
 for(I=0;I< N; I++)
    printf ("\n\t%d", V[I]);
}
/************************************************************************************/
int SUMA_MATRIZ(int M[][2], int F, int C)
{
int I,J, S = 0;
  for(I=0;I< F; I++)
   for(J=0;J< C; J++)
      S+= M[I][J];
  return (S);
}

/************************************************************************************/
int MAXIMO_MATRIZ (int M[][2], int F, int C)
{
 int I,J, MAXI;
 MAXI = M[0][0];
  for(I=0;I< F; I++)
   for(J=0;J< C; J++)
      if (M[I][J] > MAXI)
          MAXI = M[I][J];

  return (MAXI);
}
/************************************************************************************/
void INFORME_MAXIMO_MATRIZ(int M[][2], int MAXI, int F, int C)
{
 int I,J;
 printf ("\n \n \n VALOR MAXIMO DE LA MATRIZ %d ",MAXI);
  for(I=0;I< F; I++)
   for(J=0;J< C; J++)
      if (M[I][J] == MAXI)
        printf("\n \t \t FILA %d   COLUMNA %d ", I+1 , J+1);
}
/************************************************************************************/











