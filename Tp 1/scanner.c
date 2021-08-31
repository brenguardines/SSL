#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "scanner.h"

void get_token() {
    char letra = getchar();
    char* cadena = NULL;

    while(letra != EOF) {
        if(! isspace(letra)) {
            if (letra == ',') { 
                cadena = strdup(verificarCadena(cadena));
                printf("Separador: ,\n");
            }
            else
              cadena = strdup(guardarCaracter(cadena, letra));
        }
        else
            cadena = strdup(verificarCadena(cadena));
        letra = getchar();
    }

    cadena = strdup(verificarCadena(cadena));
    printf("Fin de Texto.");
}

char* guardarCaracter(char* cadena, char letra) {
    char temp[2];

    temp[0] = letra;
    temp[1] = '\0';
    
    if(cadena == NULL)
        cadena = strdup(temp);
    else
        strcat(cadena, temp);

    return cadena;
}

char* verificarCadena(char* cadena) {
    if(cadena != NULL){
        printf("Cadena: %s\n", cadena);
        cadena = NULL;
    }

    return cadena;
}