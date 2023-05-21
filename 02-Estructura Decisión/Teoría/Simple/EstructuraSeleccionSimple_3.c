#include <stdio.h> //Biblioteca para el ingreso y egreso de datos

int main() //Función principal
{
    int num; //Variable que guarda el valor ingresado por teclado
    printf("\n Ingrese un valor: "); //Se solicita el ingreso de un valor por teclado
    scanf("%d",&num); //Se obtiene el valor ingresado por teclado y se almacena en la variable num


    if(num>0)//Si el valor ingresado por teclado es mayor a cero se imprime un mensaje correspondiente.
    {
        printf("\n El valor ingresado %d es mayor que cero...",num);
    }
    else
    {
        if(num<0)//En caso contrario, si el valor ingresado por teclado se imprime el mensaje correspondiente.
        {
            printf("\n El valor ingresado %d NO es mayor que cero...",num);
        }
        else//En caso contrario, si el valor ingresado es igual a cero, se imprime el mensaje correspondiente.
        {
            printf("\n El valor ingresado %d es igual a cero...",num);
        }
    }

    return 0;
}

/* CASOS DE PRUEBA
   1. Ingrese un valor mayor a cero y debería imprimir el mensaje correspondiente, debido que se ha contemplado
      cuando el valor ingresado es mayor a cero.
   2. Ingrese un valor  menor a cero y deberá imprimir otro mensaje, debido que se ha contemplado cuando el valor
      ingresado es menor a cero.
   3. Ingrese un valor  igual a cero y deberá imprimir otro mensaje, debido que se ha contemplado cuando
      el valor ingresado es igual a cero.
*/







