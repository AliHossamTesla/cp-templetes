/*
أَمْ خُلِقُوا مِنْ غَيْرِ شَيْءٍ أَمْ هُمُ الْخَالِقُونَ (35)
*/
#include <bits/stdc++.h>
using namespace std;
#define i64 long long
const i64 inf = 1e18 ;
const int MOD = 1e9 + 7 ;
const int N = 1000001 ;
struct mi{
	i64 v; explicit operator i64() const { return v; }
	mi() { v = 0; }
	mi(i64 _v) {
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) {
		return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) {
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) {
		return a.v < b.v; }

	mi& operator+=(const mi& m) {
		if ((v += m.v) >= MOD) v -= MOD;
		return *this; }
	mi& operator-=(const mi& m) {
		if ((v -= m.v) < 0) v += MOD;
		return *this; }
	mi& operator*=(const mi& m) {
		v = v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi pow(mi a, i64 p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0);
		return pow(a,MOD-2); }

	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	mi operator++(int) { v++; if (v == MOD) v = 0; return mi(v); }
	mi operator--(int) { v--; if (v < 0) v = MOD-1; return mi(v); }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
	friend ostream& operator<<(ostream& os, const mi& m) {
		os << m.v; return os;
	}
	friend istream& operator>>(istream& is, mi& m) {
		i64 x; is >> x;
		m.v = x;
		return is;
	}
};
vector<vector<mi>>dp(N,vector<mi>(8,1)) ;
void solve(){
	int n ; cin >> n ;
	mi ans = dp[n - 1][2] + dp[n - 1][6]  ;
	cout << ans << '\n' ;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	for(int i = 1 ; i < N ; i ++){
		for(int j = 0 ; j < 8 ; j ++){
			if(j == 0 or j == 2 or j == 3 or j == 4 or j == 5)
				dp[i][j] =
						dp[i - 1][0] +
						dp[i - 1][1] +
						dp[i - 1][3] +
						dp[i - 1][4] +
						dp[i - 1][5] ;
			else
				dp[i][j] =
						dp[i - 1][2] +
						dp[i - 1][6] +
						dp[i - 1][7] ;

		}
	}
	int tc = 1 ;
	cin >> tc ;
	while(tc--){
		solve() ;
	}
	return 0;
}