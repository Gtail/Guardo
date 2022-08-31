#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "arrayPokemon.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPokemon)
{
		int retorno=-1;
		int contPokemones=0;
		char buffer[6][128];

		ePokemon* auxPokemon;


		if (pFile != NULL && pArrayListPokemon != NULL)
		{

			   printf("\n\t>-Numero     Nombre         Tipo     Tamanio 	 Ataque Cargado		 Valor Ataque 	   	Vario Color-<\t\n");
				printf("-----------------------------------------------------------------------------------------------------------\n");
				while (!feof(pFile))
				{
						if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n" , buffer[0], buffer[1], buffer[2],buffer[3],buffer[4], buffer[5], buffer[6])==7)
						fscanf(pFile," ");
						{

							auxPokemon=Pokemon_newParametros(buffer[0], buffer[1], buffer[2],buffer[3],buffer[4], buffer[5], buffer[6]);

								if(auxPokemon != NULL)
								{
									ll_add(pArrayListPokemon, auxPokemon);
									Pokemon_MostrarUnPokemon(auxPokemon);

									contPokemones+=1;
									retorno=0;

								}
						}


				}

		}
		fclose(pFile);
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int retorno = -1;
		ePokemon *auxPasajero;

		if (pFile != NULL && pArrayListPassenger != NULL)
		{

			while (!feof(pFile)) {
				auxPasajero = Pokemon_new();

				if (auxPasajero != NULL) {
					if (fread(auxPasajero, sizeof(ePokemon), 1, pFile)==1) {
						ll_add(pArrayListPassenger, auxPasajero);
						//printf("ID %d", auxPasajero->id);
						retorno=0;
					}else{
						Pokemon_delete(auxPasajero);
					}
				}
			}
		}
		return retorno;

}
