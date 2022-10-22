/*
 * Servicio.c
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


		/** \ Hardcodeo de estructura Servicio.
		* 	\ Servicio* recibe un puntero a estructura Author.
		* 	\ parame n: recibe entero.
		* 	\ parametro d y m: recibe punteros a char.
		*/

		void set_servicios(struct Servicio* servicios, int n, char* m,float a) {

			servicios-> idServicio = n;
			strcpy(servicios -> descripcion, m);
			servicios -> precio = a;

				  return;

				}

		/** \ Inicialización de estructura Servicio.
		 * 	\ Servicio* recibe un puntero a estructura.
		 */

		void initialize_servicios(struct Servicio* servicios){

			set_servicios(servicios,    1 , "Bateria",2250);
			set_servicios(servicios +1, 2 , "Display",10300);
			set_servicios(servicios +2 ,3 , "Teclado",4400);
			set_servicios(servicios +3 ,4 , "Fuente", 5600);


		}
