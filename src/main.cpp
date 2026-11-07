#include <iostream>
#include <string>
#include <iomanip>

// Funcion para leer texto
std::string leerCadena(std::string mensaje) {
    std::string dato;
    std::cout << mensaje;
    std::getline(std::cin, dato);
    return dato;
}

// Funcion para leer numeros decimales
double leerDecimal(std::string mensaje) {
    double dato;
    std::cout << mensaje;
    std::cin >> dato;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "[ERROR] Ingrese un numero valido.\n";
        std::cout << mensaje;
        std::cin >> dato;
    }

    return dato;
}

// Funcion para leer numeros enteros
int leerEntero(std::string mensaje) {
    int dato;
    std::cout << mensaje;
    std::cin >> dato;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "[ERROR] Ingrese un numero entero valido.\n";
        std::cout << mensaje;
        std::cin >> dato;
    }

    return dato;
}

// Funcion para imprimir el ticket
void imprimirTicket(std::string nombre, int cantidad,
                    double precio, double subtotal,
                    double descuento, double iva, double total) {

    std::cout << "\n========== TICKET DE VENTA ==========\n";
    std::cout << "Producto: " << nombre << "\n";
    std::cout << "Cantidad: " << cantidad << "\n";
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Precio unitario: $" << precio << "\n";
    std::cout << "Subtotal: $" << subtotal << "\n";
    std::cout << "Descuento: $" << descuento << "\n";
    std::cout << "IVA (16%): $" << iva << "\n";
    std::cout << "TOTAL: $" << total << "\n";
    std::cout << "=====================================\n";
}

int main() {

    std::cout << "=== SISTEMA DE VENTAS MECATRONICA ===\n";

    // Paso 1: solicitar el nombre del producto
    std::string nombre = leerCadena("Ingrese el nombre del producto: ");

    // Paso 2: solicitar y validar precio
    double precio = leerDecimal("Ingrese el precio unitario: ");

    while (precio <= 0) {
        std::cout << "[ERROR] El precio debe ser mayor a 0. Intente de nuevo.\n";
        precio = leerDecimal("Ingrese el precio unitario: ");
    }

    // Solicitar y validar cantidad
    int cantidad = leerEntero("Ingrese la cantidad de piezas: ");

    while (cantidad <= 0) {
        std::cout << "[ERROR] La cantidad debe ser mayor a 0. Intente de nuevo.\n";
        cantidad = leerEntero("Ingrese la cantidad de piezas: ");
    }

    // Solicitar y validar descuento
    double descuento = leerDecimal("Ingrese el porcentaje de descuento (0-99): ");

    while (descuento < 0 || descuento > 99) {
        std::cout << "[ERROR] El descuento debe estar entre 0 y 99. Intente de nuevo.\n";
        descuento = leerDecimal("Ingrese el porcentaje de descuento (0-99): ");
    }

    // Paso 3: calcular los importes
    double subtotal = precio * cantidad;
    double montoDescuento = subtotal * descuento / 100.0;
    double baseImponible = subtotal - montoDescuento;
    double iva = baseImponible * 16.0 / 100.0;
    double total = baseImponible + iva;

    // Paso 4: imprimir el ticket
    imprimirTicket(nombre, cantidad, precio, subtotal,
                   montoDescuento, iva, total);

    return 0;
}