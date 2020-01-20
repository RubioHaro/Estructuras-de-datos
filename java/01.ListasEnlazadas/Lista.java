public class Lista {
    private Nodo cabeza;
    private String propietario;
    private int longitud = 0;

    private class Nodo {

        public Libro libro;
        public Nodo siguiente = null;

        public Nodo(Libro libro) {
            this.libro = libro;
        }
    }

    public Lista(String propietario) {
        this.propietario = propietario;
    }

    /**
     * @return the propietario
     */
    public String getPropietario() {
        return propietario;
    }

    /**
     * @param propietario the propietario to set
     */
    public void setPropietario(String propietario) {
        this.propietario = propietario;
    }

    public void insertarPrincipio(Libro libro) {
        Nodo nodo = new Nodo(libro);
        nodo.siguiente = cabeza;
        cabeza = nodo;
        longitud++;
    }

    public void insertarFinal(Libro libro) {
        Nodo nodo = new Nodo(libro);

        if (cabeza == null) {
            cabeza = nodo;
        } else {
            Nodo puntero = cabeza;
            while (puntero.siguiente != null) {
                puntero = puntero.siguiente;
            }
            puntero.siguiente = nodo;
        }
        longitud++;
    }

    public void insertarLibro(int posicion, Libro libro) {
        Nodo nodo = new Nodo(libro);

        if (cabeza == null) {
            cabeza = nodo;
        } else {
            Nodo puntero = cabeza;
            int contador = 0;

            while (contador < posicion && puntero.siguiente != null) {
                puntero = puntero.siguiente;
                contador++;
            }

            nodo.siguiente = puntero.siguiente;
            puntero.siguiente = nodo;
        }
        longitud++;
    }

    public Libro getLibro(int n) {
        if (cabeza == null) {
            return null;
        } else {
            Nodo puntero = cabeza;
            int contador = 0;

            while (contador < n && puntero.siguiente != null) {
                puntero = puntero.siguiente;
                contador++;
            }

            if (contador != n) {
                return null;
            } else {
                return puntero.libro;
            }
        }
    }

    public int contar() {
        return longitud;
    }

    public boolean estaVacia() {
        return cabeza == null;
    }

    public void eliminarPrincipio() {
        if (cabeza != null) {
            Nodo primero = cabeza;
            cabeza = cabeza.siguiente;
            primero.siguiente = null;
            longitud--;
        }
    }

    public void eliminarUltimo() {
        if (cabeza != null) {

            if (cabeza.siguiente.siguiente == null) {
                cabeza = null;
            } else {
                Nodo puntero = cabeza;
                while (puntero.siguiente.siguiente != null) {
                    puntero = puntero.siguiente;
                }
                puntero.siguiente = null;
            }
            longitud--;
        }
    }

    public void eliminarLibro(int n) {
        if (cabeza != null) {

            if (n == 0) {
                Nodo primero = cabeza;
                cabeza = cabeza.siguiente;
                primero.siguiente = null;
            } else if (n < longitud) {
                Nodo puntero = cabeza;
                int contador = 0;
                while (contador < (n - 1)) {
                    puntero = puntero.siguiente;
                    contador++;
                }

                Nodo temp = puntero.siguiente;
                puntero.siguiente = temp.siguiente;
                temp.siguiente = null;
            }

            longitud--;
        }
    }

}



