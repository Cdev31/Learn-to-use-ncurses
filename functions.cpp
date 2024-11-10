#include <iostream>
#include <string>
using namespace std;

// Definir las funciones de saludo que reciben un nombre como parámetro
void saludo1(string name) {
    cout << "¡Hola, " << name << "! Bienvenido al programa." << endl;
}

void saludo2(string name) {
    cout << "¡Saludos, " << name << " desde la segunda función!" << endl;
}

void saludo3(string name) {
    cout << "¡Hola, " << name << "! ¿Cómo estás?" << endl;
}

void saludo4(string name) {
    cout << "¡Buenos días, " << name << "!" << endl;
}

void saludo5(string name) {
    cout << "¡Que tengas un gran día, " << name << "!" << endl;
}

int main() {
    // Definir el array de punteros a función que toman un string como parámetro
    void (* screens[5] )(string name);  // Un array de 5 punteros a funciones que reciben un string y no retornan nada

    // Asignar las funciones a las posiciones del array
    screens[0] = saludo1;
    screens[1] = saludo2;
    screens[2] = saludo3;
    screens[3] = saludo4;
    screens[4] = saludo5;

    // Llamar a una función usando el array
    string name = "Juan"; // El nombre que queremos pasar a la función
    int index = 2; // Esto puede ser cualquier índice válido entre 0 y 4

    // Llamamos a la función en screens[index] pasando el nombre
    screens[index](name);  // Llama a saludo3, que es la función en screens[2] y pasa "Juan" como argumento

    return 0;
}
