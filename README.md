# Práctica 3: Área y perímetro de un rectángulo
## 1. Descripción del problema (Fase 1)

El programa pide el ancho y el alto de un rectángulo, valida que sean mayores que 0 y muestra su área y su perímetro. Serviría, por ejemplo, para calcular la lámina que se necesita para cortar un gabinete o el perímetro de un marco.

## 2. Entradas y salidas (Fase 1)

**Entradas:**
1. `ancho`: número decimal (`double`), en cm, debe ser mayor que 0.
2. `alto`: número decimal (`double`), en cm, debe ser mayor que 0.

**Salidas:**
1. `area`: número decimal (`double`), en cm2.
2. `perimetro`: número decimal (`double`), en cm.

**Fórmulas** (área y perímetro):
- Área = ancho × alto (es lo que mide la superficie: cuántos cuadritos de 1 cm² caben).
- Perímetro = 2 × (ancho + alto) (es la suma de los cuatro lados: dos anchos y dos altos).

## 3. Restricciones e invariante (Fase 1 y 2)

**Restricciones** (¿qué debe cumplirse?):
- El ancho debe ser mayor que 0.
- El alto debe ser mayor que 0.

**¿Qué hace mi programa con una medida de 0 o negativa? ¿Por qué?**
Muestra un aviso ("El ancho debe ser mayor a 0" o "El alto debe ser mayor a 0") y vuelve a pedir la medida, las veces que haga falta, hasta que sea mayor que 0. Lo hace porque un rectángulo no puede medir 0 ni una cantidad negativa, y sin validar el programa da resultados sin sentido físico (Experimento B).

**¿Quién detecta cada error?** (¿qué revisa `leerDecimal` y qué reviso yo?)
`leerDecimal` revisa el formato: que lo escrito sea un número (rechaza `abc` o `12abc`). Pero `-3` sí es un número, así que lo deja pasar. Yo reviso el rango (que sea mayor que 0) con un `while (ancho <= 0)` y otro para el alto.

**Invariante** (al salir del ciclo que pide el ancho, ¿qué es seguro sobre `ancho`?):
Al salir del ciclo, `ancho` es mayor que 0 (y lo mismo pasa con `alto`). Por eso el área y el perímetro se pueden calcular sin riesgo de obtener resultados negativos o cero.

## 4. Casos resueltos a mano (Fase 1)

| Caso | Ancho | Alto | Área calculada a mano | Perímetro calculado a mano |
|---|---|---|---|---|
| 1 | 5 | 3 | 15 | 16 |
| 2 (cuadrado) | 4 | 4 | 16 | 16 |
| 3 (con decimales) | 2.5 | 4 | 10 | 13 |

## 5. Receta en pseudocódigo (Fase 2)

**¿Probé mi receta a mano con un caso válido y uno inválido?** Sí (con -1, -5 y 3 en el ancho)
**¿Tuve que corregirla?** Sí. Al principio no tenía ciclo, luego tenía la condición al revés (`> 0`) y el ciclo no leía un dato nuevo, y faltaban los cierres de `MIENTRAS`.
**¿Cuántas versiones de mi receta escribí hasta la final?** Varias (ajusta el número a las que recuerdes).

## 6. Cómo compilar y ejecutar (Fase 3)

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o rectangulo
./rectangulo
```

## 7. Ejemplo de ejecución (Fase 3)

```
Area y perimetro de un rectangulo
Escribe el ancho en cm (mayor que 0): 2
Escribe el alto en cm (mayor que 0): 4
Area: 8 cm2
Perimetro: 12 cm
```

## 8. Experimentos (Fase 3)

**Experimento A: ¿qué resultado dio `2 * ancho + alto` con 5 × 3? ¿Por qué?**
Con 5 × 3, `2 * ancho + alto` da 13 en lugar de 16. Yo lo probé en el programa con 2 × 4 y dio 8 en lugar de 12. La causa es que `*` se evalúa antes que `+`: primero se hace `2 * ancho` y luego se suma `alto` una sola vez, así que solo se duplica el ancho. Con paréntesis, `2 * (ancho + alto)`, la suma se hace primero y el resultado es correcto (12 con 2 × 4).

**Experimento B: sin validación, ¿qué mostró el programa con ancho -4 y alto 3? ¿Tiene sentido?**
Lo probé con ancho -12 y alto 22: mostró área -264 cm2 y perímetro 20 cm. No tiene sentido físico, porque un rectángulo no puede tener área negativa. El programa no se detuvo ni avisó de nada (error silencioso). Con -4 y 3 saldría área -12 y perímetro -2. Por eso hay que validar.

**Experimento C (opcional):** No lo realicé.

## 9. Tabla de pruebas (Fase 4)

| Caso | Ancho | Alto | Esperado | Obtenido | ¿Pasó? |
|---|---|---|---|---|---|
| Normal | 5 | 3 | Área 15, perímetro 16 | _____ | _____ |
| Cuadrado | 4 | 4 | Área 16, perímetro 16 | _____ | _____ |
| Decimales | 2.5 | 4 | Área 10, perímetro 13 | _____ | _____ |
| Muy pequeño | 0.1 | 0.1 | Área 0.01, perímetro 0.4 | _____ | _____ |
| Ancho cero | 0 | 3 | vuelve a pedir el ancho | _____ | _____ |
| Alto negativo | 5 | -2 | vuelve a pedir el alto | _____ | _____ |
| Texto | `abc` | 3 | `leerDecimal` vuelve a pedir | _____ | _____ |
| Caso propio 1 | 10 | 1 | Área 10, perímetro 22 | _____ | _____ |
| Caso propio 2 | -3 (luego 6) | 2 | vuelve a pedir el ancho; luego área 12, perímetro 16 | _____ | _____ |

## 10. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | El perímetro con 2 × 4 daba 8 en lugar de 12 | Agregué paréntesis: `2 * (ancho + alto)` | Sí, ahora da 12 |
| 2 | Faltaban las llaves `}` que cierran los `while`, y el título salía después de las lecturas | Cerré cada `while` con su `}` y moví el título antes de las lecturas | Sí (confírmalo al compilar) |

**Reto elegido (opcional):** Reto 1: mensajes que explican por qué se rechazó la medida ("El ancho debe ser mayor a 0").

## 11. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| ¿Cuándo conviene usar `do-while` en lugar de `while` para validar? | Usé `while` con una primera lectura antes del ciclo, y funcionó. |
| ¿Cómo evitar repetir el mismo `while` para ancho y alto? | Copié el esquema; entiendo que se resolverá con funciones propias más adelante. |

## 12. Reflexión final (revísala y ajústala con tus palabras)

**¿Qué aprendí con esta práctica?**
Aprendí qué es una variable y para qué sirve el tipo `double`, la diferencia entre crear una variable y asignarle un valor, cómo funciona `std::cout`, y cómo usar un ciclo `while` para volver a pedir un dato inválido. También aprendí que la precedencia de operadores puede dar resultados incorrectos sin que el compilador avise.

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
Probaría mi receta a mano con más casos antes de programar y compilaría con más frecuencia, después de cada paso pequeño, para encontrar errores como las llaves faltantes más rápido.

**¿Qué fue lo más difícil y cómo lo resolví?**
Lo más difícil fue escribir la receta desde cero, sobre todo el ciclo de validación (la condición de seguir pidiendo y la nueva lectura dentro del ciclo). Lo resolví probándolo a mano con -1, -5 y 3 y corrigiendo la receta.

**¿Qué pregunta me quedó sin responder?**
¿Cómo evito que me den numeros negativos, si doy la condicion que no se pueden numeros menos de 0?

**Diseñar la receta desde cero, ¿fue más fácil o más difícil de lo que esperaba? ¿Qué haría distinto la próxima vez?**
Fue más difícil de lo que esperaba, porque hay que pensar en cada detalle (dónde se guarda el dato, cuándo termina el ciclo). La próxima vez escribiría un borrador completo primero y lo probaría a mano antes de refinarlo.

## 13. Lista de verificación antes de entregar (Fase 5)

- [ ] Llené todas las secciones (no quedan `_____`)
- [ ] Escribí mi receta completa en `RECETA.md` antes de programar
- [ ] Mi programa compila sin advertencias
- [ ] Probé todos los casos de la tabla
- [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ ] No modifiqué `utilerias.h`
- [ ] Hice al menos 3 commits con mensajes claros
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Entregué el enlace de mi fork en Classroom