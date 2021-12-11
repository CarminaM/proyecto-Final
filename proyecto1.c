//JUEGO REALIZADO EN LENGUAJE C

/*Descripcion: 
Este ejercicio funciona como un juego del ahorcado.El jugador 1 ingresa una palabra o
frase y una pista para que el jugador 2 intente adivinarla.
Cada jugada tiene su valor de puntos en caso de adivinar una letra.
AdemAs se le muestra al usuario el estado actual del juego */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCIONES

void categorias();

void ingresoCategoria (int op);

void empezarJuego (char palabras[][15], char nombre[]);


//FUNCION PRINCIPAL 



int main(){
	system("mode con cols=80 lines=25");
	categorias();

	system("pause");

	return 0;

}



//CATEGORIAS



void categorias(){
	int op;
	do{


		system("cls");
		printf("\n\t\t\t\tJUEGO EL AHORCADO\n\n");
		printf("\Escribir la respuesta con mayusculas\n\n");
		printf(" CATEGORIAS\n\n");
		printf(" 1. Peliculas\n");
		printf(" 2. Paises\n");
		printf(" 3. Objetos\n\n");
		scanf("%i",&op);
	while(op<1 || op>4);
	}
	if (op==1) ingresoCategoria(op);
	if (op==2) ingresoCategoria(op);
	if (op==3) ingresoCategoria(op); 
}


// RECIBE UN VALOR



void ingresoCategoria (int op){



	char nombrecat[4][15] = {"Peliculas","Paises","Objetos"};

	char Peliculas [10][15] = {"PONYO","IT","RAYOS","CLICK","NEMO","DUMBO","MOANA","KLAUS","MUPPETS","TROLLS"};

	char paises [10][15] = {"TAILANDIA","ALEMANIA","BARBADOS","JAPON","ITALIA","MEXICO","CANADA","TURQUIA","CHINA","BRASIL"};

	char objetos [10][15] = {"BOTELLA","VASO","ZAPATO","ESPEJO","LAPIZ","LABIAL","DINERO","STICKER","ESTUCHE","AURICULARES"};


	switch(op){



		case 1:
			empezarJuego(Peliculas,nombrecat[op-1]);

			break;

		case 2:
			empezarJuego(paises,nombrecat[op-1]);
			
			break;
			
		case 3:

			empezarJuego(objetos,nombrecat[op-1]);

			break;	

	}	



}




//ALGORITMO



void empezarJuego (char palabras[][15], char nombre[]){
	int opcion,i,j,k,longitud,espacios,puntos=1300;
	char letra;
	int aciertos = 0;
	int intentos = 0;
	int ganar = 0;


    opcion = rand() % 10; 
	longitud = strlen(palabras[3]); // LA LONGITUD DE LA PALABRA 
	char frase[longitud];


	//SE COLOCAN GUIONES BAJOS PARA EJEMPLIFICAR LAS LETRAS DE LA PALABRA

	for(i=0; i < longitud; i++){
		frase[i] = '_';
	}

    do{
		aciertos = 0;
		system("cls");
		printf("\n\t\t\t\tJUEGO EL AHORCADO\n\n");
		printf(" CATEGORIA: %s\n\n",nombre);
		printf(" Intentos Disponibles: %i\t\t\t\tPuntuacion: %i\n\n",6-intentos,puntos);



		//CARACTERES DE LA PALABRA

		printf("\n\n\n");
		for(i=0; i < longitud; i++){
		   printf(" %c ",frase[i]);
	    }


		if (intentos == 6){

			printf("\n\n PERDISTE!!\n");
			printf(" LA SOLUCION ERA: %s\n\n",palabras[opcion]);
			printf(" Presiona una tecla para volver a jugar..");
			categorias();
		}

		
		//ADIVINADO LA PALABRA



		espacios=0;




		for (i = 0; i < longitud; i++){
			if (frase[i] == '_')
				espacios++;
		}



		if (espacios == 0){
			printf("\n\n FELICIDADES.. GANASTE!!\n\n");
			printf(" Presiona una tecla para volver a jugar..");
			categorias();		
		}
		
		printf("\n\n Digite una letra: ");
		scanf(" %c",&letra);


		//VERIFICACION DE LA PALABRA INGRESADA
	    for (j = 0; j < longitud; j++){
			if (letra == palabras[opcion][j]){
				frase[j] = letra;
				aciertos++;

			}	

		}

		if (aciertos == 0){
			intentos++;	

			puntos -= 200;
	    }
	while(intentos != 7);
	printf("\n\n");		


return
}