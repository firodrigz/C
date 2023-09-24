/* Una empresa desea realizar un cuadro con el detalle anual de las ventas de sus productos

Por teclado se ingresa el detalle de ventas:
• Código de Producto (entero de 5 cifras)
• Mes (entero del 1 al 12)
• Cantidad Vendida (entero mayor a 0)
• Precio Unitario (float)

La carga se realiza sin orden alguno y finaliza con un código de producto igual a 0.

No se sabe la cantidad exacta de productos, pero sí que no son más de 30. No se realiza carga inicial de
productos ya que se van ingresando junto con el detalle de ventas. Si se ingresan dos veces ventas para el mismo
producto/mes se debe preguntar al usuario si desea reemplazar o no el dato anterior.

En base a los datos ingresados se debe mostrar por pantalla un cuadro resumen del importe recaudado en
cada mes de las ventas de cada producto según el siguiente esquema respetando los títulos.
*/

#include <stdio.h>
#include <locale.h>
#define TAMPROD 30
#define TAMMES 12

int validar(int,int,int);
int busqueda(int [], int, int);
int cargaIncompleta(float [][TAMMES], int [], int, int);
void mostrarMatriz(float [][TAMMES], int [], int, int);

int main(){
	int vectorCodigoProducto[TAMPROD]={0};
	float matrizRecaudacion[TAMPROD][TAMMES]={{0}};
	int ingreso;
	
	setlocale(LC_ALL,"spanish");
	
	ingreso=cargaIncompleta(matrizRecaudacion, vectorCodigoProducto, TAMPROD, TAMMES);
	
	if(ingreso!=0){
		mostrarMatriz(matrizRecaudacion, vectorCodigoProducto, ingreso, TAMMES);
	}else{
		printf("\nNo se registraron ventas!");
	}	
	
	return 0;	
}


int validar(int LI,int LS,int exc){
	int nro, band=0;
	
	do{
		if(band==0){
			printf("\nValor válido entre %d y %d: ", LI,LS);
			band++;
		}else{
			printf("\nError, valor fuera de rango, vuelva a intentarlo, ingrese valor válido: ");
		}
		scanf("%d", &nro);
			
	}while((nro<LI||nro>LS)&&nro!=exc);
	
	return nro;
}

int busqueda(int vector[], int nro, int ce){
	int encuentra=-1, i=0;
	
	while(i<ce && encuentra==-1){
		if(vector[i]==nro){
			encuentra=i;
		}else{
			i++;
		}
	}
	
	return encuentra;
}

int cargaIncompleta(float matrizValores[][TAMMES], int vectorCodigos[], int tamProd, int tamMes){
	int i=0, codigoProducto, mes, cantVendida, esUnico;
	float precioUnitario, precioFinal;
	
	printf("Carga de ventas durante el año\n\n");
	
	printf("Ingrese código de producto (termina con 0): ");
	codigoProducto=validar(10000,99999,0);
	
	while(codigoProducto !=0){
		
		printf("\nIngrese precio unitario del producto:");
		scanf("%f", &precioUnitario);
			
		printf("\nIngrese cantidad vendida (mayor a 0): ");
		cantVendida= validar(1,9999,9999);
		
		printf("\nIngrese mes de venta (1 - 12): ");
		mes= validar(1,12,12);
		
		precioFinal= cantVendida * precioUnitario;		
		
		esUnico = busqueda(vectorCodigos,codigoProducto,i);
		if(esUnico==-1 && i<tamProd){
			//Es único - lo uso para la carga x acceso directo de matriz
			vectorCodigos[i]=codigoProducto;
			matrizValores[i][mes-1]=precioFinal;
			i++;
		}else{
			matrizValores[esUnico][mes-1]=precioFinal;
		}
				
		printf("\nIngrese código de producto (termina con 0): ");
		codigoProducto=validar(10000,99999,0);
					
	}	
	
	return i;
}

void mostrarMatriz(float matriz[][TAMMES], int vector[], int cf, int cc){
	int i,j;
	
	printf("\nProducto\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\n");
	for(i=0;i<cf;i++){
		printf("%d\t\t", vector[i]);
		for(j=0;j<cc;j++){
			printf("%.2f\t", matriz[i][j]);
		}
		printf("\n");
	}
}
