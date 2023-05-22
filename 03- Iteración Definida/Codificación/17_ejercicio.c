/*Ingresar N art�culos (c�digos) y sus correspondientes precios. Indicar el c�digo del art�culo m�s caro y el
precio del m�s barato. NOTA: todos los art�culos tienen precios distintos.*/

#include <stdio.h>

int main() {
    int band = 0;
    int n,cod,i,codmax;
    float precio,pmin,pmax;
    
    printf("Ingresar cantidad de art�culos: ");
    scanf("%d",&n);
    
    for(i=1;i<=n;i++){
    	printf("\nIngresar c�digo del art�culo: ");
    	scanf("%d",&cod);
    	
    	printf("Ingresar precio del art�culo: ");
    	scanf("%f",&precio);
    	
    	if(band==0){  // Hecho con bandera, si no usar�a directamente el contador if(i==1)
    		pmax=precio;
    		pmin=precio;
    		codmax=cod;
    		band=1;
		}
		else{
			if(precio>pmax){
				pmax=precio;
				codmax=cod;
			}
			else{
				if(precio<pmin){
					pmin=precio;
				}
			}
		}
	}
	
	printf("\nC�digo del art�culo m�s caro: %d  \nPrecio del art�culo m�s barato: %.2f ",codmax,pmin);    

    return 0;
}
