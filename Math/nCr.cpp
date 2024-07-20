const int MAX = 2e5 + 5 ;

long long factorial[MAX];
long long inv_factorial[MAX];
// Modular exponentiation function
long long pow(long long base, long long exp, long long mod) {
	long long result = 1;
	base = base % mod;

	while (exp > 0) {
		if (exp % 2 == 1)
			result = (result * base) % mod;

		exp = exp >> 1;
		base = (base * base) % mod;
	}

	return result;
}
// Function to precompute factorials and their inverses
void precomputeFactorials() {
	factorial[0] = 1;
	inv_factorial[0] = 1;

	for (int i = 1; i < MAX; i++) {
		factorial[i] = (factorial[i - 1] * i) % MOD;
		inv_factorial[i] = pow(factorial[i], MOD - 2, MOD); // Using modular exponentiation
	}
}

// Function to find binomial coefficient
int nCr(int n, int r) {
	if (r > n)
		return 0;

	int ans = (factorial[n] * inv_factorial[r]) % MOD;
	ans = (ans * inv_factorial[n - r]) % MOD;

	return ans;
}