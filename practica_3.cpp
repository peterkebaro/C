#include <stdio.h>

typedef enum TipoDia {
  Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo
};

typedef enum TipoMes {
  Enero, Febrero, Marzo, Abril, Mayo, Junio, Julio,
  Agosto, Septiembre, Octubre, Noviembre, Diciembre
};

/*FUNCI�N PARA IDENTIFICAR SI EL A�O ES BISIESTO O NO*/

bool AnnoBisiesto(int anno) {

  bool bisiesto;

  if ( anno%4==0 && (anno%100==0 || anno%400==0) ) {
    bisiesto = true;
  }
  else {
    bisiesto = false;
  }
  return bisiesto;
}

/*PROCEDIMIENTO PARA IMPRIMIR EL CALENDARIO*/

void ImprimirCalendario() {
  const int longitudColumna = 27;
  const int longitudFila = 10;

  //Primer bucle for para recorrer columnas

  for ( int fila=0; fila < longitudFila; fila++) {

    //Segundo bucle que recorra las filas

    for ( int columna=0; columna < longitudColumna; columna++) {

        printf ("*");

    }

  }


  //pag 244 libro Calendario

  // Crear una funcion que segun el d�a del mes, nos de el mismo en letras

  //Pintar Mes en letras, luego blancos y luego los �ltimos 4 digitos que sean el anno

  //Pintar lineas y dias de semana fijos

  // Aqui calcular con Procedimiento externo en que d�a empieza el mes

}

int main() {

  int mes, anno;

  do {
    printf("�Mes (1..12)?");
    scanf("%d", &mes);
    printf("\n�A%co (1601..3000)?", 164);
    scanf("%d", &anno);
    printf("\n"); /*Salto a una nueva p�gina para imprimir calendario*/
  } while ((mes < 1 || mes > 12) || (anno < 1601 || anno > 3000)); /* Si no se ponen los meses o a�os dentro de paramentros, se repite la pregunta*/

  ImprimirCalendario();

}
