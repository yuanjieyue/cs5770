#include <stdio.h>
#include <math.h>

int mod(int, int, int);
int discreteLogarithm(int, int, int);

int main(void) {
	// p a b is the public key.
	int p = 31847;
	int a = 5;
	int b = 26379;
	// x is the message.
	int x = 20543;
	// c and d is the signature.
	int c = 20679;
	int d = 11082;

	// (a). verify the b^c * c^d = a^m (mod)p.
	int exp1 = mod(b, c, p);
	int exp2 = mod(c, d, p);
	int prod = exp1 * exp2 % p;
	int exp3 = mod(a, x, p);
	printf("---------------------\n");
	printf("(a). prod is %d and exp3 is %d\n", prod, exp3);
	if (prod == exp3) {
		printf("Verified\n");
	} else {
		printf("Does not verified\n");
	}
	
	// (b). compute the private key.
	printf("---------------------\n");

	int privateKey = discreteLogarithm(a, b, p);
	printf("(b). the private key a is: %d\n", privateKey);
	int ver = mod(a, privateKey, p);
	printf("the ver num is: %d\n", ver);
	if (ver == b) {
		printf("Verified\n");
	} else {
		printf("Do not verified\n");
	}

	// (c). compute the random number k. 
	printf("--------------------\n");
	int k = discreteLogarithm(a, c, p);
	printf("(c). the k is: %d\n", k);
	return 0;
}


// compute the modular exponent.
int mod(int base, int exponent, int modulus) {
	int res = 1;
	while (exponent > 0) {
		if (exponent % 2 == 1) {
			res = (res * base) % modulus;
		}
		exponent = exponent / 2;
		base = (base * base) % modulus;
	}
	return res;
}

// compute the exponent of in such equation a^x = b (mod p), return the value of x. 
// I found this on the web, it is called bady step - giant step algorithm
// proposed by Shanks in 1971.
int discreteLogarithm(int a, int b, int m)  { 
	int n = (int) sqrt (m) + 1; 
	// Calculate a ^ n  
	int an = 1; 
	for (int i = 0; i<n; ++i) { 
        	an = (an * a) % m; 
	}
  
	// the value array act as a hashmap to store the value appeared.
 	int value[m];
     	for (int i = 0; i < m; i++) {
		value[i] = 0;
	}
  
    	// store all values of a^(n*i) of LHS 
    	for (int p = 1, cur = an; p <= n; p++) { 
        	if (! value[ cur ]) {
            		value[ cur ] = p;
		}
        	cur = (cur * an) % m; 
    	}	 
  
    	for (int q = 0, cur = b; q <= n; q++) { 
        	// Calculate (a ^ j) * b and check 
        	// for collision 
	        if (value[cur]) { 
	            int ans = value[cur] * n - q; 
    		    if (ans < m) {
			    return ans; 
		    }
	        } 
        	cur = (cur * a) % m; 
	} 
	return -1; 
} 
