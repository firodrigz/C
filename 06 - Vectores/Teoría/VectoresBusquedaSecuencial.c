/***************************************************************
 En un negocio trabajan 4 vendedores,  identificados por Numero de vendedor de 3 cifras, que se conoce.
 Por cada venta se ingresa:
	Nro de Factura-
    Nro.(codigo)vendedor que realizo la factura
	Importe.
 Esta informacion termina con Nro. de factura cero.
 Se pide:
 a-) Cantidad de facturas por vendedor
 b-) Recaudacion por vendedor
 c-) Recaudacion total del negocio
***************************************************************/
#include<stdio.h>
#include<stdlib.h>

int LEECONTROLRANGO (int,int);
int BUSQUEDA (int[],int,int);
void CARGA (int[],int);
void MOSTRAR (int[],int[],float[],int);

main()
{	int CODV[4], CANTFxV[4]={0}, POS, NF, VDOR;
	float RECxV[4]={0}, RECTOT=0, IMPO;

	CARGA(CODV,4);

    system ("cls");
	printf("\n INGRESO DE LAS VENTAS ");
	printf("\n ********************* ");
	printf("\nIngrese numero de factura (FINALIZA CON CERO): ");
	scanf("%d",&NF);

	while(NF!=0)
   {
	printf("\nIngrese numero de VENDEDOR QUE REALIZO LA VENTA: ");
	scanf("%d",&VDOR);

	POS=BUSQUEDA(CODV,VDOR,4);
	if(POS>=0)
	{  	printf("\nIngrese Importe de la venta: ");
		scanf("%f",&IMPO);

		CANTFxV[POS]++;
		RECxV[POS]+=IMPO;
		RECTOT+=IMPO;
	}
	else
		printf("\nERROR CODIGO VENDEDOR ");

	printf("\nIngrese numero de factura (FINALIZA CON CERO): ");
	scanf("%d",&NF);
  }

system ("cls");
MOSTRAR(CODV,CANTFxV,RECxV,4);
printf("\n\n\nLa recaudacion total es:  %.2f",RECTOT);

}

/*************************************************************/

int LEECONTROLRANGO (int LI, int LS)
{
int DATO, BAND = 0;
  do{
  	  if (BAND == 0)
  	      BAND = 1;
  	  else
		  printf("\n ERROR, INGRESAR NUEVAMENTE ");

	scanf("%d",&DATO);
	}while(DATO<LI||DATO>LS);

	return DATO;

}
/************************************************************/
void CARGA (int V[], int N)
{
	int I, POS, DATO_VEND;

	for(I=0;I<N;I++)
	{
	  do{
	      printf("\nIngresar  NRO. de vendedor (3 CIFRAS) ");
	      DATO_VEND = LEECONTROLRANGO(100,999);

          POS = BUSQUEDA( V, DATO_VEND,I);

	      if (POS >=0)
             printf("\nNUMERO DE VENDEDOR REPETIDO!!!!!!!");

         }while(POS >=0);

         V[I] = DATO_VEND;
      }
}
/**********************************************************/
int BUSQUEDA (int V[],int D, int N)
{
	int I=0,POSI=-1;
    while(POSI==-1&&I<N)
	{
		if(V[I]==D)
		    POSI=I;
		else
		    I++;
	}
   	return POSI;
}

/*********************************************************/

void MOSTRAR (int V[],int F[],float R[],int N)
{
	int I=0;
	printf("\nNUMERO(codigo)VENDEDOR     CANTIDAD DE FACTURAS     RECAUDACION ");
	printf("\n***************************************************************** ");
	for(I=0;I<N;I++)

	printf("\n\t %d                  %4d                    %8.2f",V[I],F[I],R[I]);
}

/********************************************************/
