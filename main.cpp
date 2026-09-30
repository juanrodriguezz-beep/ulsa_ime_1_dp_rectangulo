// ¿Recuerdas qué hace iostream?
#include <iostream>

// ¿Por qué este include usa comillas y no < >?
#include "utilerias.h"

// ¿por qué debe existir la función main()?
int main() {
    // 1. Variables (siempre inicializadas)
    //    TODO: ¿qué variables necesitas? ¿De qué tipo? ¿Con qué valor empiezan?
 double ancho = 0;
double alto = 0;
double area = 0;
double perimetro = 0;

    std::cout << "Area y perimetro de un rectangulo\n";


// 2 y 3. Entrada (todavía sin validar)
 ancho = leerDecimal("Escribe el ancho en cm (mayor que 0): ");
    while (ancho <= 0) {
        std::cout << "El ancho debe ser mayor a 0\n";
        ancho = leerDecimal("Escribe el ancho en cm (mayor que 0): ");
alto = leerDecimal("Escribe el alto en cm (mayor que 0): ");

std::cout << "Ancho: " << ancho << " Alto: " << alto << "\n";


    // 2. Entrada: el ancho
    //    TODO: lee el ancho con leerDecimal("...")
    //    TODO: ¿qué haces si es 0 o negativo? ¿Cuántas veces lo vuelves a pedir?

    // 3. Entrada: el alto
    //    TODO: mismo criterio que el ancho

    // 4. Proceso
    //    TODO: calcula el área y el perímetro
    //    ¿Estás seguro(a) del orden en que C++ hace las operaciones?
  area = ancho * alto;
perimetro = 2 * (ancho + alto);



    // 5. Salida
    //    TODO: muestra el área y el perímetro, con sus unidades
    std::cout << "Area: " << area << " cm2\n";
    std::cout << "Perimetro: " << perimetro << " cm\n";

    // ¿Qué significa return 0;?
    return 0;
}