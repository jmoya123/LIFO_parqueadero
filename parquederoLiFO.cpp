#include <iostream>
#include <cstring>
#include <malloc.h>

using namespace std;

struct Vehiculo {
    char placa[8];
    int tipo; 
    int costo_parqueo;
    int costo_movimiento;
    
    Vehiculo* siguiente;
};

Vehiculo* top = NULL;

int registrar_placa(int tipo) {
    Vehiculo* nuevo_vehiculo = (Vehiculo*)malloc(sizeof(Vehiculo));
    cout << "Ingrese la placa: ";
    cin >> nuevo_vehiculo->placa;
    nuevo_vehiculo->tipo = tipo;
    
    nuevo_vehiculo->costo_parqueo = (tipo == 1) ? 5000 : 2500;
    nuevo_vehiculo->costo_movimiento = (tipo == 1) ? 1000 : 500;

    nuevo_vehiculo->siguiente = top;
    top = nuevo_vehiculo;
    return 0;
}
int mostrar_Dinero_gasto() {
  int total_parqueo_autos = 0;
  int total_parqueo_motos = 0;
  int total_movimiento_autos = 0;
  int total_movimiento_motos = 0;
  
  Vehiculo* temp = top;

   while (temp != NULL) {
   if (temp->tipo == 1) { 
   total_parqueo_autos += temp->costo_parqueo;
   total_movimiento_autos += temp->costo_movimiento;
   } else if (temp->tipo == 2) { 
   total_parqueo_motos += temp->costo_parqueo;
     total_movimiento_motos += temp->costo_movimiento;
    }
   temp = temp->siguiente;
  }

   cout << "Gastos de autos:\n";
   cout << "Parqueo: " << total_parqueo_autos << "\n";
   cout << "Movimiento: " << total_movimiento_autos << "\n";

  cout << "\nGastos de motos:\n";
   cout << "Parqueo: " << total_parqueo_motos << "\n";
   cout << "Movimiento: " << total_movimiento_motos << "\n";
   return 0;
}

int mostrar_parqueada() {
   int contador_autos = 0;
   int contador_motos = 0;
   Vehiculo* temp = top;

  cout << "Autos:\n";
  while (temp != NULL) {
    if (temp->tipo == 1) {
    contador_autos++;
    cout << "Placa: " << temp->placa << ", Tipo: Auto" << endl;
   }
    temp = temp->siguiente;
   }
    if (contador_autos == 0) {
   cout << "No hay autos parqueados.\n";
   }

   cout << "\nMotos:\n";
   temp = top; 
  while (temp != NULL) {
   if (temp->tipo == 2) {
    contador_motos++;
     cout << "Placa: " << temp->placa << ", Tipo: Moto" << endl;
   }
    temp = temp->siguiente;
   }

  if (contador_motos == 0) {
    cout << "No hay motos parqueadas.\n";
  }
  return 0;
}

int eliminar_vehiculo() {
    char placa[8];
    mostrar_parqueada();
    cout << endl << "Ingrese la placa del vehículo a eliminar: ";
    cin >> placa;

    Vehiculo* temp = top;
    Vehiculo* prev = NULL;
    int costo_movimiento_eliminar = 0; 

    while (temp != NULL) {
        if (strcmp(temp->placa, placa) == 0) {
            
            costo_movimiento_eliminar = temp->costo_movimiento; 
            if (prev == NULL) {
                
                top = temp->siguiente;
            } else {
                
                prev->siguiente = temp->siguiente;
            }
            free(temp);
            cout << "Vehículo eliminado correctamente.\n";
            
            cout << "Costo de movimiento del vehículo eliminado: " << costo_movimiento_eliminar << "\n";
            return 0;
        }
        prev = temp;
        temp = temp->siguiente;
    }

    cout << "No se encontró ningún vehículo con la placa ingresada.\n";
    return 0;
}

int main() {
    int opcion;
    do {
        cout << "1. Agregar auto\n";
        cout << "2. Agregar moto\n";
        cout << "3. Eliminar vehiculo\n";
        cout << "4. Mostrar dinero\n";
        cout << "5. Mostrar parqueda\n";
        cout << "6. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrar_placa(1);
                break;
            case 2:
                registrar_placa(2);
                break;
            case 3:
                mostrar_Dinero_gasto();
                break;
            case 4:
                mostrar_parqueada();
                break;
            case 5:
                eliminar_vehiculo();
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}