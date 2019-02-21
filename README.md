# Estructura de datos

Formas de organizar informacion para manipular, buscar e insertar datos de forma eficiente.

## Ejercicios

### I. Operadores

01. Calculadora (operadores basicos: +,-,/,*)
02. Calculadora de Sisema de Ecuaciones (forma Ax + By = C)
03. Velocidad de una caida libre Vf = g * t
04. Fuerza de gravedad entre dos cuerpos, conociendo sus masas y la distancia entre ellos
05. Pendiente y la ordenada al origen de una recta de la forma f(x)= mx + b, conociendo dos de sus puntos.
06. Promedio de una cantidad determinada de numeros (reales)
07. Descuento (15%) sobre una compra.
08. Visualizar la tarifa de 'La luz' según el gasto de corriente eléctrica.
09. Obtener el factorial de un número.
10. Obtener la sucesión de fibonacci.
11. Saber si un número es impar haciendo uso del operador (?).
12. Obtener uno o varios numeros aleatorios.

### II. Bucles

1. Ejemplo basico para usar un DoWhile.
2. Bucle para hacer la suma de los multiplos de un numero.

### III. Punteros

1. Ejemplo basico para usar punteros.
2. Ejercicio de uso de punteros.
3. Obtener el radio y las coordenadas del centro de una circunferencia dada su ecuación.
4. Evaluación una función predeterminada.
5. Obtener la hipotenusa de un triangulo.

### IV. Cadenas

1. Ejemplo básico para usar cadenas.

### V. Arreglos

#### 2. Arreglos Bidimensionales

1. Ejemplo básico para arreglos bidimensionales estaticos.

### VI. Archivos

1. Comprobar si existe un archivo.
2. Crear un archivo.
3. Abrir y cerrar archivos.
4. Crear un archivo y escribir en el.
5. Leer los caracteres de un archivo.

### Por Rubio Haro Rodrigo Rodolfo

<https://github.com/RubioHaro>

### INSTITUTO POLITECNICO NACIONAL (IPN)

<https://www.ipn.mx/>

### ESCUELA SUPERIOR DE COMPUTO (ESCOM)

<https://www.escom.ipn.mx/>


## Pilas/Stack

La pila es una lista de elementos caracterizada porque las operaciones de inserción y eliminación de elementos se realizan solamente en un extremo de la estructura. El extremo donde se realizan estas operaciones se denomina habitualmente cima (top en la nomenclatura inglesa).

Los arreglos pueden ser arreglos circulares, o podemos darle la forma que queramos.

LIFO: Last in. First out.

UEPS: Ultimo en Entrar. Primero en salir.

1. Operaciones
    >Push mete elementos a la lista.

   <!---->
    >Pop retira elementos de la lista.

1. Estados a validar
    > Si la pila esta vacia

    En las pilas, exise un indice -1 (el zotano) para indicar que la pila esta vacia, cuando al hacer un pop al cero, top debe de apuntar a este indice.

    Si esta vacía y hacemos un pop, el error que saldra es:
    `underflow`

    > Si la pila esta llena

    Cuando top este en el ultimo elemento del arreglo (TOP == (TAM-1)).

    Si la pila esta llena y hacemos un push el error sera:
    `overflow`


























## Variables

Es la posicion de memoria a la que le asignamos un valor, este valor puede cambiar. Si una variable esta dentro de una funcion se le llama "local", y si se puede usar en varias funciones se puede llamar "variable global".

## Constantes

Es la posicion de memoria a la que le asignamos un valor pero este valor no puede cambiar, a diferencia de las variables.
[ver diferencias con las Macros (define)].

## Tipos de datos en c

Existen diferentes tipos de datos:

    1. int (2 bytes, rango: -32768 a 32768)
    2. short (2 bytes, rango: -128 a 127)
    3. long (4 bytes)
    4. float (4 bytes)
    5. double (8 bytes)
    6. char (1 byte, rango: 0 a 255)

## Entradas

Son todos los datos que requiere el programa que sean ingresados por el o los usuarios para poder operar y/o funcionar.

Para recibir los datos ingresados por un usuario, se utiliza el comando:

`char[30] name; scanf("%s", name)`

La cuestión con este comando es que obtiene solo obtiene los caracteres hasta que encuentre un espacio en blanco. Otra alternativa es:

`char[30] name; gets(name)`

## Salidas

Son todos los datos mostrados por el programa.

Para imprimir, se utiliza el comando:

`printf("Hola mundo")`

Para imprimir algun dato, se utiliza el comando:

`printf("Hola mundo, mi nombre es: %c ", name)`

Para imprimir con varios datos, se utiliza el comando:

`printf("Hola mundo, mi nombre es: %c %c ", name, surname)`

## Operadores

Para realizar las operaciones basicas se usan los signos de comunes de operacion
>
Suma: `a = x + y`
>
Resta: `a = x - y`
>
Multiplicacion: `a = x * y`
>
Division: `a = x / y`
>

## Operadores de Asignacion

Son operaciones que abrevian determinadas operaciones.
Por ejemplo:
>
`a = a + 10` = `a += 10`
>
`a = a - 10` = `a -= 10`
>
`a = a * 10` = `a *= 10`
>
`a = a / 10` = `a /= 10`

## Paso de parametros

Existen diversas formas de pasar parametros a funciones o incluso a clases, en general y para la mayoria de lenguajes de progrmación existen dos formas:

### Paso por valor

Se hace una copia del valor, valga la redundancia, que tiene la variable, esto implica que no se puede modificar el parametro original.

### Paso por referencia

Llamamos paso por referencia, alternativa a pasar por valor, al envio de la dirección o posición de memoria donde está guardada la variable por lo que se puede modificar, en cierta forma se puede decir que literalmente se esta pasando el parametro, no solo se esta copiando el valor de este.

## Puntero

Es una variable que almacena la dirección de memoria de otra variable. Esto quiere decir, que el puntero apunta al espacio físico donde está el dato o la variable.

### Declaración de punteros

La siguiente es la manera de declarar un puntero que apunte a un entero:

`int *x;`

Esto se puede leer «lo apuntado por x es un entero». En este caso, * no es una multiplicación, sino una derreferenciación.

Los únicos valores válidos que se puede asignar a un puntero, en este caso a x, son NULL o una dirección de memoria. Y debe si se le asigna una direccion de memoria esta debe contener una variable del mismo tipo de dato, en este caso un entero (int).

### Operadores de punteros

1. Operador dirección (&)
    > devuelve la dirección de memoria de una variable.
2. Operador indirección o contenido (*)
    > Devuelve el valor o el contenido de la variable a la que se apunta.

Ejemplos:

>
`int *numeroPuntero;`
>
`float *numeroDecimalPuntero;`
>
`char *CaracterPuntero;`

La declaración de un apuntador debe de ser siempre de del mismo tipo de dato a la cual va a apuntar.
Hay dos operadores para el manejo de punteros.

## Recursividad

Técnica utilizada en programación que nos permite que un bloque de instrucciones se ejecute un cierto número de veces.
