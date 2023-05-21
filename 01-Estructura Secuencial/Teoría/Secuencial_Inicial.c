
//I - DIRECTIVAS AL PRECOMPILADOR (include y constantes).
#include <stdio.h>
#include <conio.h>//getch();
//#include <stdlib.h>//system("comando del sistema op.");

//PROGRAMA PRINCIPAL.
int main()
 {
     //II - BLOQUE DECLARATIVO DE VARIABLES.
     int variableInt;

     //III - BLOQUE EJECUTIVO.

	 //CODIFICACIÓN DEL SÍMBOLO DE SALIDA DE DATOS.
     printf("Ingrese un valor entero:");

	 //CODIFICACIÓN DEL SÍMBOLO DE ENTRADA O INGRESO DE DATOS.
     scanf("%d",&variableInt);


     printf("La direccion de localizacion de la variables es : %x\n",&variableInt);
     printf("El contenido de la variables es : %d\n",variableInt);

 getch();//GENERA UNA PAUSA.
 //system("pause");//GENERA UNA PAUSA.

 return 0;//INFORMAR QUE EL PROGRAMA FINALIZÓ CORRECTAMENTE.
}
//DEARROLLO DE FUNCIONES.

