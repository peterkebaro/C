#include <stdio.h>

int main() {

  int lado = 0;

  printf( "�Lado del Rombo? " );
  scanf( "%d", &lado );
  printf("\n");

  if ( lado == 1 ) {

   printf ("@\n");

  }

  if ( lado > 1 ) {

    if ( lado <= 20 ) {

    /* TRIANGULO SUPERIOR */

    for ( int i=1; i <= lado; i++ ){

      /* MITAD IZQUIERDA TRIANGULO SUPERIOR */

      for ( int j=1; j <= (lado - i); j++ ) {

        printf (" ");

      }

      for ( int contCaracter = 1; contCaracter <= i; contCaracter++ ) {

          if ( contCaracter%4 == 1 ) {
            printf("@");
          }
          if ( contCaracter%4 == 2 ) {
            printf(".");
          }
          if ( contCaracter%4 == 3 ) {
            printf("o");
          }
          if ( contCaracter%4 == 0 ) {
            printf(".");
          }
      }

      /* MITAD DERECHA TRIANGULO SUPERIOR */

      for ( int contCaracter = i; contCaracter >= 2; contCaracter-- ) {

          if ( contCaracter%4 == 2 ) {
            printf("@");
          }
          if ( contCaracter%4 == 3 ) {
            printf(".");
          }
          if ( contCaracter%4 == 0 ) {
            printf("o");
          }
          if ( contCaracter%4 == 1 ) {
            printf(".");
          }
      }

  printf ("\n");
  }
  /* TRIANGULO INFERIOR */

  for ( int i=1; i <= lado; i++){

    /* MITAD IZQUIERDA TRIANGULO INFERIOR */

    for ( int j=1; j <= i; j++ ) {

      printf (" ");

    }

    for ( int contCaracter = 1; contCaracter <= (lado - i); contCaracter++ ) {

        if ( contCaracter%4 == 1 ) {
          printf("@");
        }
        if ( contCaracter%4 == 2 ) {
          printf(".");
        }
        if ( contCaracter%4 == 3 ) {
          printf("o");
        }
        if ( contCaracter%4 == 0 ) {
          printf(".");
        }
    }

    /* MITAD DERECHA TRIANGULO INFERIOR */

    for ( int contCaracter = (lado - i); contCaracter >= 2; contCaracter-- ) {

        if ( contCaracter%4 == 2 ) {
          printf("@");
        }
        if ( contCaracter%4 == 3 ) {
          printf(".");
        }
        if ( contCaracter%4 == 0 ) {
          printf("o");
        }
        if ( contCaracter%4 == 1 ) {
          printf(".");
        }
       }
     printf("\n");
   }
  }
 }
}
