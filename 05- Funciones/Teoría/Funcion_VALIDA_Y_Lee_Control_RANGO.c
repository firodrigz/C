/**** El siguiente programa utiliza las funciones para Leer Controlar Rango y la funcion VALIDA.****/
#include <stdio.h>

/*** DECLARACION DE FUNCIONES ***/
int VALIDA (int, int, int );
int LeeControlRangoNumero (int, int);

main()
{
  int NRO;

  printf ("\n INGRESAR UN NRO. ENTERO DE 3 CIFRAS POSITIVO : ");
  NRO = LeeControlRangoNumero (100, 999);             /**** LLAMADA A FUNCION ****/
  printf("\n SE INGRESO EL NUMERO %d CORRECTAMENTE ", NRO);

}

/***************************************************************************/
/**********  DEFINICION DE FUNCIONES **************************************/
/**************************************************************************/

int VALIDA (int DATO, int LI, int LS)
{
    if ( DATO < LI || DATO > LS )
  	      return 0;      /*** SI RETORNA  0 SIGNIFICA QUE SE INGRESO MAL***/
  	  else
		  return 1;      /*** SI RETORNA  1 SIGNIFICA QUE SE INGRESO BIEN***/
}

/***************************************************************************/
int LeeControlRangoNumero (int LI, int LS)
{
  int DATO;
  int BAND = 0; // ES una bandera. Su objetivo es para que la interfaz sea mas amigable
  do{
  	  if (BAND == 0)
  	      BAND = 1;
  	  else
		  printf("\n INGRESAR NUEVAMENTE ");
	  scanf ("%d", &DATO);
    }while ( VALIDA ( DATO, LI, LS)== 0);

  return DATO;
}

/***************************************************************************/


