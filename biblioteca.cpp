#include "biblioteca.h"
#include <fstream>
#include <sstream>
#include <map>

// Libros
void BibliotecaDB::actualizarLibro(int id) {
    for (auto &l : libros) {
        if (l.id == id) {
            cin.ignore();
            cout << "Nuevo titulo (antes: " << l.titulo << "): ";
            getline(cin, l.titulo);
            cout << "Nuevo ISBN (antes: " << l.isbn << "): ";
            getline(cin, l.isbn);
            cout << "Nuevo anio (antes: " << l.anio << "): ";
            cin >> l.anio;
            cout << "Nuevo ID Autor (antes: " << l.id_autor << "): ";
            cin >> l.id_autor;
            cout << "Libro actualizado correctamente.\n";
            return;
        }
    }
    cout << "No se encontro un libro con ID " << id << "\n";
}

void BibliotecaDB::eliminarLibro(int id) {
    for (size_t i = 0; i < libros.size(); i++) {
        if (libros[i].id == id) {
            libros.erase(libros.begin() + i);
            cout << "Libro eliminado correctamente.\n";
            return;
        }
    }
    cout << "No se encontro un libro con ID " << id << "\n";
}

void BibliotecaDB::agregarLibro(Libro l) {
    int nuevoID = (libros.empty() ? 1 : libros.back().id + 1);
    l.id = nuevoID;

    // Validar que el autor exista
    bool existeAutor = false;
    for (auto &a : autores) {
        if (a.id == l.id_autor) {
            existeAutor = true;
            break;
        }
    }
    if (!existeAutor) {
        cout << "Error: El autor con ID " << l.id_autor << " no existe.\n";
        return;
    }

    libros.push_back(l);
    cout << "Libro agregado con ID: " << l.id << "\n";
}

void BibliotecaDB::listarLibros() {
    if (libros.empty()) {
        cout << "No hay libros registrados.\n";
        return;
    }

    cout << "\n--- Lista de Libros ---\n";
    for (auto &l : libros) {
        // Buscar autor correspondiente
        string nombreAutor = "(desconocido)";
        for (auto &a : autores) {
            if (a.id == l.id_autor) {
                nombreAutor = a.nombre;
                break;
            }
        }

        cout << "ID: " << l.id 
             << " | Titulo: " << l.titulo
             << " | ISBN: " << l.isbn
             << " | Anio: " << l.anio
             << " | Autor: " << nombreAutor << "\n";
    }
}



void BibliotecaDB::guardarLibros() {
    ofstream file("libros.txt");
    for (auto &l : libros) {
        file << l.id << "," << l.titulo << "," << l.isbn << "," 
             << l.anio << "," << l.id_autor << "\n";
    }
    file.close();
}

void BibliotecaDB::cargarLibros() {
    ifstream file("libros.txt");
    string linea;
    while (getline(file, linea)) {
        stringstream ss(linea);
        string id, titulo, isbn, anio, id_autor;
        getline(ss, id, ',');
        getline(ss, titulo, ',');
        getline(ss, isbn, ',');
        getline(ss, anio, ',');
        getline(ss, id_autor, ',');
        if (!id.empty())
            libros.push_back({stoi(id), titulo, isbn, stoi(anio), stoi(id_autor)});
    }
    file.close();
}

// Autores

void BibliotecaDB::actualizarAutor(int id) {
    for (auto &a : autores) {
        if (a.id == id) {
            cin.ignore();
            cout << "Nuevo nombre (antes: " << a.nombre << "): ";
            getline(cin, a.nombre);
            cout << "Nueva nacionalidad (antes: " << a.nacionalidad << "): ";
            getline(cin, a.nacionalidad);
            cout << "Autor actualizado correctamente.\n";
            return;
        }
    }
    cout << "No se encontro un autor con ID " << id << "\n";
}

void BibliotecaDB::eliminarAutor(int id) {
    for (size_t i = 0; i < autores.size(); i++) {
        if (autores[i].id == id) {
            autores.erase(autores.begin() + i);
            cout << "Autor eliminado correctamente.\n";
            return;
        }
    }
    cout << "No se encontro un autor con ID " << id << "\n";
}


void BibliotecaDB::agregarAutor(Autor a) {
    for (auto &aut : autores) {
        if (aut.id == a.id) {
            cout << "Error: ID de autor duplicado.\n";
            return;
        }
    }
    autores.push_back(a);
    cout << "Autor agregado con exito.\n";
}

void BibliotecaDB::listarAutores() {
    if (autores.empty()) {
        cout << "No hay autores registrados.\n";
        return;
    }
    cout << "\n--- Lista de Autores ---\n";
    for (auto &a : autores) {
        cout << "ID: " << a.id << " | Nombre: " << a.nombre
             << " | Nacionalidad: " << a.nacionalidad << "\n";
    }
}

void BibliotecaDB::guardarAutores() {
    ofstream file("autores.txt");
    for (auto &a : autores) {
        file << a.id << "," << a.nombre << "," << a.nacionalidad << "\n";
    }
    file.close();
}

void BibliotecaDB::cargarAutores() {
    ifstream file("autores.txt");
    string linea;
    while (getline(file, linea)) {
        stringstream ss(linea);
        string id, nombre, nacionalidad;
        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, nacionalidad, ',');
        if (!id.empty())
            autores.push_back({stoi(id), nombre, nacionalidad});
    }
    file.close();
}

void BibliotecaDB::autorConMasLibros() {
    if (libros.empty()) {
        cout << "No hay libros registrados.\n";
        return;
    }

    map<int,int> conteo;
    for (auto &l : libros) {
        conteo[l.id_autor]++;
    }

    int maxAutor = -1, maxLibros = 0;
    for (auto &par : conteo) {
        if (par.second > maxLibros) {
            maxLibros = par.second;
            maxAutor = par.first;
        }
    }

    // Buscar nombre del autor
    string nombreAutor = "(desconocido)";
    for (auto &a : autores) {
        if (a.id == maxAutor) {
            nombreAutor = a.nombre;
            break;
        }
    }

    cout << "Autor con mas libros: " << nombreAutor
         << " (" << maxLibros << " libros)\n";
}


// Estudiantes
void BibliotecaDB::agregarEstudiante(Estudiante e) {
    for (auto &est : estudiantes) {
        if (est.id == e.id) {
            cout << "Error: ID de estudiante duplicado.\n";
            return;
        }
    }
    estudiantes.push_back(e);
    cout << "Estudiante agregado con exito.\n";
}

void BibliotecaDB::listarEstudiantes() {
    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados.\n";
        return;
    }
    cout << "\n--- Lista de Estudiantes ---\n";
    for (auto &e : estudiantes) {
        cout << "ID: " << e.id 
            << " | Nombre: " << e.nombre
            << " | Carne: " << e.grado << "\n";
    }
}

void BibliotecaDB::guardarEstudiantes() {
    ofstream file("estudiantes.txt");
    for (auto &e : estudiantes) {
        file << e.id << "," << e.nombre << "," << e.grado << "\n";
    }
    file.close();
}

void BibliotecaDB::cargarEstudiantes() {
    ifstream file("estudiantes.txt");
    string linea;
    while (getline(file, linea)) {
        stringstream ss(linea);
        string id, nombre, grado;
        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, grado, ',');

        if (!id.empty())
            estudiantes.push_back({stoi(id), nombre, grado});
    }
    file.close();
}

void BibliotecaDB::actualizarEstudiante(int id) {
    for (auto &e : estudiantes) {
        if (e.id == id) {
            cin.ignore();
            cout << "Nuevo nombre (antes: " << e.nombre << "): ";
            getline(cin, e.nombre);
            cout << "Nuevo grado (antes: " << e.grado << "): ";
            getline(cin, e.grado);
            cout << "Estudiante actualizado.\n";
            return;
        }
    }
    cout << "No se encontro estudiante con ID " << id << "\n";
}


void BibliotecaDB::eliminarEstudiante(int id) {
    for (size_t i = 0; i < estudiantes.size(); i++) {
        if (estudiantes[i].id == id) {
            estudiantes.erase(estudiantes.begin() + i);
            cout << "Estudiante eliminado.\n";
            return;
        }
    }
    cout << "No se encontro estudiante con ID " << id << "\n";
}


// Préstamos

// Verificar si un libro está disponible (no prestado actualmente)
bool BibliotecaDB::libroDisponible(int id_libro) {
    for (auto &p : prestamos) {
        if (p.id_libro == id_libro && p.fecha_devolucion == "N/A") {
            return false; // libro prestado y no devuelto
        }
    }
    return true;
}

void BibliotecaDB::agregarPrestamo(Prestamo p) {
    // Validar ID duplicado
    for (auto &pr : prestamos) {
        if (pr.id == p.id) {
            cout << "Error: ID de prestamo duplicado.\n";
            return;
        }
    }

    // Validar estudiante existente
    bool estudianteExiste = false;
    for (auto &e : estudiantes) {
        if (e.id == p.id_estudiante) {
            estudianteExiste = true;
            break;
        }
    }
    if (!estudianteExiste) {
        cout << "Error: El estudiante no existe.\n";
        return;
    }

    // Validar libro existente y disponible
    bool libroExiste = false;
    for (auto &l : libros) {
        if (l.id == p.id_libro) {
            libroExiste = true;
            break;
        }
    }
    if (!libroExiste) {
        cout << "Error: El libro no existe.\n";
        return;
    }
    if (!libroDisponible(p.id_libro)) {
        cout << "Error: El libro ya esta prestado.\n";
        return;
    }

    prestamos.push_back(p);
    cout << "Prestamo registrado con exito.\n";
}

void BibliotecaDB::listarPrestamos() {
    if (prestamos.empty()) {
        cout << "No hay prestamos registrados.\n";
        return;
    }
    cout << "\n--- Lista de Prestamos ---\n";
    for (auto &p : prestamos) {
        cout << "ID: " << p.id 
             << " | Estudiante: " << p.id_estudiante
             << " | Libro: " << p.id_libro
             << " | Fecha Prestamo: " << p.fecha_prestamo
             << " | Fecha Devolucion: " << p.fecha_devolucion << "\n";
    }
}

void BibliotecaDB::guardarPrestamos() {
    ofstream file("prestamos.txt");
    for (auto &p : prestamos) {
        file << p.id << "," << p.id_estudiante << "," << p.id_libro 
             << "," << p.fecha_prestamo << "," << p.fecha_devolucion << "\n";
    }
    file.close();
}

void BibliotecaDB::cargarPrestamos() {
    ifstream file("prestamos.txt");
    string linea;
    while (getline(file, linea)) {
        stringstream ss(linea);
        string id, id_est, id_lib, f_prest, f_dev;
        getline(ss, id, ',');
        getline(ss, id_est, ',');
        getline(ss, id_lib, ',');
        getline(ss, f_prest, ',');
        getline(ss, f_dev, ',');
        if (!id.empty())
            prestamos.push_back({stoi(id), stoi(id_est), stoi(id_lib), f_prest, f_dev});
    }
    file.close();
}

void BibliotecaDB::actualizarPrestamo(int id) {
    for (auto &p : prestamos) {
        if (p.id == id) {
            cin.ignore();
            cout << "Nueva fecha prestamo (antes: " << p.fecha_prestamo << "): ";
            getline(cin, p.fecha_prestamo);
            cout << "Nueva fecha devolucion (antes: " << p.fecha_devolucion << "): ";
            getline(cin, p.fecha_devolucion);
            cout << "Prestamo actualizado.\n";
            return;
        }
    }
    cout << "No se encontro prestamo con ID " << id << "\n";
}

void BibliotecaDB::eliminarPrestamo(int id) {
    for (size_t i = 0; i < prestamos.size(); i++) {
        if (prestamos[i].id == id) {
            prestamos.erase(prestamos.begin() + i);
            cout << "Prestamo eliminado.\n";
            return;
        }
    }
    cout << "No se encontro prestamo con ID " << id << "\n";
}

void BibliotecaDB::listarLibrosPrestadosPorEstudiante(int id_estudiante) {
    cout << "\n--- Libros prestados por Estudiante ID " << id_estudiante << " ---\n";
    for (auto &p : prestamos) {
        if (p.id_estudiante == id_estudiante) {
            for (auto &l : libros) {
                if (l.id == p.id_libro) {
                    cout << "Libro: " << l.titulo << " | Fecha préstamo: " << p.fecha_prestamo
                         << " | Fecha devolucion: " << p.fecha_devolucion << "\n";
                }
            }
        }
    }
}
