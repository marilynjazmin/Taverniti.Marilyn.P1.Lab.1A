#include "input.h"

void pedirCadena(char* cadena, char mensaje[], char mensajeError[])
{
	if(cadena!=NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		gets(cadena);

		while(validacionCadena(cadena)==0)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			gets(cadena);
			validacionCadena(cadena);
		}
		strlwr(cadena);
		cadena[0]=toupper(cadena[0]);
	}
}

void pedirCaracter(char* letra, char mensaje[], char mensajeError[])
{
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", letra);

	while(!isalpha(*letra))
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%c", letra);
	}
}

int validacionCadena(char cadena[])
{
	int validado=-1;
	int tam;

	tam=strlen(cadena);

	for(int i=0; i<tam; i++)
	{
		if(isdigit(cadena[i]) || isalpha(cadena[i])==0)
		{
			validado=0;
		}
	}

	return validado;
}

int validarNumero (char numeros[])
{
    int validacion=-1;
    for(int i=0;i<strlen(numeros);i++)
    {
        if(!(numeros[i] == 46 || (numeros[i]>=48 && numeros[i]<=57)))
        {

            validacion=0;

        }
    }
    return validacion;
}

int pedirFlotante(float* numero, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno=-1;
	char numeroIngresado[100];

	if(numero!=NULL && mensaje!=NULL && mensajeError!=NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%s", numeroIngresado);

		while(!validarNumero(numeroIngresado))
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%s", numeroIngresado);
			validarNumero(numeroIngresado);
		}

		*numero=atof(numeroIngresado);

		while(*numero < min || *numero > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%s", numeroIngresado);

			while(!validarNumero(numeroIngresado))
			{
				printf("%s", mensajeError);
				fflush(stdin);
				scanf("%s", numeroIngresado);
				validarNumero(numeroIngresado);
			}
		}

		*numero=atof(numeroIngresado);
		retorno=0;
	}

	return retorno;
}

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
    int retorno = -1;
    int numeroIngresado;

    if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%d", &numeroIngresado);

        while(numeroIngresado < min || numeroIngresado > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%d", &numeroIngresado);
        }

        *entero = numeroIngresado;
        retorno = 0;
    }

    return retorno;
}

void getString(char cadena[], char mensaje[])
{
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", cadena);
}

int pedirNumero(char mensaje[])
{
	int numeroIngresado;

	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}
