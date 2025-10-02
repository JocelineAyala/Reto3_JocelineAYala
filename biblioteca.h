#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structs
struct Autor {
    int id;
    string nombre;
    string nacionalidad;
};

struct Libro {
    int id;
    string titulo;
    string isbn;
    int anio;
    int id_autor;  
};

struct Estudiante {
    int id;
    string nombre;
    string grado;
};

struct Prestamo {
    int id;
    int id_estudiante;
    int id_libro;
    string fecha_prestamo;
    string fecha_devolucion;
};



// Clase BD
class BibliotecaDB {
public:
    vector<Autor> autores;
    vector<Libro> libros;
    vector<Estudiante> estudiantes;
    vector<Prestamo> prestamos;
    
    // Métodos Libros
    void agregarLibro(Libro l);
    void listarLibros();
    void guardarLibros();
    void cargarLibros();
    void actualizarLibro(int id);
    void eliminarLibro(int id);

    // Métodos Autor
    void agregarAutor(Autor a);
    void listarAutores();
    void guardarAutores();
    void cargarAutores();
    void actualizarAutor(int id);
    void eliminarAutor(int id);
    void autorConMasLibros();

    // Métodos Estudiante
    void agregarEstudiante(Estudiante e);
    void listarEstudiantes();
    void guardarEstudiantes();
    void cargarEstudiantes();
    void actualizarEstudiante(int id);
    void eliminarEstudiante(int id);


    // Métodos Préstamo
    void agregarPrestamo(Prestamo p);
    void listarPrestamos();
    void guardarPrestamos();
    void cargarPrestamos();
    bool libroDisponible(int id_libro);
    void actualizarPrestamo(int id);
    void eliminarPrestamo(int id);

    void listarLibrosPrestadosPorEstudiante(int id_estudiante);

};

#endif
