/***************************************************************************************
 MAXIMO DE UN VECTOR
***************************************************************************************/

#include<stdio.h>
void CARGA(int [],int);
int MAXIMO(int [],int);
void INFO_MAXIMO (int [], int, int);
main()
{
  int VEC[5],MAX;
  CARGA(VEC,5);
  MAX= MAXIMO(VEC,5);
  INFO_MAXIMO(VEC, MAX, 5);

}
///////////////////////////////////////////
void CARGA(int V[],int N)
{
  int I;
  for(I=0;I<N;I++)
  {
  	printf("\nINGRESAR ELEMENTO EN POSICION %d  ",I+1);
  	scanf("%d",&V[I]);
  }
}
////////////////////////////////////////////
int MAXIMO(int V[],int N)
{
 int I , MAXI= V[0];
  for(I=1;I<N;I++)
    if (V[I]>MAXI)
       MAXI = V[I];
  return (MAXI);
}
////////////////////////////////////
void INFO_MAXIMO(int V[],int MAXI, int N)
{
 int I ;
 printf("\n VALOR MAXIMO DEL VECTOR %d",MAXI);
  for(I=0;I<N;I++)
    if (V[I]== MAXI)
        printf("\n POSICION %d ", I+1);
}



