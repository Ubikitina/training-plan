/**********************************************************
* Módulo: FechayCalendario
*
* Este modulo contiene los elementos relacionados con la
* fecha. Permite leer e imprimir una fecha e imprimir el
* calendario correspondiente, entre otras funcionalidades.
**********************************************************/

#include <stdio.h>
#include "FechayCalendario.h"


void TipoFecha::LeerFecha() {
  printf("\nIntroduzca la fecha de inicio del plan:\n");
  do {
    printf("Día? ");
    scanf("%d", &dia);
    printf("Mes (1..12)? ");
    scanf("%d", &mes);
    printf("Año (1601..3000)? ");
    scanf("%d", &anno);

    FechaCorrecta();
    if(!FechaCorrecta()){
      printf("\nLa fecha introducida es incorrecta. Introduzca una fecha correcta:\n");
    }
  }while(!FechaCorrecta());
}

bool TipoFecha::FechaCorrecta() {
  if((anno<=1601) || (anno>=3000)) {
    return false;
  }
  switch (mes) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return (dia <= 31);
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      return (dia <= 30);
      break;
    case 2:
      if (EsBisiesto(anno) == true) {
        return (dia <= 29);
      }else{
        return (dia <= 28);
      };
      break;
    default:
      return false;
  }
}

void TipoFecha::ImprimirFecha() {
  printf("La fecha introducida es: %d/%d/%d\n", dia, mes, anno);
}


int TipoFecha::CalcularDiasTotalesMes(){
  switch (mes) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
      break;
    case 2:
      if (EsBisiesto(anno) == true) {
        return 29;
      }else{
        return 28;
      };
      break;
    default:
      return 0; /*sería un error*/
  }
}

int TipoFecha::CalcularPrimerDia(){
  int ddia1aanno = 0;
  int resultadocalculo; //variable que se devolverá

  /*1º calcular primer dia del año*/
  for (int aux = 1601; aux <= (anno-1); aux++){ //hasta el año anterior al año que nos han pedido
    if(EsBisiesto(aux) == 0){ //si no es bisiesto se desfasa 1 día
      ddia1aanno = ddia1aanno+1;
    }else if(EsBisiesto(aux) == 1){ //si es bisiesto se desfasa 2 dias
      ddia1aanno = ddia1aanno+2;
    }
  }

  /*2º calcular primer dia mmes basado en el primer dia aanno*/
  switch (mes) { //calculo incial como no bisiesto
    case 1:
      ddia1aanno = ddia1aanno+0;
      break;
    case 2:
      ddia1aanno = ddia1aanno+0+3;
      break;
    case 3:
      ddia1aanno = ddia1aanno+0+3+0;
      break;
    case 4:
      ddia1aanno = ddia1aanno+0+3+0+3;
      break;
    case 5:
      ddia1aanno = ddia1aanno+0+3+0+3+2;
      break;
    case 6:
      ddia1aanno = ddia1aanno+0+3+0+3+2+3;
      break;
    case 7:
      ddia1aanno = ddia1aanno+0+3+0+3+2+3+2;
      break;
    case 8:
      ddia1aanno = ddia1aanno+0+3+0+3+2+3+2+3;
      break;
    case 9:
      ddia1aanno = ddia1aanno+0+3+0+3+2+3+2+3+3;
      break;
    case 10:
      ddia1aanno = ddia1aanno+0+3+0+3+2+3+2+3+3+2;
      break;
    case 11:
      ddia1aanno = ddia1aanno+0+3+0+3+2+3+2+3+3+2+3;
      break;
    case 12:
      ddia1aanno = ddia1aanno+0+3+0+3+2+3+2+3+3+2+3+2;
      break;
  }  //no hay default porque no puede haber un mes incorrecto (comprobado previamente)

  /*3º calcular el desfase si es bisiesto*/
  if (EsBisiesto(anno) == 1 && mes >= 3){ //los bisiestos se desfasan un dia a partir de marzo (enero y febrero no)
    ddia1aanno = ddia1aanno + 1;
  }

  resultadocalculo = ddia1aanno%7;
  return resultadocalculo;
}

void TipoFecha::ImprimirCalendario(CarreraDescansoV vectordeCoD, int cursorVector) {
  int ddia1 = 0;
  int ddiasmes = 0;
  int contador = 0;

  EsBisiesto(anno);
  ddiasmes = CalcularDiasTotalesMes();
  ddia1 = CalcularPrimerDia();

  /*Imprimir cabecera*/
  switch (mes) {
    case 1:
      printf("\nENERO                  %4d\n",anno);
      break;
    case 2:
      printf("\nFEBRERO                %4d\n",anno);
      break;
    case 3:
      printf("\nMARZO                  %4d\n",anno);
      break;
    case 4:
      printf("\nABRIL                  %4d\n",anno);
      break;
    case 5:
      printf("\nMAYO                   %4d\n",anno);
      break;
    case 6:
      printf("\nJUNIO                  %4d\n",anno);
      break;
    case 7:
      printf("\nJULIO                  %4d\n",anno);
      break;
    case 8:
      printf("\nAGOSTO                 %4d\n",anno);
      break;
    case 9:
      printf("\nSEPTIEMBRE             %4d\n",anno);
      break;
    case 10:
      printf("\nOCTUBRE                %4d\n",anno);
      break;
    case 11:
      printf("\nNOVIEMBRE              %4d\n",anno);
      break;
    case 12:
      printf("\nDICIEMBRE              %4d\n",anno);
      break;
  }
  printf("===========================\nLU  MA  MI  JU  VI | SA  DO\n===========================\n");

  /*Imprimir PUNTOS INICIALES (for)*/
  for (int aux2 = 1; aux2 <= ddia1; aux2++){
      printf(" .");
      if((aux2+2)%7 == 0){
        printf(" | ");
      }else{
        printf("  ");
      }
    }

  /*Imprimir NUMEROS (for) y C-s o D-s (while)*/
  for (int aux = 1; aux <= ddiasmes; aux++){
    if(aux == dia) { //incluir D o C si aux == dia
      while (cursorVector <= 9 && aux+cursorVector-1 != ddiasmes){  //en vez de un for, se ha hecho un while para meter doble condicion de que pare o cuando termine con el vector o cuando llegue a ddiasmes
        printf(" %c", vectordeCoD[cursorVector]); //mismo codigo que para los numeros, cambiando el printf
        if((aux+contador+ddia1+2)%7 == 0){
          printf(" | ");
        }else{
          printf("  ");
        }
        if((aux+contador+ddia1)%7 == 0){
          printf("\n");
        }
        cursorVector++;
        contador++;
      }
      aux = aux + contador - 1; //se hace -1 porque tenemos el ++ al final de la sentencia while
    }else{
      printf("%2d", aux);
      if((aux+ddia1+2)%7 == 0){
        printf(" | ");
      }else{
        printf("  ");
      }
      if((aux+ddia1)%7 == 0){
        printf("\n");
      }
    }
  }
  /*Imprimir PUNTOS FINALES (for)*/
  for (int aux3 = 1; aux3 <= (7-((ddia1+ddiasmes)%7)); aux3++){
      if(((ddia1+ddiasmes)%7)!=0){ //es para que no imprima nada si el ult. numero termina en domingo
        printf(" .");
        if((aux3+ddiasmes+ddia1+2)%7 == 0){
          printf(" | ");
        }else{
          printf("  ");
        }
      }else{
      }
    }

  printf("\n");
}


bool TipoFecha::NecesidadDeDosMeses(){
  if(CalcularDiasTotalesMes() - dia < 9){
    return true;
  }else{
    return false;
  }
}

void TipoFecha::CalcularFechaDos(TipoFecha fechaUno) {
  dia = fechaUno.dia; //inicializar a fecha1
  mes = fechaUno.mes;
  anno = fechaUno.anno;

  if (mes == 12) {   //calcular fecha2
    anno = anno + 1;
    mes = 1;
  }else{
    anno = anno;
    mes = mes + 1;
  }
    dia = 1;
}

int TipoFecha::CalcularCursorParaProxMes() {
  return CalcularDiasTotalesMes() - dia +1;
}


bool EsBisiesto(int aanno){ // (p^(¬qvr) es bisiesto si es divisible entre cuatro y (no es divisible entre 100 ó es divisible entre 400)
  if (aanno%4 == 0 && aanno%100 != 0 || aanno%400 == 0) {
    return true;
  }else{
    return false;
  }
}
