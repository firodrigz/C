/*Un negocio de perfumería efectúa descuentos en sus ventas según el importe de las mismas, con la
siguiente escala:
? menor a 50 pesos el 3.5 %
? entre 50 y 150 pesos el 10 %
? entre 151 y 300 pesos el 20 %.
? mayor a 300 pesos el 25 %
Confeccionar un programa que:
a. Solicite un importe y calcule el descuento a efectuar y el importe neto a cobrar, con mensajes
aclaratorios.
b. Informe el importe promedio de todas las ventas realizadas.
Se debe contemplar que se puedan ingresar varios importes y para finalizar se ingresa un valor negativo o
cero*/

#include <stdio.h>
#include <locale.h>

int main(){
	int acumPrecio = 0, venta = 0;
	float importe,neto,dto;
	
	setlocale(LC_ALL,"spanish");
	
	printf("Ingrese importe: ");
	scanf("%f",&importe);
	
	while(importe>=1){
	venta++;
					
		if(importe<50){
			dto=importe*3.5/100;
			neto=importe-dto;
			acumPrecio+=neto;
		}
		else{
			if((importe>=50)&&(importe<=150)){				
				dto=importe*10/100;
				neto=importe-dto;
				acumPrecio+=neto;
			}
			else{
				if((importe>=151)&&(importe<=300)){
					dto=importe*20/100;
					neto=importe-dto;
					acumPrecio+=neto;
				}
				else{
					dto=importe*25/100;
					neto=importe-dto;
					acumPrecio+=neto;
				}				
			}
		}
				
		printf("\nImporte Neto: %.2f ",neto);
		
		printf("\n\nIngrese importe: ");
		scanf("%f",&importe);
		
	}
	
	if(venta!=0){
		
		printf("\nPromedio de todas las ventas: %.2f",(float)acumPrecio/venta);
	}
	else{
		printf("\nNo se realizaron ventas");
	}	
	return 0;
}

