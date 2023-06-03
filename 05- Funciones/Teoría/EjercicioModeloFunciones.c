
/***********************************************************************************************************************
 UNA EMPRESA DE SUBTES POSEE VARIAS LINEAS QUE REALIZAN SU RECORRIDO EN CAPITAL FEDERAL Y DESEA OBTENER UNA ESTADISTICA
 DE LA RECAUDACION, PARA ELLO SE DISPONE, DE PLANILLAS DIARIAS CONTENIENDO:
    Día de la recaudación (1 a 30) Función LeeControlRango
	Línea de subte ('A', 'B','C', 'D') Funcion LeeControlLetra
	Recaudación del día. (mayor a cero)  Funcion LeeControlMayor
 Esta información termina con Día de recaudación igual a cero.
 Se pide:
 a-) Recaudación por línea de subte.
 b-) Porcentaje de recaudacion de la línea 'A' solamente.
************************************************************************************************************************/

#include <stdio.h>
#include <ctype.h>
/******************************************* DECLARACIONES DE FUNCIONES **************************/
int LeeControlRango (int, int);    // Declaracion Funciones
char LeeControlLetra (char, char, char, char);
float LeeControlMayor (float);
float PORCENTAJE(float,float);
/************************************************************************************************/
main()
{
  int DIA;
  char LI;
  float REC, RECTOT, RA, RB, RC, RD;

  RECTOT=RA=RB= RC=RD =0;

  printf ("\n INGRESAR UN NRO. DE DIA ( FINALIZA CON CERO ): ");
  DIA = LeeControlRango (0, 30);  // llamada a la funcion
  while (DIA !=0)
  {

    printf ("\n INGRESAR LINEA DE SUBTE ( A B C D ) ");
    LI = LeeControlLetra ('A', 'B', 'C', 'D');  // llamada a la funcion

   printf ("\n INGRESAR RECAUDACION DEL DIA ");
   REC = LeeControlMayor (0);
   RECTOT += REC;
   switch (LI)
   {
   	 case 'A': RA +=REC;  break;
   	 case 'B': RB +=REC;  break;
	 case 'C': RC +=REC;  break;
	 case 'D': RD +=REC;  break;
   	}

  printf ("\n INGRESAR UN NRO. DE DIA ( FINALIZA CON CERO ): ");
  DIA = LeeControlRango (0, 30);  // llamada a la funcion
 }
 if(RECTOT != 0)
 {
  printf ("\n RECAUDACION DEL SUBTE A %.2f",RA);
 printf ("\n RECAUDACION DEL SUBTE B %.2f",RB);
 printf ("\n RECAUDACION DEL SUBTE C %.2f",RC);
 printf ("\n RECAUDACION DEL SUBTE D %.2f",RD);
 printf("\n EL PORCENTAJE DE RECAUDACION DE LA ESTACION  \"A\" ES  %.2f %%", PORCENTAJE (RA,RECTOT));

 }
 else
   printf ("\n NO SE INGRESARON DATOS");

}

/******************************************* DEFINICIONES DE FUNCIONES **************************/
int LeeControlRango (int LI, int LS)
{
  int DATO;
  int BAND = 0; // ES una bandera. Su objetivo es para que la interfaz sea mas amigable
  do{
  	  if (BAND == 0)
  	      BAND = 1;
  	  else
		  printf("\n INGRESAR NUEVAMENTE ");
	  scanf ("%d", &DATO);
    }while (( DATO < LI ) || (DATO > LS ));

  return DATO;
}
/***********************************************************************************************/
char LeeControlLetra (char L1, char L2, char L3, char L4)
{
  char DATO;
  int BAND = 0; // ES una bandera. Su objetivo es para que la interfaz sea mas amigable
  do{
  	  if (BAND == 0)
  	      BAND = 1;
  	  else
		  printf("\n INGRESAR NUEVAMENTE ");
	      fflush(stdin);
		  scanf ("%c", &DATO);
		  DATO = toupper(DATO);
    }while ( (DATO != L1)  &&  (DATO != L2 ) && (DATO != L3)  && (DATO !=L4));

  return DATO;
}

/**********************************************************************************************/
float LeeControlMayor (float VALOR)
{
  float DATO;
  int BAND = 0; // ES una bandera. Su objetivo es para que la interfaz sea mas amigable
  do{
  	  if (BAND == 0)
  	      BAND = 1;
  	  else
		  printf("\n INGRESAR NUEVAMENTE ");
	  scanf ("%f", &DATO);
    }while ( DATO <= VALOR);

  return DATO;
}

/**********************************************************************************************/
float PORCENTAJE(float X ,float Z)
{
	return (X/Z *100);
}
/**********************************************************************************************/





