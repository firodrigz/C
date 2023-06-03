
/**El siguiente programa utiliza las funciones para Leer Controlar Rango y un Valor
   para Numero enteros y para caracteres***/
#include <stdio.h>
#include <ctype.h>

/*** DECLARACION DE FUNCIONES ***/
int LeeControlRangoNumeroValor (int, int, int);
char LeeControlRangoLetraValor (char, char, char);

main()
{
  int NRO;
  char LE;

  printf ("\n INGRESAR UN NRO. ENTERO DE 3 CIFRAS  O CERO : ");
  NRO = LeeControlRangoNumeroValor (100, 999, 0);           /**** LLAMADA A FUNCION ****/
  printf("\n SE INGRESO EL NUMERO %d CORRECTAMENTE ", NRO);

  printf ("\n INGRESAR UNA LETRA DEL ALFABETO O * : ");
  LE = LeeControlRangoLetraValor ('A', 'f', '*');           /**** LLAMADA A FUNCION ****/
  printf("\n SE INGRESO  %c CORRECTAMENTE ", LE);
}

/***************************************************************************/
/**********  DEFINICION DE FUNCIONES **************************************/
/**************************************************************************/
int LeeControlRangoNumeroValor (int LI, int LS, int VALOR)
{
  int DATO;
  int BAND = 0; // ES una bandera. Su objetivo es para que la interfaz sea mas amigable
  do{
  	  if (BAND == 0)
  	      BAND = 1;
  	  else
		  printf("\n INGRESAR NUEVAMENTE ");
	  scanf ("%d", &DATO);
    }while (( DATO < LI  || DATO > LS ) && (DATO != VALOR));

  return DATO;
}

/********************************************************************************/
char LeeControlRangoLetraValor (char L1, char L2, char L3)
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
    }while (( DATO < L1  || DATO > L2 ) && (DATO != L3));

  return DATO;
}
/********************************************************************************/


