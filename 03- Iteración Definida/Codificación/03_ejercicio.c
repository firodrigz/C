/*
  Ingresar 6 números enteros y luego informar:
  a) La cantidad de números negativos ingresados.
  b) La sumatoria de los números positivos ingresados.

*/

#include <stdio.h>

int main()
{
    int suma/*=0*/,cont/*=0*/,nro,i;

    cont=0;
    suma=0;
    //cont=suma=0;//Asignación múltiple.

    for(i=1;i<=6;i++)
    {
       printf("Ingrese el numero de orden %d: ",i);
       scanf("%d",&nro);

       if(nro<0)
          cont++;//cont=cont+1;
       else
          suma+=nro;//suma =suma + nro;
    }

    printf("\nLa cantidad de numeros negativos ingresados es = %d\n",cont);
    printf("\nLa sumatoria de numeros positivos ingresados es = %d\n",suma);

    return 0;
}

