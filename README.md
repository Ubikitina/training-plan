# Objetivo de training-plan
Este repositorio contiene un trabajo realizado en el curso universitario "Fundamentos de Programación". Es un programa que almacena un plan de entrenamiento de 10 días para corredores. 

# Descripción
El objetivo de la práctica es crear un programa capaz de almacenar un plan de entrenamiento de 10 días para corredores, para después poder listar en pantalla todas las actividades del plan y tras introducir una fecha de inicio, mostrar a modo resumen los días del plan en el calendario como carrera (C) o descanso (D).
El programa ofrece el menú principal con cinco opciones a elegir mediante el teclado ( 1 | 2 | 3 | 4 | 5 ), explicadas a continuación:
1. **Introducir plan de entrenamiento**: El programa solicitará al usuario que introduzca las actividades a realizar durante cada uno de los 10 días de entrenamiento. Las actividades a realizar se introducirán a modo de texto (vector de caracteres), y la descripción de una actividad tendrá como máximo 1000 caracteres.
2. **Listar plan de entrenamiento**: Al seleccionar esta opción, el programa imprimirá en pantalla las actividades introducidas para los 10 días de entrenamiento, día a día de manera consecutiva.
3. **Introducir fecha de inicio del plan**: La opción 3 sirve para que el usuario indique la fecha que desea iniciar el plan. El programa solicitará el día, mes y año para comenzar el plan.
4. **Mostrar plan en el calendario**: Esta opción muestra a modo resumen los días del plan en el calendario como carrera (C) o descanso (D). Para mostrar C o D, se basa en el plan de entrenamiento introducido, identificando si procede ser un día de descanso o no. Otra característica de esta opción es que si la fecha de inicio se especifica después de los últimos 9 días de un mes, el plan abarcará dos meses, y en este caso específico, imprimirá dos meses.
5. **Salir del programa**: La última opción abortará la ejecución del programa.
