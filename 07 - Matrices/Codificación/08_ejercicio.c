/*Un consorcio desea controlar la cobranza de las expensas en un edificio de 5 pisos donde existen 15
departamentos en cada piso. El valor de las expensas es de $ 1000. Para registrar la cobranza se ingresa el
número de piso (1 a 5) y el número de departamento (correlativo de 1 a 15 en cada piso). El ingreso finaliza
con un piso igual a 99.
Al finalizar mostrar el dinero total recaudado y una tabla con una X indicando aquellos departamentos
deudores de la siguiente manera:

									TOTAL RECAUDADO
								DEPARTAMENTOS DEUDORES
PISO 		DPTO 1 			DPTO2 		… 		DPTO 15
PISO 1 		  X
PISO 2 		  X 			  X
PISO 3 												X
PISO 4 						  X                     X
PISO 5 		  X
*/

#include <stdio.h>
#include <locale.h>
#define PISOS 5
#define DEPARTAMENTOS 15

int validarIngreso(int,int,int);
int cargarPagos(int [][DEPARTAMENTOS],int,int,int);
int montoTotal(int [][DEPARTAMENTOS],int,int);
void cargarDeudas(int [][DEPARTAMENTOS],char [][DEPARTAMENTOS],int,int);
void mostrarMatrizPagos(int [][DEPARTAMENTOS],int,int);
void mostrarMatrizDeudas(char [][DEPARTAMENTOS],int,int);

int main(){
	int expensasPagas[PISOS][DEPARTAMENTOS]={{0}};
	char expensasDeudores[PISOS][DEPARTAMENTOS]={{'O'}};
	int cantPagos, totalRecaudado;
	
	setlocale(LC_ALL,"spanish");
		
	cantPagos=cargarPagos(expensasPagas,PISOS,DEPARTAMENTOS,99);
	
	if(cantPagos==0){
		printf("\n\nTodos los departamentos del edificio son deudores");		
	}
	else{
		totalRecaudado=montoTotal(expensasPagas,PISOS,DEPARTAMENTOS);
		printf("\nTotal recaudado: $ %d", totalRecaudado);
		cargarDeudas(expensasPagas,expensasDeudores,PISOS,DEPARTAMENTOS);
		mostrarMatrizDeudas(expensasDeudores,PISOS,DEPARTAMENTOS);
	}
	
	return 0;
}

int validarIngreso(int LI,int LS,int exc){
	int band = 0;
	int nro;
	
	do{
		if(band==0){
			printf("Ingrese valor entre %d - %d : ",LI,LS);
			band = 1;	
		}
		else{
			printf("ERROR, vuelva a ingresar valor entre %d - %d : ",LI,LS);
		}
		
		scanf("%d",&nro);		
		
	}while(nro<LI || nro>LS && nro!=exc);
	
	return nro;
}

int cargarPagos(int matrizPagos[][DEPARTAMENTOS],int cf, int cc,int exc){
	int piso, departamento, condicion;
	int cantPagos;
	int band=0;
	
	printf("-- Pagos de expensas --\n");
	printf("\nPiso del edificio\n ");
	piso = validarIngreso(1,cf,exc);
	
	while(piso!=exc){
		band++;
		
		printf("\nDepartamento\n ");
		departamento = validarIngreso(1,cc,cc);
		
		printf("\nEstado de pago (1 si pagó - 0 si no pagó)\n ");
		condicion = validarIngreso(0,1,1);
		
		//actualizo matriz
		if(condicion == 1)
			matrizPagos[piso-1][departamento-1]=1000;
			
		mostrarMatrizPagos(matrizPagos,cf,cc);		
		
		printf("\nPiso del edificio\n ");
		piso = validarIngreso(1,cf,exc);	
	}	
	return cantPagos;
}

int montoTotal(int expensas[][DEPARTAMENTOS],int cantidadPisos,int cantidadDepartamentos){
	int total = 0;
	int i,j;
	
	for(i = 0; i < cantidadPisos; i++){
		for(j = 0; j < cantidadDepartamentos; j++){
			total += expensas[i][j];
		}
	}	
	
	return total;
}

void mostrarMatrizPagos(int matriz[][DEPARTAMENTOS],int cf,int cc){
	int i,j;
	
	printf("\nCarga exitosa!\n");	
	printf("\n\t\t\t\t\t\t\t-- Muestra de matriz --\n");
	for(i = 0; i < cc;i++){
		printf("\tDPTO%d",i+1);		
	}	
	printf("\n");
	
	
	for(i = 0; i < cf; i++){
		printf("PISO %d ",i+1);
		for(j = 0; j < cc; j++){
			printf("| %4d |",matriz[i][j]);
		}
		printf("\n");
	}	
}

void cargarDeudas(int pagos[][DEPARTAMENTOS],char deudores[][DEPARTAMENTOS],int piso,int departamento){
	int i,j;
	
	for(i = 0; i < piso; i++){
		for(j = 0; j < departamento; j++){
			if(pagos[i][j]==0)
				deudores[i][j]= 'X';
		}
	}
}

void mostrarMatrizDeudas(char matrizdeudas[][DEPARTAMENTOS],int cf,int cc){
	int i,j;
		
	printf("\n\t\t\t\t\t\t\t-- Departamentos Deudores --\n");
	for(i = 0; i < cc;i++){
		printf("\tDPTO%d",i+1);		
	}	
	printf("\n");
	
	
	for(i = 0; i < cf; i++){
		printf("PISO %d ",i+1);
		for(j = 0; j < cc; j++){
			printf("  %c\t",matrizdeudas[i][j]);
		}
		printf("\n");
	}
	
}
