/*
 * Validaciones.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Llorj
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int utn_getNumero(int* pResultado, char* mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char * mensajeError, int reintentos);
int esDescripcion(char* cadena, int longitud);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo,int reintentos);
int esFlotante(char* cadena);

#endif /* VALIDACIONES_H_ */
