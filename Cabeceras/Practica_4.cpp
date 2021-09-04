/*******************************************************************************************
* Programa: Practica_4
*
* Descripción: Este programa cumple los requisitos del enunciado de la cuarta práctica
*   de Fundamentos de Programación del Grado de Ingeniería Informática.
*   El programa almacena un plan de entrenamiento de 10 días, y tiene las opciones de listar
*   el plan, y mostrar las actividades a modo C o D en un calendario, introduciendo la fecha
*   de inicio prevista para el plan.
********************************************************************************************/
#include <stdio.h>
#include <locale.h>
#include "PlanEntrenamiento.h"
#include "FechayCalendario.h"


int main(){
  char tecla;
  bool ejecucion1 = false; //control de la ejecucion de las opciones 1 y 3, para ejecutar las opciones 2 y 4
  bool ejecucion3 = false;
  TipoFecha mifecha;
  TipoFecha mifecha2;
  TipoPlan miEntrenamiento;
  CarreraDescansoV miCoD;
  int cursorenmiCoD = 0;

  tecla = '0';
  setlocale (LC_ALL, "spanish"); //Evita errores con la ñ, acentos, etc. Lenguaje español


  do {
    printf("\nMENÚ PRINCIPAL:\n  1. Introducir plan de entrenamiento\n  2. Listar plan de entrenamiento\n  3. Introducir fecha de inicio del plan\n  4. Mostrar plan en el calendario\n  5. Salir del programa\n\nElija una opción (1..5): ");
    scanf(" %c", &tecla);
    fflush(stdin); //limpiar el buffer. Si no se limpia, queda el intro almacenado.
    switch (tecla) {
      case '1':
        miEntrenamiento.LeerPlan(miCoD);
        ejecucion1 = true;
        break;
      case '2':
        if(ejecucion1 == true) {
          miEntrenamiento.ImprimirPlan();
        }else{
          printf("\nOpción no disponible. Se debe introducir plan (opción 1).\n");
        }
        break;
      case '3':
        mifecha.LeerFecha();
        mifecha.ImprimirFecha();
        ejecucion3 = true;
        break;
      case '4':
        if(ejecucion1 == true && ejecucion3 == true) {
          mifecha.ImprimirCalendario(miCoD, cursorenmiCoD);
          if(mifecha.NecesidadDeDosMeses() == true){
            mifecha2.CalcularFechaDos(mifecha);
            cursorenmiCoD = mifecha.CalcularCursorParaProxMes(); //calcular la posición por donde tiene que empezar a imprimir C-s y D-s
            mifecha2.ImprimirCalendario(miCoD, cursorenmiCoD);
            cursorenmiCoD = 0; //resetear el cursor para la proxima impresión del calendario
          }
        }else{
          printf("\nOpción no disponible. Se debe introducir plan (opción 1) y fecha de inicio (opción 3).\n");
        }
        break;
    }
  } while (tecla != '5');
}
