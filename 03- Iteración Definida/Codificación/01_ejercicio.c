/*
 Ingresar número de documento y nota de los 5 alumnos de un curso,
 informar por cada uno el número de documento y la leyenda “APROBADO” o
 “DESAPROBADO” si la nota es mayor o igual a 4 o no.
*/

#include <stdio.h>

int main()
{
    int nroDoc,nota,i,cantAlum;

    printf("Cantidad de alumnos del curso ");
    scanf("%d",&cantAlum);

    for(i=1;i<=cantAlum;i++)
    {
        printf("Nro documento del alumno %d ",i);
        scanf("%d",&nroDoc);
        printf("Nota del alumno %d ",i);
        scanf("%d",&nota);

        if(nota>=4)
            printf("%d aprobo\n",nroDoc);
        else
            printf("%d desaprobo\n",nroDoc);
    }

    return 0;
}
