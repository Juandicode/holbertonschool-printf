🌟git printf 🌟

📖 Descripción del Proyecto

Este proyecto consiste en implementar una versión simplificada de la función printf de la biblioteca estándar de C. El objetivo es proporcionar soporte para el manejo de diferentes especificadores de formato, como %c, %s, %d, %i, y %%, además de aprender el uso de funciones variádicas y manipulación de datos en C.

🔤 Especificadores de Formato Soportados

%c: Imprime un solo carácter.

%s: Imprime una cadena de caracteres.

%d / %i: Imprime un número entero con signo.

%%: Imprime el símbolo % literal.

🚀 Valor de Retorno

La función _printf devuelve:

El número total de caracteres impresos (excluyendo el carácter nulo final \0).

En caso de error, retorna -1.

📂 Descripción de los Archivos

main.h: Archivo de cabecera que contiene las declaraciones de funciones utilizadas en el proyecto.

printf.c: Implementación principal de la función _prin, tambien contiene las funciones printch que imprime chars, printstr que imprime strings y printpercent que imprime "%"

printnum.c: Contiene la función printnumd, que maneja la impresión de números enteros.

main.c: Archivo de pruebas que muestra ejemplos de uso de _printf y compara su salida con la función estándar printf.

🔄 Flowchart (Diagrama de Flujo)

![image](https://github.com/user-attachments/assets/de58bd90-f8c7-4e31-a43b-0f04f5111dc2)


💻 Casos de Ejemplo y Salida Esperada

Entrada

Salida

_printf("Hello %c!\n", 'A');

Hello A!

_printf("%s\n", "world");

world

_printf("%%d: %d\n", 42);

%d: 42

_printf("Edge case: %d\n", -123);

Edge case: -123

✍️ Autores

[Juan Diego Martinez Haedo]

[Martín Suárez Bruschera]

¡Gracias por revisar este README! 😄


