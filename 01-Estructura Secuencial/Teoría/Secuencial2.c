/*
  EJEMPLO DE CODIFICACI�N DE UN PROGRAMA QUE LE SOLICITA AL USUARIO
  EL INGRESO DE DOS N�MEROS ENTEROS E INFORMA LA SUMA DE LOS N�MEROS.
*/

//I- DIRECTIVAS AL PRECOMPILADOR O PREPROCESADOR.
#include<stdio.h>
#include<stdlib.h>

//PROGRAMA PRINCIPAL
int main()//--------------------------------------------------------------------------------------->(c)
{                                        //
    //II- BLOQUE DECLARATIVO DE VARIABLES.
    int nro1, nro2, suma;                //
                                         //
    //III- BLOQUE EJECUTIVO.                                                         __________________________________________________________________
    printf("Ingrese dos numeros separados por espacio o tabulacion o enter:"); //-> /_"Ingrese dos numeros separados por espacio o tabulacion o enter:"\
                                         //                                        /____________________________________________________________________\                                                                    \

                                         //           ______________
    scanf("%d%d",&nro1,&nro2);           //------->   \  nro1,nro2 /
                                         //            \__________/
                                         //            _____________
    suma=nro1+nro2;                      //------->   |  s=nro1+nro2|
                                         //            _____________
                                         //                _________________________________
    printf("El resultado de la suma es :%d\n",suma); //-> /"El resultado de la suma es",suma\
                                                     //  /___________________________________\

    system("PAUSE");

    return 0;
                                                       //___
}//--------------------------------------------------->//\F/
                                                       // -

/*

  Formatos de Variable
  --------------------

    TIPO DE DATO    FORMATO
       int            %d
       float          %f
       char           %c

  funci�n printf
  --------------

  1) Mostrar solo texto : printf("cadena de control");

     Ejemplo:

     printf("texto que se desea mostrar en pantalla");

  2) Mostrar solo variable o variables : printf("Formato de variable",variable);
                                         printf("Formato de variable1 Formato de variable2",variable1,variable2);

     Ejemplo:

     int VariableTipoInt = 5;
     float VariableTipoFloat = 10.2;
     char VariableTipoChar = '*';

     printf ("%d %.2f %c",VariableTipoInt,VariableTipoFloat,VariableTipoChar);

  3) Mostrar texto y variables: printf("texto + formato de variable",variable);

     Ejemplo:

     printf("El valor entero es %d \n el valor real es %.2f, el valor char es %c",VariableTipoInt,VariableTipoFloat,VariableTipoChar);

  funci�n scanf
  -------------

   Nota: el operador & indica direcci�n f�sica o  de localizaci�n de la variable.

   Para leer una sola variable:

   scanf("FormatoDeVariable",&variable);

   Para leer m�s de una variable en la misma l�nea de c�digo:

   scanf("FormatoDeVariable1FormatoDeVariable2FormatoDeVariable3",&variable1,&variable2,&variable3);

   Ejemplo:

   scanf("%d",&VariableTipoInt);

   scanf("%d%f",&VariableTipoInt,&&VariableTipoFloat);

*/


//---------COMENTARIOS---------//

//COMETARIO DE UNA SOLA L�NEA.

/*
  COMENTARIOS DE M�S DE UNA L�NEA
  O DE UNA L�NEA
*/



