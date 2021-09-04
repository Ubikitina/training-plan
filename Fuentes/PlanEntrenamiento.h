/**********************************************************
* Interfaz del módulo: PlanEntrenamiento
*
* Este modulo contiene los elementos para leer, almacenar
* e imprimir el plan de entrenamiento.
**********************************************************/

#pragma once

const int longitudfrase = 1000;
const int longitudplan = 10;

typedef char FraseV[longitudfrase];
typedef FraseV PlanEntrenamientoV[longitudplan];
typedef char CarreraDescansoV[longitudplan]; //tipo para vector C o D

typedef struct TipoPlan {
  void LeerPlan(CarreraDescansoV vectordeCoD);
  void ImprimirPlan();
private:
  PlanEntrenamientoV miPlan;
};
