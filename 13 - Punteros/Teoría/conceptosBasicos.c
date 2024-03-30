#include <stdio.h>

int main(){

    int nro, *punt_nro;

    printf("Demostración de funcionamiento básico de punteros\n");
    printf("\nIngrese nro: ");
    scanf("%d", &nro);

    punt_nro = &nro; //Guarda la dirección de memoria de nro

    printf("\n[+] El número ingresado es: %d", *punt_nro); //Se pone * para ingresar al contenido de la dirección de memoria apuntada.
    printf("\n[+] Almacenado en la dirección de memoria: %d", punt_nro);

    return 0;
}