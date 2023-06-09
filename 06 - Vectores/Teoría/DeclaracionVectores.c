/****************** DECLARACION e INICIALIZACION DE VECTORES ******************/
#include <stdio.h>
main()
{
 int I;
 //int V1[];  ERROR DE SINTAXIS, NO PUEDE QUEDAR VACIO LA CANTIDAD DE CELDAS (ENTRE CORCHETES )
 int V2[]={23,45,89,14};
 int V3[4]={23,45,89,14};
// int V4[4]={23,67,-1,78,56,100}; ERROR DE SINTAXIS, HAY MAS VALORES QUE EL TAMAÑO DEL VECTOR
 int V5[4]={0};
 int V6[4]={65};
 int V7[4]={45,89};
 char V8[4]={'A','B', 'C', 'D'};

 printf("\n CONTENIDOS DE LOS VECTORES");
 printf("\n  POSICION\tV2\tV3\tV5\tV6\tV7\tV8");
 for (I=0;I < 4 ;I++)
   printf ("\n     %d\t\t%d\t%d\t%d\t%d\t%d\t%c", I+1,V2[I],V3[I],V5[I],V6[I],V7[I],V8[I]);


}
