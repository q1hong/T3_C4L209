#include <stdio.h>
#include <string.h>

int main() {
    char input[1000]; //Arreglo de caracteres para almacenar la cadena                               
    char ch;          //Almacena el caracter que se va a buscar
    int count = 0;    //Contador

    printf("Ingrese un string: ");
    fgets(input, sizeof(input), stdin); //Lee la linea ingresada por el usuario

    size_t len = strlen(input);     
    if (len > 0 && input[len - 1] == '\n')  //Elimina el salto de linea reemplazandola con \0
        input[len - 1] = '\0';

    printf("Ingrese el caracter que desea buscar: ");
    scanf(" %c", &ch);

    for (int i = 0; input[i]; i++) {    //itera sobre la cadena y cuenta las veces que aparece el caracter deseado
        if (input[i] == ch)
            count++;
    }

    printf("El caracter '%c' aparece '%d' veces\n", ch, count);

    printf("Cadena invertida: ");
    for (int i = strlen(input) - 1; i >= 0; i--)    //Itera desde el ultimo caracter hasta el primero
        putchar(input[i]);                          //Imprime los caracteres en orden inverso
    printf("\n");

    return 0;
}
