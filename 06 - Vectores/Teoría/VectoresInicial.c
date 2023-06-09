/*

 VECTORES O ARRAYS UNIDIMENSIONALES
 ----------------------------------

 - Es una estructura EST�TICA en memoria principal que agrupa un conjunto de direcciones de memoria o elementos
   continuas cuyo contenido pertenece a un tipo de dato homog�neo.

 - Es un conjunto de variables de tipo homog�neo (todas tienen el mismo tipo de dato) agrupadas u organizadas
   de forma continua o contigua en la memoria principal bajo un �nico nombre.

 - Es una variable dimensionada muy grande que contiene un conjunto de variables peque�as ordenadas en forma consecutiva.
   cuyo contenido pertenece a un tipo de dato homog�neo.

   Cada elemento se identifica por su posici�n dentro del vector (�ndice del vector).


DECLARACI�N - (SE REALIZA EN TIEMPO DE COMPILACI�N)
------------

   --------------------------------------------------
  | <tipo de dato> Identificador o variable [Tama�o];| ---> VECTOR EST�TICO: Se debe conocer en tiempo de compilaci�n.
   --------------------------------------------------

   - Tipo de dato : int,float, char;

   - Identificador: Nombre de la variable dimensionada, es una referencia.

   - Tama�o (Tama�o m�ximo): Es la cantidad de direcciones de memoria continuas que se van a reservar en la
                             memoria principal. Es un int mayor que cero y menor un n�mero int.


FORMATO L�GICO
--------------

  int vector[4];


    INDICE CONTENIDO                   N�MERO DE ORDEN
            -----
       0   | int |    ---> vector[0]          1
            -----
       1   | int |    ---> vector[1]          2
            -----
       2   | int |    ---> vector[2]          3
            -----
       3   | int |    ---> vector[3]          4
            -----

-INDICE O POSICI�N: Es un int mayor e igual que cero y menor que el tama�o del vector.
                    Identifica a las variables peque�as o los casilleros del vector.
                    Es lo que permite el acceso al vector. En el lenguaje C comienza desde la posici�n
                    cero.

- N�MERO DE ORDEN: Es el �ndice que visualiza el usuario,es decir la POSICI�N + 1

- CONTENIDO : Es el valor absoluto de cada posici�n del vector.

FORMATO F�SICO -MEMORIA PRINCIPAL
--------------

   int vector[4]; // Se reservan 4 direcciones de memoria continua, las posiciones van desde 0 a 3.

   ------
  | BC05 |--------------------------------------
   ------                                      |
   vector         ZONA DE MEMORIA RESERVADA    |
                  ------------------------     |
                  |  POSICI�N CONTENIDO   |    |
                  |           ----        |    |
                  |     0    |    |  BC05 <----| DIRECCI�N DE INICIO.
                  |           ----        |
                  |     1    |    |       |
                  |           ----        |
                  |     2    |    |       |
                  |           ----        |
                  |     3    |    |       |
                  |           ----        |
                  |-----------------------|

 El nombre o identificador del vector es una referencia a la primera direcci�n de memoria
 de la zona de memoria reservada para el mismo.
 "EL IDENTIFICADOR DEL VECTOR ES UN PUNTERO A LA PRIMERA DIRECCI�N DE LA ZONA
 RESERVADA QUE EST� EN LA POSICI�N CERO".

 Puntero: Es una variable cuyo contenido es una direcci�n de memoria.


 ACCESO
 ------

     -------------------------
     |Identificador [INDICE] |  0<=INDICE<=TAMA�O.
     -------------------------


     DIRECTO: Se coloca directamente la posici�n, a trav�s de una constante int, para acceder al contenido de una
              posici�n.

     INDIRECTO: Se coloca una operaci�n o expresi�n como �ndice que genere como resultado un int.
                Puede ser una constante, una operaci�n, una funci�n, un vector que sean int.


 RECORRIDO
 ---------

 Se realiza a trav�s de las estructuras de iteraci�n definida o condicionada (for,while,do-while).

*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
  int vector[4],i;//DECLARACI�N.

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

