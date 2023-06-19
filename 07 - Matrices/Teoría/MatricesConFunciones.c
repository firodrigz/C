/*

 MATRICES COMO PAR�METROS FORMALES Y ACTUALES DE UNA FUNCI�N
 -----------------------------------------------------------

 Recordar que el nombre o identificador de la matriz es una referencia a la primera direcci�n de la zona de memoria reservada.

 -Matriz como par�metro real o actual o argumento:  SOLO DE COLOCA EL NOMBRE O IDENTIFICADOR DE LA MATRIZ.
                                                    EN REALIDAD LO QUE SE ENV�A ES LA DIRECCI�N DE INICIO
                                                    DE MEMORIA PARA QUE SE COPIE EN OTRO ARRAY EN VIRTUD
                                                    DE QUE AMBOS APUNTEN A LA MISMA DIRECCI�N DE MEMORIA.
                                                    EL PASAJE DE PAR�METROS ES POR REFERENCIA.


- Matriz como par�metro formal: ES IGUAL A LA DECLARACI�N DE UNA MATRIZ, PERO NO ES OBLIGATORIO COLOCAR EL TAMA�O DE FILA,
                                PERO S� ES OBLIGATORIO COLOCAR EL TAMA�O DE LA COLUMNA, DEBIDO A QUE ES EL L�MITE DE CORTE
								POR CADA FILA.            

- Tipo de dato de la matriz en el prototipo: tipo de dato [][CANTIDAD DE COLUMNAS]  - NO ES OBLIGATORIO COLOCAR LA CANTIDAD DE FILAS -


*/

#include<stdio.h>
#include<stdlib.h>

//CONSTANTES.
#define CANT_FILAS 2
#define CANT_COLUMNAS 2

//PROTOTIPO DE FUNCIONES
void Carga(int [][CANT_COLUMNAS],int,int); //SIEMPRE SE DEBE INDICAR LA CANT. DE COLUMNAS.
void Mostrar(int [][CANT_COLUMNAS],int,int);

//PROGRAMA PRINCIPAL.
int main()
{

  int matriz[CANT_FILAS][CANT_COLUMNAS];//DECLARACI�N.


  printf("La direccion de inicio de memoria de la matriz declarada en el main es %x\n\n",matriz);

  //LLAMAR O INVOCAR A LAS FUNCIONES.
  Carga(matriz,CANT_FILAS,CANT_COLUMNAS);   //SOLO SE COLOCAR EL NOMBRE DE LA MATRIZCUANDO SE ENV�A COMO PAR�METOR REAL.
  Mostrar(matriz,CANT_FILAS, CANT_COLUMNAS); //SOLO SE COLOCAR EL NOMBRE DE LA MATRIZ CUANDO SE ENV�A COMO PAR�METOR REAL.

  system("pause");
  return 0;

}

//DEFINICI�N DE FUNCIONES.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Carga(int mat[][CANT_COLUMNAS],int cf,int cc)
{
 int f,c;

 printf("\nEl contenido de la matriz mat (matriz que recibe como parametro formal) de la funcion en Carga es %x\n\n",mat);

   for (f=0;f<CANT_FILAS;f++)//CARGA POR FILAS.
  {
    for (c=0;c<CANT_COLUMNAS;c++)//INGRESAR EL VALOR DE CADA ELEMENTO DE LA MATRIZ POR COLUMNA.
         {
          printf("Ingrese el contenido de la fila %d y columna %d ",f,c);
          scanf("%d",&mat[f][c]);
         }
  }


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Mostrar(int mat[][CANT_COLUMNAS],int cf,int cc)
{
 int f,c;

 printf("\nEl contenido de la matriz mat (matriz que recibe como parametro formal) de la funcion en Carga es %x\n\n",mat);

  printf("\nMATRIZ\n");
   for (f=0;f<CANT_FILAS;f++)//RECORRIDO POR FILAS.
    {
      for (c=0;c<CANT_COLUMNAS;c++)

         printf("%d\t",mat[f][c]);

      printf("\n");
  }
}

