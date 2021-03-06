#include "hackedgenerator.h"

#include "constants.h"

namespace LCG {

    uint64_t pow( uint64_t base, uint64_t exp )
    {
        base %= P;
        uint64_t result = 1;
        while( exp )
        {
            if ( exp & 1 )
            {
                result = (result * base) % P;
            }
            exp >>= 1;
            base = (base * base) % P;
        }
        return result;
    }

    uint64_t tail(uint64_t n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        uint64_t t = n >> 1ULL;
        return ((pow(A, n - t) % P) * (tail(t) % P) + (tail(n - t) % P)) % P;
    }

    uint64_t HackedGenerator::get(uint64_t n) {

        return ((tail(n + 1) * C) % P + (pow(A, n + 1) * INITIAL) % P) % P;
    }


}
