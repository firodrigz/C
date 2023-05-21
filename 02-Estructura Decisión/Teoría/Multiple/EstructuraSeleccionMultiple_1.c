/*

  ESTRUCTURA DE SELECCI�N M�LTIPLE
  --------------------------------

  Es una estructura que permite ejecutar el mismo conjunto de instrucci�n/es para diferentes
  condiciones. Evita el uso de estructuras de selecci�n anidadas (if anidados) "SOLO SI SE COMPARA POR IGUALDAD".

  Cada condici�n involucra un conjunto finito de valores o valor, en la cual para
  diferentes valores se pueden ejecutar las mismas instrucciones.


  DIAGRAMACI�N
  ------------
                               PUNTO DE INICIO 
                                   / \
                                  /   \
                                 /     \
                                /       \
                               /         \
                              /           \
                             /             \
                            /               \
                           /                 \
                          /                   \
                         /                     \
                        /                       \
                       /                         \
                      /                           \
                     /           VARIABLE          \
                    /            SELECTORA          \
                   /                                 \
                  /                                   \
                  --------------------------------------
                 | R�TULO 1 | R�TULO 2 | ... | DEFAULT |
                  --------------------------------------
                 |  INST.   | INST.    | ... | INST.   |
                 | R�TULO 1 | R�TULO 2 | ... | R�TULO  |
                 |          |          | ... | DEFAULT |
                 ---------------------------------------
                              PUNTO DE FIN 



  COMPONENTES
  -----------

  - Variable selectora: Es una vaiable que debe ser de tipo int o char, su contenido es el valor que eval�a la estructura contra los valores contenidos en los r�tulos, los valores que puede contener la variable selectora deben ser conocidos desde el enunciado.

  - R�tulo:
             1) Es el valor o conjunto de valores que se van a comparar contra el contenido de la variable selectora.
                El operador relacional de comparaci�n es igualdad (==).
                "EL CONJUNTO DE VALORES DE CADA R�TULO DEBE SER FINITO Y LOS VALORES QUE PUEDE ADOPTAR LA VARIABLE
                SELECTORA DEBEN SER CONOCIDOS"

                Contiene un/a conjunto de instrucci�n/es que se ejecutar�n si se cumple alguna coincidencia del paso 1)

             2) �stos valores (uno o varios) deben pertenecer al mismo tipo de dato que la variable selectora. Si el
                r�tulo contiene m�s de un valor se lo llama "switch en cascada".

                La lista de valores se separan con el caracter coma o dos puntos.

                No se pueden colocar como valores del r�tulo rangos, solo VALORES CONSTANTES (int o char).

                Pueden no estar ordenados (num�ricamente o alfab�ticamente).

             3) Existe un r�tulo llamado default, que se ejecuta en el caso de que no se cumpla ninguna condici�n
                de los r�tulos anteriores. Es opcional colocarlo.


 FUNCIONAMIENTO
 --------------

 Compara por igualdad el valor contenido en la variable selectora contra el el/los valor/es del r�tulo 1, si existe coincidencia
 ejecuta las instrucciones de dicho r�tulo y sale de la estructrua. En el caso de que no exista coincidencia realiza la misma secuencia
 con el r�tulo 2, luego el r�tulo 3, ........ Si no hay coincidencia con ning�n r�tulo ejecuta las instrucciones del r�tulo default (SI
 EXISTE).


CODIFICACI�N
------------

switch (VARIABLE SELECTORA )

       {
         case <valor1> :
                        INSTRUCCIONES;
                        break;

         case <valor2> :
                        INSTRUCCIONES;
                        break;
         case <valor3> :
                        INSTRUCCIONES;
                        break;
         .....

         default:
                        INSTRUCCIONES;

       }

*/


int main()
{
  int VariableSelectora;


  printf("ingrese un valor entre 1 y 10 : ");
  scanf("%d",&VariableSelectora);


  //CODIFICACI�N DE LA ESTRUCTURA DE SELECCI�N M�LTIPLE.
  switch(VariableSelectora)
  {
   case 1: printf("UNO");
           break; //SALIR DE LA ESTRUCTURA.

   //SWITCH EN CASCADA.
   case 2:
   case 3:
   case 4: printf("DOS - TRES - CUATRO");
           break; //SALIR DE LA ESTRUCTURA.

   //SWITCH EN CASCADA.
   case 5:
   case 6:
   case 7: printf("CINCO - SEIS - SIETE");
           break;//SALIR DE LA ESTRUCTURA.

   //SWITCH EN CASCADA.
   case 8:
   case 9:
   case 10: printf("OCHO - NUEVE - DIEZ");
            break;//SALIR DE LA ESTRUCTURA.

   //OPCIONAL.
   default: printf("\n Valor ingresado fuera de rango. \n");
            //break; OPCIONAL

  }//FIN DE LA ESTRUCTURA DE SELECCI�N M�LTIPLE.

  getch();
  return 0;

}
