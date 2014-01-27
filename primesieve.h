#ifndef _PRIME_SIEVE_H
#define _PRIME_SEIVE_H

#include <stdlib.h>
#include <limits.h>

// Sieve of Eratosthenes generates prime numbers.
// Returns an array of length limit, containing boolean values:
// 1 = index is composite, 0 = index is prime.
// comp must be freed in the caller once finished!
unsigned char* primesieve(unsigned long long int limit) {
  unsigned char* comp = NULL;
  if (limit < ULLONG_MAX) {
    comp = (unsigned char*) calloc(limit, sizeof(unsigned char));
    unsigned long long int i, j;
    comp[0] = comp[1] = 1;  // 0, 1 not prime
    for (i = 4; i < limit; i += 2)
      comp[i] = 1;          // Even numbers > 2 are not prime
    for (i = 3; i * i < limit; i += 2)
      if (! comp[i])        // Skip numbers already marked not prime
        for (j = i * i; j < limit; j += i)
          comp[j] = 1;      // Odd numbers that are mutiples are not prime
  }
  return comp;
}

#endif // _PRIME_SIEVE_H
