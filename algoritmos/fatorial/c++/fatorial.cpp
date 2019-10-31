#include <iostream>
#include <map>

#include "fatorial.hpp"


int main(int args, const char* argv[]) {
	int num;
	double start_time, end_time;

	if (args == 1)
		std::cin >> num;
	else
		num = atoi(argv[1]);

	auto resultado_r = fatR(num);
	auto resultado_s = fatS(num);
	auto resultado_d = fatD(num);

	printf(
		"Fatorial Recursivo: \t%llu\n"
		"Fatorial Sequencial: \t%llu\n"
		"Fatorial Dinamico: \t%llu\n",
		resultado_r, resultado_s, resultado_d
	);
}

long long int fatR(long long int num) {
	if (num <= 1) return 1;

	return num * fatR(num - 1);
}

long long int fatS(long long int num) {
	long long int total = num;

	while (num --> 1) {
		total *= num;
	}

	return total;
}

long long int fatD(long long int num) {
	static std::map<int,int> cache;

	if (num <= 1) return 1;

	if (cache.find(num) == cache.end()) { // Nao foi cacheado
		cache[num] = num * fatD(num - 1);
	}

	return cache[num];
}