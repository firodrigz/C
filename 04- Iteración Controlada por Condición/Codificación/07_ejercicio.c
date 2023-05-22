/* Ingresar diversos quintetos de números positivos de 1 cifra c/u, finalizando cuando las cinco cifras leídas
sean iguales a cero. Determinar e informar cuantos de los quintetos ingresados han formado números
capicúas 'triples' y cuantos 'quíntuples'. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3, num4, num5, conttriple=0, contquintuple=0;

    printf("Ingrese el num 1: ");
    do
    {
        scanf("%d",&num1);
        if(num1<0 || num1>=10)
            printf("Debe ser positivo y de 1 cifra\n");
    }while(num1<0 || num1>=10);

    printf("Ingrese el num 2: ");
    do
    {
        scanf("%d",&num2);
        if(num2<0 || num2>=10)
            printf("Debe ser positivo y de 1 cifra\n");
    }while(num2<0 || num2>=10);

    printf("Ingrese el num 3: ");
    do
    {
        scanf("%d",&num3);
        if(num3<0 || num3>=10)
            printf("Debe ser positivo y de 1 cifra\n");
    }while(num3<0 || num3>=10);

    printf("Ingrese el num 4: ");
    do
    {
        scanf("%d",&num4);
        if(num4<0 || num4>=10)
            printf("Debe ser positivo y de 1 cifra\n");
    }while(num4<0 || num4>=10);

    printf("Ingrese el num 5: ");
    do
    {
        scanf("%d",&num5);
        if(num5<0 || num5>=10)
            printf("Debe ser positivo y de 1 cifra\n");
    }while(num5<0 || num5>=10);


    while(num1!=0 || num2!=0 || num3!=0 || num4!=0 || num5!=0)
    {
        if(num1==num3)
            conttriple++;

        if(num2==num4)
            conttriple++;

        if(num3==num5)
            conttriple++;

        if((num1==num5)&&(num2==num4))
            contquintuple++;

        printf("Ingrese el num 1: ");
        do
        {
            scanf("%d",&num1);
            if(num1<0 || num1>=10)
                printf("Debe ser positivo y de 1 cifra\n");
        }while(num1<0 || num1>=10);

        printf("Ingrese el num 2: ");
        do
        {
            scanf("%d",&num2);
            if(num2<0 || num2>=10)
                printf("Debe ser positivo y de 1 cifra\n");
        }while(num2<0 || num2>=10);

        printf("Ingrese el num 3: ");
        do
        {
            scanf("%d",&num3);
            if(num3<0 || num3>=10)
                printf("Debe ser positivo y de 1 cifra\n");
        }while(num3<0 || num3>=10);

        printf("Ingrese el num 4: ");
        do
        {
            scanf("%d",&num4);
            if(num4<0 || num4>=10)
                printf("Debe ser positivo y de 1 cifra\n");
        }while(num4<0 || num4>=10);

        printf("Ingrese el num 5: ");
        do
        {
            scanf("%d",&num5);
            if(num5<0 || num5>=10)
                printf("Debe ser positivo y de 1 cifra\n");
        }while(num5<0 || num5>=10);
    }
    printf("Capicuas Triples: %d\n",conttriple);
    printf("Capicuas Quintuples: %d\n",contquintuple);
    system("pause");
    return 0;
}
