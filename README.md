![Estructuras](/LOGO.png)

[![Ask Me Anything !](https://img.shields.io/badge/Ask%20me-anything-1abc9c.svg)](https://github.com/RubioHaro/)
[![PyPI license](https://img.shields.io/pypi/l/ansicolortags.svg)](https://github.com/RubioHaro/Estructuras-de-datos/blob/master/LICENSE)

# Estructura de datos

Este repositorio contiene las practicas realizadas en el seguimiento de los tutoriales Estructuras de datos, de [makigas](https://www.makigas.es/series/estructuras-de-datos) (Tutoriales a mi parecer con aportes de contenido de enorme valor y con un formato inigualable), así como fundamentos teóricos de diversas fuentes (véase bibliografía).

Definición: Son Formas de organizar informacion para manipular, buscar e insertar datos de forma eficiente.

## Listas enlazadas

Una lista enlazada es una colección de elementos dispuestos uno detrás de otro, en la que cada elemento se conecta al siguiente mediante un enlace, o un puntero. Los elementos de estas listas son llamados nodos, y estan compuestos por dos partes:

- Dato: es donde se contiene la información.
- Puntero: es el enlace al siguiente elemento de la lista, al siguiente nodo.

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

## Cola

### Cola Circular



# Autor y Bibliografía

Repositorio desarrollado por [Rubio Haro Rodrigo R.](https://github.com/RubioHaro). Curso de Estructuras desarrollado por [makigas](https://www.makigas.es/series/estructuras-de-datos). Cabe mencionar el deslinde de cualquier relación de autoría y/o colaboración para este repositorio.
