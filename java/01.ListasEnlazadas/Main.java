public class Main {

    public static void main(String[] args) {
        Lista biblioteca = new Lista("Rodrigo Rubio Haro");

        Libro book1 = new Libro("Estructuras de datos", "Rodrigo Rubio Haro", "9780143440314");
        Libro book2 = new Libro("Programación Orientada a Objetos", "Rodrigo Rubio Haro", "9788429772456");
        
        System.out.println("Libros creados");

        System.out.println(book1.toString());
        System.out.println(book2.toString());
        
        System.err.println("Insertando libros");

        biblioteca.insertarPrincipio(book1);
        biblioteca.insertarPrincipio(book2);

        System.out.println(biblioteca.getLibro(0).toString());
        System.out.println(biblioteca.getLibro(1).toString());
        
        System.out.println("Biblioteca de: " + biblioteca.getPropietario());




    }
}