/*
 * entidades.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Llorj
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Notebook.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "Validaciones.h"



	//Recorre un Array en busca de lugar libre
	//Si encuentra lugar, retorna el indice de la posición libre.
	//Si no encuentra, devuelve -1.

	int new_indexAvalible(struct Notebook* books){

		for(int i = 0; i < 25 ; i++){
			if((books + i) -> active == 0){
				return i;

			}
		}

		return -1;

	}


	/** \ Hardcodeo de estructura Marca.
	* 	\ param Marca* recibe un puntero a estructura Marca.
	* 	\ parame n: recibe entero.
	* 	\ parametro m: recibe punteros a char.
	*/

	void set_marca(struct Marca* marcas, int n, char* m) {

		marcas-> idMarca = n;
		strcpy(marcas-> descripcion, m);


			  return;

			}

	/** \ Inicialización de estructura Marca.
	 * 	\ paramAuthor* recibe un puntero a estructura.
	 */

	void initialize_marca(struct Marca* marcas){

		set_marca(marcas,    1 , "COMPAQ");
		set_marca(marcas +1, 2 , "ASUS");
		set_marca(marcas +2 ,3 , "ACER");
		set_marca(marcas +3 ,4 , "HP");


	}

	 /** \ Hardcodeo de estructura Tipo.
		* 	\ Tipo* recibe un puntero a estructura Author.
		* 	\ parame n: recibe entero.
		* 	\ parametro d y m: recibe punteros a char.
		*/

		void set_tipos(struct Tipo* tipos, int n, char* m) {

			tipos-> idTipo = n;
			strcpy(tipos-> descripcion, m);


				  return;

				}

		/** \ Inicialización de estructura Tipos.
		 * 	\ paramAuthor* recibe un puntero a estructura.
		 */

		void initialize_tipos(struct Tipo* marcas){

			set_tipos(marcas,    1 , "GAMER");
			set_tipos(marcas +1, 2 , "DISENIO");
			set_tipos(marcas +2 ,3 , "ULTRABOOK");
			set_tipos(marcas +3 ,4 , "NORMALITA");


		}


		/** \ Hardcodeo de estructura Notebook, le da el valor 0 a el campo Active.
		* 	\ Tipo* recibe un puntero a estructura Notebook.
		* 	\ parame n: recibe entero.
		*/
		void set_notebook(struct Notebook* notebooks, int n) {

			for(int i = 0; i > 50 ; i++){
			(notebooks + i) -> active = n;

			 }

		}

			/** \ Inicialización de estructura Notebook.
		 	 * 	\ paramAuthor* recibe un puntero a estructura.
		 	 */

		void initialize_notebook(struct Notebook* notebooks){

			set_notebook(notebooks,0);

		}


	/** \ Imprime la estructura Marcas.
	 * 	\ param  Album recibe array de estructura Marcas.
	 */

		void print_marcas(struct Marca marcas[]){

				int i;
				int tam = 4;


				printf("Lista de Marcas ingresadas : \n\n");

				for( i = 0; i < tam ; i++)
				{
					{
						printf(" \n %d,%s\n\n ",

							marcas[i].idMarca,
							marcas[i].descripcion);
					}


				}


			}


		/** \ Imprime la estructura Tipo
		 * 	\ param  Album recibe array de estructura tipos.
		 */

			void print_tipo(struct Tipo tipos[]){

					int i;
					int tam = 4;


					printf("Lista de tipos : \n\n");

					for( i = 0; i < tam ; i++)
					{
						{
							printf(" \n %d ,  %s  \n\n ",

									tipos[i].idTipo,
									tipos[i].descripcion);
						}


					}


				}

			/** \ Imprime la estructura notebook
			 * 	\ param  notebooks recibe array de estructura notebooks.
			 * 	\ param contadorNotebooks recibe puntero a entero.
			 */

				void print_notebooks(struct Notebook notebooks[], int *contadorNotebooks){

						int i;


						printf("Lista de las notebooks ingresadas : \n\n");

						for( i = 0; i < *contadorNotebooks ; i++)
						{
							if(notebooks[i].active == 1)
							{
								printf(" \n %d,%s,%f \n\n ",

										notebooks[i].idNotebook,
										notebooks[i].modelo,
										notebooks[i].precio);
						}


						}


					}


			/** \ Valida si es correcto el codigo Marca ingresado por el usuario
			 * 	\ param  authors recibe array de estructura Marca.
			 * 	\ param codeIngresado recibe entero.
			 */

		int	validate_marcaCode(struct Marca* marcas, int codeIngresado){

					int tam = 3;
					int i = 0;
					int retorno = 1;


					for( i = 0; i < tam ; i++){
						if((marcas + i) -> idMarca == codeIngresado)
						printf("\n-%s-\n", (marcas + i ) -> descripcion);
						return retorno;

					}

					return -1;

			}

		/** \ Valida si es correcto el codigo Tipo ingresado por el usuario
		 * 	\ param  editorials recibe array de estructura Tipos.
		 * 	\ param codeIngresado recibe entero.
		 */

		int	validate_tipoCode(struct Tipo* tipos, int codeIngresado){

				int tam = 3;
				int i = 0;
				int retorno = 1;


				for( i = 0; i < tam ; i++){
					if((tipos + i) -> idTipo == codeIngresado)
					printf("\n-%s-\n", (tipos + i ) -> descripcion);
					return retorno;

				}

				return -1;

						}




		void new_notebook(struct Notebook *notebooks,struct Marca *marcas,struct Tipo *tipos, int *contadorNotebooks){

			char modeloAux[20];
			float precio;
			int marcaCode;
			int tipoCode;


			int available_index = new_indexAvalible(notebooks);

			if(available_index != -1){

				if(utn_getDescripcion(modeloAux,20, "\n Ingrese el Modelo de la Notebook por favor \n ","\n Ingrese el Modelo nuevamente",3) == 0){

					strcpy((notebooks + (available_index)) -> modelo , modeloAux);
					printf("\n ¡El modelo de Notebook fue cargado exitosamente! \n");

				}else
					return;

				if(utn_getNumeroFlotante(&precio,"\n Ingrese el importe de la Notebook ", "\n Vuelva a intentarlo \n",0.01,999999999.00,3) == 0){

					(notebooks + (available_index)) -> precio = precio;

				}else return;

				print_marcas(marcas);
				if(utn_getNumero(&marcaCode,"\n Ingrese código correspondiente a la marca : \n", "\n Vuelva a intentarlo \n",1,9,3) == 0){
					if(validate_marcaCode(marcas,marcaCode) == 1)
									{
										(marcas +(available_index))-> idMarca = marcaCode;
									}
									else
									{
										printf("El código ingresado no es valido \n");
										return;
									}
					}

				print_tipo(tipos);
				if(utn_getNumero(&tipoCode,"\n Ingrese código correspondiente al tipo : \n", "\n Vuelva a intentarlo \n",1,9,3) == 0){

					if(validate_tipoCode(tipos,tipoCode) == 1)
					{
						(tipos +(available_index))-> idTipo = tipoCode;


					} else {

						printf("El código ingresado no es valido \n");
						return;

					     }

					    (notebooks+(available_index))-> active = 1;
						(notebooks+(available_index))-> idNotebook = *contadorNotebooks;
						*contadorNotebooks = *contadorNotebooks + 1;

				}



			}
			return;

		}



			/** \ Opcion del swich: Modifica el tipo.
			 * 	\ param struct Tipos* recibe un puntero a estructura
			 */


			void update_tipo(struct Tipo* tipos)
				{
					char auxNuevoTipo[20];

					printf("Ingrese el nuevo tipo: \n");
					scanf("%s",auxNuevoTipo);
					strcpy(tipos -> descripcion , auxNuevoTipo);


				}

			/** \ Opcion del swich: Modifica el importe de la estructura libro.
			 * 	\ param struct Album* recibe un puntero a estructura
			 */


				void update_amount(struct Notebook* notebooks)
					{
					float auxImporte;

					printf("Ingrese el nuevo importe: \n");
					scanf("%f",&auxImporte);
					notebooks-> precio = auxImporte;

					}



				/** \ Imprime Submenu del Case 2: Modificar
				 */
				void print_submenu()
				{
					printf("¿Que desea modificar? \n\n"
							"1. Tipo \n"
							"2. Precio.  \n");

				}





		/** \ Se realiza una baja lógica.
		 *  \ El usuario ingresa codigo de libro que deseea dar de baja.
		 * 	\ param struct Book* recibe un puntero a estructura
		 * 	\ bookCounter recibe un puntero a entero.
		 */


	void logic_down(struct Notebook* notebooks, int* contadorNotebooks)
	{
		int i;
		int auxIdNotebook;

		printf("\n Ingrese el Id de la notebook que desea dar de baja \n");
		scanf("%d",&auxIdNotebook);

		for( i = 0; i < *contadorNotebooks ; i++)
		{

			if((notebooks + i )-> idNotebook== auxIdNotebook)
			{
				(notebooks + i) -> active = 0;
			}

		}


	}

	/** \ Modifica la estructura Notebooks.
	 * 	\ Le pide al usuario que ingrese el codigo de la notebook.
	 * 	\ El usuario eligue una opcion para modificar (titulo, fecha o importe)
	 * 	\ y en un switch se resuelve cada caso.
	 * 	\ param  Notebook recibe array de estructura Books.
	 * 	\ param contadorNotebooks recibe puntero a entero.
	 */



	void update_notebook(struct Notebook notebooks [], int *contadorNotebooks,struct Tipo tipos[])
	{
		int auxIdNotebooks;
		int i;
		int opcion;

		printf("\nIngrese el código de la notebook que desea modificar : \n\n");
		scanf("%d", &auxIdNotebooks);

		for( i = 0; i < *contadorNotebooks ; i++)
		{
			if(auxIdNotebooks == notebooks[i].idNotebook && notebooks[i].active == 1)
			{
				print_submenu();
				utn_getNumero(&opcion,"\n\nIngrese la opcion, por favor \n", "Ingrese una opcion correcta",1,3,3);

				switch(opcion) {


				case 1: update_tipo(tipos + auxIdNotebooks);
					break;
				case 2: update_amount(notebooks + auxIdNotebooks);
					break;





				}
			}
		}





	}

