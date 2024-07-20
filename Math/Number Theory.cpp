/*
Description: this contains function for number theory
By : @own.
*/
namespace number_theory{
	using ll = long long;
	const int MOD = 1e9 + 7;

	// Function to compute the greatest common divisor (GCD)
	ll gcd(ll a, ll b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	// Function to compute the least common multiple (LCM)
	ll lcm(ll a, ll b) {
		return (a / gcd(a, b)) * b;
	}

	// Function to compute the modular inverse using Extended Euclidean Algorithm
	ll inv(ll a, ll m = MOD) {
		return 1 < a ? m - inv(m % a, a) * m / a : 1;
	}

	// Function to perform modular multiplication
	ll mod_mul(ll a, ll b, ll m = MOD) {
		return (a % m * b % m) % m;
	}

	// Function to compute the modular inverse using Fermat's Little Theorem
	ll mod_inv(ll base, ll m = MOD) {
		ll ans = 1;
		ll expo = m - 2;
		while (expo) {
			if (expo & 1) {
				ans = mod_mul(ans, base, m);
			}
			expo >>= 1;
			base = mod_mul(base, base, m);
		}
		return ans;
	}

	// Function to perform modular addition
	ll add_mod(ll x, ll y, ll m = MOD) {
		return ((x % m) + (y % m)) % m;
	}

	// Function to perform modular subtraction
	ll sub_mod(ll x, ll y, ll m = MOD) {
		return ((x % m) - (y % m) + m) % m;
	}

	// Function to perform modular multiplication (again, for consistency)
	ll prod_mod(ll x, ll y, ll m = MOD) {
		return ((x % m) * (y % m)) % m;
	}

	// Function to compute x^n % m using iterative method
	ll fast_power_mod(ll x, ll n, ll m = MOD) {
		ll result = 1;
		x = x % m;
		while (n > 0) {
			if (n & 1) {
				result = (result * x) % m;
			}
			n = n >> 1;
			x = (x * x) % m;
		}
		return result;
	}

	// Function to compute x^n % MOD using recursive method
	int fast_power(int a, int n, int m = MOD) {
		if (n == 0) return 1;
		else if (n & 1) return (a * fast_power(a, n - 1, m)) % m;
		else return (fast_power((a * a) % m, n / 2, m)) % m;
	}

	// Function to check if a number is prime
	bool is_prime(ll n) {
		if (n <= 1) return false;
		if (n <= 3) return true;
		if (n % 2 == 0 || n % 3 == 0) return false;
		for (ll i = 5; i * i <= n; i += 6) {
			if (n % i == 0 || n % (i + 2) == 0) return false;
		}
		return true;
	}

	// Function to find the number in the series given a selector
	ll get_series(ll x, bool selector) {
		ll l = 0, r = 1e9, ans;
		while (l <= r) {
			ll mid = l + (r - l) / 2;
			ll sum = (mid * (mid + 1)) / 2;
			if (sum == x) {
				ans = mid;
				break;
			} else if (sum < x) {
				if (selector) ans = mid;
				l = mid + 1;
			} else {
				if (!selector) ans = mid;
				r = mid - 1;
			}
		}
		return ans;
	}

	// Function to count the divisors of a number by factorization
	int counting_divisors_by_factorization(ll n) {
		int ans = 1;
		std::map<int, int> mp;
		for (int i = 2; i * i <= n; i++) {
			while (n % i == 0) {
				n /= i;
				mp[i]++;
			}
		}
		if (n != 1) mp[n]++;
		for (auto& I : mp) ans *= (I.second + 1);
		return ans;
	}

	// Function to perform prime factorization
	std::vector<ll> prime_factorization(ll n) {
		std::vector<ll> ans;
		for (int i = 2; i * i <= n; i++) {
			while (n % i == 0) {
				ans.push_back(i);
				n /= i;
			}
		}
		if (n > 1) ans.push_back(n);
		return ans;
	}

	const int SZ = 1e7;
	std::bitset<SZ> is_prime_bitset;
	std::vector<int> primes;

	// Function to perform Sieve of Eratosthenes
	void sieve() {
		is_prime_bitset.set();
		is_prime_bitset[0] = is_prime_bitset[1] = 0;
		for (int i = 4; i < SZ; i += 2) {
			is_prime_bitset[i] = 0;
		}
		for (int i = 3; i * i < SZ; i += 2) {
			if (is_prime_bitset[i]) {
				for (int j = i * i; j < SZ; j += i * 2) {
					is_prime_bitset[j] = 0;
				}
			}
		}
		for (int j = 0; j < SZ; j++) {
			if (is_prime_bitset[j]) {
				primes.push_back(j);
			}
		}
	}

	// Euler's Totient Function (phi)
	ll euler_totient(ll n) {
		ll result = n;
		for (ll p = 2; p * p <= n; ++p) {
			if (n % p == 0) {
				while (n % p == 0) {
					n /= p;
				}
				result -= result / p;
			}
		}
		if (n > 1) {
			result -= result / n;
		}
		return result;
	}

	// Binomial Coefficient C(n, k) % MOD
	ll binomial_coefficient(ll n, ll k, ll m = MOD) {
		if (k > n) return 0;
		if (k == 0 || k == n) return 1;

		std::vector<ll> fact(n + 1, 1);
		for (ll i = 2; i <= n; ++i) {
			fact[i] = fact[i - 1] * i % m;
		}

		return fact[n] * mod_inv(fact[k], m) % m * mod_inv(fact[n - k], m) % m;
	}

	// Function to generate prime factors up to a maximum number using the Sieve of Eratosthenes
	std::vector<int> prime_factors_up_to(int max_n) {
		std::vector<int> spf(max_n + 1);  // Smallest Prime Factor
		for (int i = 1; i <= max_n; ++i) {
			spf[i] = i;
		}
		for (int i = 2; i * i <= max_n; ++i) {
			if (spf[i] == i) {  // i is a prime number
				for (int j = i * i; j <= max_n; j += i) {
					if (spf[j] == j) {
						spf[j] = i;
					}
				}
			}
		}
		return spf;
	}
	// get logb(a)

    double get_log(ll a, int b){
        return log(a) / log(b);
    }

    // Check if number power of another or not

    bool is_power(ll number, int base = 2){
        return (get_log(number, base) - (ll) get_log(number, base) <= EPS);
    }

    // Distination Between two points

    double dist(double x1, double y1, double x2, double y2){
        return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    }

    // Check if it valid triangle with 3 length sides

    bool is_triangle(ll a, ll b, ll c){
        return (a + b > c) && (a + c > b) && (b + c > a) && (a && b && c);
    }

    // Get Slope of two points

    double slope(double x1, double y1, double x2, double y2){
        if(x2 == x1) return 0;
        return (y2 - y1) / (x2 - x1);
    }

    // Check if three points in the same line

    bool is_same_line(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
        return (y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1);
    }

    // Check if is perfect square

    bool is_perfect_square(ll n){
        ll sq = sqrt(n);
        return sq * sq == n;
    }

    // number of coprime witn n from 1 to n

    ll phi(ll n) {
        ll result = n;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {   
                while (n % i == 0)
                    n /= i;
                result -= result / i;
            }
        }
        if (n > 1)
            result -= result / n;
        return result;
    }

    // get the power of prime factor in n
    ll FactN_PrimePowers(ll n, ll p){
        ll powers = 0;
        for(ll i = p; i <= n; i *= p)
            powers += n / i;
        return powers;
    }
}
using namespace number_theory;