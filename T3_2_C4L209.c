#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>


int es_formato_valido(const char *s) { //Verifica si la cadena está vacía

    if (s[0] == '\0') {
        return 0;
    }
    
    int i = 0;

    if (s[i] == '+' || s[i] == '-') {           //Permite un signo opcional al inicio
        i++;
        if (s[i] == '\0') {
            return 0;
        }
    }
    
    for (; s[i] != '\0'; i++) {
        if (!isdigit((unsigned char)s[i])) {     //Verifica que todos los caracteres restantes sean dígitos
            return 0;
        }
    }
    return 1;
}

int main() {
    char line[1024];     //Buffer para almacenar cada línea

    while (fgets(line, sizeof(line), stdin) != NULL) {   //Lee la entrada línea por línea
        size_t len = strlen(line);
        
        if (len > 0 && line[len - 1] == '\n') {         //Elimina el salto de línea
            line[len - 1] = '\0';
            len--;
        }
        if (len > 0 && line[len - 1] == '\r') {
            line[len - 1] = '\0';
            len--;
        }
 
        if (!es_formato_valido(line)) {
            fprintf(stderr, "Error- Línea inválida: '%s'\n", line);    //Valida el formato del número
            continue;
        }

        // Convierte a long y verifica errores
        char *endptr;
        errno = 0; 
        long num = strtol(line, &endptr, 10);
        
  
        if (*endptr != '\0') {
            fprintf(stderr, "Error- Línea inválida: '%s'\n", line);
        } 

        else if (errno == ERANGE) {
            fprintf(stderr, "Error- Línea inválida (desbordamiento): '%s'\n", line);
        } 

        else {
            printf("Número: '%s'\n", line);
        }
    }

    return 0;
}