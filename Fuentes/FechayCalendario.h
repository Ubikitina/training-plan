/**********************************************************
* Interfaz del módulo: FechayCalendario
*
* Este modulo contiene los elementos relacionados con la
* fecha. Permite leer e imprimir una fecha e imprimir el
* calendario correspondiente, entre otras funcionalidades.
**********************************************************/

#pragma once
#include "PlanEntrenamiento.h"

typedef struct TipoFecha {
  void LeerFecha();
  void ImprimirFecha();
  void ImprimirCalendario(CarreraDescansoV vectordeCoD, int cursorVector);

  bool NecesidadDeDosMeses();
  void CalcularFechaDos(TipoFecha fechaUno);
  int CalcularCursorParaProxMes();

private:
  int dia, mes, anno;
  bool FechaCorrecta();
  int CalcularPrimerDia();
  int CalcularDiasTotalesMes();
};

bool EsBisiesto(int aanno); //fuera del TAD porque se utiliza en casos relacionados con años sueltos y no con fechas completas
