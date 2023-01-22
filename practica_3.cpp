#include <stdio.h>

/*DECLARACI�N DE TIPOS*/

typedef enum TipoDia {
  Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo
};

typedef enum TipoMes {
  Enero, Febrero, Marzo, Abril, Mayo, Junio, Julio,
  Agosto, Septiembre, Octubre, Noviembre, Diciembre
};

typedef struct TipoFecha {
  int dia;
  TipoMes mes;
  int anno;
};

bool AnnoBisiesto(int anno) {

  return ((anno%4==0) && (anno%100!=0)) || (anno%400==0);

}

/* PROCEDIMIENTO SUMA DE D�A DE LA SEMANA C�CLICAMENTE */

TipoDia SumarDias (TipoDia dia, int incDia) {

  const int diasTotales = 7;
  int aux;
  aux = (int(dia) + incDia ) % diasTotales;
  return TipoDia (aux);

}

/*PROCEDIMIENTO PARA CALCULAR EL D�A DE LA SEMANA QUE CORRESPONDE A UNA FECHA*/

TipoDia DiaDeLaSemana ( TipoFecha fecha ) {

  TipoMes mes = fecha.mes;
  int anno = fecha.anno;
  int incDias;
  int incAnnos;
  int incBisiesto;
  const int primerAnno = 1601;
  const TipoDia diaReferencia = Domingo;

  if (mes == Enero) {
    incDias = 0;
  } else if (mes == Febrero){
    incDias = 3;
  } else if (mes == Marzo) {
    incDias = 3;
  } else if (mes == Abril) {
    incDias = 6;
  } else if (mes == Mayo) {
    incDias = 1;
  } else if (mes == Junio) {
    incDias = 4;
  } else if (mes == Julio) {
    incDias = 6;
  } else if (mes == Agosto) {
    incDias = 2;
  } else if (mes == Septiembre) {
    incDias = 5;
  } else if (mes == Octubre) {
    incDias = 0;
  } else if (mes == Noviembre) {
    incDias = 3;
  } else {
    incDias = 5;
  }

  incAnnos = anno - primerAnno;

  incBisiesto = 0;

  for ( int i=1602; i<anno; i++){
    if (AnnoBisiesto(i)) {
        incBisiesto++;
    }

    if (AnnoBisiesto(anno) && ( mes > Febrero)){
        incDias++;
    }

    incDias = incDias + incAnnos + incBisiesto + fecha.dia;
    return SumarDias (diaReferencia, incDias);
  }
}

/* FUNCION PARA CALCULAR CUANTOS D�AS CONTIENE UN MES */

int DiasDelMes (TipoFecha fecha) {
  switch (fecha.mes){
      case Febrero:
        if (AnnoBisiesto (fecha.anno)){
          return (29);
        } else {
          return (28);
        };
        break;
      case Abril:
      case Junio:
      case Septiembre:
        return (30);
        break;
      default:
        return (31);
  }
}



int main() {

  int ref;
  TipoFecha fecha;
  TipoDia primerDia;



  do {
    printf("�Mes (1..12)?");
    fflush(stdin);
    scanf("%d", &fecha.mes);
    printf("\n�A%co (1601..3000)?", 164);
    fflush(stdin);
    scanf("%d", &fecha.anno);
    printf("\n"); /*Salto a una nueva p�gina para imprimir calendario*/
  } while ((fecha.mes < 1 || fecha.mes > 12) || (fecha.anno < 1601 || fecha.anno > 3000)); /* Si no se ponen los meses o a�os dentro de paramentros, se repite la pregunta*/

  /* IMPRIMIR LA CABECERA */

  printf ("\n");


  switch(fecha.mes - 1) {
  case Enero:
  printf("ENERO             ");
  break;
  case Febrero:
  printf("FEBRERO           ");
  break;
  case Marzo:
  printf("MARZO             ");
  break;
  case Abril:
  printf("ABRIL             ");
  break;
  case Mayo:
  printf("MAYO              ");
  break;
  case Junio:
  printf("JUNIO             ");
  break;
  case Julio:
  printf("JULIO             ");
  break;
  case Agosto:
  printf("AGOSTO            ");
  break;
  case Septiembre:
  printf("SEPTIEMBRE        ");
  break;
  case Octubre:
  printf("OCTUBRE           ");
  break;
  case Noviembre:
  printf("NOVIEMBRE         ");
  break;
  case Diciembre:
  printf("DICIEMBRE         ");
  break;
  }

  printf("%d\n", fecha.anno);
  printf("======================\n");
  printf("LU MA MI JU VI | SA DO\n");
  printf("======================\n");

  /* IMPRIMIR RESTO DEL CALENDARIO */

  fecha.mes = TipoMes (fecha.mes - 1);
  primerDia = DiaDeLaSemana(fecha);
  ref = 0;

  /* IMPRIMIR PUNTOS, ESPACIOS O BARRAS ANTES DE EMPEZAR EL D�A 1 */
  for (int i = int (primerDia); i >= 1; i--){

    if (ref % 7 == 5) {
        printf(" | ");
    }
    if ((ref % 7 != 0) && (ref % 7 != 5)) {
      printf(" ");
    }
    printf(" .");
    ref++;

  }


  /* IMPRIMIR LOS D�AS DEL MES */
  for (int i = 0; i < DiasDelMes (fecha); i++){

    if (ref != 0) {
      if (ref % 7 == 0) {
        printf("\n");
      }
    }
    if (ref % 7 == 5) {
      printf(" | ");
    }
    if ((ref % 7 != 0) && (ref % 7 != 5)) {
      printf(" ");
    }
    printf("%2d", i+1);
    ref++;
  }

  /* IMPRIMIR ESPACIOS, PUNTOS O BARRAS EN EL FINAL */

  while (ref % 7 != 0){

    if (ref % 7 == 5) {
        printf(" | ");
    }
    if ((ref % 7 != 0) && (ref % 7 != 5)) {
      printf(" ");
    }
    printf(" .");
    ref++;

  }
  printf("\n");
}
