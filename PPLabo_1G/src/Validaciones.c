/*
 * Validaciones.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Llorj
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"


 static int getDescripcion(char* pResultado, int longitud);
 static int getString(char* cadena, int longitud);
 static int getFloat(float* pResultado);



 	 	 /** \ brief verifica que lo ingresado sea un numero
		  * 	\ param *pResultado recibe un puntero
		  * 	\ parame char mensaje: se le pide al usuario que ingrese un numero.
		  * 	\ parame char mensaje error: avisa que lo ingresado no es valido.
		  * 	\ int minimo : Numero minimo que se requiere.
		  * 	\ int maximo: Numero máximo que se pide.
		  * 	\ int reintentos: Cantidad de reintentos que tiene el usuario.
		  */


		 int utn_getNumero(int* pResultado, char* mensaje, char *mensajeError, int minimo, int maximo, int reintentos){

		 	int retorno = -1;
		 	int bufferInt;
		 	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
		 	{
		 		retorno = -2;

		 		do
		 		{
		 		printf("%s", mensaje);
		 		fflush(stdin);
		 		scanf("%d",&bufferInt);
		 		if(bufferInt >= minimo && bufferInt <=maximo)
		 		{
		 			retorno = 0;
		 			*pResultado = bufferInt;
		 			break;
		 		}

		 		reintentos--;
		 		}while(reintentos >= 0);
		 	}
		 	return retorno;
		 }


		  /**
		    * Brief: Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
		    * Paramentro: pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
		    * parametro longitud: Es la longitud del array resultado
		    * parametro mensaje: Es el mensaje de error a ser mostrado
		    * parametro reintentos: Cantidad de reintentos
		    * return retorna 0 si se obtuvo y -1 si no
		    */
		   int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char * mensajeError, int reintentos)
		   {
		 	  char bufferString [4096];
		 	  int retorno = -1;
		 	  while(reintentos >= 0)
		 	  {
		 		  reintentos--;
		 		  printf("%s",mensaje);
		 		  if(getDescripcion(bufferString, sizeof(bufferString)) == 0 && strnlen (bufferString, sizeof (bufferString)) < longitud)
		 		  {
		 			  strncpy(pResultado, bufferString, longitud);
		 			  retorno = 0;
		 			  break;

		 		  }
		 		  printf("%s", mensajeError);
		 	  }
		 	  return retorno;
		   }

		   /**
		    * Brief:Verifica si la cadena ingresada es un nombre valido
		    * Parametro candena :Cadena de caracteres a ser analizada
		    * Return retorna 1(verdadero) si la cadena es valida y 0(falso) si no lo es
		    */

		   int esDescripcion(char* cadena, int longitud)
		  {
		 	 int i=0;
		 	 int retorno = -1;

		 	 if(cadena != NULL && longitud > 0)
		 	 {
		 		 for(i=0 ; cadena [i] != '\0' && i < longitud; i++)
		 		 {
		 			 if((cadena[i] < 'A' || cadena [i] > 'Z') && (cadena [i] < 'a' || cadena[i] > 'z'))
		 			 {
		 				 retorno = 0;
		 				 break;
		 			 }
		 		 }
		 	 }
		 	 return retorno;
		  }

		  /**
		   * Brief Obtiene un string valido como descripcion
		   * paramentro pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
		   * return Retorna 0(Exito) si se obtiene
		   * y -1 si no.
		   */

		   static int getDescripcion(char* pResultado, int longitud)
		  {
		 	 int retorno = -1;
		 	 char buffer [4096];

		 	 if(pResultado != NULL)
		 	 {
		 		 if( getString(buffer,sizeof(buffer)) == 0 &&
		 			 esDescripcion(buffer,sizeof(buffer)) &&
		 			 strnlen(buffer,sizeof (buffer)) < longitud)
		 		 {
		 			 strncpy(pResultado, buffer, longitud);
		 			 retorno = 0;
		 		 }


		 	 }
		 	 return retorno;
		  }


		   /**
		     	 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un maximo de 'longitud - 1' caracteres.
		     	 * \param cadena char* Puntero al espacio de memoria donde se copiara la cadena obtenida
		     	 * \param longitud int Define el tamaÃ±o de cadena
		     	 * \return int Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
		     	 */

		   static int getString(char* cadena, int longitud)
		    	{
		    		int retorno=-1;
		    		char bufferString[4096];

		    		if(cadena != NULL && longitud > 0)
		    		{
		    			fflush(stdin);
		    			if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		    			{
		    				if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
		    				{
		    					bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
		    				}
		    				if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
		    				{
		    					strncpy(cadena,bufferString,longitud);
		    					retorno=0;
		    				}
		    			}
		    		}
		    		return retorno;
		    	}
		   /**
		    * Brief: Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado.
		    * Parametro pResultado: Puntero al espacio de memoria donde se dejará el resultado de la función.
		    * Parametro mensaje: Es el mensaje a ser mostrado.
		    * Parametro mensajeError: Es el mensaje de error a ser mostrado.
		    * Parametro minimo: Es el numero minimo a ser aceptado.
		    * Parametro máximo: Es el numero máximo a ser aceptado.
		    * Return: Retorna 0 si se obtuvo el numero flotante y -1 si no.
		    */



		   int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo,int reintentos)
		   {

		   	int retorno = -1;
		   	float bufferFloat;

		   	while(reintentos >= 0)
		   	{
		   		reintentos--;
		   		printf("%s", mensaje);

		   		if(getFloat(&bufferFloat) == 0)
		   		{
		   			if(bufferFloat >= minimo && bufferFloat <= maximo)
		   			{
		   				*pResultado = bufferFloat;
		   				retorno = 0;
		   				break;
		   			}
		   		}
		   		printf("%s", mensajeError);
		   	}
		   	return retorno;
		   }

		   int myGets (char* cadena, int longitud)
		       {

		    	   int retorno = -1;
		    	   char bufferString[4096];

		    	   if(cadena != NULL && longitud > 0)
		    	   {
		    		   fflush(stdin);
		    		   if(fgets(bufferString,sizeof (bufferString), stdin) != NULL)
		    		{
		    			   if(bufferString[strnlen(bufferString, sizeof (bufferString))-1] == '\n')
		    			{
		    				bufferString[strnlen(bufferString, sizeof(bufferString)) -1] = '\0';

		    			}
		    			   if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
		    			{
		    				strncpy(cadena,bufferString,longitud);
		    				retorno = 0;
		    			}



		    		}

		    	}
		    	return retorno;

		       }



		   /**
		      * Brief: Verifica si la cadena ingresada es flotante.
		      * Parametro cadena: Cadena de caracteres a ser analizada
		      * Return: Retorna 1 (verdadero) si la cadena es float y 0 (falso) si no lo es.
		      */

		        int esFlotante(char* cadena)
		      {
		     	 int retorno = 1;
		     	 int i = 0;
		     	 int contadorPuntos = 0;

		     	 if (cadena != NULL && strlen(cadena) > 0)
		     	 {
		     		 for( i= 0 ; cadena [i] != '\0' ; i++)
		     		 {
		     			 if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
		     	         {
		     		        continue;
		     	         }

		     	           if(cadena [i] > '9' || cadena [i] < '0')
		     		       {
		     			   if (cadena [i] == '.' && contadorPuntos == 0)
		     			   {
		     				 contadorPuntos++;
		     			   }
		     			   else
		     			   {
		     				 retorno = 0;
		     				 break;
		     			   }
		     		    }
		     	      }

		          }

		     	 return retorno;
		      }

		   /**
		    * Brief: Verifica si la cadena ingresada es flotante.
		    * Parametro pResultado: Puntero al espacio de memoria donde se dejará el resultado de la funcion.
		    * Return: Retorna 0 [EXITO] si se obtiene un numero flotante y -1 [ERROR] si no.
		    */



		   static int getFloat(float* pResultado)
		   {
		   	 int retorno = 1;
		   	 char buffer [64];

		   	 if (pResultado != NULL)
		   	 {
		   		if(myGets(buffer, sizeof(buffer)) == 0 && esFlotante(buffer))
		   		 {
		   			*pResultado = atof (buffer);
		   			 retorno = 0;

		   		 }
		   	 }

		   	 return retorno;
		    }

