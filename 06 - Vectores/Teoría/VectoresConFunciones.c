/*

 VECTORES COMO PAR�METROS FORMALES Y ACTUALES DE UNA FUNCI�N
 -----------------------------------------------------------

 Recordar que el nombre o identificador del vector es una referencia a la primera direcci�n de la zona de memoria reservada.

 -Vector como par�metro real o actual o argumento:  SOLO DE COLOCA EL NOMBRE O IDENTIFICADOR DEL VECTOR.
                                                    EN REALIDAD LO QUE SE ENV�A ES LA DIRECCI�N DE INICIO
                                                    DE MEMORIA PARA QUE SE COPIE EN OTRO ARRAY EN VIRTUD
                                                    DE QUE AMBOS APUNTEN A LA MISMA DIRECCI�N DE MEMORIA.
                                                    EL PASAJE DE PAR�METROS ES POR REFERENCIA.


- Vector como par�metro formal: ES IGUAL A LA DECLARACI�N DE UN VECTOR, PERO NO ES OBLIGATORIO COLOCAR EL TAMANO,
                                YA QUE LO QUE RECIBE ES UNA DIRECCI�N DE MEMORIA.

- Tipo de dato vector en el prototipo: tipo de dato []  - NO ES OBLIGATORIO COLOCAR EL TAMA�O -


*/

#include<stdio.h>
#include<stdlib.h>

//DECLARACI�N DE CONSTANTES.
#define TAM 4

//PROTOTIPO DE FUNCIONES

void Carga(int [],int);
void Mostrar(int [],int);
float Promedio(int[],int);



int main()
{
 //DECLARACI�N DEL ARRAY.
 int vector[TAM];

 printf("La direccion de inicio de memoria del vector declarado en el main es %x\n\n",vector);

 //LLAMAR O INVOCAR A LAS FUNCIONES.
 Carga(vector,TAM);   //SOLO SE COLOCA EL NOMBRE DEL VECTOR CUANDO SE ENV�A COMO PAR�METOR REAL.
 Mostrar(vector,TAM); //SOLO SE COLOCA EL NOMBRE DEL VECTOR CUANDO SE ENV�A COMO PAR�METOR REAL.
 printf("El promedio de los valores ingresados es %.2f",Promedio(vector,TAM));

 system("pause");
 return 0;

}

//DEFINICI�N DE FUNCIONES.
void Carga(int vec[],int tamanio)
{
 int i;

 printf("\nEl contenido del vector vec (vector que recibe como parametro formal) de la funcion en Carga es %x\n\n",vec);

 for (i=0;i<tamanio;i++)
  {
      printf("Ingrese el contenido de la %d posicion del vector:",i+1);
      scanf("%d",&vec[i]);
  }
}
/////////////////////////////////////////////////////////////////////////
void Mostrar(int vi[],int tamanio)
{
  int i;

  printf("\nEl contenido del vector vi (vector que recibe como parametro formal) de la funcion en Mostrar es %x\n\n",vi);

  printf("POSICION CONTENIDO\n");

  for (i=0;i<tamanio;i++)
       printf("%4d%10d\n",i+1,vi[i]);
}
/////////////////////////////////////////////////////////////////////////
float Promedio(int va[],int tamanio)
{
 printf("\nEl contenido del vector va (vector que recibe como parametro formal) de la funcion en Promedio es %x\n\n",va);

 int suma=0,i;
 float prom;

 for (i=0;i<tamanio;i++)
       suma+=va[i];

 prom=(float)suma/tamanio;//CAST EN EL NUMERADOR.

 return prom;
}
