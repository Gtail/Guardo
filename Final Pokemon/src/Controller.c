#include <stdio.h>
#include <stdlib.h>
#include "arrayPokemon.h"
#include "LinkedList.h"
#include "parser.h"



/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int Franzoso_controller_loadFromText(char* path , LinkedList* pArrayListMovies)
{
	FILE* pFile;
	int retorno;
	pFile=fopen(path,"r");

	if(pFile!=NULL && pArrayListMovies!=NULL){

		if(parser_PassengerFromText(pFile, pArrayListMovies)!=-1){

			retorno=0;
		}else{
			retorno=-1;
		}

	}
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int Franzoso_controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	FILE* pFile;
	pFile=fopen(path,"rb");


	if( pArrayListPassenger!=NULL && path!=NULL)
	{

		if(pFile!= NULL)
		{

			if(parser_PassengerFromBinary(pFile, pArrayListPassenger)==0){
			retorno=0;
			}
		}
	fclose(pFile);
	}
    return retorno;
}


/** \brief Listar Peliculas
 * \param
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int Franzoso_controller_ListPokemones(LinkedList *pArrayListPokemones) {
	int retorno = -1;
	int tamList;
	int i;
	ePokemon *auxPokemon;
	if (pArrayListPokemones != NULL) {
		tamList = ll_len(pArrayListPokemones);
		for (i = 0; i < tamList; i++) {
			auxPokemon = (ePokemon*) ll_get(pArrayListPokemones, i);
			Pokemon_MostrarUnPokemon(auxPokemon);
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int Franzoso_controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
		int criterio=0;
		int opcion;
		char confirmar[4];
		strcpy(confirmar,"no");
		LinkedList* copia;
		if(pArrayListPassenger!=NULL)
		{
			copia = ll_clone(pArrayListPassenger);

			if(copia!=NULL)
			{
				do
				{
					opcion = Movies_MenuOrden();
					if(opcion!=2 && opcion!=3)
					{
						criterio = Movies_MenuCriterio();
					}
					switch(opcion)
					{
						case 1:
							if(!ll_sort(copia,Movies_CompararGenero_Rating,criterio))
							{
								if(criterio)
								{
									puts("Se ha ordenado la lista de forma descendente \n");
								}
								else
								{
									puts("Se ha ordenado la lista por de forma ascendente \n");

								}
							}else{
								printf("Error orden \n");
							}
							break;
						case 2:
							//controller_ListMovies(copia);
							break;
						case 3:
							getStringSoloLetras("Esta seguro de Salir? si/no \n", "Error. ingrese solo letras \n", confirmar, 4, 2);
							strlwr(confirmar);
							ll_deleteLinkedList(copia);
							break;
						}
				}while(stricmp(confirmar,"si"));
			}
		}

	    return retorno;
	}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int Franzoso_controller_saveAsText(char* path , LinkedList* pArrayListPokemones)
{
	int retorno;
	int i;
	int tamList;
	int auxId;
	char auxNombre[128];
	char auxTipo[128];
	char auxTamanio[4];
	char auxAtaqueCargado[128];
	int valorAtaque;
	int esVarioColor;

	ePokemon *auxPokemon=NULL;
	FILE *pFile;

	if (path != NULL && pArrayListPokemones != NULL) {
		pFile = fopen(path, "w");
		if (pFile != NULL) {
			tamList = ll_len(pArrayListPokemones);
			fprintf(pFile, "numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVarioColor \n");
			for (i = 0; i < tamList; i++) {
				auxPokemon = (ePokemon*) ll_get(pArrayListPokemones, i);
				if(auxPokemon!=NULL){
				Pokemon_getId(auxPokemon, &auxId);
				Pokemon_getNombre(auxPokemon, auxNombre);
				Pokemon_getTipo(auxPokemon, auxTipo);
				Pokemon_getTamanio(auxPokemon, auxTamanio);
				Pokemon_getAtaqueCargado(auxPokemon, auxAtaqueCargado);
				Pokemon_getValorAtaque(auxPokemon, &valorAtaque);
				Pokemon_getEsVarioColor(auxPokemon, &esVarioColor);


				fprintf(pFile,"%d,%s,%s,%s,%s,%d,%d\n", auxId, auxNombre, auxTipo, auxTamanio, auxAtaqueCargado, valorAtaque, esVarioColor);

				retorno = 1;
				}

			}
		}

	}
	fclose(pFile);
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    int retorno=-1;
	int i;
	int tamList;
	ePokemon* auxPassenger;
	FILE* pFile;
	pFile=fopen(path,"wb");

	if(path!=NULL && pArrayListPassenger!=NULL){
	tamList=ll_len(pArrayListPassenger);
		for(i=0;i<tamList;i++){
			auxPassenger=(ePokemon*)ll_get(pArrayListPassenger, i);
			fwrite(auxPassenger,sizeof(ePokemon),1,pFile);
			retorno=1;
		}
	}
	fclose(pFile);
    return retorno;
}

int controller_SetRating(LinkedList* pArrayMovies) {
	int retorno = -1;

	if ( pArrayMovies != NULL) {
		ll_map(pArrayMovies, ValorAtaque);
		//controller_ListMovies(pArrayMovies);
		retorno=0;
	}
	return retorno;
}



int controller_SetGenero(LinkedList* pArrayMovies) {
	int retorno = -1;

	if ( pArrayMovies != NULL) {
		ll_map(pArrayMovies, asignarGenero);
		//controller_ListMovies(pArrayMovies);
		retorno=0;
	}
	return retorno;
}


int controller_filterComedia(LinkedList* pArrayMovies)
{
	int retorno=-1;

	LinkedList* listaComedia=NULL;


	if(pArrayMovies!=NULL){
			listaComedia=ll_filter(pArrayMovies, filtrarComedia);
			if(listaComedia!=NULL){
				//controller_ListMovies(listaComedia);
				//controller_saveAsText("peliculasComedia.csv", listaComedia);
				retorno=0;
			}else{
				printf("No se logro filtrar \n");
			}
		}


	return retorno;
}

int controller_filterAccion(LinkedList* pArrayMovies)
{
	int retorno=-1;

	LinkedList* listaAccion=NULL;


	if(pArrayMovies!=NULL){
			listaAccion=ll_filter(pArrayMovies, filtrarAccion);
			if(listaAccion!=NULL){
				//controller_ListMovies(listaAccion);
				//controller_saveAsText("peliculasAccion.csv", listaAccion);
				retorno=0;
			}else{
				printf("No se logro filtrar \n");
			}
		}


	return retorno;
}

int Franzoso_controller_filterAguaVarioColor(LinkedList* pArrayListPokemones)
{
	int retorno=-1;

	LinkedList* listaAguaVarioColor=NULL;


	if(pArrayListPokemones!=NULL){
		listaAguaVarioColor=ll_filter(pArrayListPokemones, filtrarAguaVarioColor);
			if(listaAguaVarioColor!=NULL){
				Franzoso_controller_ListPokemones(listaAguaVarioColor);
				//controller_saveAsText("peliculasTerror.csv", listaTerror);
				retorno=0;
			}else{
				printf("No se logro filtrar \n");
			}
		}


	return retorno;
}

int Franzoso_controller_filterFire(LinkedList* pArrayListPokemones)
{
	int retorno=-1;

	LinkedList* listaFire=NULL;


				puts("pase el null\n");
	if(pArrayListPokemones!=NULL){
		listaFire=ll_filter(pArrayListPokemones, filtrarFire);
			if(listaFire!=NULL){
				Franzoso_controller_ListPokemones(listaFire);
				//controller_saveAsText("peliculasDrama.csv", listaDrama);
				retorno=0;
			}else{
				printf("No se logro filtrar \n");
			}
		}


	return retorno;
}

int controller_countDrama(LinkedList* pArrayMovies){
	int retorno=-1;
	int cantidad;
	if(pArrayMovies!=NULL){
		//cantidad=ll_count(pArrayMovies, filtrarDrama);
		if(cantidad>0){
			printf("La cantidad de Peliculas de Drama es %d \n", cantidad);
			retorno=0;
		}else{
			puts("No hay peliculas de Drama \n");
		}
	}
	return retorno;
}


int Franzoso_controller_removePokemon(LinkedList *pArrayListPokemones) {
	int retorno = -1;
	int id;
	int index;
	ePokemon *auxPokemon = NULL;
	int tamList;
	char respuesta[4];
	if (pArrayListPokemones != NULL) {

		tamList = ll_len(pArrayListPokemones);
		Franzoso_controller_ListPokemones(pArrayListPokemones);
		id = getValidInt("Ingrese el ID de Pokemon a eliminar\n",
						 "ERROR. Intente Nuevamente\n", 0, tamList);
		index = buscar_PokemonPorId(pArrayListPokemones, &id);
		if (index != -1) {
			auxPokemon = (ePokemon*) ll_get(pArrayListPokemones, index);
			printf("%d index \n", index);
			Pokemon_MostrarUnPokemon(auxPokemon);
			getStringSoloLetras("Esta seguro de eliminar este Pokemon? \n",
								"Respuesta invalida \n", respuesta, 4, 2);

			if (!(stricmp(respuesta, "si"))) {
				if (ll_remove(pArrayListPokemones, index) == 0) {
					printf("Pokemon Eliminado con exito \n");
				}else{
					printf("Baja cancelada \n");
				}
			}

			retorno = 1;
		}else{
			printf("No se encontro el numero de Pokemon\n");
		}

	}
	return retorno;
}

