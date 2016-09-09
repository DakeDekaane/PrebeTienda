#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

//enum boolean{false,true};

//int num_usuarios=2;
//int tamano_contrasena=5;
//int tamano_usuario=10;

char usuarios[2][10]={"donaldo","2"};
char contrasenas[2][5]={"1994","1991"};



int intentos=3;	
int check=0;

enum boolean valida_usuario();


int main(int argc, char const *argv[])
{
	printf("\t\tPrebeTienda\n");

	valida_usuario();

	FILE *archivo = fopen("Productos.txt","a+");
	if (!archivo) {
		printf("Error al cargar base de datos. Verifique el archivo.\n");
		return 1;
	}

	char linea[30];
	fscanf(archivo,"%s",linea);
	printf("%s\n",linea);
	fclose(archivo);

	InsertaNodo(crearNodo("Papas",10,8.00));	
	InsertaNodo(crearNodo("Refresco",15,9.50));
	InsertaNodo(crearNodo("Leche",2,100.00));
	InsertaNodo(crearNodo("Chocolate",30,0.50));
	InsertaNodo(crearNodo("Cafe",25,2.50));
	ImprimeNodos();
	printf("\n");
	RemueveNodo("Refresco");
	ImprimeNodos();
	printf("\n");
	ModificaNodo("Dulces");
	ModificaNodo("Papas");
	ImprimeNodos();
	printf("\n");
	BuscaNodo("Leche");
	BuscaNodo("Agua");
	
	return 0;
}

enum boolean valida_usuario(){

	char usuarioIngresado[16]={'\0'}, contrasenaIngresada[16]={'\0'};
	do {
		printf("Usuario: ");
		scanf(" %[^\n]",usuarioIngresado);
		printf("Contraseña: ");
		scanf(" %[^\n]",contrasenaIngresada);
	
		for (int i=0;i<2;i++) {
			if( strcmp(usuarioIngresado,usuarios[i]) == 0 && strcmp(contrasenaIngresada,contrasenas[i]) ==0 ) {
				printf("Acceso autorizado. Bienvenido, %s.\n",usuarioIngresado);
				check = 1;
				break;
			}
			else {
				continue;
			}
		}
		
		if ( check == 0 ) {
			printf("Acceso denegado. Verifique sus datos\n");
			intentos--;
		}
		else {
			continue;
		}

	} while(intentos > 0 && check == 0 );

	if (intentos == 0) printf("Ha realizado 3 intentos fallidos, se le reportará al servidor\n\n");
	return 1;
}

