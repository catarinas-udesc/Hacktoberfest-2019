#include <iostream>
#include <chrono>
#include "fibonacci.hpp"

int main(){
  int rep;
  do{
    int number;
    std::cout << "Numero: ";
    std::cin >> number;
    std::cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    std::cout << "+- (1) Padrao                      -+\n";
    std::cout << "+- (2) Programacao Dinamica        -+\n";
    std::cout << "+- (3) Programacao Dinamica Fast   -+\n";
    std::cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    std::cout << "Operacao: ";
    int op; std::cin >> op;
    auto startTime = std::chrono::high_resolution_clock::now();
    if(op == 1){
      std::cout << "fibonacci(" << number << ") = " << fibonacci(number) << std::endl;
    } else if(op == 2){
      std::cout << "dpFibonacci(" << number << ") = " << dpFibonacci(number) << std::endl;
    } else if(op == 3){
      std::cout << "dpfmFibonacci(" << number << ") = " << dpfmFibonacci(number) << std::endl;
    } else {
      std::cout << "Opcao invalida\n";
      break;
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    std::cout << "Operacao levou " << duration.count() / 1000<< " milisegundos" << std::endl;
    std::cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    std::cout << "+- (1) Sim                         -+\n";
    std::cout << "+- (2) Nao                         -+\n";
    std::cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
    std::cout << "Repetir ? ";
    std::cin >> rep;
  } while (rep == 1);

  return 0;
}
