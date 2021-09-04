# Objetivo de training-plan
Este repositorio contiene un trabajo realizado en el curso universitario "Fundamentos de Programación". Es un programa que almacena un plan de entrenamiento de 10 días para corredores. 

El programa está desarrollado en el lenguaje C+-. Se trata de un lenguaje propio desarrollado por la UNED con fines didácticos, que está constituido por un subconjunto de los lenguajes C y C++. 

# Descripción
El objetivo de la práctica es crear un programa capaz de almacenar un plan de entrenamiento de 10 días para corredores, para después poder listar en pantalla todas las actividades del plan y tras introducir una fecha de inicio, mostrar a modo resumen los días del plan en el calendario como carrera (C) o descanso (D).
El programa ofrece el menú principal con cinco opciones a elegir mediante el teclado ( 1 | 2 | 3 | 4 | 5 ), explicadas a continuación:
1. **Introducir plan de entrenamiento**: El programa solicitará al usuario que introduzca las actividades a realizar durante cada uno de los 10 días de entrenamiento. Las actividades a realizar se introducirán a modo de texto (vector de caracteres), y la descripción de una actividad tendrá como máximo 1000 caracteres.
2. **Listar plan de entrenamiento**: Al seleccionar esta opción, el programa imprimirá en pantalla las actividades introducidas para los 10 días de entrenamiento, día a día de manera consecutiva.
3. **Introducir fecha de inicio del plan**: La opción 3 sirve para que el usuario indique la fecha que desea iniciar el plan. El programa solicitará el día, mes y año para comenzar el plan.
4. **Mostrar plan en el calendario**: Esta opción muestra a modo resumen los días del plan en el calendario como carrera (C) o descanso (D). Para mostrar C o D, se basa en el plan de entrenamiento introducido, identificando si procede ser un día de descanso o no. Otra característica de esta opción es que si la fecha de inicio se especifica después de los últimos 9 días de un mes, el plan abarcará dos meses, y en este caso específico, imprimirá dos meses.
5. **Salir del programa**: La última opción abortará la ejecución del programa.

# Descripción de los ficheros
Los ficheros subidos se encuentran divididos en dos carpetas: _Cabeceras_ y _Fuentes_. La carpeta _Fuentes_ contiene las implementaciones de las cabeceras (archivadas en la carpeta _Cabeceras_).

La descomposición modular del programa se divide en tres módulos diferentes:
- **Practica_4**: Se trata del programa principal. Contiene la función main.
- **PlanEntrenamiento**: Está compuesto por el fichero de cabecera `PlanEntrenamiento.h` y el fichero de implementación `PlanEntrenamiento.cpp`. Contiene los elementos para leer e imprimir el plan de entrenamiento (opciones 1 y 2 del programa) y la declaración de tipos de vectores necesarios para ello.
- **FechayCalendario**: Está compuesto por el fichero de cabecera `FechayCalendario.h` y el fichero de implementación `FechayCalendario.cpp`. Contiene los elementos relacionados con una fecha. Permite leer e imprimir una fecha e imprimir el calendario correspondiente a la fecha, entre otros.
