#include <iostream>

// 18
// a) n-1
// b) n Speicherplaetze
// c) beide O(n)

int fact_re(int n) {
  if (n <= 1) {
    return 1;
  } else {
    return n * fact_re(--n);
  }
}

// 19
// a) n-1
// b) Konstant viele (Unabhaengig von n)
// c) O(n), O(1)

void fact_it(int n, int result = 1) {
  for (int i = 2; i <= n; i++) {
    result *= i;
  }
  std::cout << result << std::endl;
}

int main() {
  int a;
  std::cin >> a;
  fact_it(a);
}
