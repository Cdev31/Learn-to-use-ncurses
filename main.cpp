#include <iostream>
#include <ncurses.h>

using namespace std;

int main(){
    initscr();

    if( has_colors() == FALSE ){
        endwin();
        return 1;
    }

     start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);   // Color rojo para el texto y negro para el fondo
    init_pair(2, COLOR_GREEN, COLOR_BLACK); // Color verde para el texto y negro para el fondo
    
    // Mover el cursor a la posición (2, 5) y cambiar el color
    attron(COLOR_PAIR(1));  // Usamos el color rojo
    move(2, 5);
    printw("Texto en rojo");
    attroff(COLOR_PAIR(1)); // Desactivamos el color rojo

    move(4, 5);
    attron(COLOR_PAIR(2));  // Usamos el color verde
    printw("Texto en verde");
    attroff(COLOR_PAIR(2)); // Desactivamos el color verde

    // Simulación de paginación
    move(6, 5);
    printw("Página 1 de 3");
    refresh();  // Actualizamos la pantalla
    
    // Esperamos 2 segundos antes de pasar a la siguiente "página"
    napms(2000);
    
    clear();
    move(6, 5);
    printw("Página 2 de 3");
    refresh();
    napms(2000);
    
    clear();
    
    move(6, 5);
    printw("Página 3 de 3");
    refresh();
    
    // Esperamos hasta que el usuario presione la tecla 'q'
    char ch;
    while (true) {
        ch = getch();  // Leemos una tecla
        if (ch == 'q' || ch == 'Q') {  // Si la tecla es 'q' o 'Q', salimos
            break;
        }
    }
    
    // Finalizamos ncurses y restauramos la terminal
    endwin();

}