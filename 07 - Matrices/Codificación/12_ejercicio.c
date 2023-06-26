/*La cadena de supermercados NORTE, tiene 40 sucursales y comercializa 120 rubros de distintas
mercaderías. La Casa Central recibe a diario las notas de pedido de mercaderías emitidas por cada una de las
sucursales.
Se ingresa por teclado las unidades pedidas (estos datos se ingresan hasta que aparece una sucursal igual
a 99, los datos vienen desordenados, y puede venir más de una información de una misma sucursal y el
mismo rubro):
- Número de sucursal (1 a 40).
- Código de rubro (1 a 120).
- Cantidad de unidades pedidas.
Informar:
a. La cantidad de pedidos por sucursal.
b. Cuál fue la sucursal que pidió la menor cantidad en total (puede haber varias sucursales que
tienen el mismo valor mínimo).
FUNCIONES
I. Para inicializar la matriz.
II. Para mostrar el resultado del punto b.*/

#include <stdio.h>
#define SUCURSALES 40
#define RUBROS 120

void inicializar (int [][RUBROS],int,int);
int ingresaValida(int,int,int);
int cargaMatriz(int [][RUBROS],int,int);
void mostrarMatriz(int [][RUBROS],int [],int,int);
void menor(int [],int);


int main(){
	int matriz[SUCURSALES][RUBROS];
	int estadoCarga;
	int cantXSucur[SUCURSALES]={0};
	
	inicializar(matriz,SUCURSALES,RUBROS);
	
	estadoCarga=cargaMatriz(matriz,SUCURSALES,RUBROS);
	
	if(estadoCarga==0){
		printf("No se cargaron pedidos");
	}
	else{
		mostrarMatriz(matriz,cantXSucur,estadoCarga,RUBROS);
		menor(cantXSucur,estadoCarga);
	}
	
	return 0;
}

void inicializar (int m[][RUBROS],int sucursales,int rubros){
	int f,c;
	
	for(f=0;f<sucursales;f++){
		for(c=0;c<rubros;c++){
			m[f][c]=0;
		}
	}	
}

int ingresaValida(int LI, int LS,int EXC){
	int nro, band=0;
	
	do{
		if(band==0){
			printf("\nIngrese valor: ");
			band=1;
		}			
		else
			printf("\nError, vuelva a ingresar valor:");
		
		scanf("%d",&nro);
		
	}while(nro<LI || nro>LS && nro!=EXC);
	
	return nro;	
}

int cargaMatriz(int matriz[][RUBROS],int sucursales,int rubros){
	int nroSucursal, nroRubro, cantidadPedida,i=0;
	
	printf("-- Sucursal --");
	nroSucursal=ingresaValida(1,40,99);
	
	while(i<rubros && nroSucursal!=99){		
		
		printf("\n-- Rubro --");
		nroRubro=ingresaValida(1,120,120);	
		
		printf("\n-- Cantidad --");	
		cantidadPedida=ingresaValida(0,999999,999999);
		
		matriz[nroSucursal-1][nroRubro-1]+=cantidadPedida;
		
		i++;
		
		printf("\n-- Sucursal --");
		nroSucursal=ingresaValida(1,40,99);		
	}	
	return i;	
}


void mostrarMatriz(int matriz[][RUBROS],int cantXSucur[],int sucursal,int rubros){
	int f,c,contador;
		
	for(f=0;f<sucursal;f++){
		contador=0;
		for(c=0;c<rubros;c++){
			contador+=matriz[f][c];			
		}
		cantXSucur[f]=contador;				
	}
	
	for(f=0;f<sucursal;f++){
		printf("%d ",cantXSucur[f]);
	}
}


void menor(int cantSucur[], int tam) {
    int i, band = 0, menor = cantSucur[0], pos = 0;

    for (i = 1; i < tam; i++) {
        if (cantSucur[i] < menor) {
            menor = cantSucur[i];
            pos = i;
        }
    }

    printf("\nEl menor es: %d, encontrado en la posicion %d", menor, pos);
}
