/*
  Ejercicio de funciones para entender la estructura

*/
#include<stdio.h>

//Constantes (�mbito global)
#define NOTA_INFERIOR 1
#define NOTA_SUPERIOR 10

/*Prototipo de las funciones (Encabezado de las funciones)
  �mbito global.

  Formato:
  Tipo de dato de retorno Nombre (tipo de dato de los par�metros formales);
 */
void msjIngresoDni();//void msjIngresoDni (void);
void msjIngresoNota(int);
int ingresaYValida(int,int);
int sumar(int,int);
float promedio(int,int);
void msjResultado(int,float);

int main()
{
 //Variables locales de la funci�n main.
 int dni,nota1,nota2;
 float prom;

 //Llamado -> Nombre (par�metros);
 msjIngresoDni();//Llamado o invocar a la funci�n.
 dni=ingresaYValida(1000000,99999999);

 msjIngresoNota(1);
 nota1=ingresaYValida(NOTA_INFERIOR,NOTA_SUPERIOR);
 msjIngresoNota(2);
 nota2=ingresaYValida(NOTA_INFERIOR,NOTA_SUPERIOR);

 prom=promedio(nota1,nota2);

 msjResultado(dni,prom);//msjResultado(dni,promedio(nota1,nota2));

 return 0;
} //Fin de la funci�n main.

//Definici�n de las funciones (Encabezado + par�metros formales + desarrollo).
////////////////////////////////////////////////////
void msjIngresoDni()
{
    printf("Ingrese el dni:");
}
////////////////////////////////////////////////////
void msjIngresoNota(int x)//x es par�metro formal.
{
  printf("\nIngrese la nota %d = ",x);
}
////////////////////////////////////////////////////
int ingresaYValida(int desde,int hasta)
{
    //Bloque declarativo de variables locales.
    int nro;

    do{
        scanf("%d",&nro);

      }while(nro<desde || nro >hasta);

    return nro; //return Expresi�n;
}
////////////////////////////////////////////////////
int sumar(int a,int b)
{
    return a + b;
}
////////////////////////////////////////////////////
float promedio(int n1,int n2)
{
    float p;
    int s;

    s=sumar(n1,n2);
    p=(float)s/2;//p=(float)sumar(n1,n2)/2;

    return p;//return (float)sumar(n1,n2)/2;
}
////////////////////////////////////////////////////
void msjResultado(int d,float p)
{
    printf("\nEl promedio de %d es %.2f\n",d,p);
}
