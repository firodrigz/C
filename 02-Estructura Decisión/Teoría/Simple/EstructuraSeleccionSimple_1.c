/*
    ESTRUCTURA DE SELECCI�N O DECISI�N
    ----------------------------------

    Es una estructura de control que permite decidir o seleccionar un curso de acci�n, u otro, en la ejecuci�n del programa a partir del resultado de una condici�n l�gica.


    DIAGRAMACI�N
    ------------
                                      PUNTO DE INICIO
                                           /\
                                          /  \
                                         /    \
                                        /      \
                                       /        \
                                      /          \
                                     /            \
                                    /              \
                                   / CONDICI�N/NES  \
                                  /  L�GICA/S        \
                                 /                    \
                                /----------------------\
                                |    BLOQUE  | BLOQUE  |
                                |  VERDADERO |  FALSO  |
                                ------------------------
								        PUNTO DE FIN  


    COMPONENTES
    -----------

    - CONDICI�N/NES : Retorna un valor l�gico (booleano) -> Verdadero/Falso. 
	
	Se puede representar de tres formas distintas:
	                  
                      1) Expresi�n   Operador relacional    Expresi�n 
                                       de comparaci�n
                      2) ! Expresi�n
                       
                      3) Expresi�n  					   

    - EXPRESI�N : Es un valor que puede ser entregado por constante/s y/o
  	  variable/s y/u operaci�n o llamado a una funci�n que retorna valor.

    -OPERADOR RELACIONAL:
                          == IGUALDAD
                          != DESIGUALDAD.
                          <= MENOR E IGUAL.
                          >= MAYOR E IGUAL.
                          < MENOR ESTRICTO.
                          > MAYOR ESTRICTO.



   - BLOQUE VERDADERO : Es un bloque OBLIGATORIO que se ejecuta si el resultado
     de la condici�n l�gica es verdadera.
     Si se utiliza esta estructura entonces, "SIEMPRE DEBE ESTAR REPRESENTADO ESTE
	 BLOQUE".
	  

   - BLOQUE FALSO : Es un bloque OPCIONAL, que se ejecuta si el resultado de la  
     condici�n l�gica es falso.

   Tanto el bloque verdadero como el falso, contienen un conjunto de instrucciones que permiten combinar todas las estrucuturas (Secuencial, selecci�n,iteraci�n).

 FUNCIONAMIENTO
 --------------
 Primero eval�a el resultado de la condici�n l�gica. 
 
    Si es verdadero entonces: Direcciona la ejecuci�n del programa hacia el bloque verdadero. Ejecuta todas las intrucciones del mismo y luego de ejecutar la �ltima instrucci�n, continua hacia la salida de la estructura.
	
	Si el falso: (Y el bloque existe), Ejecuta todas las intrucciones del mismo y  luego de ejecutar la �ltima instrucci�n, continua hacia la salida de la estructura.


 CODIFICACI�N
 ------------

 if (<CONDICI�N/NES>)
    {
      //BLOQUE VERDADERO.

      INSTRUCCION 1;
	  INSTRUCCION 2;
	     ....
 	  INSTRUCCION N; 	  
    }
 else
   {
     //BLOQUE FALSO.

     INSTRUCCION 1;
	 INSTRUCCION 2;
	     ....
 	 INSTRUCCION N;
   }

 NOTA : Si el bloque VERDADERO O FALSO tiene una sola instrucci�n no es obligatorio colocar las llaves.

*/
#include <stdio.h> //Biblioteca para el ingreso y egreso de datos.

int main() //Funci�n principal
{
    int num; //Variable que guarda el valor ingresado por teclado
    printf("\n Ingrese un valor: "); //Se solicita el ingreso de un valor por teclado
    scanf("%d",&num); //Se obtiene el valor ingresado por teclado y se almacena en la variable num

    if(num>0) //Si el valor ingresado por teclado es mayor a cero se imprime un mensaje. En caso contrario,
    {         //no se realiza ninguna acci�n. En este caso no se contempla la parte falsa, ya que la misma es opcional.
        printf("\n El valor ingresado %d es mayor que cero...",num);
    }

    return 0;
}

/* CASOS DE PRUEBA
   1. Ingrese un valor mayor a cero y deber�a imprimir el mensaje correspondiente.
   2. Ingrese un valor menor a cero y no deber�a imprimir ning�n mensaje, debido que no se ha contemplado la parte falsa.
   3. Ingrese un valor igual a cero y no deber�a imprimir ning�n mensaje, debido que no se ha contemplado la parte falsa.
*/
