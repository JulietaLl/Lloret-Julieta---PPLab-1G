/*
 ============================================================================
 Name        : PPLabo_1G.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Notebook.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "Validaciones.h"


int main(void) {

    setbuf(stdout,NULL);

    struct Marca marcas [15];
    struct Notebook notebooks [15];
    struct Tipo tipos [15];
    struct Servicio servicios [15];

    initialize_notebook(notebooks);
    initialize_marca(marcas);
	initialize_tipos(tipos);
	initialize_servicios(servicios);

	int contadorNotebooks = 0;

	int opcion;

    do{


    			if(utn_getNumero(&opcion,"\n Elige la opción deseada: \n 1)Alta Notebook\n\n "
    																						" 2)Modificar Notebook\n\n "
    																						" 3)Baja Notebook\n\n"
    																						" 4)Listar Notebooks\n\n "
    																						" 5)Listar Marcas \n\n"
    																						" 6)Listat tipos \n\n"
    																						" 7)Listar servicios   \n\n ",  "Ingrese una opcion correcta",1,6,3) == 0){

    			switch(opcion){




    				case 1:

    						new_notebook(notebooks,marcas,tipos,&contadorNotebooks);
    						printf("\n¡La notebook fue ingresada correctamente!\n\n");


    					break;

    				case 2:
    						print_notebooks(notebooks,&contadorNotebooks);
    						update_notebook(notebooks,&contadorNotebooks,tipos);
    					break;

    				case 3: logic_down(notebooks,&contadorNotebooks);

    					break;


    				case 4: print_notebooks(notebooks,&contadorNotebooks);
    					break;

    				case 5:	print_marcas(marcas);

    					break;
    				case 6:	print_tipo(tipos);
    			    	break;

    				default:
    					break;



    			}

    		            }



            }while(opcion != 6);









    	}

















