/*
5.1.15 Se realizó un concurso de tiro al blanco. Existen 5 participantes y cada uno de ellos efectúa 3 disparos, registrándose
las coordenadas X-Y de cada disparo. Determinar:
a. Cuantos disparos se efectuaron en cada cuadrante por cada participante
b. Cuantos disparos se efectuaron en total en el centro.
NOTA: no considere disparos sobre los ejes.
*/

#include <stdio.h>

int main()
{
    int i,j,X,Y,c1,c2,c3,c4,centro=0;

    for(i=1;i<=5;i++)
    {
        printf("\n Participante %d",i);
        c1=0;c2=0;c3=0;c4=0;
        for(j=1;j<=3;j++)
        {
            printf("\n Ingresar la cordenada X ");
            scanf("%d",&X);
            printf("\n Ingresar la cordenada Y ");
            scanf("%d",&Y);
            if(X>0&&Y>0)
                c1++;
            else
                if(X<0&&Y>0)
                    c2++;
                else
                    if(X<0&&Y<0)
                        c3++;
                    else
                        if(X>0 && Y<0)
                            c4++;
            if(X==0 && Y==0)
                centro++;
            else
                 if ((X==0 && Y!=0) || (X!=0 && Y==0))
                    printf ("ERROR. TIRO EN EJE");
        }

    printf("\n El Participante %d hizo \n%d disparos en el primer cuadrante \n%d en el segundo cuadrante \n%d en el tercer cuadrante \n%d en el cuatro cuadrante", i,c1,c2,c3,c4);

}

printf("\n\n Hubo %d disparos al centro", centro);
return 0;
}
