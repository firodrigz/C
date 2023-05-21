#include<stdio.h>

int main()
{

  char VariableSelectora;


  printf("ingrese una vocal: ");
  scanf("%c",&VariableSelectora);

  //CODIFICACIÓN DE LA ESTRUCTURA DE SELECCIÓN MÚLTIPLE.
  switch(VariableSelectora)
  {
    case 'A':
    case 'a':
        printf("VOCAL ingresada %c",VariableSelectora);
        break;

   case 'E':
   case 'e':
   case 'I':
   case 'i':
        printf("VOCAL ingresada %c", VariableSelectora);
        break;
   case 'o':
   case 'O':
        printf("VOCAL ingresada %c",VariableSelectora);
        break;
   case 'u':
   case 'U':
        printf("VOCAL ingresada %c",VariableSelectora);
        break;

  default: printf("\n Valor ingresado fuera de rango. \n");
  }

 
  return 0;

}
