# Práctica: Ticket de compra

> Llena cada sección en la fase que se indica. Las instrucciones completas están en `PRACTICA.md`.
> Si una pregunta no aplica (por ejemplo, no hiciste el Experimento C o no tuviste dudas), escribe `No aplica`. Si te sobran filas en una tabla, bórralas.

## 1. Descripción del problema (Fase 1)
<!-- Explica con tus palabras qué hace tu programa y para qué serviría en la vida real. Máximo 4 líneas. -->

Mi programa sirve para registrar la venta de un producto y calcular cuánto debe pagar el cliente. Solicita el nombre, precio, cantidad y descuento, valida que los datos sean correctos y calcula el IVA. Al final muestra un ticket con el desglose de la compra.

## 2. Entradas y salidas (Fase 1)
<!-- Define cada entrada y cada salida, con su tipo de dato y la función de utilerias.h con la que la vas a leer. -->

**Entradas:**

| Entrada | Tipo de dato | Función de `utilerias.h` |
|---|---|---|
| Nombre del producto | string | leerCadena0 |
| precio | double | leerDecimal0 |
| cantidad | int | leerEntero0 |
| descuento | double | leerDecimal0 |

**Salida** (¿qué datos muestra el ticket?):
Muestra el nombre del producto, cantidad de piezas, precio unitario, subtotal, monto del descuento, IVA y total a pagar.

**¿El IVA se calcula sobre el subtotal o sobre lo que queda después del descuento? ¿Por qué?**
Se calcula sobre lo que queda después del descuento, porque primero se resta el descuento al subtotal y después se aplica el IVA al resultado.

## 3. Restricciones e invariante (Fases 1 y 2)

**Restricciones** (¿qué debe cumplirse?):

| Dato | ¿Qué valores son válidos? | ¿Por qué? |
|---|---|---|
| Nombre del producto | texto con el nombre del producto | para identificar que se esta vendiendo |
| Precio | mayor que 0 | porque un producto debe tener un precio positivo |
| Cantidad | entero mayor que 0 | porque se debe vender al emnos una pieza |
| Descuento (%) | entre 0 y 99 | Para evitar descuentos negativos o mayores al límite permitido. |

**¿Qué hace mi programa si el usuario escribe un dato fuera de rango?**
Muestra un mensaje de error y vuelve a solicitar el dato hasta que el usuario escriba un valor válido.

**¿Puede el total salir negativo? ¿Por qué?**
No, porque el precio y la cantidad deben ser mayores que cero y el descuento está limitado entre 0 y 99 por ciento. Además, el IVA se suma al importe después del descuento.

**Invariante 1** (después del ciclo que valida el precio, ¿qué es siempre cierto sobre `precio`?):
Que el precio siempre será mayor que cero.

**Invariante 2** (¿qué relación se cumple siempre entre el subtotal, el descuento, el IVA y el total?):
El total siempre es igual al subtotal menos el descuento, más el IVA calculado sobre la cantidad restante.

## 4. Casos resueltos a mano (Fase 1)

| Caso | Nombre | Precio | Cantidad | Descuento (%) | Subtotal | Descuento ($) | IVA | Total |
|---|---|---|---|---|---|---|---|---|
| 1 (sin descuento) | Cuaderno | 50 | 2 | 0 | 100 | 0 | 16 | 116 |
| 2 (con descuento) | Cuaderno | 50 | 2 | 10 | 100 | 10 | 14.40 | 104.40 |
| 3 (precio con centavos) | Pluma | 19.99 | 1 | 0| 19.99 | 0 | 3.20 | 23.19 |

## 5. Tipo de dato abstracto (Fase 1)

| TDA | Datos (¿qué tiene?) | Operaciones (¿qué se puede hacer con él?) |
|---|---|---|
| Producto | nombre, precio, cantidad | calcular su subtotal |
| venta | subtotal, descuento, iva, total | calcular el importe final e imprimir el ticket |

**Jerarquías:** una tienda vende productos por pieza (un cuaderno) y productos por peso (un kilo de tortillas). ¿Los dos son productos? ¿Qué datos tienen en común y cuál cambia?
Sí, los dos son productos porque se pueden vender en una tienda. Ambos tienen nombre y precio, pero cambia la manera de medirlos: uno se vende por piezas y el otro por peso, como los kilogramos.

## 6. Análisis descendente (Fase 2)
<!-- Completa el árbol. Marca con (ya existe) las partes que ya resuelve una función de utilerias.h o de ticket.h. -->

```
Generar ticket de compra
├── 1. Mostrar bienvenida
├── 2. Pedir los datos
│     ├── 2.1 Pedir el nombre del producto
│     ├── 2.2 Pedir el precio (y validar que sea mayor que 0)
│     ├── 2.3  Pedir la cantidad y validar que sea mayor que 0
│     └── 2.4  Pedir el descuento y validar que esté entre 0 y 99
├── 3. Calcular los importes
│     ├── 3.1 Calcular el subtotal
│     ├── 3.2 Calcular el monto del descuento
    ├── 3.3 Calcular la base imponible y el IVA
     └── 3.4 Calcular el total
└── 4. Imprimir el tikcet de compra
```

**Análisis ascendente: ¿qué partes del árbol ya estaban resueltas por una función que existe? ¿Cuáles?**
Las funciones que ya estaban resueltas eran leerCadena(), leerDecimal(), leerEntero() e imprimirTicket(). Estas funciones ayudan a solicitar los datos y mostrar el resultado sin tener que escribir todo directamente en main().

**¿Alguna parte del árbol hacía más de una cosa? ¿Cómo la dividiste?**
Sí, la parte de calcular los importes realizaba varias operaciones. La dividí en subtotal, descuento, IVA y total para que cada cálculo fuera más fácil de entender y revisar.

## 7. Módulos y receta (Fase 2)

| Módulo | ¿Qué recibe? | ¿Qué devuelve? | ¿Función o procedimiento? |
|---|---|---|---|
| `calcularSubtotal` | precio, cantidad | el subtotal | Función |
| `calcularDescuento` | subtotal, porcentaje | el monto del descuento | Función |
| `calcularIVA` | base imponible, porcentaeje iva | el monto del iva | funcion |
| `imprimirTicket` | 

nombre, cantidad, precio, subtotal, descuento, IVA y total | Nada, solamente muestra el ticket | procedimiento |
| calculartotal | base imponible, iva | el total | funcion |

<!-- Tu receta va en el archivo RECETA.md. Aquí solo responde las preguntas. -->

**¿Probé mi receta a mano con mis 3 casos?** Sí
**¿Tuve que corregirla? ¿Qué cambié?** Sí, revisé los cálculos para asegurarme de que el IVA se aplicara después de restar el descuento y que el total fuera correcto.

## 8. Cómo compilar y ejecutar (Fase 3)

Compilar (desde la carpeta del proyecto):

```bash
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o ticket
```

Ejecutar en macOS:

```bash
./ticket
```

Ejecutar en Windows:

```bash
.\ticket.exe
```

**¿En qué sistema operativo trabajé?** Windows

## 9. Ejemplo de ejecución (Fase 3)
<!-- Pega aquí lo que muestra tu programa en pantalla con el caso 2 de la tabla de pruebas (Cuaderno, 50, 2, 10). -->

```
 SISTEMA DE VENTAS MECATRONICA 
Ingrese el nombre del producto: Cuaderno
Ingrese el precio unitario: 50
Ingrese la cantidad de piezas: 2
Ingrese el porcentaje de descuento (0-99): 10

 TICKET DE VENTA 
Producto: Cuaderno
Cantidad: 2
Precio unitario: $50.00
Subtotal: $100.00
Descuento: $10.00
IVA (16%): $14.40
TOTAL: $104.40
```

## 10. De la receta al código (Fase 3)
<!-- Para cada paso de TU receta, escribe el módulo o la instrucción de C++ que lo implementa. Agrega las filas que necesites. -->

| Paso de la receta | Módulo o instrucción de C++ que lo implementa |
|---|---|
1. Mensaje de bienvenida

std::cout

2. Solicitar el nombre del producto

leerCadena()

3. Solicitar y validar el precio

leerDecimal() y while

4. Solicitar y validar la cantidad

leerEntero() y while

5. Solicitar y validar el descuento

leerDecimal() y while

6. Calcular el subtotal

precio * cantidad

7. Calcular el descuento

subtotal * descuento / 100.0

8. Calcular el IVA

baseImponible * 16.0 / 100.0

9. Calcular el total

baseImponible + iva

10. Imprimir el ticket

imprimirTicket()
**¿Hubo algún paso de mi receta que me costó traducir a C++? ¿Cuál y por qué?**
Sí, la parte de las validaciones con while, porque tuve que entender cómo hacer que el programa volviera a solicitar un dato cuando el usuario escribiera un valor incorrecto.

**Formato del ticket: ¿qué ancho usé en `std::setw` y por qué? ¿Qué pasa si uso un número menor que el largo de la etiqueta más larga?**
En mi código actual no utilicé std::setw, porque imprimí los datos directamente. Si utilizo un ancho menor que el largo de una etiqueta, el texto no se ajustará correctamente y podría perderse la alineación.

**¿Convertí el ancho de las líneas del ticket (36) en una constante? ¿Cómo la llamé? Si no, ¿por qué?**
No, todavía no lo convertí en una constante porque mi versión actual imprime el ticket sin utilizar un ancho fijo de 36 caracteres.

## 11. Experimentos y depuración (Fase 3)

**Experimento A: depuración de `calcularDescuento`**

| Paso de depuración | Lo que hice o encontré |
|---|---|
| 1. Reproduce: ¿con qué datos falló? | 

Se debe probar con un descuento diferente de 0, por ejemplo, 10 %. |
| 2. Aísla: ¿qué valor intermedio estaba mal? (salidas `[DEBUG]`) | El monto del descuento que se obtiene al aplicar el porcentaje al subtotal. |
| 3. Explica: ¿cuál era la causa? | Un error en la fórmula o en la operación utilizada para calcular el porcentaje. |
| 4. Corrige: ¿qué cambiaste? | Revisé la fórmula para multiplicar el subtotal por el porcentaje y dividirlo entre 100. |
| 5. Limpia: ¿comentaste tus salidas `[DEBUG]`? | Se deben comentar o eliminar después de terminar la depuración. |

La prueba con 0 % pasó aunque la función tenía un error. ¿Qué me enseña eso sobre elegir mis casos de prueba?

Me enseña que no es suficiente probar solamente un caso. También hay que utilizar diferentes porcentajes para encontrar errores que no aparecen cuando el descuento es cero.

Experimento B: al cambiar el IVA a 8 %, ¿cuántas líneas tuve que cambiar? ¿Qué mejoraría?

En mi código actual tendría que cambiar dos líneas: la fórmula del IVA y el texto que aparece en el ticket. Mejoraría creando una constante para el porcentaje del IVA, para modificarlo desde un solo lugar.

¿Mi ticket seguía diciendo IVA (16%)? ¿Qué hice al respecto?

Sí, porque el texto estaba escrito directamente en el código. Tendría que cambiarlo a IVA (8%) para que coincida con el nuevo porcentaje.

Experimento C (opcional): al cambiar el parámetro dentro de calcularIVA, ¿cambió la variable de main()? ¿Por qué?

No necesariamente, porque si el parámetro se recibe por valor, solamente cambia la copia que utiliza la función y no la variable original de main().

## 12. La constante "Le atendio" (Fase 3)

**¿Dónde definí la constante con mi nombre?** (marca una)
- [ ] Constante local dentro de `imprimirTicket`
- [ ] Constante a nivel de la librería, en `ticket.h`
- [ ] Función que siempre devuelve la misma cadena

**¿Por qué elegí esa opción?**
Todavía no he implementado esa constante en mi código actual. Una buena opción sería definirla en ticket.h para poder utilizarla en diferentes partes del programa.

**¿Qué otras partes del programa podrían necesitar el nombre de quien atiende? (un mensaje de bienvenida, un ticket de devolución...)**
Podría utilizarse en el mensaje de bienvenida, en el ticket de compra y en los tickets de devolución para identificar quién realizó la atención.

**Si mañana atiende otra persona, ¿en cuántos lugares tengo que cambiar el nombre?**
Si utilizo una constante, solamente tendría que cambiar el nombre en un lugar y el resto del programa utilizaría el nuevo valor.

**Si el nombre se leyera del teclado o de un archivo, ¿cuánto código tendría que cambiar con mi opción?**
Tendría que modificar principalmente la parte donde se obtiene el nombre para leerlo desde el teclado o desde un archivo, en lugar de tenerlo escrito directamente en una constante.

## 13. Tabla de pruebas (Fase 4)
<!-- Los datos de entrada de cada caso están en PRACTICA.md, Fase 4. -->

| # | Caso | Esperado (subtotal / descuento / IVA / total) | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| 1 | Sin descuento | 100.00 / 0.00 / 16.00 / 116.00 | _____ | _____ |
| 2 | Con descuento | 100.00 / 10.00 / 14.40 / 104.40 | _____ | _____ |
| 3 | Descuento de 15 % | 600.00 / 90.00 / 81.60 / 591.60 | _____ | _____ |
| 4 | Precio con centavos | 19.99 / 0.00 / 3.20 / 23.19 | _____ | _____ |
| 5 | Descuento total | 90.00 / 90.00 / 0.00 / 0.00 | _____ | _____ |
| 6 | Precio inválido | vuelve a pedir el precio dos veces; 40.00 / 0.00 / 6.40 / 46.40 | _____ | _____ |
| 7 | Cantidad inválida | vuelve a pedir la cantidad dos veces; 20.00 / 0.00 / 3.20 / 23.20 | _____ | _____ |
| 8 | Descuento inválido | vuelve a pedir el descuento dos veces; 100.00 / 20.00 / 12.80 / 92.80 | _____ | _____ |
| 9 | Texto en el precio | vuelve a pedir el precio una vez; 100.00 / 0.00 / 16.00 / 116.00 | _____ | _____ |
| 10 | Nombre con espacios | muestra el nombre completo; 25.50 / 0.00 / 4.08 / 29.58 | _____ | _____ |
| 11 | Nombre vacío | vuelve a pedir el nombre una vez; 12.00 / 0.00 / 1.92 / 13.92 | _____ | _____ |
| 12 | Caso propio 1: _____ | _____ | _____ | _____ |
| 13 | Caso propio 2: _____ | _____ | _____ | _____ |

**En el caso 4 el IVA real es 3.1984. ¿Por qué mi ticket muestra 3.20?**
_____

**En el caso 10, ¿el ticket siguió alineado? Si no, ¿qué corregí?**
_____

## 14. Generalización (Fase 4)

**¿Qué cálculo hacen `calcularDescuento` y `calcularIVA`? ¿Qué cambia entre una y otra?**
_____

**Receta de `calcularPorcentaje`** (también va en `RECETA.md`):

```text
_____
```

**¿Cómo quedaron el descuento y el IVA después del cambio?**
_____

**¿Volví a correr toda la tabla de pruebas después del cambio? ¿Todo siguió pasando?**
_____

**¿Agregué `calcularPorcentaje` a mi tabla de módulos (sección 7)?** Sí / No

**¿En qué otro programa podría reutilizar `calcularPorcentaje`?**
_____

## 15. Revisión de calidad (Fase 4)

| Principio | Pregunta | ¿Lo cumple? | Evidencia |
|---|---|---|---|
| Correcto | ¿Pasa todas las pruebas de la tabla? | _____ | _____ |
| Robusto | ¿Resiste datos inválidos sin fallar ni terminar? | _____ | _____ |
| Legible | ¿Otra persona entiende tu código sin que se lo expliques? | _____ | _____ |
| Modular | ¿Cada función hace una sola cosa? | _____ | _____ |
| Sin números mágicos | ¿Los valores fijos tienen nombre? | _____ | _____ |
| Fácil de mantener | Si cambia el IVA o quien atiende, ¿cuántas líneas cambias? | _____ | _____ |
| Reutilizable | ¿Alguna de tus funciones serviría en otro programa? | _____ | _____ |

## 16. Reto obligatorio (Fase 4)

**¿Qué reto elegí?** (número y nombre; el 4 no cuenta como obligatorio) _____

**¿Por qué lo elegí?**
_____

**¿Cómo lo resolví? ¿Qué módulos agregué o cambié?**
_____

**¿Hice algún otro reto opcional? ¿Cuál?**
_____

## 17. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | _____ | _____ | _____ |
| 2 | _____ | _____ | _____ |

## 18. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| _____ | _____ |

## 19. Reflexión final

**¿Qué aprendí con esta práctica?**
_____

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
_____

**¿Qué fue lo más difícil y cómo lo resolví?**
_____

**¿Qué pregunta me quedó sin responder?**
_____

**Comparado con las prácticas anteriores, donde todo estaba en `main()`, ¿dividir el programa en módulos me facilitó o me complicó el trabajo? ¿Por qué?**
_____

**¿Cómo encontré el error de `calcularDescuento`? ¿Lo habría encontrado si solo hubiera probado sin descuento?**
_____

## 20. Commits (Fase 5)

**¿Cuántos commits hice durante la práctica?** _____

**Si hice menos de 3, ¿por qué?**
_____

## 21. Lista de verificación antes de entregar (Fase 5)

- [ ] Llené las secciones 1 a 20 (no quedan `_____`; escribí `No aplica` donde corresponde)
- [ ] Completé el árbol de análisis descendente y la tabla de módulos
- [ ] Escribí en `RECETA.md` la receta de `main` y la de cada módulo, antes de programar
- [ ] Cada bloque de `main.cpp` tiene su comentario `// Paso N`, de acuerdo con mi receta
- [ ] Corregí el error de `calcularDescuento` y documenté cómo lo encontré
- [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ ] Mi ticket se ve alineado y termina con la línea "Le atendio:", leída de una constante
- [ ] Justifiqué dónde definí la constante con mi nombre
- [ ] Escribí `calcularPorcentaje` y volví a correr todas las pruebas
- [ ] Hice al menos uno de los retos y lo documenté
- [ ] No queda ninguna salida `[DEBUG]` activa
- [ ] Mi programa compila sin advertencias
- [ ] Probé todos los casos de la tabla
- [ ] Revisé los principios de calidad de mi programa
- [ ] No modifiqué `utilerias.h`
- [ ] Tengo al menos 3 commits con mensajes claros (o justifiqué por qué no)
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Mi fork se llama `ulsa_ime_1_dp_ticket_compra`, mis módulos están en `include/ticket.h` y mi programa principal en `src/main.cpp`
- [ ] Entregué el enlace de mi fork en Classroom
