#include<stdio.h>
#define CANT 5
/***************************** DECLARACION DE FUNCIONES ****************/
void CARGA(int [],int);
void MOSTRAR(int [],int);
main()
{
  int VEC[CANT],I;

  CARGA(VEC,CANT);  /*** LLAMADA A FUNCION ***/

  MOSTRAR(VEC,CANT); /*** LLAMADA A FUNCION ***/

  printf("\nNUMEROS MAYORES AL ULTIMO INGRESADO ");
  for (I=0;I<CANT-1;I++)
    if (VEC[I] > VEC[CANT-1])
	   printf("\n\t %d",VEC[I]);


}
/**************** DEFINICION DE FUNCIONES *******/
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
void MOSTRAR(int V[],int N)
{
 int I;
 printf("\n POSICION     ELEMENTO");
 for(I=0;I<N;I++)
   printf("\n   %2d            %4d",I+1,V[I]);
}
