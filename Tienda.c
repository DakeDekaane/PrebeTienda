#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

//enum boolean{false,true};

//int num_usuarios=2;
//int tamano_contrasena=5;
//int tamano_usuario=10;

char usuarios[2][10] = {"donaldo","2"};
char contrasenas[2][5] = {"1994","1991"};

int intentos = 3;	

enum boolean validaUsuario();

int main(int argc, char const *argv[]) {

	if(validaUsuario()) {

		system("clear");
		int salir = 0;
		int opcion;
		char nombreProducto[20]={'\0'};
		int cantidad;
		float precio;
		CargaInventario();
		
		do {
		
			printf("\n\t\t\t\tLa PrebeTienda\n\n\n");			
			system("clear");
			printf("Menú:\n");
			printf("1. Mostrar inventario completo.\n");
			printf("2. Mostrar detalles de un producto.\n");
			printf("3. Agregar producto.\n");
			printf("4. Remover producto.\n");
			printf("5. Editar detalles de un producto.\n");
			printf("6. Salir\n");
			printf("Ingrese una opción: ");
			scanf("%d",&opcion);
			
			switch(opcion) {
				case 1:
					ImprimeInventario();
					break;
				case 2:
					printf("\nIngrese el nombre del producto: ");
					scanf(" %[^\n]",nombreProducto);
					BuscaProducto(nombreProducto);
					break;
				case 3:
					printf("\nIngrese el nombre del producto: ");
					scanf(" %[^\n]",nombreProducto);
					printf("\nIngrese la cantidad del producto: ");
					scanf("%d",&cantidad);
					printf("\nIngrese el precio del producto: ");
					scanf("%f",&precio);
					InsertaProducto(crearNodo(nombreProducto,cantidad,precio));
					break;
				case 4:
					printf("\nIngrese el nombre del producto: ");
					scanf(" %[^\n]",nombreProducto);
					RemueveProducto(nombreProducto);
					break;
				case 5:
					printf("\nIngrese el nombre del producto: ");
					scanf(" %[^\n]",nombreProducto);
					ModificaInventario(nombreProducto);
					break;
				case 6:
					salir = 1;
					break;
				default:
					printf("\nOpción inválida");
					break;
			}

			GuardaInventario();

		} while(salir == 0);

	}
	
	return 0;
}

enum boolean validaUsuario(){

	char usuarioIngresado[16]={'\0'}, contrasenaIngresada[16]={'\0'};
	do {
		printf("Usuario: ");
		scanf(" %[^\n]",usuarioIngresado);
		printf("Contraseña: ");
		scanf(" %[^\n]",contrasenaIngresada);
	
		for (int i=0;i<2;i++) {
			if( strcmp(usuarioIngresado,usuarios[i]) == 0 && strcmp(contrasenaIngresada,contrasenas[i]) ==0 ) {
				printf("Acceso autorizado. Bienvenido, %s.\n\n\n\n\n",usuarioIngresado);
				return true;
			}
			else {
				continue;
			}
		}
		printf("Acceso denegado. Verifique sus datos\n");
		intentos--;
	} while(intentos > 0);

	if (intentos == 0) printf("Ha realizado 3 intentos fallidos, se le reportará al administrador.\n\n");
	return false;
}

