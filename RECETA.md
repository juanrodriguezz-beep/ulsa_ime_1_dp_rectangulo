# Receta: Área y perímetro de un rectángulo

<!-- Escribe aquí tu receta completa en pseudocódigo, ANTES de programar.
     El primer paso es solo un ejemplo del formato; el resto de la receta es completamente tuyo.
     Si la corriges después de probarla a mano, deja aquí la versión final. -->

``` text
1. MOSTRAR "Bienvenido a mi programa de rectangulo"
2. ancho ← leerDecimal("Escribe el ancho en cm (mayor que 0): ")
3. MIENTRAS (ancho <= 0) HACER
      MOSTRAR "El ancho debe ser mayor a 0"
      ancho ← leerDecimal("Escribe el ancho en cm (mayor que 0): ")
   FIN MIENTRAS
4. alto ← leerDecimal("Escribe el alto en cm (mayor que 0): ")
5. MIENTRAS (alto <= 0) HACER
      MOSTRAR "El alto debe ser mayor a 0"
      alto ← leerDecimal("Escribe el alto en cm (mayor que 0): ")
   FIN MIENTRAS
6. area ← ancho * alto
7. perimetro ← 2 * (ancho + alto)
8. MOSTRAR "Area: ", area, " cm2"
   MOSTRAR "Perimetro: ", perimetro, " cm"
9. FIN

```