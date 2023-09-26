/*El gobierno de la nación desea controlar el volumen de facturación de la matriz energética nacional, que
está compuesto por las empresas que brindan servicios de Luz, Agua y Gas. Existen a lo sumo 10 empresas y
por cada una se debe ingresar:
• Código de la empresa (número entero entre 1000 y 5000)
• Tipo de servicio (caracter L, A o G (correspondiente a Luz, Agua y Gas respectivamente))
La carga finaliza con un código de empresa igual a 0.
Luego se ingresa el detalle de la facturación con los siguientes datos:
• Código de empresa
• Mes
• Importe facturado
No todas empresas facturaron todos los meses y puede existir más de una factura por empresa/mes.
La carga de facturación finaliza con un mes igual a -1.

1. Mostrar la matriz energética con el siguiente formato respetando los títulos
Empresa\Mes 1 		2 		3 		... 12
xxxx 		xxx.xx xxx.xx xxx.xx 	... xxx.xx
xxxx 		xxx.xx xxx.xx xxx.xx 	... xxx.xx
xxxx 		xxx.xx xxx.xx xxx.xx 	...	xxx.xx 
2. Indicar el/los trimestres de mayor facturación, indicando el número de trimestre y el monto
3. Mostrar en forma ordenada de mayor a menor el importe total facturado por tipo de servicio. Mostrando un
listado con Tipo de empresa y total facturado.
4. Mostrar el código y tipo de servicio de aquellas empresas que no hayan facturado en 2 o más meses  // recorrer la matriz como si fuera una muestra y con un
contador ir controlando si es 0 mas de 2 veces imprimir solo el código 
*/

#include <stdio.h>
#include <locale.h>
#define EMPRESAS 10
#define MESES 12
#define SERVICIOS 3

int validar(int, int, int);
int busqueda(int [], int, int);
int cargaEmpresas(int [], char [], int);
int cargaFacturas(float [][MESES], int [], char [], float [], int, int);
void mostrarMatriz(float [][MESES], int[], int, int);
void mostrarImporteServicio(float [], int);

int main(){
	int vectorCodigoEmpresas[EMPRESAS];
	char vectorTipoServicio[EMPRESAS];
	float recaudacionTipoServicio[SERVICIOS]={0};
	float matrizFacturacion[EMPRESAS][MESES]={{0}};
	
	
	setlocale(LC_ALL,"spanish");
	
	int empresasCargadas, facturasCargadas;
	
	empresasCargadas= cargaEmpresas(vectorCodigoEmpresas, vectorTipoServicio, EMPRESAS);
	
	if(empresasCargadas!=0){
		facturasCargadas=cargaFacturas(matrizFacturacion, vectorCodigoEmpresas, vectorTipoServicio, recaudacionTipoServicio, EMPRESAS, MESES);
		if(facturasCargadas!=0){
			mostrarMatriz(matrizFacturacion, vectorCodigoEmpresas, empresasCargadas, MESES);
			mostrarImporteServicio(recaudacionTipoServicio, SERVICIOS);
		}else{
			printf("\nNo se cargaron facturas!");
		}
	}else{
		printf("\nNo se cargaron empresas!");
	}
	
	return 0;
}

int validar(int LI, int LS, int exc){
	int nro, band=0;
	
	do{
		if(band==0){
			printf("\nValor válido entre %d y %d: ", LI,LS);
			band++;
		}else{
			printf("\nError, valor fuera de rango, vuelva a intentarlo, ingrese valor válido: ");
		}
		scanf("%d",&nro);
		
	}while((nro<LI||nro>LS) && nro!=exc);
	
	return nro;
}

int busqueda(int vector[], int nro, int ce){
	int i=0, encuentra=-1;
	
	while(encuentra==-1 && i<ce){
		if(vector[i]==nro){
			encuentra=i;
		}
		else{
			i++;
		}
	}
	
	return encuentra;
}

int cargaEmpresas(int vectorCodigo[], char vectorTipo[], int ce){
	int i=0, codigo, encuentra, band;
	char tipo;
	
	printf("Carga de empresas\n");
	
	printf("Ingrese código de empresa (finaliza con 0): ");
	codigo=validar(1000,5000,0);
	
	while(codigo!=0 && i<ce){
		encuentra=busqueda(vectorCodigo, codigo, i);
		
		if(encuentra==-1){
			band=0;
			vectorCodigo[i]=codigo;			
			do{
				if(band==0){
					printf("\nIngrese tipo de servicio (A-G-L): ");
					band++;
				}else{
					printf("\nError, ingrese tipo de servicio válido (A-G-L): ");
				}
				fflush(stdin);
				scanf("%c",&tipo);				
			}while(tipo!='A' && tipo!='G' && tipo!='L');
			vectorTipo[i]=tipo;
						
			i++;
			
		}else{
			printf("\nError, código repetido, intente nuevamente\n");
		}
		
		printf("\nIngrese código de empresa (finaliza con 0): ");
		codigo=validar(1000,5000,0);
	}
		
	return i;
}

int cargaFacturas(float matrizAcumulador[][MESES], int vectorCodigo[], char vectorTipo[], float vectorValoresTipo[], int cEmpresas, int cMeses){
	int i=0, codigoIngresado, mesIngresado, encontrado;
	float importeIngresado;
	char tipoEncontrado;
	
	printf("Ventas\n");
	
	printf("Mes de venta: ");
	mesIngresado=validar(1,12,-1);
	
	while(mesIngresado!=-1){
		
		printf("\nCódigo de empresa: ");
		codigoIngresado=validar(1000,5000,5000);				
		
		encontrado=busqueda(vectorCodigo, codigoIngresado,cEmpresas);
		
		if(encontrado!=-1){
			printf("\nImporte facturado: ");
			scanf("%.2f",&importeIngresado);
			
			tipoEncontrado=vectorTipo[encontrado];
			if(tipoEncontrado=='A'){
				vectorValoresTipo[0]+=importeIngresado;
			}if(tipoEncontrado=='G'){
				vectorValoresTipo[1]+=importeIngresado;
			}else{
				vectorValoresTipo[2]+=importeIngresado;
			}
			
			matrizAcumulador[encontrado][mesIngresado-1]+=importeIngresado;
		}else{
			printf("\nError, código de empresa no encontrado, ingrese otro\n");
		}
		
		
		printf("\nMes de venta: ");
		mesIngresado=validar(1,12,-1);
		
	}
	
	return i;
}

void mostrarMatriz(float matriz[][MESES], int vector[], int cf, int cc){
	int i, j;
	
	printf("EMPRESA\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12");
	
	for(i=0;i<cf;i++){
		printf("%d\t", vector[i]);
		for(j=0;j<cc;j++){
			printf("%.2f\t",matriz[i][j]);
		}
		printf("\n");
	}
}

void mostrarImporteServicio(float vector[], int ce){
	int i, j, aux;
	
	for(i=0;i<ce-1;i++){
		for(j=0;j<ce-i-1;j++){
			if(vector[j]<=vector[j+1]){
				aux=vector[j];
				vector[j]=vector[j+1];
				vector[j+1]=aux;
			}
		}
	}
	
	printf("\nMuestra mayor a menor el importe total facturado por tipo de servicio\n");
	
	for(i=0;i<ce;i++){
		printf("%d\t", vector[i]);
	}
}


