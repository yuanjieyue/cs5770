#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(unsigned long long);
int main(void) {

	long long n = 718548065973745507;
	long long e = 3449;
	long long d = 543546506135745129;
	long long p, q;

	unsigned long long m = e * d;

	long long a = 1;
	long long c = n; 
	unsigned long long b ;

	unsigned long long delta;
	unsigned long long k;
	int found = 0;
	int i = 1;
	while (!found) {
		// since n and d got the same length, we could use this condition as a boundary to avoid infinite loop.
		if (i >= (n / d * e)) break;
		printf("the %d round\n", i);
		k = (m - 1) / i;
		b = k - n - 1;
		unsigned long long delta = b * b - 4 * a * c;
		if (delta >= 0) {
			p = (-b + sqrt(delta)) / (2 * a);
			q = (-b - sqrt(delta)) / (2 * a);
			if (isPrime(p) && isPrime(q)) {
				printf("p value is: %lld\n", p);
				printf("q value is: %lld\n", q);
				found = 1;
			}	
		}
		i++;
	}

	return 0;
}

// return 0 means num is not prime,
// return 1 means num is prime
int isPrime(unsigned long long num) {
     if (num <= 1) return 0;
     if (num % 2 == 0 && num > 2) return 0;
     for(int i = 3; i <= sqrt(num); i += 2) {
         if (num % i == 0) {
             return 0;
	 }
     }
     return 1;
}
