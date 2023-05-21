/****************************************************************************
En un laboratorio se realizan ensayos. Por cada ensayo se registra:
// Nro. del ensayo y temperatura medida.
// LA INFORMACION TERMINA CON NRO. DE ENSAYO NEGATIVO O CERO
// Determinar:
// a-) la temperatura maxima medida
// b-) Nro. de ensayo de temperatura minima
// NOTA: TODOS LOS VALORS DE TEMPERATURA SON DISTINTOS
/***************************************************************************/
#include <stdio.h>
main()
{
  int NE, TEMP, TMAX, TMIN, NEMIN, CONT=0;

  printf ("\n INGRESAR NRO. de ENSAYO (TERMINA CON NEGATIVO O CERO) ");
  scanf ("%d",&NE);
  while (NE > 0)
  {
  	CONT ++;
	printf ("\n INGRESAR TEMPERATURA ");
    scanf ("%d",&TEMP);

    if (CONT == 1)
     {
       TMAX = TEMP;
	   TMIN = TEMP;
	   NEMIN = NE;
     }
    else
       if (TEMP > TMAX)
           TMAX = TEMP;
       else
	      if (TEMP < TMIN)
	         {
	           TMIN = TEMP;
			   NEMIN = NE;
	         }

  printf ("\n INGRESAR NRO. de ENSAYO (TERMINA CON NEGATIVO O CERO)");
  scanf ("%d",&NE);
  }
   if (CONT > 0)
   {
    printf ("\n LA TEMPERATURA MAXIMA ES %d", TMAX);
    printf ("\n EL NRO. DE ENSAYO DONDE SE PRODUJO LA TEMPERATURA MINIMA ES %d", NEMIN);
   }
   else
    printf("\n NO SE INGRESARON ENSAYOS");
}
