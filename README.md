# Reto 3 - Joceline Ayala


Este proyecto es parte del Reto 3 de Programación en C++.  
Incluye el modelo de base de datos, la normalización y la implementación del sistema de biblioteca.


Informe de Aprendizaje
Durante el desarrollo de este reto pude integrar varios conceptos de bases de datos y programación en C++., desde la primera fase, con el diagrama ER, entendí la importancia de identificar claramente las entidades y sus relaciones, en este caso, trabajar con Libro, Autor, Estudiante y Préstamo me ayudó a visualizar cómo una biblioteca funciona en la vida real y cómo trasladarlo a un modelo digital. Además, pude aprender mediante videos que explicaban sumamente bien este tipo de diagramas.

En la fase de normalización, logré comprender mejor por qué no es buena idea repetir información. Por ejemplo, si guardaba el nombre del autor dentro de la tabla de libros, cada vez que se registraba un nuevo libro de ese mismo autor se duplicaba el dato, gracias a la normalización pude separar las tablas y usar llaves foráneas, la normalización evitó duplicados en autores y mantuvo el modelo más claro y organizado.

En la fase de implementación, aprendí a trabajar con structs, vectores y archivos de texto en C++, fue un reto lograr el CRUD completo en todas las entidades, pero me di cuenta de que seguir una misma estructura de funciones (agregar, listar, actualizar, eliminar) hacía el trabajo más ordenado, también reforcé el manejo de persistencia con fstream, ya que tuve que guardar y cargar la información en archivos .txt y asegurarme de que el formato fuera correcto. 

Otro aprendizaje importante fue cómo simular relaciones con bucles. Por ejemplo, para poder mostrar los libros prestados por un estudiante, tuve que recorrer los préstamos y relacionarlos con los libros correspondientes. Igualmente, implementar la consulta del autor con más libros me ayudó a aplicar conteo y búsqueda dentro de vectores, reforzando la lógica de programación.

En conclusión, este proyecto me enseñó no solo la parte técnica de C++ y bases de datos básicas, sino también la importancia de organizar la información para evitar redundancias, validar los datos y presentar menús claros para el usuario, pude comprobar que un sistema de biblioteca, aunque sencillo, requiere pensar bien el modelo desde el inicio, este reto me dejó más confianza para trabajar proyectos que integren teoría de bases de datos con programación práctica, aunque aun tenga un camino de aprendizaje extenso por delante.

¿Cómo compilar y ejecutar el proyecto?
1. Descargar el repositorio
Haz clic en el botón verde **Code → Download ZIP**, o usa el siguiente comando en la terminal:

2. Abrir la terminal en la carpeta
En Windows: clic derecho dentro de la carpeta → “Abrir en Terminal” o “Git Bash Here”.

3. Compilar el programa
Ejecuta este comando en la terminal:
g++ main.cpp biblioteca.cpp -o biblioteca.exe

