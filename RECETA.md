# Receta: Ticket de compra

<!-- Escribe aquí tus recetas en pseudocódigo, ANTES de programar.
     Primero la receta del programa principal (main) y después una receta corta para cada módulo que vas a escribir tú.
     El primer paso de main es solo un ejemplo del formato; el resto es tuyo.
     Si las corriges después de probarlas a mano, deja aquí la versión final. -->

## Receta del programa principal (`main`)

<!-- Debe leerse casi igual que tu árbol de análisis descendente (sección 6 del README). -->

1. Mostrar mensaje de bienvenida al sistema de ventas.
2. Pedir el nombre del producto y leerlo (utilizando utilerias.h).
3. Pedir el precio unitario y validar mediante un ciclo que sea mayor a 0.
4. Pedir la cantidad de piezas y validar mediante un ciclo que sea mayor a 0.
5. Pedir el porcentaje de descuento y validar mediante un ciclo que esté entre 0 y 100.
6. Calcular el subtotal llamando a la función calcularSubtotal(precio, cantidad).
7. Calcular el monto del descuento llamando a la función calcularPorcentaje
8. Obtener la base imponible restando el descuento al subtotal.
9. Calcular el IVA llamando a la función calcularPorcentaje
10. Calcular el total final sumando la base imponible y el IVA.
11. Llamar al procedimiento imprimirTicket con todos los valores calculados y los datos del producto.
