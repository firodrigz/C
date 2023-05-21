#include <stdio.h> //Biblioteca para el ingreso y egreso de datos

int main() //Función principal
{
    int num; //Variable que guarda el valor ingresado por teclado
    printf("\n Ingrese un valor: "); //Se solicita el ingreso de un valor por teclado
    scanf("%d",&num); //Se obtiene el valor ingresado por teclado y se almacena en la variable num


    if(num>0) //Si el valor ingresado por teclado es mayor a cero se imprime un mensaje correspondiente.
    {
        printf("\n El valor ingresado %d es mayor que cero...",num);
    }
    else //En caso contrario, se imprime otro mensaje debido que se se contempla la parte falsa.
    {
        printf("\n El valor ingresado %d NO es mayor que cero...",num);
    }

    return 0;
}

/* CASOS DE PRUEBA
   1. Ingrese un valor mayor a cero y debería imprimir el mensaje correspondiente.
   2. Ingrese un valor  menor a cero y deberá imprimir otro mensaje, debido que se ha contemplado la parte falsa.
   3. Ingrese un valor  igual a cero y se ejecutan las acciones por la parte falsa. En este caso, no se contempla cuando
      el valor ingresado es igual a cero.
*/








