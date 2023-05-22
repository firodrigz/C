/*
  Realizar un programa para mostrar los números pares entre 30 y 10
  en forma descendente.
*/

#include <stdio.h>

int main()
{
    int i;

    for(i=30;i>=10;i-=2)//i-=2 => i = i - 2
        printf("%d  ",i);

    printf("\n");

    return 0;

}
