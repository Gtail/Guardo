/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "arrayPokemon.h"

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

int subMenu_One()
{

	int opcion;
	printf("\n\t>-MENU FILTRADO-<\t\n");
	printf("-----------------------------------------\n");
	printf("\n Opcion 5 Filtrar Peliculas de Drama \n");
	printf("\n Opcion 6 Filtrar Peliculas de  Comedia \n");
	printf("\n Opcion 7 Filtrar Peliculas de  Accion\n");
	printf("\n Opcion 8 Filtrar Peliculas de Terror \n");
	printf("\n Opcion 9 SALIR \n");
	scanf("%d", &opcion);

	return opcion;
}

int Movies_MenuOrden()
{
	int opcion;

	printf("\n\t>-MENU ORDENAMIENTO-<\t\n");
	printf("-----------------------------------------\n");
	printf("1. Ordenar Ordenar por genero y Rating\n");
	printf("2. Mostrar Listado\n");
	printf("3. Salir \n");


	opcion=getValidInt("Ingrese una opcion 1-3 \n", "ERROR solo 1-3 \n", 1, 3);

	return opcion;
}

int Movies_MenuCriterio()
{
	int opcion;

	printf("\n\t>-CRITERIO DE ORDENAMIENTO-<\t\n");
	printf("-----------------------------------------\n");
	printf("0. Descendente\n");
	printf("1. Ascendente\n");

	opcion=getValidInt("Ingrese una Opcion 0 - 1", "Error Ingrese una opcion 0 - 1", 0, 1);

	return opcion;
}

ePokemon* Pokemon_new(){
	ePokemon* auxPokemon;

	auxPokemon = (ePokemon*) malloc(sizeof(ePokemon));

	Pokemon_setFields(auxPokemon, 0, "sin asignar", "sin asignar", "NA", "sin asignar", 0, 0);
	return auxPokemon;

}
ePokemon* Pokemon_newParametros(char *idStr, char *nombreStr, char *tipoStr, char* tamanioStr, char *ataqueStr, char* valorAtaqueStr, char* esVarioColorStr) {
	ePokemon *pPokemon = Pokemon_new();
	int auxId;
	int auxValorAt;
	int auxEsVarioC;

	auxId = atoi(idStr);
	auxValorAt = atoi(valorAtaqueStr);
	auxEsVarioC= atoi(esVarioColorStr);

	if (pPokemon != NULL && idStr != NULL && nombreStr != NULL && tipoStr != NULL && tamanioStr!=NULL && ataqueStr != NULL && valorAtaqueStr != NULL && esVarioColorStr != NULL ) {

		if (Pokemon_setFields(pPokemon, auxId, nombreStr, tipoStr,tamanioStr ,ataqueStr ,auxValorAt, auxEsVarioC) != -1) {
			//printf("Campos asignados exitosamente \n");

		}else{
			Pokemon_delete(pPokemon);
		}
	}

	return pPokemon;
}

int Pokemon_setFields(ePokemon* pPokemon, int auxId, char* auxNombre, char* auxTipo,char* auxTamanio,char* auxAtaqueCargado, int auxValorAtaque,
		int auxEsVarioColor)
{
	int retorno=-1;
	int id=Pokemon_setId(pPokemon, &auxId);
	int name=Pokemon_setNombre(pPokemon, auxNombre);
	int type=Pokemon_setTipo(pPokemon, auxTipo);
	int tamanio=Pokemon_setTamanio(pPokemon, auxTamanio);
	int atack= Pokemon_setAtaqueCargado(pPokemon, auxAtaqueCargado);
	int valorA= Pokemon_setValorAtaque(pPokemon, auxValorAtaque);
	int esVarioColor= Pokemon_setEsVarioColor(pPokemon, auxEsVarioColor);


	if(pPokemon != NULL)
	{
		//printf("id %d, name %d, type %d, tam %d, attack %d, valor At %d, esVarioC %d \n", id, name, type, tamanio, atack, valorA, esVarioColor);
		if(id==0&& name==0&& type==0&& tamanio==0 && atack==0 && valorA==0 && esVarioColor==0)
		{

			retorno=0;
		}else{
			printf("Error al asignar los datos \n");
		}
	}
	return retorno;
}


void Pokemon_delete(ePokemon *this) {
	if (this != NULL) {
		free(this);
		this = NULL;
	}
}

int Pokemon_setId(ePokemon *this, int* id) {
	int retorno = -1;

	if (this != NULL && id >= 0) {
		this->numero = *id;
		retorno = 0;
	}
	return retorno;
}

int Pokemon_setNombre(ePokemon *this, char *nombre) {
	int retorno = -1;

	if (this != NULL && nombre != NULL) {
		if (strlen(nombre) < 128 && strlen(nombre) > 2) {

			strcpy(this->nombre, nombre);
			retorno = 0;
		}
	}
	return retorno;
}

int Pokemon_setTamanio(ePokemon *this, char *tamanio) {
	int retorno = -1;
	if (this != NULL) {
		if (this != NULL && tamanio != NULL) {
			if (strlen(tamanio) < 4 && strlen(tamanio) > 0) {
				strcpy(this->tamanio, tamanio);
				retorno = 0;
			}
		}
	}
	return retorno;
}


int Pokemon_setTipo(ePokemon *this, char *tipo) {
	int retorno = -1;

	if (this != NULL && tipo != NULL) {
		if (strlen(tipo) < 128 && strlen(tipo) > 1) {
			strcpy(this->tipo, tipo);

			retorno = 0;
		}
	}

	return retorno;
}



int Pokemon_setAtaqueCargado(ePokemon *this, char *ataqueCargado) {
	int retorno = -1;

	if (this != NULL && ataqueCargado != NULL) {
		if (strlen(ataqueCargado) < 128 && strlen(ataqueCargado) > 3) {
			strcpy(this->ataqueCargado, ataqueCargado);

			retorno = 0;
		}
	}

	return retorno;
}

int Pokemon_setValorAtaque(ePokemon *this, int valorAtaque) {
	int retorno = -1;

	if (this != NULL && valorAtaque >= 0) {
		this->valorAtaque = valorAtaque;
		retorno = 0;
	}
	return retorno;
}


int Pokemon_setEsVarioColor(ePokemon *this, int trueFalse) {
	int retorno = -1;

	if (this != NULL && (trueFalse == 0 || trueFalse ==1)) {
		this->esVarioColor = trueFalse;
		retorno = 0;
	}
	return retorno;
}

//Getters

int Pokemon_getId(ePokemon *this, int *id) {
	int retorno = -1;

	if (this != NULL && id != NULL) {

		*id = this->numero;

		retorno = 0;
	}
	return retorno;
}

int Pokemon_getNombre(ePokemon *this, char *nombre) {
	int retorno = -1;

	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);

		retorno = 0;
	}
	return retorno;
}

int Pokemon_getValorAtaque(ePokemon *this, int* valorAtaque) {
	int retorno = -1;
	if (this != NULL && valorAtaque != NULL) {
		*valorAtaque = this->valorAtaque;
		retorno = 0;
	}
	return retorno;
}

int Pokemon_getTipo(ePokemon* this, char* tipo)
{
	int retorno=-1;
	 if(this!=NULL && tipo!=NULL)
	    {
	        strcpy(tipo, this->tipo);

	        retorno=0;
	    }
	return retorno;
}

int Pokemon_getTamanio(ePokemon* this, char* tamanio)
{
	int retorno=-1;
	 if(this!=NULL && tamanio!=NULL)
	    {
	        strcpy(tamanio, this->tamanio);

	        retorno=0;
	    }
	return retorno;
}

int Pokemon_getAtaqueCargado(ePokemon* this, char* ataqueCargado)
{
	int retorno=-1;
	 if(this!=NULL && ataqueCargado!=NULL)
	    {
	        strcpy(ataqueCargado, this->ataqueCargado);

	        retorno=0;
	    }
	return retorno;
}

int Pokemon_getEsVarioColor(ePokemon *this, int *trueFalse) {
	int retorno = -1;

	if (this != NULL && trueFalse != NULL) {
		*trueFalse = this->esVarioColor;
		retorno = 0;
	}
	return retorno;
}

int Pokemon_getDescripcionVarioColor(int trueFalse , char* descripcionVariocolor)
{
	int retorno=-1;

		if(descripcionVariocolor!=NULL)
		{
			if(trueFalse>-1 || trueFalse<2){

			switch(trueFalse){
			case 0:
				strcpy(descripcionVariocolor, "No");
				break;
			case 1:
				strcpy(descripcionVariocolor, "Si");
				break;
			}
			retorno=0;
			}
		}

		return retorno;
}

void Pokemon_MostrarUnPokemon(ePokemon* pokemon) {
	int id;
	char nombre[128];
	char tipo[128];
	char auxTamanio[4];
	char auxAtaqueCargado[128];
	char descripcionVarioColor[128];
	int valorAtaque;
	int trueFalse;

	int num=Pokemon_getId(pokemon, &id);
	int name=Pokemon_getNombre(pokemon, nombre);
	int type=Pokemon_getTipo(pokemon, tipo);
	int tamanio= Pokemon_getTamanio(pokemon, auxTamanio);
	int valorAtack= Pokemon_getValorAtaque(pokemon, &valorAtaque);
	int ataqueCargado= Pokemon_getAtaqueCargado(pokemon, auxAtaqueCargado);
	int esVarioC= Pokemon_getEsVarioColor(pokemon, &trueFalse);

	int descVarioC= Pokemon_getDescripcionVarioColor(trueFalse, descripcionVarioColor);


	if (num==0 && name==0&& type==0 && valorAtack==0 && tamanio==0 && ataqueCargado==0 && esVarioC==0 && descVarioC==0) {
		printf( "| %-4d |  %-12s|  %-12s| %-6s | %-12s | %-4d | %-6s |\n",
				id, nombre, tipo, auxTamanio, auxAtaqueCargado, valorAtaque, descripcionVarioColor);
	} else {

		printf("Error al obontener los datos del Pokemon a mostrar \n");

	}

}

int obtenerId(char* path, int* id)
{
	int retorno=-1;
	FILE* pFile;

	if(path!=NULL && id!=NULL)
	{
		pFile=fopen(path,"r");
		fscanf(pFile,"%d",id);
		retorno=1;
	}
	fclose(pFile);
	return retorno;
}


int buscar_PokemonPorId(LinkedList *pArrayListPokemon, int *id) {
	int retorno = -1;
	int i;
	int tamList;
	 ePokemon *auxPokemon;

	if (pArrayListPokemon != NULL && id != NULL) {
		tamList = ll_len(pArrayListPokemon);

		for (i = 0; i <= tamList; i++) {
			auxPokemon = (ePokemon*) ll_get(pArrayListPokemon, i);

			if (auxPokemon != NULL) {
				if (*id == auxPokemon->numero) {

					retorno = i;
					break;
				}
			}
		}
	}

	return retorno;
}


int Movies_CompararId(void* passenger1, void* passenger2)
{
	int resultado = 0;
	ePokemon* passenger = NULL;
	ePokemon* passengerDos = NULL;
	int id1;
	int id2;

	if(passenger1!=NULL && passenger2!=NULL)
	{
		passenger = (ePokemon*) passenger1;
		passengerDos = (ePokemon*) passenger2;

		if((!Pokemon_getId(passenger, &id1)) && (!Pokemon_getId(passengerDos, &id2)))
		{
			//0 -> si son iguales
			//1 -> mayor
			//-1 -> menor
			if(id1 > id2)
			{
				resultado = 1;
			}
			else
			{
				if(id1 < id2)
				{
					resultado = -1;
				}
			}
		}
	}

	return resultado;
}

int Movies_CompararGenero_Rating(void *pelicula1, void *pelicula2) {

	int resultado;
	ePokemon *pelicula = NULL;
	ePokemon *peliculaDos = NULL;

	char nombre1[128];
	char nombre2[128];
	float rating1;
	float rating2;

//	Se deberá mostrar por pantalla un listado de las películas ordenadas por
//	género y dentro de las del mismo género que aparezcan ordenadas por rating descendente.
	pelicula = (ePokemon*) pelicula1;
	peliculaDos = (ePokemon*) pelicula2;

	if (pelicula1 != NULL && pelicula2 != NULL) {
		//Pokemon_getValorAtaque(pelicula, &rating1);
		//Pokemon_getValorAtaque(peliculaDos, &rating2);
		Pokemon_getTipo(pelicula, nombre1);
		Pokemon_getTipo(peliculaDos, nombre2);

		if(strcmp(nombre1, nombre2)<0)
		        {
			resultado=1;
		        }
		        else if(strcmp(nombre1, nombre2)>0)
		        {
		        	resultado=-1;
		        }
		        else
		        {
		            if(strcmp(nombre1, nombre2)==0)
		            {
		                if(rating1 > rating2)
		                {
		                	resultado = 1;
		                }
		                else if(rating1 < rating2)
		                {
		                	resultado = -1;
		                }
		            }
		        }

}
	return resultado;
}


void* incrementarValorAtaque(void *t1) {
	ePokemon *auxPokemon = NULL;
	int min = 1;
	int max = 10;
	int rating;

	if (t1 != NULL) {
		auxPokemon = (ePokemon*) t1;
		if (auxPokemon != NULL) {
			rating = (int) (rand() % (max - min + 1)) + min;
			//Pokemon_setTamanio(auxPokemon, rating);

		}
	}

	return auxPokemon;
}

void* asignarGenero(void *t1) {
	ePokemon *auxMovies = NULL;
	int min = 1;
	int max = 4;
	int genero;
	char auxGenero[128];

	if (t1 != NULL) {
		auxMovies = (ePokemon*) t1;
		if (auxMovies != NULL) {
			genero = (rand() % (max - min + 1)) + min;
			//Movies_getdescripcionGenero(genero, auxGenero);
			Pokemon_setTipo(auxMovies, auxGenero);

		}
	}

	return auxMovies;
}

int filtrarFire(void* a)
{
	int retorno=0;
	ePokemon* pPokemon;

	if(a!=NULL){
		pPokemon=(ePokemon*) a;

			if(strcmp(pPokemon->tipo,"Fire")==0){
				retorno=1;

		}
	}
	return retorno;
}

int filtrarAguaVarioColor(void *a) {
	int retorno = 0;
	ePokemon *pMovies;

	if (a != NULL) {
		pMovies = (ePokemon*) a;
		if(!strcmp(pMovies->tipo,"Water") && pMovies->esVarioColor)
		{
			retorno=1;
		}
	}
	return retorno;
}


int filtrarComedia(void *a) {
	int retorno = 0;
	ePokemon *pMovies;

	if (a != NULL) {
		pMovies = (ePokemon*) a;


	}
	return retorno;
}


int filtrarAccion(void *a) {
	int retorno = 0;
	ePokemon *pMovies;

	if (a != NULL) {
		pMovies = (ePokemon*) a;

	}
	return retorno;
}


