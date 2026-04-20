#include <iostream>


// Rukursiv 
long fibonacci(int n){
  if (n<=2){
    return 1;
  }
  else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}


// Iterativ mit array
int fibo_iterativ(int n){
  int* afib;
  afib = new int [n +1];
  afib [1] = 1;
  afib [2] = 1;
  for (int i = 3; i <= n; i++){
    afib[i] = afib [i - 1] + afib[i - 2];
  }
  return afib[n];
}


// Iterativ mit 3 Speicherplaetzen
long long fib3(int n){
  if (n <= 2) return 1;

  long long prev2 = 1;
  long long prev1 = 1;
  long long current = 0;

  for (int i = 3; i <= n; i++){
    current = prev1 + prev2;
    prev2 = prev1;
    prev1 = current;
  }
  return current;
}

  
int main() {
  int testN = 10;

  std::cout << "fib(10)" << std::endl;
  std::cout << "fib2(10)" << std::endl;
  std::cout << "fib3(10)" << std::endl;
  
  return 0;
 }
