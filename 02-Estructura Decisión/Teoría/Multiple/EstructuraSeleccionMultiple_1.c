/*

  ESTRUCTURA DE SELECCIÓN MÚLTIPLE
  --------------------------------

  Es una estructura que permite ejecutar el mismo conjunto de instrucción/es para diferentes
  condiciones. Evita el uso de estructuras de selección anidadas (if anidados) "SOLO SI SE COMPARA POR IGUALDAD".

  Cada condición involucra un conjunto finito de valores o valor, en la cual para
  diferentes valores se pueden ejecutar las mismas instrucciones.


  DIAGRAMACIÓN
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
                 | RÓTULO 1 | RÓTULO 2 | ... | DEFAULT |
                  --------------------------------------
                 |  INST.   | INST.    | ... | INST.   |
                 | RÓTULO 1 | RÓTULO 2 | ... | RÓTULO  |
                 |          |          | ... | DEFAULT |
                 ---------------------------------------
                              PUNTO DE FIN 



  COMPONENTES
  -----------

  - Variable selectora: Es una vaiable que debe ser de tipo int o char, su contenido es el valor que evalúa la estructura contra los valores contenidos en los rótulos, los valores que puede contener la variable selectora deben ser conocidos desde el enunciado.

  - Rótulo:
             1) Es el valor o conjunto de valores que se van a comparar contra el contenido de la variable selectora.
                El operador relacional de comparación es igualdad (==).
                "EL CONJUNTO DE VALORES DE CADA RÓTULO DEBE SER FINITO Y LOS VALORES QUE PUEDE ADOPTAR LA VARIABLE
                SELECTORA DEBEN SER CONOCIDOS"

                Contiene un/a conjunto de instrucción/es que se ejecutarán si se cumple alguna coincidencia del paso 1)

             2) Éstos valores (uno o varios) deben pertenecer al mismo tipo de dato que la variable selectora. Si el
                rótulo contiene más de un valor se lo llama "switch en cascada".

                La lista de valores se separan con el caracter coma o dos puntos.

                No se pueden colocar como valores del rótulo rangos, solo VALORES CONSTANTES (int o char).

                Pueden no estar ordenados (numéricamente o alfabéticamente).

             3) Existe un rótulo llamado default, que se ejecuta en el caso de que no se cumpla ninguna condición
                de los rótulos anteriores. Es opcional colocarlo.


 FUNCIONAMIENTO
 --------------

 Compara por igualdad el valor contenido en la variable selectora contra el el/los valor/es del rótulo 1, si existe coincidencia
 ejecuta las instrucciones de dicho rótulo y sale de la estructrua. En el caso de que no exista coincidencia realiza la misma secuencia
 con el rótulo 2, luego el rótulo 3, ........ Si no hay coincidencia con ningún rótulo ejecuta las instrucciones del rótulo default (SI
 EXISTE).


CODIFICACIÓN
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


  //CODIFICACIÓN DE LA ESTRUCTURA DE SELECCIÓN MÚLTIPLE.
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

  }//FIN DE LA ESTRUCTURA DE SELECCIÓN MÚLTIPLE.

  getch();
  return 0;

}
