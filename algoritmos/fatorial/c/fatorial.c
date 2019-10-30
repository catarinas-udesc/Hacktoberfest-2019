#include "fatorial.h"

long long int fatorial (long long int parametro) {
    
    long long int fatorial = 1;
    
    for (parametro; parametro > 1; parametro --) {
        fatorial *= parametro;
    }
    
    return fatorial;
}
