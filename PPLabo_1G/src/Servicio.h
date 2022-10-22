/*
 * Servicio.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Llorj
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_


	 struct Servicio
			{
		 	 	int idServicio;
				char descripcion[25];
				float precio;

			};


	 void set_servicios(struct Servicio* servicios, int n, char* m,float a);
	 void initialize_servicios(struct Servicio* servicios);

#endif /* SERVICIO_H_ */
