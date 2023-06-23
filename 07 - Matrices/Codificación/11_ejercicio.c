/*****************************************************************************************
Una empresa de peajes, en una determinada zona tiene 5 cabinas para el cobro de peajes.
Desea obtener una estadistica diaria de la recaudacion de cada cabina en cada hora entre las 0 y 6 horas.
Se ingresa:  Nro. cabina (1 a 5)  Hora (0 a 6) Importe del peaje.
Finaliza con Nro. cabina cero.
*****************************************************************************************/

#include <stdio.h>

void MOSTRAR_MATRIZ_PEAJE (float[][7],int,int);
int LEECONTROL (int, int);
float LEEMAYOR(float);

main()
{
  float MP[5][7]={{0}}, IMPO;
  int NC,H;

  printf("\n INGRESAR NRO. DE CABINA (1 a 5 - 0 PARA TERMINAR) ");
  NC = LEECONTROL(0,5);
  while(NC != 0)
  {
      printf("\n INGRESAR HORA (0 a 6) ");
      H = LEECONTROL(0,6);
      printf("\n INGRESAR IMPORTE ");
      IMPO = LEEMAYOR(0);
      MP[NC-1][H] += IMPO;
      printf("\n INGRESAR NRO. DE CABINA (1 a 5 - 0 PARA TERMINAR) ");
      NC = LEECONTROL(0,5);
  }
  MOSTRAR_MATRIZ_PEAJE (MP, 5, 7);
  printf("\n\n\n");

 }
/***************************************************************************************
***************************** DEFINICION DE FUNCIONES **********************************
***************************************************************************************/
void MOSTRAR_MATRIZ_PEAJE (float M[][7],int F,int C)
{
  int I,J;
  printf ("\n \t\t\t\t\tRECAUDACION SEGUN CABINA ENTRE LAS 0 y 6 HORAS");
  printf("\n\t\n\t\t\t\t\t\t H    O    R    A ");
  printf ("\n     CABINA");
  for(J=0;J< C; J++)
       printf ("\t     %d\t",J);
  printf("\n\t\t  ********************************************************************************************************");
  for(I=0;I< F; I++)
  {
    printf("\n\t%d",I+1);
     for(J=0;J< C; J++)
       printf ("\t%8.2f",M[I][J]);
  }
}

/**************************************************************************************/
int LEECONTROL (int LI, int LS)
{  int DATO, MARCA =0;
   do{
        if( MARCA == 1)
             printf("\n INGRESE NUEVAMENTE: ");
        scanf("%d",&DATO);
        MARCA = 1;
      }while(DATO < LI || DATO > LS);
     return (DATO);
}

/**************************************************************************************/
float LEEMAYOR(float VALOR)
{  float DATO;
   int  MARCA =0;
   do{
        if( MARCA == 1)
             printf("\n INGRESE NUEVAMENTE: ");
        scanf("%f",&DATO);
        MARCA = 1;
      }while(DATO <= VALOR);
     return (DATO);
}
/**************************************************************************************/



