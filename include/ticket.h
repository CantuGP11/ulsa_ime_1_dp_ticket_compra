inline double calcularSubtotal(double precio, int cantidad) {
    return precio * cantidad;
}

// Recibe: el subtotal y el porcentaje de descuento (de 0 a 100).
// Devuelve: el monto del descuento en pesos.
inline double calcularDescuento(double subtotal, double porcentaje) {
    return subtotal * porcentaje / 100.0;
}

// TODO: calcularIVA
//       ¿Qué recibe? ¿Qué devuelve? ¿Dónde guardas la tasa del 16 %?
inline double calcularIVA(double base, double tasa) {
    // Si la tasa te la pasan como porcentaje (ej. 16.0), la divides entre 100:
    return base * (tasa / 100.0);
}

// TODO: imprimirTicket
//       ¿Es función o procedimiento? ¿Qué datos necesita para imprimir el ticket?

inline void imprimirTicketImpl(const std::string& nombre, int cantidad, double precio, double subtotal, double descuentoMonto, double iva, double total) {
    std::cout << " TICKET DE VENTA MECATRÓNICA \n";
    std::cout << "Producto: " << nombre << "\n";
    std::cout << "Precio U: $" << precio << "\n";
    std::cout << "Cantidad: " << cantidad << "\n";
    std::cout << "Subtotal: $" << subtotal << "\n";
    std::cout << "Descuento: -$" << descuentoMonto << "\n";
    std::cout << "IVA: $" << iva << "\n"; // Usamos la variable directa
    std::cout << "------------------------\n";
    std::cout << "TOTAL:    $" << total << "\n";
    std::cout<< "Gracias por su compra :)";
}

inline void imprimirTicket(const std::string& nombre, int cantidad, double precio, double subtotal, double descuentoMonto, double iva, double total) {
    imprimirTicketImpl(nombre, cantidad, precio, subtotal, descuentoMonto, iva, total);
}
