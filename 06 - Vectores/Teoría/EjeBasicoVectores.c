/****************************************************************************
 SE DISPONE DE UNA LISTA DE 10 VALORES ENTEROS
// A-) CARGAR LOSDATOS EN UN VECTOR LLAMADO VA
// B-) COPIAR VA EN VB
// C-) SUMAR LOS ELEMENTOS DEL VECTOR VA
// D-) VALOR PROMEDIO DEL VECTOR VA
// E-) CANTIDAD DE CEROS CONTENIDOS EN EL VECTOR VA
****************************************************************************/

#include<stdio.h>

/****************************  DECLARACION DE FUNCIONES ********************/
void CARGA (int [], int);
void MOSTRAR (int [], int);
void COPIAR (int[], int[], int);
int SUMAR (int [],int);
float PROMEDIO (int, int);
int CANTIDAD (int[], int, int);
/**************************************************************************/
main()
{
  int VA[10],VB[10], SUM, CANT;
  float PROM;

  CARGA(VA , 10 );  /*****  LLAMADA A FUNCION *****/
  printf ("\n\tVECTOR  VA");

  MOSTRAR(VA , 10 );   /*****  LLAMADA A FUNCION *****/

  COPIAR(VA, VB, 10);   /*****  LLAMADA A FUNCION *****/
  printf ("\n\tVECTOR  VB");
  MOSTRAR(VB , 10 );    /*****  LLAMADA A FUNCION *****/

  SUM = SUMAR (VA, 10);    /*****  LLAMADA A FUNCION *****/
  printf("\n\n LA SUMA DEL VECTOR A es %d ", SUM);

  printf("\n VALOR PROMEDIO DEL VECTOR A es %.2f", PROMEDIO(SUM,10)); /*****  LLAMADA A FUNCION *****/

  CANT = CANTIDAD(VA,0,10); /*****  LLAMADA A FUNCION *****/
  printf("\n CANTIDAD DE CEROS DEL VECTOR A es %d ", CANT);
}

/**********************   DEFINICION DE FUNCIONES *********************************/
/////////////////////////////////////////////////
void CARGA(int V[], int N)
{
  int I;
  for(I=0;I<N;I++)
  {
  	printf("\nINGRESAR VALOR EN POSICION %d ",I+1);
   	scanf("%d",&V[I]);
  }
}

//////////////////////////////////////////////
void MOSTRAR(int V[], int N)
{
  int I;
  printf("\nPOSICION   ELEMENTO ");
  for(I=0;I<N;I++)
    	printf("\n %2d         %5d", I+1, V[I]);
}
///////////////////////////////////////////////
void COPIAR (int V1[], int V2[], int N)
{
  int I;
  for(I=0;I<N;I++)
    V2[I]=V1[I];
}
///////////////////////////////////////////////
float PROMEDIO (int SUM, int N)
{
  return ((float)SUM/N );

}
///////////////////////////////////////////////
int CANTIDAD (int V[], int DATO, int N)
{
 int I , CONT = 0;
  for(I=0;I<N;I++)
    if(V[I]== DATO)
       CONT++;
 return CONT;
}
////////////////////////////////////////////////
int SUMAR(int V[],int N)
{
 int I , S=0;
  for(I=0;I<N;I++)
    S+=V[I];
  return (S);
}
////////////////////////////////////////////////
