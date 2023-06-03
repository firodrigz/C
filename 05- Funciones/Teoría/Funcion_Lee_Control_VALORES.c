/*** El siguiente programa utiliza la funcion Lee Control Valor
     para NumeroS enteros y para caracteres ***/

#include <stdio.h>
#include <ctype.h>


/*** DECLARACION DE FUNCIONES ***/
int LeeControlNumeroValores (int, int );
char LeeControlLetraValores (char, char);

main()
{
  int NRO;
  char LE;

  printf ("\n INGRESAR EL NRO. ENTERO 1000 o   O CERO : ");
  NRO = LeeControlNumeroValores (1000, 0);                   /**** LLAMADA A FUNCION ****/
  printf("\n SE INGRESO EL NUMERO %d CORRECTAMENTE ", NRO);

  printf ("\n INGRESAR EL NRO. ENTERO -5 o   O 1000000 : ");
  NRO = LeeControlNumeroValores (-5, 1000000);                   /**** LLAMADA A FUNCION ****/
  printf("\n SE INGRESO EL NUMERO %d CORRECTAMENTE ", NRO);

  printf ("\n INGRESAR UNA LETRA 'F' O 'M' : ");
  LE = LeeControlLetraValores ('F', 'M');                    /**** LLAMADA A FUNCION ****/
  printf("\n SE INGRESO  %c CORRECTAMENTE ", LE);
 }

/***************************************************************************/
/**********  DEFINICION DE FUNCIONES **************************************/
/**************************************************************************/
int LeeControlNumeroValores (int X, int Z)
{
  int DATO;
  int BAND = 0; // ES una bandera. Su objetivo es para que la interfaz sea mas amigable
  do{
  	  if (BAND == 0)
  	      BAND = 1;
  	  else
		  printf("\n INGRESAR NUEVAMENTE ");
	  scanf ("%d", &DATO);
    }while (( DATO != X) && (DATO != Z));

  return DATO;
}

/********************************************************************************/
char LeeControlLetraValores (char L1, char L2)
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
    }while (( DATO != L1 ) && (DATO != L2));

  return DATO;
}

/********************************************************************************/


