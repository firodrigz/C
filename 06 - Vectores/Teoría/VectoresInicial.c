/*

 VECTORES O ARRAYS UNIDIMENSIONALES
 ----------------------------------

 - Es una estructura ESTÁTICA en memoria principal que agrupa un conjunto de direcciones de memoria o elementos
   continuas cuyo contenido pertenece a un tipo de dato homogéneo.

 - Es un conjunto de variables de tipo homogéneo (todas tienen el mismo tipo de dato) agrupadas u organizadas
   de forma continua o contigua en la memoria principal bajo un único nombre.

 - Es una variable dimensionada muy grande que contiene un conjunto de variables pequeñas ordenadas en forma consecutiva.
   cuyo contenido pertenece a un tipo de dato homogéneo.

   Cada elemento se identifica por su posición dentro del vector (índice del vector).


DECLARACIÓN - (SE REALIZA EN TIEMPO DE COMPILACIÓN)
------------

   --------------------------------------------------
  | <tipo de dato> Identificador o variable [Tamaño];| ---> VECTOR ESTÁTICO: Se debe conocer en tiempo de compilación.
   --------------------------------------------------

   - Tipo de dato : int,float, char;

   - Identificador: Nombre de la variable dimensionada, es una referencia.

   - Tamaño (Tamaño máximo): Es la cantidad de direcciones de memoria continuas que se van a reservar en la
                             memoria principal. Es un int mayor que cero y menor un número int.


FORMATO LÓGICO
--------------

  int vector[4];


    INDICE CONTENIDO                   NÚMERO DE ORDEN
            -----
       0   | int |    ---> vector[0]          1
            -----
       1   | int |    ---> vector[1]          2
            -----
       2   | int |    ---> vector[2]          3
            -----
       3   | int |    ---> vector[3]          4
            -----

-INDICE O POSICIÓN: Es un int mayor e igual que cero y menor que el tamaño del vector.
                    Identifica a las variables pequeñas o los casilleros del vector.
                    Es lo que permite el acceso al vector. En el lenguaje C comienza desde la posición
                    cero.

- NÚMERO DE ORDEN: Es el índice que visualiza el usuario,es decir la POSICIÓN + 1

- CONTENIDO : Es el valor absoluto de cada posición del vector.

FORMATO FÍSICO -MEMORIA PRINCIPAL
--------------

   int vector[4]; // Se reservan 4 direcciones de memoria continua, las posiciones van desde 0 a 3.

   ------
  | BC05 |--------------------------------------
   ------                                      |
   vector         ZONA DE MEMORIA RESERVADA    |
                  ------------------------     |
                  |  POSICIÓN CONTENIDO   |    |
                  |           ----        |    |
                  |     0    |    |  BC05 <----| DIRECCIÓN DE INICIO.
                  |           ----        |
                  |     1    |    |       |
                  |           ----        |
                  |     2    |    |       |
                  |           ----        |
                  |     3    |    |       |
                  |           ----        |
                  |-----------------------|

 El nombre o identificador del vector es una referencia a la primera dirección de memoria
 de la zona de memoria reservada para el mismo.
 "EL IDENTIFICADOR DEL VECTOR ES UN PUNTERO A LA PRIMERA DIRECCIÓN DE LA ZONA
 RESERVADA QUE ESTÁ EN LA POSICIÓN CERO".

 Puntero: Es una variable cuyo contenido es una dirección de memoria.


 ACCESO
 ------

     -------------------------
     |Identificador [INDICE] |  0<=INDICE<=TAMAÑO.
     -------------------------


     DIRECTO: Se coloca directamente la posición, a través de una constante int, para acceder al contenido de una
              posición.

     INDIRECTO: Se coloca una operación o expresión como índice que genere como resultado un int.
                Puede ser una constante, una operación, una función, un vector que sean int.


 RECORRIDO
 ---------

 Se realiza a través de las estructuras de iteración definida o condicionada (for,while,do-while).

*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
  int vector[4],i;//DECLARACIÓN.

  for (i=0;i<4;i++)//CARGAR EL VECTOR.
  {
      printf("Ingrese el contenido de la %d posicion del vector:",i+1);
      scanf("%d",&vector[i]);
  }

  printf("NRO ORDEN CONTENIDO\n");
  for (i=0;i<4;i++)//MOSTRAR EL VECTOR.
       printf("%4d%10d\n",i+1,vector[i]);

 system("pause");
 return 0;
}

