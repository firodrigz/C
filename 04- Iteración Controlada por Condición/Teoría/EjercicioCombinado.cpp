/********************************************************************
  En una farmacia por cada venta, se registra.
    Nro de factura (4 cifras)
    Importe (mayor que cero)
    Codigo que indica la forma de pago. Este codigo puede ser:
       'M' si fue efectuada a una mutual, con el 30% de descuento.
       'C' si fue venta de contado efectivo, 10% de descuento.
       'T' si la venta fue con tarjeta, 15% de recargo.
   La informacion termina con Nro. de factura cero
   Por cierre de caja se debe informar:
      a)Recaudacion por cada forma de pago.
      b)Nro. de Factura de mayor importe (se supone unico)
      c)Ventas totales del dia.
  ******************************************************************/

#include <stdio.h>
#include <ctype.h>

main()
{
 int NF, MAXNF, CONT = 0;
 float impo,impom, impoc, impot,vta_total, MAXIMPO;
 char cod;
 impom=impoc=impot=0;

 do{
	 printf("\n Ingresar Nro. de Factura (4 cifras) TERMINA CON CERO : ");    // AQUI ESTA LA VALIDACION DEL NRO DE FACTURA
     scanf("%d",&NF);
   } while(((NF < 1000)|| (NF > 9999)) && (NF != 0));


 while (NF !=0)       // CONDICION DE FIN
 {   // empieza while de condicion de fin
  CONT ++;  				// cuenta ventas

 do{
     fflush(stdin);		// limpia el buffer
     printf("\n Ingresar el codigo del pago ( M (Mutual) - C (Contado) - T (Tarjeta) : ");           // AQUI ESTA LA VALIDACION DE LA FORMA DE PAGO
     scanf("%c",&cod);
     cod = toupper(cod);	// convierte a mayuscula el caracter
   } while(cod !='M' && cod !='C' && cod !='T');

  do{

     printf("\n Ingresar importe de la venta (mayor que cero) : ");       // AQUI ESTA LA VAIDACION DEL IMPORTE
     scanf("%f",&impo);
   }while (impo <= 0);


    switch (cod)
    {
     case 'M': impo = impo * 0.70;
	           impom += impo;
                break;
     case 'C':  impo = impo *0.90;
                impoc += impo;
	          	break;
     case 'T':  impo = impo * 1.15;
	            impot+= impo;
    }

   if (CONT == 1)
     {
     	MAXIMPO = impo;
     	MAXNF = NF;
	 }
   else
      if (impo > MAXIMPO)
        {
		 MAXIMPO = impo;
		 MAXNF = NF;
        }

    do{

	    printf("\n Ingresar Nro. de Factura (4 cifras) TERMINA CON CERO : ");    // AQUI ESTA LA VALIDACION DEL NRO DE FACTURA
        scanf("%d",&NF);
       } while(((NF < 1000)|| (NF > 9999)) && (NF != 0));

  }  // finaliza while de condicion de fin

 if(CONT > 0)
 {
   vta_total = impom + impoc + impot;

   printf("\n\nRECAUDACION MUTUAL :  %.2f PESOS", impom);
   printf("\n\nRECAUDACION CONTADO :  %.2f  PESOS", impoc);
   printf("\n\nRECAUDACION TARJETA :  %.2f  PESOS", impot);
   printf("\n\nLAS VENTAS TOTALES DEL DIA ES DE :  %.2f  PESOS", vta_total);
   printf ("\n NUMERO DE FACTURA DE MAYOR IMPORTE  %d", MAXNF);
 }
 else
   printf ("\n NO HUBO VENTAS");

 }
