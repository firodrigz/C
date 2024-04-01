#include <stdio.h>

struct empleados {
	char nombre[10];
	char apellido[15];
	int edad;
	float sueldo;
};

void muestraDatos(struct empleados *emp);

int main(){

    int nro, *punt_nro;

    printf("Demostraci贸n de funcionamiento b谩sico de punteros\n");
    printf("\nIngrese nro: ");
    scanf("%d", &nro);

    punt_nro = &nro; //Guarda la direcci贸n de memoria de nro

    printf("\n[+] El n煤mero ingresado es: %d", *punt_nro); //Se pone * para ingresar al contenido de la direcci贸n de memoria apuntada.
    printf("\n[+] Almacenado en la direcci贸n de memoria: %d", punt_nro);
    
	struct empleados empl;
	    
	fflush(stdin);	    //limpia buffer
	printf("\n\nIngrese Apellido del empleado: ");
	fgets(empl.apellido, 10, stdin);
	
	fflush(stdin);	
	printf("Ingrese nombre del empleado: ");
	fgets(empl.nombre, 10, stdin);
	
	printf("Ingrese edad del empleado: ");
	scanf("%d",&empl.edad);

	printf("Ingrese sueldo del empleado: ");
	scanf("%f",&empl.sueldo);

	muestraDatos(&empl); //se hace el env韔 de la direcci髇 de memoria para que no se tenga que hacer copia de la estructura completa.

    return 0;
}


void muestraDatos(struct empleados *emp){
	printf("El empleado %s, %s con edad %d, tiene el siguiente sueldo: %.2f.", 
			emp->apellido, emp->nombre, emp->edad, emp->sueldo); //Al ser puntero se reemplaza . por ->
}
