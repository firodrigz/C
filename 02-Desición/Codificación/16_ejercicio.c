/********************************************************************************************************************************************
 Un negocio vende distintos artículos identificados por un código, según se muestra:
 • código 1; 10; 100:   10 pesos la unidad
 • código 2; 22; 222:    7 pesos la unidad. La caja de 10 unidades vale 65 pesos.
 • código 3; 33:         3 pesos la unidad. Si la compra es por más de 10 unidades se hace un descuento del 10% sobre el total de la compra.
 • código 4; 44:       1 peso la unidad.

 Confeccionar un programa que ingrese como dato el código de un artículo y la cantidad a comprar y se informe
 el importe de la compra, con las siguientes leyendas:   CODIGO  xxxxx CANTIDAD xxxx IMPORTE A PAGAR $ xxxx.xx

 **********************************************************************************************************************************/
#include <stdio.h>
main()
{
  int COD,  CANT , BAND =0;
  float IMPO;
  printf ("\n INGRESAR CODIGO ARTICULO ");
  scanf ("%d",&COD);
  printf("\n INGRESAR CANTIDAD DE PRODUCTOS ");
  scanf("%d",&CANT);
  switch (COD)
  {
  	case 1 : case 10 : case 100 : IMPO = CANT * 10; break;
  	case 2 : case 22 : case 222 : IMPO = CANT / 10 * 65 + CANT % 10 * 7; break;
  	case 3 : case 33 : IMPO = CANT *3;
  	                   if (CANT > 10)
                           IMPO = IMPO * 0.9;
                       break;

    case 4 : case 44 : IMPO = CANT *1; break;

  	default : BAND = 1;
  }
  if (BAND == 0)
    printf ("\n ARTICULO %d  CANTIDAD %d  IMPORTE A PAGAR %.2f\n\n", COD, CANT, IMPO);
  else
    printf("\n ERROR EN CODIGO ARTICULO\n\n");
}
