#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h> //CONFIGURACIÓN DEL IDIOMA.

//CONSTANTES.
#define ANIO_MIN 1600 //1582
#define ANIO_MAX 2023
#define DNI_MIN 4000000
#define DNI_MAX 99999999

//PROGRAMA PRINIPAL.
int main()
{
    //BLOQUE DECLARATIVO DE VARIABLES (26 VARIABLES).
    int anioHoy,anioNac,ban,cantEnc,canAlu,canCol,cantdias,
        colB,diaHoy,diaNac,dni,edad,eNoTec,i,mayorE,mesHoy,mesNac,
        mujTec,totM,totalEnc,mayorB,nroCol,totB;
    char conoc,espec,sexo;

    //BLOQUE EJECUTIVO.
    setlocale(LC_ALL,"spanish");//SETEAR EL IDIOMA A ESPAÑOL.

    //BLOQUE DE INICIALIZACIÓN DE CONTADORES Y ACUMULADORES GENERALES.
    eNoTec=mujTec=totM=totalEnc=mayorE=mayorB=0;

    system("cls");//LIMPIAR LA PANTALLA.
    printf("Ingrese fecha de la encuesta:");

    //VALIDACIÓN DE LA FECHA DEL PROCESO.
     do
       {
        ban=0;
        printf("\n\tDia(1-31): ");
        scanf("%d",&diaHoy);
        printf("\n\tMes(1-12): ");
        scanf("%d",&mesHoy);
        printf("\n\tAño(%d-%d): ",ANIO_MIN,ANIO_MAX);
        scanf("%d",&anioHoy);

        if(anioHoy>=ANIO_MIN && anioHoy<=ANIO_MAX)
        {
            if(mesHoy>=1 && mesHoy <=12)
            {
               switch(mesHoy)
                     {
                        case 1:case 3:case 5:case 7:case 8:
                        case 10:case 12:
                                cantdias=31;
                                break;
                        case 4:case 6:case 9:
                        case 11: cantdias=30;
                                 break;

                        case 2: cantdias=28;
                                if((anioHoy % 4==0 && anioHoy % 100!=0)|| anioHoy % 400==0)
                                    cantdias++;
                     }

                      if( diaHoy<1 || diaHoy>cantdias)
                         {printf("\n\tDía incorrecto.\n");
                          ban=1;
                         }

            }
            else
                {
                 printf("\n\tMes incorrecto.\n");
                 ban=1;
                }
        }
        else
             {
              printf("\n\tAño incorrecto.\n");
              ban=1;
             }

    }while(ban == 1);
    //FIN VALIDACIÓN DE FECHA DE PROCESO.

    //INGRESAR LA CANTIDAD DE ESCUELAS.
    ban=0;
    do
    {   if(ban==1)
            printf("\t\t\t\tCantidad incorrecta!!! - Ingrese Nuevamente");
        printf("\nINGRESE CANTIDAD DE COLEGIOS ENCUESTADOS(MAYOR a 0) : ");
        scanf("%d",&canCol);
        ban=1;
    }while(canCol<1);


    /*******************INGRESO POR COLEGIO******************/
    for (i=1;i<=canCol;i++)
    {
        printf("\nIngresar las encuestas del colegio: %3d",i);

        ban=0;
        do
        {   if(ban==1)
                printf("\t\t\t\tNúmero de escuela incorrecta!!! - Ingrese Nuevamente");
            printf("\nINGRESE EL NÚMERO DE ESCUELA (MAYOR A CERO) : ");
            scanf("%d",&nroCol);
            ban=1;
        }while(nroCol<1);

        //INGRESAR LA CANTIDAD DE ALUMNOS.
        ban=0;
        do
        {   if(ban== 1)
                printf("\t\t\t\tCantidad incorrecta!!! - Ingrese Nuevamente");
            printf("\nINGRESE LA CANTIDAD DE ALUMNOS (MAYOR A CERO) : ");
            scanf("%d",&canAlu);
            ban=1;
        }while(canAlu<1);

         //INGRESAR LA ESPECIALIDAD DE LA ESCUELA.
        ban=0;
        do
        {   if(ban==1)
                printf("\t\t\t\tespecialidad incorrecta!!! - Ingrese Nuevamente");
            printf("\nINGRESE LA ESPECIALIDAD DE LA ESCUELA (T:TÉCNICA / N:NO TÉCNICA): ");
            fflush(stdin);
            scanf("%c",&espec);
            espec=toupper(espec);
            ban=1;
        }while(espec!='T'&& espec !='N');

         //INGRESAR EL DNI.
        ban=0;
        do
        {
           if(ban==1)
                printf("\t\t\t\tDNI incorrecto!!! - Ingrese Nuevamente");
           printf("\nINGRESE DNI ENTRE %d y %d(0 PARA FINALIZAR) : ",DNI_MIN,DNI_MAX);
           scanf("%d",&dni);
           ban=1;
        }while (dni!=0 && (dni<DNI_MIN || dni>DNI_MAX));

        cantEnc=totB=0;//INICIALIZACIÓN DE CONTADORES PARTICULARES.

        //PROCESAR CADA ESCUELA.
        while (dni!=0 && cantEnc<canAlu)
        {
            //INGRESAR LA FECHA DE NACIMIENTO DEL ALUMNO.
            printf("Ingresar la fecha de nacimiento:");

             do
               {
                ban=0;
                printf("\n\tDia(1-31): ");
                scanf("%d",&diaNac);
                printf("\n\tMes(1-12): ");
                scanf("%d",&mesNac);
                printf("\n\tAño(%d-%d): ",ANIO_MIN,ANIO_MAX);
                scanf("%d",&anioNac);

                if(anioNac>=ANIO_MIN && anioNac<=ANIO_MAX)
                {
                    if(mesNac>=1 && mesNac <=12)
                    {
                       switch(mesNac)
                             {
                              case 1:case 3:case 5:case 7:case 8:case 10:
                              case 12: cantdias=31;
                                       break;

                              case 4:case 6:case 9:
                              case 11: cantdias=30;
                                       break;

                              case 2: cantdias=28;
                                      if((cantdias % 4==0 && cantdias % 10!=0)|| cantdias % 400==0)
                                          cantdias++;
                              }

                              if(diaNac<1 || diaNac>cantdias)
                                 {
                                  printf("\n\tDía incorrecto.\n");
                                  ban=1;
                                 }
                  }
                  else
                     {
                      printf("\n\tMes incorrecto.\n");
                      ban=1;
                     }
                }
                else
                     {
                      printf("\n\tAño incorrecto.\n");
                      ban=1;
                     }

        }while(ban == 1);

        //INGRESAR EL SEXO DEL ALUMNO.
        ban=0;
        do
        { if (ban==1)
              printf("\t\t\t\tSexo Incorrecto!!! - Ingrese Nuevamente");
          printf("\nIngresar el Sexo(F:FEMENINO / M:MASCULINO): ");
          fflush(stdin);
          scanf("%c",&sexo);
          sexo=toupper(sexo);
          ban=1;
        }while(sexo!='F'&& sexo !='M');

        //INGRESAR EL NIVEL DE CONOCIMIENTO.
        ban=0;
        do
        {
          if (ban==1)
              printf("\t\t\t\tOpinion Incorrecta!!! - Ingrese Nuevamente");
          printf("\nIngresar opinion sobre el Nivel de conocimiento(B:BUENO / M:MALA): ");
          fflush(stdin);
          scanf("%c",&conoc);
          conoc=toupper(conoc);
          ban=1;
         }while(conoc!='B'&& conoc !='M');

         cantEnc++;//INCREMENTAR EN UNO LA CANTIDAD DE ESCUESTADOS.


        //PROCESAR EL TIPO DE ESCUELA Y EL SEXO DEL ALUMNO.
        if (espec=='T')
            if (sexo=='F')
                mujTec++;
        else
            eNoTec++;

        //PROCESAR EL NIVEL DE CONOCIMIENTOS.
        if (conoc=='M')
            totM++;
        else
            totB++;

        //CALCULAR LA EDAD DEL ALUMNO
        edad=anioHoy-anioNac;
        if(mesNac > mesHoy)
           edad--;
        else
           if(mesNac == mesHoy && diaNac > diaHoy)
                 edad--;

        //OBTENER EL ALUMNO DE MAYOR EDAD.
        if (edad>mayorE)
            mayorE=edad;


        //INGRESO DEL DNI (LECTURA INTERNA DEL CICLO WHILE).
            ban=0;
            do
             {
              if(ban==1)
                printf("\t\t\t\tDNI incorrecto!!! - Ingrese Nuevamente");
              printf("\nINGRESE DNI ENTRE %d y %d(0 PARA FINALIZAR) : ",DNI_MIN,DNI_MAX);
              scanf("%d",&dni);
              ban=1;
             }while (dni!=0 && (dni<DNI_MIN || dni>DNI_MAX));

        }//FIN WHILE.

        //ACTUALIZAR LOS ACUMULADORES.
        totalEnc+=cantEnc;

        //printf("\nTotal de encuestados = %3d\n",cantEnc);

        //INFORMES POR COLEGIO
        if(cantEnc>0)
           {
            printf("\n\nPorcentaje de alumnos que respondieron la encuesta del colegio %d fue : %.2f%% ",nroCol,((float)cantEnc/canAlu) *100);

            //ESCUELA CON MAYOR OPINIÓN BUENA DE CONOCIMIENTOS.
            if (totB > mayorB)
               {
                mayorB=totB;
                colB=nroCol;
               }

           }

        else
            printf("\n\nNingún alumno respondió la encuesta\n");



    }// FIN DEL CICLO FOR.

    /*****************************INFORME FINAL*****************************/
    if(totalEnc > 0)
      {
       printf("\n\nCantidad de alumnos que contestó la encuesta del Colegio NO TÉCNICO: %d", eNoTec);
       printf("\n\nPorcentaje de Mujeres de escuelas técnicas sobre la cantidad de estudiantes que respondieron la encuesta fue:  %.2f%%",(float) mujTec/totalEnc*100);
       printf("\n\nPorcentaje de estudiantes que respondieron que los conocimientos adquiridos eran malos, sobre total de encuestados:  %.2f%%" ,(float) totM/totalEnc*100);
       printf("\n\nMayor edad de los estudiantes encuestados: %d", mayorE);
       if(mayorB>0)
          printf("\n\nNúmero de Colegio con mayor opinión buena sobre conocimientos adquiridos: %d",colB );
       else
          printf("\n\nNo existen escuelas con opinión buena respecto al nivel de conocimientos adquiridos\n");
     }
    else
      printf("\n\nNo se ingresaron alumnos.");

    printf("\n\n");

    system("pause");
    return 0;
}
