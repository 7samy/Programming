#include <stdio.h>


void foo(int *p) {
   *p = 10;   // Direkter Zugriff auf den Speicher des Originals
}

int  main() {
   int x = 5;
   foo(&x);   // &x übergibt die Adresse
   // Jetzt ist x = 10
}

