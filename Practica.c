#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

int contar_digitos(int n) {
    int contador = 0;
    if (n == 0) return 1;  
    if (n < 0) n = -n;      
    while (n > 0) {
        n /= 10;  
        contador++;
    }
    return contador;
}


//Busca una clave en un archivo, la clave tiene que estar en los primeros bytes, retorna la fila de lo encontrado.
int buscarClave(int clave,FILE *fptr){

    int claveLen= contar_digitos(clave);
    char fila[14]; 
    char buffer[claveLen];
    int claveComparar;
    int contador = 0;

    while(fgets(fila,sizeof(fila),fptr)){
        contador++;
        printf("fila %s\n",fila);
    
        for(int i=0;i<claveLen;i++){
            buffer[i] = fila[i];
        }

        claveComparar = atoi(buffer);
        if(clave == claveComparar){
            return contador;
        }

    }
    return 0;
}


int main(){

    FILE *fptr;
    fptr =fopen("BaseDeDatos.TXT","r");
    int clave = 666;

    printf("la clave %d esta en la fila %d\n",clave,buscarClave(clave,fptr));

    fclose(fptr);
    system("pause");
    return 0;

}