#include "fatorial.h"

int fatorial (int parametro) {
    int fatorial = 1;
    for (parametro; parametro > 1; parametro --) fatorial *= parametro;
    return fatorial;
}
