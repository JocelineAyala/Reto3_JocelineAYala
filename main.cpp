#include "biblioteca.h"

void menuLibros(BibliotecaDB &db) {
    int op;
    do {
        cout << "\n--- MENU LIBROS ---\n";
        cout << "1. Agregar Libro\n";
        cout << "2. Listar Libros\n";
        cout << "3. Actualizar Libro\n";
        cout << "4. Eliminar Libro\n";
        cout << "5. Volver al menu principal\n";
        cout << "Opcion: ";
        cin >> op;

        if (op == 1) {
            Libro l;
            cin.ignore();
            cout << "Titulo: "; getline(cin, l.titulo);
            cout << "ISBN: "; getline(cin, l.isbn);
            cout << "Anio: "; cin >> l.anio;

            // Mostrar autores disponibles
            if (db.autores.empty()) {
                cout << "No hay autores registrados. Debes agregar un autor primero.\n";
                return; // no se puede continuar
            }

            cout << "\n--- Autores Disponibles ---\n";
            for (auto &a : db.autores) {
                cout << "ID: " << a.id << " | Nombre: " << a.nombre 
                    << " | Nacionalidad: " << a.nacionalidad << "\n";
            }

            cout << "Elige el ID del autor: ";
            cin >> l.id_autor;

            // Validar que exista ese autor
            bool existeAutor = false;
            for (auto &a : db.autores) {
                if (a.id == l.id_autor) {
                    existeAutor = true;
                    break;
                }
            }

            if (!existeAutor) {
                cout << "Autor no encontrado. No se agrego el libro.\n";
            } else {
                db.agregarLibro(l);
            }
        }


        else if (op == 2) {
            db.listarLibros();
        }
        else if (op == 3) {
                int id;
                cout << "ID del libro a actualizar: ";
                cin >> id;
                db.actualizarLibro(id);
            }
            else if (op == 4) {
                int id;
                cout << "ID del libro a eliminar: ";
                cin >> id;
                db.eliminarLibro(id);
            }
        } while (op != 5);
    }
void menuAutores(BibliotecaDB &db) {
    int op;
    do {
        cout << "\n--- MENU AUTORES ---\n";
        cout << "1. Agregar Autor\n";
        cout << "2. Listar Autores\n";
        cout << "3. Actualizar Autor\n";
        cout << "4. Eliminar Autor\n";
        cout << "5. Volver al menu principal\n";
        cout << "Opcion: ";
        cin >> op;

        if (op == 1) {
            Autor a;
            cin.ignore();
            cout << "Nombre: "; getline(cin, a.nombre);
            cout << "Nacionalidad: "; getline(cin, a.nacionalidad);
            db.agregarAutor(a);
        }
        else if (op == 2) {
            db.listarAutores();
        }
        else if (op == 3) {
            int id;
            cout << "ID del autor a actualizar: ";
            cin >> id;
            db.actualizarAutor(id);
        }
        else if (op == 4) {
            int id;
            cout << "ID del autor a eliminar: ";
            cin >> id;
            db.eliminarAutor(id);
        }
    } while (op != 5);
}

void menuEstudiantes(BibliotecaDB &db) {
    int op;
    do {
        cout << "\n--- MENU ESTUDIANTES ---\n";
        cout << "1. Agregar Estudiante\n";
        cout << "2. Listar Estudiantes\n";
        cout << "3. Volver al menu principal\n";
        cout << "Opcion: ";
        cin >> op;

        if (op == 1) {
            Estudiante e;
            cin.ignore();
            cout << "ID: " << e.id 
                << " | Nombre: " << e.nombre
                << " | Grado: " << e.grado << "\n";
            db.agregarEstudiante(e);
        }
        else if (op == 2) {
            db.listarEstudiantes();
        }

        else if (op == 3) {
            int id; cout << "ID del estudiante a actualizar: "; cin >> id;
            db.actualizarEstudiante(id);
        }
        else if (op == 4) {
            int id; cout << "ID del estudiante a eliminar: "; cin >> id;
            db.eliminarEstudiante(id);
        }

    } while (op != 5);
}

void menuPrestamos(BibliotecaDB &db) {
    int op;
    do {
        cout << "\n--- MENU PRESTAMOS ---\n";
        cout << "1. Registrar Prestamo\n";
        cout << "2. Listar Prestamos\n";
        cout << "3. Volver al menu principal\n";
        cout << "Opcion: ";
        cin >> op;

        if (op == 1) {
            Prestamo p;
            cout << "ID Estudiante: "; cin >> p.id_estudiante;
            cout << "ID Libro: "; cin >> p.id_libro;
            cin.ignore();
            cout << "Fecha Prestamo: "; getline(cin, p.fecha_prestamo);
            p.fecha_devolucion = "N/A";
            db.agregarPrestamo(p);
        }
        else if (op == 2) {
            db.listarPrestamos();
        }

        else if (op == 3) {
            int id; cout << "ID del prestamo a actualizar: "; cin >> id;
            db.actualizarPrestamo(id);
        }
        else if (op == 4) {
            int id; cout << "ID del prestamo a eliminar: "; cin >> id;
            db.eliminarPrestamo(id);
        }

    } while (op != 5);
}


int main() {
    BibliotecaDB db;
    db.cargarLibros();
    db.cargarAutores();
    db.cargarEstudiantes();
    db.cargarPrestamos();

    int opcion;
    while (true) {
        cout << "\n--- MENU PRINCIPAL BIBLIOTECA ---\n";
        cout << "1. Gestion de Libros\n";
        cout << "2. Gestion de Autores\n";
        cout << "3. Gestion de Estudiantes\n";
        cout << "4. Gestion de Prestamos\n";
        cout << "5. Guardar y Salir\n";
        cout << "6. Listar libros prestados por un estudiante\n";
        cout << "7. Autor con mas libros\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) menuLibros(db);
        else if (opcion == 2) menuAutores(db);
        else if (opcion == 3) menuEstudiantes(db);
        else if (opcion == 4) menuPrestamos(db);
        else if (opcion == 5) {
            db.guardarLibros();
            db.guardarAutores();
            db.guardarEstudiantes();
            db.guardarPrestamos();
            cout << "Datos guardados. Saliendo...\n";
            break;
        }
        else if (opcion == 6) {
            int id;
            cout << "ID del estudiante: ";
            cin >> id;
            db.listarLibrosPrestadosPorEstudiante(id);
        }
        else if (opcion == 7) {
            db.autorConMasLibros();
        }

        else {
            cout << "Opcion invalida\n";
        }
    }
    return 0;
}
