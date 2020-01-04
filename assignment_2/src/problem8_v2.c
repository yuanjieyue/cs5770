#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int isPrime(long long num);

int main(void) {
	long long n = 718548065973745507;
	double root = sqrt(n);
//	printf("the sqrt is %f\n", root);
	long long p = (long long) root;
//	printf("the long long value is %lld\n", p);

	int found = 0;
	long long q;
	int e = 3449;
	long long d = 543546506135745129;
	unsigned long long k = e * d;
	unsigned long long m;
	while (p >= 0 && !found) {
		printf("p is %lld\n", p);
		if (isPrime(p) && m % p == 0) {
			q = m / p;
			if (isPrime(q)) {
				m = (p - 1) * (q - 1);
				if (k % m == 1) {
					found = 1;
				}	
			}
		}
		p--;
	}
	if (found) {
		printf("Found the p and q\n");
		printf("p is %lld\n", p);
		printf("q is %lld\n", q);
	}	

	return 0;
}

// 0 -> not prime
// 1 -> is prime
int isPrime(long long num) {
	if (num <= 0) return 0;
	if (num % 2 == 0 && num > 2) return 0;
	int i;
	for (i = 3; i <= sqrt(num); i += 2) {
		if (num % i == 0) {
			return 0;
		}
	}

	return 1;
}
