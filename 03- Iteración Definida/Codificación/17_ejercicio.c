/*Ingresar N artículos (códigos) y sus correspondientes precios. Indicar el código del artículo más caro y el
precio del más barato. NOTA: todos los artículos tienen precios distintos.*/

#include <stdio.h>

int main() {
    int band = 0;
    int n,cod,i,codmax;
    float precio,pmin,pmax;
    
    printf("Ingresar cantidad de artículos: ");
    scanf("%d",&n);
    
    for(i=1;i<=n;i++){
    	printf("\nIngresar código del artículo: ");
    	scanf("%d",&cod);
    	
    	printf("Ingresar precio del artículo: ");
    	scanf("%f",&precio);
    	
    	if(band==0){  // Hecho con bandera, si no usaría directamente el contador if(i==1)
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
	
	printf("\nCódigo del artículo más caro: %d  \nPrecio del artículo más barato: %.2f ",codmax,pmin);    

    return 0;
}
