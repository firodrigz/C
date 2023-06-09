/****************************************************************************************
  En un negocio trabajan 4 vendedores,   identificados por NUMERO de vendedor
  NUMERO CORRELATIVO DE 1 a 4 que se conoce.
  POr cada venta se ingresa:
   -Nro de Factura
   -Nro.(codigo) vendedor que realizo la factura
   -Importe.
  Esta informacion termina con Nro. de factura cero.
 Se pide:
 a-) Cantidad de facturas por vendedor
 b-) Recaudacion por vendedor
 c-) Recaudacion total del negocio
******************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
int LEECONTROLRANGO (int,int);
void MOSTRAR (int[],float[],int);

main()
{
	int  CANTFxV[4]={0},  NF, VDOR;
	float RECxV[4]={0}, RECTOT=0, IMPO;

	printf("\n INGRESO DE LAS VENTAS ");
	printf("\n ********************* ");
	printf("\nIngrese numero de factura (FINALIZA CON CERO): ");
	scanf("%d",&NF);

	while(NF!=0)
   {

	printf("\nIngrese numero de VENDEDOR QUE REALIZO LA VENTA (1 a 4): ");

	VDOR = LEECONTROLRANGO(1,4);

	printf("\nIngrese Importe de la venta: ");
	scanf("%f",&IMPO);

	CANTFxV[VDOR-1]++;
	RECxV[VDOR-1]+=IMPO;
	RECTOT+=IMPO;

	printf("\nIngrese numero de factura (FINALIZA CON CERO): ");
	scanf("%d",&NF);
   }
system ("cls");
MOSTRAR(CANTFxV,RECxV,4);

printf("\n\n\nLa recaudacion total es:  %.2f",RECTOT);

}

/*********************************************************************/
int LEECONTROLRANGO (int LI, int LS)
{
int DATO, BAND = 0;
  do{
  	  if (BAND == 0)
  	      BAND = 1;
  	  else
		  printf("\n INGRESAR NUEVAMENTE ");

	scanf("%d",&DATO);
	}while(DATO<LI||DATO>LS);

	return DATO;

}

/********************************************************************/

void MOSTRAR (int F[],float R[],int N)
{
	int I=0;
	printf("\nNUMERO(codigo)VENDEDOR     CANTIDAD DE FACTURAS     RECAUDACION ");
	printf("\n***************************************************************** ");
	for(I=0;I<N;I++)

	printf("\n\t %d                      %4d                 %8.2f",I+1, F[I], R[I]);
}

/*******************************************************************/
