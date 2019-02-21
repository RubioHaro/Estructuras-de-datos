# Estructura de datos

Formas de organizar informacion para manipular, buscar e insertar datos de forma eficiente.

## Pilas/Stack

La pila es una lista de elementos caracterizada porque las operaciones de inserción y eliminación de elementos se realizan solamente en un extremo de la estructura. El extremo donde se realizan estas operaciones se denomina habitualmente cima (top en la nomenclatura inglesa).

Los arreglos pueden ser arreglos circulares, o podemos darle la forma que queramos.

LIFO: Last in. First out.

UEPS: Ultimo en Entrar. Primero en salir.

1. Operaciones
    >Push mete elementos a la lista.

   <!---->
    >Pop retira elementos de la lista.

2. Estados a validar
    > Si la pila esta vacia

    En las pilas, exise un indice -1 (el zotano) para indicar que la pila esta vacia, cuando al hacer un pop al cero, top debe de apuntar a este indice.

    Si esta vacía y hacemos un pop, el error que saldra es:
    `underflow`

    > Si la pila esta llena

    Cuando top este en el ultimo elemento del arreglo (TOP == (TAM-1)).

    Si la pila esta llena y hacemos un push el error sera:
    `overflow`

# 
### Por Rubio Haro Rodrigo Rodolfo

<https://github.com/RubioHaro>

### INSTITUTO POLITECNICO NACIONAL (IPN)

<https://www.ipn.mx/>

### ESCUELA SUPERIOR DE COMPUTO (ESCOM)

<https://www.escom.ipn.mx/>
