/*******************************************************************************************
* Programa: Practica_4
*
* Descripci�n: Este programa cumple los requisitos del enunciado de la cuarta pr�ctica
*   de Fundamentos de Programaci�n del Grado de Ingenier�a Inform�tica.
*   El programa almacena un plan de entrenamiento de 10 d�as, y tiene las opciones de listar
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
  setlocale (LC_ALL, "spanish"); //Evita errores con la �, acentos, etc. Lenguaje espa�ol


  do {
    printf("\nMEN� PRINCIPAL:\n  1. Introducir plan de entrenamiento\n  2. Listar plan de entrenamiento\n  3. Introducir fecha de inicio del plan\n  4. Mostrar plan en el calendario\n  5. Salir del programa\n\nElija una opci�n (1..5): ");
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
          printf("\nOpci�n no disponible. Se debe introducir plan (opci�n 1).\n");
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
            cursorenmiCoD = mifecha.CalcularCursorParaProxMes(); //calcular la posici�n por donde tiene que empezar a imprimir C-s y D-s
            mifecha2.ImprimirCalendario(miCoD, cursorenmiCoD);
            cursorenmiCoD = 0; //resetear el cursor para la proxima impresi�n del calendario
          }
        }else{
          printf("\nOpci�n no disponible. Se debe introducir plan (opci�n 1) y fecha de inicio (opci�n 3).\n");
        }
        break;
    }
  } while (tecla != '5');
}
