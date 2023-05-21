/**********************************************************************
En un laboratorio se realizan ensayos. Por cada ensayo se registra:
// Nro. del ensayo y temperatura medida.
// Hay 5 ensayos
// Determinar:
// a-) la temperatura maxima medida
// b-) Nro. de ensayo de temperatura minima
// NOTA: TODOS LOS VALORS DE TEMPERATURA SON DISTINTOS
***********************************************************************/
#include <stdio.h>
main()
{
  int NE, TEMP, TMAX, TMIN, NEMIN, CONT, BANDERA= 0;

  for (CONT = 1 ; CONT <= 5 ; CONT ++)
  {
  	printf ("\n INGRESAR NRO. de ENSAYO ");
    scanf ("%d",&NE);
	printf ("\n INGRESAR TEMPERATURA ");
    scanf ("%d",&TEMP);

    if (BANDERA == 0)
     {
       TMAX = TEMP;
	   TMIN = TEMP;
	   NEMIN = NE;
	   BANDERA = 1;
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
  }
   printf ("\n LA TEMPERATURA MAXIMA ES %d", TMAX);
   printf ("\n EL NRO. DE ENSAYO DONDE SE PRODUJO LA TEMPERATURA MINIMA ES %d", NEMIN);
}
