#include <stdio.h>
#define  NumDias 30

void datos();
void menu1(int tempMax[NumDias], int tempMin[NumDias]);
void menu2(int tempMax[NumDias], int tempMin[NumDias]);
void menu3(int tempMax[NumDias], int tempMin[NumDias]);
void tempMaxMin(int temp[NumDias]);
int mediaMaxMin(int temp[NumDias]);
void superMedia(int tempMax[NumDias], int media);
void coincMedia(int tempMin[NumDias], int media);
void minMin(int tempMin[NumDias]);
void maxMax(int tempMax[NumDias]);
/**
 *
 * Ejecuta el programa
 *
 */
int main() {
    int tempMax[NumDias];
    int tempMin[NumDias];
    datos();
    menu1(tempMax, tempMin);
    return 0;
}
/**
 *Imprime los datos del alumno por la pantalla
 */
void datos(){
    printf("bn0073\n");
    printf("Ibarreta Sanchez-Vizcaino, Juan Luis\n\n");
}
/**
 *Imprime el menu principal por la pantalla
 * @param tempMax
 * @param tempMin
 */
void menu1(int tempMax[NumDias], int tempMin[NumDias]){
    int i;
    i = 0;
    while(i != 3) {
        printf("\n");
        printf("1. Introducir datos\n");
        printf("2. Trabajar con los datos\n");
        printf("3. Salir\n");
        printf("Seleccione Opcion: ");
        scanf("%d", &i);
        switch (i){
            case 1:
                menu2(tempMax, tempMin);
                break;
            case 2:
                menu3(tempMax, tempMin);
                break;
            case 3:
                return;
            default:
                printf("\nValor introducido no correcto\n");
        }
    }
}
/**
 *Imprime el menu de introduccion de datos por la pantalla
 * @param tempMax
 * @param tempMin
 */
void menu2(int tempMax[NumDias], int tempMin[NumDias]){
    int i;
    i = 0;
    while(i != 13) {
        printf("\nINTRODUCIR DATOS\n");
        printf("11. Introducir maximas del mes\n");
        printf("12. Introducir minimas del mes\n");
        printf("13. Volver al menu anterior\n");
        printf("Seleccione Opcion: ");
        scanf("%d", &i);
        switch (i){
            case 11:
                tempMaxMin(tempMax);
                break;
            case 12:
                tempMaxMin(tempMin);
                break;
            case 13:
                return;
            default:
                printf("Valor introducido no correcto\n");
        }
    }
}
/**
 *Imprime el menu de uso de datos por la pantalla
 * @param tempMax
 * @param tempMin
 */
void menu3(int tempMax[NumDias], int tempMin[NumDias]){
    int i, max, min;
    i = 0;
    while(i != 27){
        printf("\nTRABAJAR CON LOS DATOS\n");
        printf("21. Calcular la temperatura media de las maximas del mes\n");
        printf("22. Calcular la temperatura media de las minimas del mes\n");
        printf("23. Calcular cuantos dias se ha superado la media de las maximas\n");
        printf("24. Calcular cuantos dias las temperatus minimas coinciden con su media\n");
        printf("25. Calcular la temperatura minima de las minimas\n");
        printf("26. Calcular la temperatura maxima de las minimas\n");
        printf("27. Volver al menu anterior\n");
        printf("Seleccione Opcion: ");
        scanf("%d", &i);
        switch (i){
            case 21:
                max = mediaMaxMin(tempMax);
                printf("\nLa temperatura media maxima es de : %d\n", max);
                break;
            case 22:
                min = mediaMaxMin(tempMin);
                printf("\nLa temperatura media minima es de : %d\n", min);
                break;
            case 23:
                superMedia(tempMax, max);
                break;
            case 24:
                coincMedia(tempMin, min);
                break;
            case 25:
                minMin(tempMin);
                break;
            case 26:
                maxMax(tempMax);
                break;
            case 27:
                return;
            default:
                printf("Valor introducido no correcto\n");
            }
    }

}
/**
 * Introduccion de datos en los vectores de tempMax y tempMIn
 * @param temp
 */
void tempMaxMin(int temp[NumDias]){
    int i;
    for(i = 0; i < NumDias; i++){
        printf("\nIntroduzca la temperatura maxima/minima: ");
        scanf("%d", &temp[i]);
    }
}
/**
 * Calcula la media de los vectores tempMax y tempMin
 * @param temp
 * @return
 */
int mediaMaxMin(int temp[NumDias]){
    int i, suma;
    suma = 0;
    for(i = 0; i < NumDias; i++){
        suma = suma + temp[i];
    }
    suma = suma / 30;
    return suma;
}
/**
 * Calcula cuantos dias se ha superado la temperatura media
 * @param tempMax
 * @param media
 */
void superMedia(int tempMax[NumDias], int media){
    int i, dias;
    dias = 0;
    for(i = 0; i < NumDias; i++){
        if(tempMax[i] > media){
            dias++;
        }
    }
    printf("\n%d dias se ha superado la media maxima\n", dias);
}
/**
 * Calcula cuantos dias se ha igualado la temperatura media
 * @param tempMin
 * @param media
 */
void coincMedia(int tempMin[NumDias], int media){
    int i, dias;
    dias = 0;
    for(i = 0; i < NumDias;i++){
        if(tempMin[i] == media){
            dias++;
        }
    }
    printf("\n%d dias se ha igualado la media minima\n", dias);
}
/**
 * Halla el numero mas bajo de las temperaturas minimas
 * @param tempMin
 */
void minMin(int tempMin[NumDias]){
    int i, minimo;
    minimo = 0;
    for(i = 0; i < NumDias; i++){
        if(tempMin[i] < minimo){
            minimo = tempMin[i];
        }
    }
    printf("\n%d ha sido la temperatura minima mas baja\n", minimo);
}
/**
 *  Hall el numero mas alto de las temperaturas maximas
 * @param tempMax
 */
void maxMax(int tempMax[NumDias]){
    int i, maximo;
    maximo = 0;
    for(i = 0; i < NumDias; i++){
        if(tempMax[i] > maximo){
            maximo = tempMax[i];
        }
    }
    printf("\n%d ha sido la temperatura maxima mas alta\n", maximo);
}