/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */


#ifndef PASSENGER_H
#define PASSENGER_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "inputUtn.h"

typedef struct
{

	//id_peli,titulo,genero,duracion
	int numero;
	char nombre[128];
	char tipo[128];
	char tamanio[4];
	char ataqueCargado[128];
	int valorAtaque;
	int esVarioColor;
}ePokemon;

//Constructores y destructores
ePokemon* Pokemon_new();
ePokemon* Pokemon_newParametros(char *idStr, char *nombreStr, char *tipoStr, char* tamanioStr, char *ataqueStr, char* valorAtaqueStr, char* esVarioColorStr);
void Pokemon_delete();

//SETTERS
int Pokemon_setId(ePokemon* this,int* id);
int Pokemon_setNombre(ePokemon *this, char *nombre);
int Pokemon_setTipo(ePokemon *this, char *tipo);
int Pokemon_setTamanio(ePokemon *this, char *tamanio);
int Pokemon_setAtaqueCargado(ePokemon *this, char *ataqueCargado);
int Pokemon_setValorAtaque(ePokemon *this, int valorAtaque);
int Pokemon_setEsVarioColor(ePokemon *this, int trueFalse);
int Pokemon_setFields(ePokemon* pMovies, int auxId, char* auxNombre, char* auxTipo,char* auxTamanio,char* auxAtaqueCargado, int auxValorAtaque, int auxEsVarioColor);


//GETTERS
int Pokemon_getId(ePokemon* this,int* id);
int Pokemon_getNombre(ePokemon* this,char* titulo);
int Pokemon_getTipo(ePokemon* this, char* genero);
int Pokemon_getValorAtaque(ePokemon* this,int* valorAtaque);
int Pokemon_getEsVarioColor(ePokemon *this, int *trueFalse);
int Pokemon_getAtaqueCargado(ePokemon* this, char* ataqueCargado);
int Pokemon_getTamanio(ePokemon* this, char* tamanio);
int Pokemon_getDescripcionVarioColor(int trueFalse , char* descripcionVariocolor);


//Herramientas
void Pokemon_MostrarUnPokemon(ePokemon* pokemon);
int obtenerId(char* path, int* id);
int buscar_PokemonPorId(LinkedList *pArrayListPokemon, int *id);


//Menus
int subMenu_Dos();
int menuTen();
int subMenu_One();
int Movies_MenuOrden();
int Movies_MenuCriterio();

//Comparadores
int Movies_CompararGenero_Rating(void* pelicula1, void* pelicula2);

//Rating
void* asignarValorAtaque(void* t1);
void* asignarGenero(void *t1);

//Filtros
int filtrarFire(void* a);
int filtrarComedia(void* a);
int filtrarAccion(void* a);
int filtrarAguaVarioColor(void *a);

#endif /* PASSENGER_H_ */
