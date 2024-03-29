/*Un laboratorio dispone de una lista con sus 50 medicamentos. De cada uno conoce: 
• Código del medicamento (entero, de 3 cifras). 
• Precio (real). 
• Stock (entero). 

Se solicita: 
a. Declarar un tipo de dato que contenga la información del medicamento. 
b. Declarar un vector de estructura de tipo de datos creado en a. 
c. Cargar en un sector de estructuras, los datos referentes a los medicamentos. Función INGRESO. 
d. Consultar el precio según código del medicamento. Función BUSQUEDA_MEDI. 
e. Informar los códigos de los medicamentos cuyo stock es inferior a 10 unidades. Función INFORME. */

#include <stdio.h>
#include <string.h>

struct medicamentos {
	int codigo;
	float precio;
	int stock;
};

int validar(int, int, int);
int busquedacodigosrepetidos (struct medicamentos[], int, int);
int ingreso (struct medicamentos[], int);
void busqueda_medi(struct medicamentos[], int);
void informe(struct medicamentos[], int);


int main(){
	struct medicamentos medicamento[50];
	
	int seingreso;
	
	seingreso=ingreso(medicamento, 50);
	
	if (seingreso!=0){
		busqueda_medi(medicamento, seingreso);
		informe(medicamento, seingreso);
	}
	else{
		printf("\nNo se han registrado datos en la lista de medicamentos.\n");	
	}
	
	return 0;
}

int validar(int li, int ls, int exc ){
	int bandera=0, nro;
	
	do{
		if(bandera==0){
			printf("\nIngrese valor entre %d y %d: ", li,ls);
			bandera++;
		}	
		else{
			printf("\nValor fuera de rango, porfavor ingrese un valor entre %d y %d: ", li,ls);			
		}
		
		scanf("%d",&nro);
		
	}while((nro < li || nro > ls) && nro!=exc);
	
	return nro;
}


int busquedacodigosrepetidos (struct medicamentos medi[], int nro, int limite){
	int encuentra=-1, i=0;
	
	while(i<limite && encuentra==-1){
		if(medi[i].codigo==nro){
			encuentra=i;
		}
		else{
			i++;
		}
	}	
	return encuentra;
}

int ingreso (struct medicamentos medi[], int limite){
	int seingreso=0, band=0, cod, stock;
	float valor;
	
	printf("Listado de medicamentos!\n");
	do{
			if(band==0){
				printf("\nIngrese código del producto(%d) (termina con 0): ",seingreso+1);
				band++;
			}
			else{
				printf("\nCódigo del producto %d ingresado ya se encuentra en los registros, ingrese otro: ", seingreso+1);	
			}
			
			cod=validar(100,999,0);
		}while(busquedacodigosrepetidos(medi,cod, seingreso) != -1);
	
	while(cod!=0){
		band=0;
				
		medi[seingreso].codigo = cod;
		
		printf("\nIngrese precio del producto(%d): ", seingreso+1);
		valor=validar(0,9999999,9999999);
		medi[seingreso].precio = valor;
		
		printf("\nIngrese stock del producto(%d): ", seingreso+1);
		stock=validar(0,9999999,9999999);
		medi[seingreso].stock = stock;
		
		seingreso++;
		
		do{
			if(band==0){
				printf("\nIngrese código del producto(%d) (termina con 0): ",seingreso+1);
				band++;
			}
			else{
				printf("\nCódigo del producto %d ingresado ya se encuentra en los registros, ingrese otro: ", seingreso+1);	
			}
			
			cod=validar(100,999,0);
		}while(busquedacodigosrepetidos(medi,cod, seingreso) != -1);

	}	
	return seingreso;
}

void busqueda_medi(struct medicamentos medi[], int cantcargado){
	
	int cod=1, poscodigo;
	
	printf("\nConsulta de precios según código del medicamento!\n");
	
	while(cod!=0){
				
		printf("\nIngrese código del medicamento que desea consultar su precio (0 para salir de la consulta): ");
		cod=validar(100,999,0);
		
		if(cod!=0){
			poscodigo=busquedacodigosrepetidos(medi,cod,cantcargado);
			if(poscodigo==-1){
				printf("\nError!, código no encontrado!");
			}
			else{
				printf("\nPrecio: %.2f", medi[poscodigo].precio);
			}
		}			
	}	
}

//Informar los códigos de los medicamentos cuyo stock es inferior a 10 unidades. Función INFORME.

void informe(struct medicamentos medi[], int cantcargado){
	
	int i; 
	
	printf("\nInforme de medicamentos cuyo stock es inferior a 10 unidades!");
	
	for(i=0; i<cantcargado; i++){
		if(medi[i].stock < 10){
			printf("\n %d --> %d unidades restantes.", medi[i].codigo, medi[i].stock);
		}
	}
	
}
