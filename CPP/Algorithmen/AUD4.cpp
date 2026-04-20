#include <chrono>
#include <iostream>

long long fib_rekursiv(int n) {
  if (n <= 2)
    return 1;
  return fib_rekursiv(n - 1) + fib_rekursiv(n - 2);
}

long long fib_iterativ_array(int n) {
  if (n <= 2)
    return 1;

  long long *fib = new long long[n + 1];
  fib[1] = 1;
  fib[2] = 1;

  for (int i = 3; i <= n; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  long long result = fib[n];
  delete[] fib;
  return result;
}

long long fib_optimiert(int n) {
  if (n <= 2)
    return 1;

  long long vorvor = 1;
  long long vor = 1;
  long long aktuell = 0;

  for (int i = 3; i <= n; ++i) {
    aktuell = vor + vorvor;
    vorvor = vor;
    vor = aktuell;
  }
  return aktuell;
}

double zeit_messen(long long (*funktion)(int), int n) {
  auto start = std::chrono::high_resolution_clock::now();
  long long erg = funktion(n);
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> diff = end - start;
  std::cout << "Ergebnis fib(" << n << ") = " << erg << std::endl;
  return diff.count();
}

int main() {

  std::cout << "--- Test mit n = 10 ---" << std::endl;
  std::cout << "Rekursiv:      " << fib_rekursiv(10) << std::endl;
  std::cout << "Iterativ Array:" << fib_iterativ_array(10) << std::endl;
  std::cout << "Optimiert:     " << fib_optimiert(10) << std::endl;
  std::cout << std::endl;

  std::cout << "--- Zeitmessung ---" << std::endl;

  int test_n = 10;

  std::cout << "Variante 1 (Rekursiv):" << std::endl;
  double t1 = zeit_messen(fib_rekursiv, test_n);
  std::cout << "   Zeit: " << t1 << " Sekunden" << std::endl << std::endl;

  std::cout << "Variante 2 (Iterativ Array):" << std::endl;
  double t2 = zeit_messen(fib_iterativ_array, test_n);
  std::cout << "   Zeit: " << t2 << " Sekunden" << std::endl << std::endl;

  std::cout << "Variante 3 (Optimiert):" << std::endl;
  double t3 = zeit_messen(fib_optimiert, test_n);
  std::cout << "   Zeit: " << t3 << " Sekunden" << std::endl << std::endl;

  return 0;
}

// 13c)
// ZK: O(2 hoch n), O(n), O(n)
// SK: O(n), O(n), O(1)

// 14a)

int Vektor::bin_suche(int sw) {

  int l_u = 0, l_o = dimension - 1;
  while (l_u <= l_o) {
    int mitte = (l_u + l_o) / 2;
    if (daten[mitte] == sw)
      return mitte;
    else if (daten[mitte] < sw)
      l_u = mitte + 1;
    else
      l_o = mitte - 1;
  }
  return -1;
}

// b)
// im schlechtesten Fall log2(n)
// bei Array Leange von 2(hoch)k - 1 -> k Verlgeiche
// Log2(n) + 1

// 15
// a)

long T_rekursiv(int n) {
  if (n == 1)
    return 1;
  else
    return n * T_rekursiv(n - 1) + n;
}

// T(1)=1
// T(2)=2⋅T(1)+2=2⋅1+2=4
// T(3)=3⋅T(2)+3=3⋅4+3=15
// T(4)=4⋅T(3)+4=4⋅15+4=64
// T(5)=5⋅T(4)+5=5⋅64+5=325

// b)

long T_iterativ(int n) {
  long t = 1; // T(1)
  for (int i = 2; i <= n; i++) {
    t = i * t + i;
  }
  return t;
}

// c) O(n!)
// d) n - 1 rekursive Aufrufe
// e) O(n)
