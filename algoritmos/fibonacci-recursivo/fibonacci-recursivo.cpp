#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
typedef unsigned long long uint64;
typedef long long int64;

uint64 fibonacci(uint64 n){
  if (n <= 2){
    if(n < 0) return -1;
    return (n ? 1 : 0);
  }
  return fibonacci(n-1) + fibonacci(n-2);
}

std::map<uint64,uint64> memory;
uint64 dpFibonacci(uint64 n){
  if(memory.find(n) != memory.end()) return memory[n];
  if (n <= 2){
    if(n < 0) return -1;
    return memory[n] = (n ? 1 : 0);
  }
  return memory[n] = dpFibonacci(n-1) + dpFibonacci(n-2);
}

int64 fastMemory[10000];
int64 dpfmFibonacci(int64 n){
  if(fastMemory[n] != 0) return fastMemory[n];
  if (n <= 2){
    if(n < 0) return -1;
    return fastMemory[n] = (n ? 1 : 0);
  }
  fastMemory[n] = dpfmFibonacci(n-1) + dpfmFibonacci(n-2);
  return fastMemory[n];
}
