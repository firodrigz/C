/****************************************************************************************
   LISTA DE PRECIOS
// EN UN NEGOCIO SE CONOCE LA LISTA DE PRECIOS DE 100 PRODUCTOS
//        EL CODIGO (NRO. ENTERO DE 3 cifras)
          PRECIO (real)
// CARGAR LOS DATOS EN VECTORES PARALELOS (CODIGO-PRECIO). .
// MOSTRAR LOS DATOS INGRESADOS
// INDICAR LOS PRODUCTOS MAS CAROS
// SE CONSULTA EL PRECIO, SEGUN EL CODIGO DEL PRODUCTO.
// FIN DE LA CONSULTA CODIGO DE PRODUCTO CERO.
****************************************************************************************/

#include<stdio.h>
#define N 5
int LeeControlRango(int,int);
void CARGA(int [], float [], int);
void MOSTRAR(int [], float [], int);
float MAXIMO(float [],int);
void INFO_PRODUCTO_MAS_CARO (float [], int[], float, int);
int BUSQUEDA(int[], int, int);
main()
{
  int COD[N],CP,POS, BAND=0;
  float PRE[N],PMAX;
  CARGA(COD, PRE ,N);
  MOSTRAR(COD, PRE , N);
  PMAX= MAXIMO(PRE,N);
  INFO_PRODUCTO_MAS_CARO (PRE, COD, PMAX, N);
  printf("\n INGRESAR EL CODIGO DE PRODUCTO A CONSULTAR (0 para terminar): ");
  scanf("%d",&CP);
  while(CP!=0)
  {
  	BAND = 1;
  	POS = BUSQUEDA(COD,CP,N);
  	if (POS >= 0)
  	  printf("\n PRECIO %.2f",PRE[POS]);
  	else
	  printf("\nNO EXISTE EL CODIGO (PRODUCTO)");

    printf("\n INGRESAR EL CODIGO DE PRODUCTO A CONSULTAR (0 para terminar): ");
    scanf("%d",&CP);
  }
  if (BAND == 0)
      printf("\n\n NO SE INGRESARON CONSULTAS");
}
///////////////////////////////////////////
int LeeControlRango(int LI ,int LS)
{
 int DATO, BANDERA=0;
 do{
 	if(BANDERA == 0)
        BANDERA = 1;
    else
 	    printf("\n ERROR, INGRESAR NUEVAMENTE ");
	scanf("%d",&DATO);
 }while(DATO<LI || DATO > LS);
 return (DATO);
}
///////////////////////////////////////////
void CARGA(int VC[], float VP[], int NN)
{
  int I;

  for(I=0;I<NN;I++)
  {
  	printf("\nINGRESAR CODIGO DE PRODUCTO  %d (3 CIFRAS) ",I+1 );
  	VC[I]= LeeControlRango(100,999);
  	printf("\nINGRESE PRECIO ");
  	scanf("%f",&VP[I]);
  }
}

////////////////////////////////////////////
void MOSTRAR(int VC[], float VP[], int NN)
{
  int I;
  printf("\nCODIGO PRODUCTO          PRECIO ");
  for(I=0;I<NN;I++)
    	printf("\n %d            %8.2f", VC[I], VP[I]);
}

///////////////////////////////////////////////

float MAXIMO(float V[],int NN)
{
 int I ;
 float MAXI= V[0];
  for(I=1;I<NN;I++)
    if (V[I]>MAXI)
       MAXI = V[I];
  return (MAXI);
}
////////////////////////////////////
void INFO_PRODUCTO_MAS_CARO (float VP[], int VC[], float PMAX, int NN)
{
 int I ;
 printf("\n PRECIO MAS CARO %.2f", PMAX);
 printf("\n PRODUCTOS MAS CAROS");
  for(I=0;I<NN;I++)
    if (VP[I]== PMAX)
        printf("\n %d ", VC[I]);
}
//////////////////////////////////////////
int BUSQUEDA(int V[], int DATO, int NN)
{
 int I,POSI;
 I=0;
 POSI=-1;
 while((POSI == -1) && (I<NN))
   if (V[I]==DATO)
      POSI = I;
   else
      I++;
 return (POSI);
}

