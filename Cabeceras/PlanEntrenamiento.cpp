/**********************************************************
* Módulo: PlanEntrenamiento
*
* Este modulo contiene los elementos para leer, almacenar
* e imprimir el plan de entrenamiento.
**********************************************************/

#include <stdio.h>
#include <string.h>
#include "PlanEntrenamiento.h"

void TipoPlan::LeerPlan(CarreraDescansoV vectordeCoD){
  for(int k = 0; k < longitudplan; k++) {
    printf("Actividad del día %d? ", k+1);
    fgets(miPlan[k], longitudfrase, stdin);     //he usado el fgets porque el scanf con %s string daba problemas, solo leia hasta el espacio
    if(strstr(miPlan[k],"descanso") == NULL){
      vectordeCoD[k] = 'C';
    }else{
      vectordeCoD[k] = 'D';
    }
  }
}

void TipoPlan::ImprimirPlan() {
  for(int k = 0; k < longitudplan; k++) {
    printf("\n\nDía %d\n=====\n", k+1);
    printf("%s", miPlan[k]);
  }
  printf("\n");
}
