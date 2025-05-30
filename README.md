## T3_2_C4L209

Funcionalidad:

Valida los numeros evitando 
- Espacios 
- Letras 
- Desbordamientos 

Imprime las entradas válidas en el archivo de salida 
Imprime las entradas inválidas en el archivo de error 

Ejemplo de entrada.txt 
123 
abc 
-456 
+789 
123abc 
999999999999999999999999999999999 
0001 
-0 

Salida:

Número: '123'
Número: '-456'
Número: '+789'
Número: '0001'
Número: '-0'

Error: 

Error- Línea inválida: 'abc'
Error- Línea inválida: '123abc'
Error- Línea inválida (desbordamiento): '999999999999999999999999999999999'

Compilación: gcc T3_2_C4L209.c -o T3_2_C4L209

Uso: ./T3_2_C4L209 < archivo_entrada.txt > output.txt 2> error.txt
