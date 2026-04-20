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

  long long vorvor = 1;  // fib(i-2)
  long long vor = 1;     // fib(i-1)
  long long aktuell = 0; // fib(i)

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
