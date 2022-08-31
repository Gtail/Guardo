/*
 ============================================================================
 Name        : Final.c
 Author      : Gian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrayPokemon.h"
#include "LinkedList.h"
#include "Controller.h"


int main(void) {
	setbuf(stdout,NULL);
	srand(time(NULL));
	int option;
	//int opcion;
	LinkedList* listaPokemones = ll_newLinkedList();

	if (listaPokemones == NULL) {
		puts("No se consiguio espacio en memoria \n");
	} else {

		do {
			option = menuTen();
			switch (option) {
			case 1:
				printf("\n Usted ha seleccionado 1: Cargar Archivo de Pokemones \n");
				Franzoso_controller_loadFromText("Data_Pokemones.csv", listaPokemones);
				break;
			case 2:
				printf("\n Usted ha seleccionado 2: Eliminar Pokemon \n");
				Franzoso_controller_removePokemon(listaPokemones);
				break;
			case 3:
				printf("\n Usted ha seleccionado 3: Imprimir Lista de Pokemones \n");
				Franzoso_controller_ListPokemones(listaPokemones);
				break;
			case 4:
				printf("\n Usted ha seleccionado 4: Filtrar de Tipo Agua variocolor \n");
				Franzoso_controller_filterAguaVarioColor(listaPokemones);
				break;
			case 5:
				printf("\n Usted ha seleccionado 5: Mapear Ataque Cargado \n");

				Franzoso_controller_filterFire(listaPokemones);
				break;
			case 6:
				printf("\n Usted ha seleccionado 6: Batalla Pokemon \n");
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				printf("\n Hasta Luego! \n");
				break;
			}
		} while (option != 10);
	}
	return 0;
}

int menuTen()
{
	int opcion;
	printf("\n\t>-MENU PRINCIPAL-<\t\n");
	printf("-----------------------------------------\n");
	printf(" Opcion 1 Cargar archivo de Pokemones \n");
	printf(" Opcion 2 Eliminar Pokemon \n");
	printf(" Opcion 3 Imprimir Pokemones \n");
	printf(" Opcion 4 Filtrar por Agua variocolor \n");
	printf(" Opcion 5 Mapear Ataque Cargado \n");
	printf(" Opcion 6 Batalla Pokemon! \n");
	printf(" Opcion 10 Salir \n");

	scanf("%d", &opcion);

	return opcion;
}

