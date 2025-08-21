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


//Busca una clave en un archivo, la clave tiene que estar en los primeros bytes, retorna la fila del cliente.(puede ser que tenga que cambiar el clavelen y ponerlo fijo)
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

int buscarBytesXFila(int desde,int hasta,int clave,char buffer[],FILE *fptr){
    int cantBytes = (hasta - desde) + 1;
    int primerByte = desde - 1;
    int ultimoByte = hasta - 1;
    char fila[14]; 
    char bufferFun[cantBytes];

    int claveComparar;
    int contador = 0;
    
    while(fgets(fila,sizeof(fila),fptr)){
        int n =0;

        for(int i=0;i<=hasta;i++){
            if(i>= primerByte && i<=ultimoByte){
                bufferFun[n] = fila[i];
                n++;
            }
        }

        claveComparar = atoi(bufferFun);
        if(clave == claveComparar){
            for(int i=0;i<cantBytes;i++){
                buffer[i] = bufferFun[i];
            }
            return 0;
        }

    }
    return 1;



}




int main(){

    FILE *fptr;
    fptr =fopen("BaseDeDatos.TXT","r");
    int clave = 346;
    char claveEncontrada[3];

    buscarBytesXFila(9,11,clave,claveEncontrada,fptr);
    printf("la clave %d es igual a la clave encontrada que es %d\n",clave,atoi(claveEncontrada));


    printf("la clave %d esta en la fila %d\n",clave,buscarClave(clave,fptr));



    fclose(fptr);
    system("pause");
    return 0;

}