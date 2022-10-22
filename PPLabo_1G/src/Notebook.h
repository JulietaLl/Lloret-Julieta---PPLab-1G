/*
 * Entidades.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Llorj
 */

#ifndef NOTEBOOK_H_
#define NOTEBOOK_H_




	 struct Marca
	 		{

	 			int idMarca;
	 			char descripcion[20];

	 		};


	 struct Tipo
			{

				int idTipo;
				char descripcion[20];

			};


	 struct Notebook
	 		{
		 	 	int active;
	 			int idNotebook;
	 			char modelo [20];
	 			struct Marca marcas;
	 			struct Tipo tipos;
	 			float precio;

	 		};


	 void new_notebook(struct Notebook *notebooks,struct Marca *marcas,struct Tipo *tipos, int *contadorNotebooks);

	 void set_tipos(struct Tipo* tipos, int n, char* m);
	 void set_marca(struct Marca* marcas, int n, char* m);
	 void set_notebook(struct Notebook* notebooks, int n);

	 void initialize_marca(struct Marca* marcas);
	 void initialize_tipos(struct Tipo* marcas);
	 void initialize_notebook(struct Notebook* notebooks);

	 void print_marcas(struct Marca marcas[]);
	 void print_tipo(struct Tipo tipos[]);

	 int validate_marcaCode(struct Marca* marcas, int codeIngresado);
	 int validate_tipoCode(struct Tipo* tipos, int codeIngresado);

	 void print_submenu();
	 void print_notebooks(struct Notebook notebooks[], int *contadorNotebooks);

	 void update_notebook(struct Notebook notebooks [], int *contadorNotebooks,struct Tipo tipos[]);
	 void update_modelo(struct Notebook* notebooks);
	 void update_marca(struct Marca* marcas);
	 void update_tipo(struct Tipo* tipos);
	 void update_amount(struct Notebook* notebooks);

	 void logic_down(struct Notebook* notebooks, int* contadorNotebooks);



#endif /* NOTEBOOK_H_ */
