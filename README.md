# PROGRAMACIÓN II - RECURSIVIDAD EN C++
```json
{
  "Universidad": "UAGRM",
  "Materia": "Programación II",
  "Docente": "Ing. Contreras V. Juan Carlos",
  "Lenguaje": "C++",
  "Tecnica de Programación": "Recursividad",
  "Entorno de Desarrollo": "Embarcadero Rad Studio 😪"
}
```

## Índice (Contenido del repositorio)
- [Procedimiento para escribir algoritmos recursivos](#procedimiento-para-escribir-algoritmos-recursivos)

## Procedimiento para escribir algoritmos recursivos

### Paso 0: Determinar las entradas y salidas del algoritmo.
**E:** (parámetros de entrada)
<br>
**S:** (variables de salida)

### Paso 1: Identificar la variable de recursión.
-  Es la variable que representa (de alguna forma) la cantidad de datos que
el algoritmo irá a procesar.
- Esta variable puede ser: Explícita o implícita.

### Paso 2: Determinar el dominio de la variable de recursión.

```math
D_n  =  D_ntd  ∩  D_ncp
```
$D_ntd$ = Dominio de la variable por el tipo de dato de la variable.
<br>
$D_ncp$ = Dominio de la variable por el contexto del problema.
$${\infty}$$

<details>
  <summary>Ver ejemplo</summary>
  
Sea $n$ una variable que representa un dia de la semana.

<div align="center">

$D_n$ = byte $∩$ { 1, 2, 3, 4, 5, 6, 7 }
<br>
$D_n$ = [0, 255] $∩$ [1, 7]
<br>
$D_n$ = [1, 7]

</div>
  
</details>

### Paso 3: Caso base
Resolver el problema para el primer valor del dominio 
de la variable de recursión en todas sus situaciones.

### Paso 4: Caso general
Suponiendo que ya existe un proceso que hace lo mismo 
que tiene que hacer, pero la hace para uno menos(procesa n-1 datos).
Llamando a ese proceso (hipótesis) terminar de procesar el dato que falta.
