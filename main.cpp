#include <conio.h>

#include <iostream>

#include "Outputs.h"

using namespace std;

int main() {
   /*    cout << "Bienvenido al sistema de gestion" << endl;
      cout << "-----------------------------------"<<endl;
      cout << "Ingrese su nombre de usuario : ";
      string name,pass;
      getline(cin, name);

      cout <<endl<< "ingrese su password : ";
      char ch;
      while ((ch = _getch()) != '\r') { // '\r' es Enter en Windows
           pass.push_back(ch);
           std::cout << '*';  // Muestra un '*' en lugar del carácter ingresado
       }
       cout << endl << "Usuario y/o clave incorrecta" << endl<<endl;
       cout << "Ingrese nuevamente su nombre de usuario : ";

      getline(cin, name);

      cout <<endl<< "ingrese su password : ";
      while ((ch = _getch()) != '\r') { // '\r' es Enter en Windows
           pass.push_back(ch);
           std::cout << '*';  // Muestra un '*' en lugar del carácter ingresado
       }
       cout << endl << "Usuario y/o clave incorrecta";
    */
   cout << "Gabriel Edgardo Salas : Administrador" << endl;
   cout << "-------------------------------------" << endl;
   cout << "Elija una opcion: ";
   cout << "1 - Consultas" << endl;
   cout << "2 - Ingresos" << endl;
   cout << "3 - Informes" <<endl;
   cout << "Opcion elejida :  ";
   string opcion;
   getline(cin, opcion);
   
   system("pause");
   return 0;
}
