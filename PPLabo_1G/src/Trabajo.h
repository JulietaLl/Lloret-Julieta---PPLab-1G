/*
 * Trabajo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Llorj
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_


	struct Fecha
			{
				int dia;
				int mes;
				int anio;
			};

   struct Trabajo
			{
				int id;
				int idNotebook;
				int idServicio;
				struct Fecha fechas;


			};














#endif /* TRABAJO_H_ */
