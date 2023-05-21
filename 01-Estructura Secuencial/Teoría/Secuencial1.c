/*
  EJEMPLO DE CODIFICACIÓN DE UN PROGRAMA QUE LE SOLICITA AL USUARIO
  EL INGRESO DE DOS NÚMEROS ENTEROS E INFORMA LA SUMA DE LOS NÚMEROS.
*/

//I- DIRECTIVAS AL PRECOMPILADOR O PREPROCESADOR.
#include<stdio.h>
#include<conio.h>



//PROGRAMA PRINCIPAL
int main()//------------------------------------------->(c)
{
    //II- BLOQUE DECLARATIVO DE VARIABLES.
    int nro1, nro2, suma;                //

    //III- BLOQUE EJECUTIVO.
                                         //    ____________________________
    printf("Ingrese el primer numero:"); //-> / "Ingrese el primer numero:"\
                                         //  /______________________________\
                                                      _________
    scanf("%d",&nro1);                   //---------> \__nro1_/
                                         //     _____________________________
    printf("Ingrese el segundo numero:"); //-> /_"Ingrese el segundo numero:"\
                                         //   /_______________________________\

                                         //            _________
    scanf("%d",&nro2);                   //----------> \ nro2  /
                                         //             \_____/
                                         //           ______________
    suma=nro1+nro2;                      //---------> | s=nro1+nro2|
                                         //           ______________
                                         //                _________________________________
    printf("El resultado de la suma es :%d\n",suma); //-> /"El resultado de la suma es",suma\
                                                    //   /___________________________________\

    getch();/*
             GENERA UNA PAUSA HASTA QUE EL USUARIO
             PRESIONE UNA TECLA.
             ES UNA FUNCIÓN QUE SE ENCUENTRA EN LA
             BIBLIOTECA conio.h.
             TAMBIÉN SE PUEDE UTILIZAR LA FUNCIÓN system("PAUSE");
             QUE SE ENCUENTRA EN LA BIBLIOTECA stdlib.h

            */

    return 0; /*
                EL VALOR CERO LE INDICA AL SISTEMA OPERATIVO QUE
                EL PROGRAMA FINALIZÓ OK.
              */
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

  función printf
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

función scanf
-------------

   Nota: el operador & indica dirección física o  de localización de la variable.

   Para leer una sola variable:

   scanf("FormatoDeVariable",&variable);

   Para leer más de una variable en la misma línea de código:

   scanf("FormatoDeVariable1FormatoDeVariable2FormatoDeVariable3",&variable1,&variable2,&variable3);

   Ejemplo:

   scanf("%d",&VariableTipoInt);

   scanf("%d%f",&VariableTipoInt,&&VariableTipoFloat);

*/


//---------COMENTARIOS---------//

//COMETARIOS DE UNA SOLA LÍNEA.

/*
  COMENTARIOS DE MÁS DE UNA LÍNEA
  O DE UNA LÍNEA
*/


