/*
أَمْ خُلِقُوا مِنْ غَيْرِ شَيْءٍ أَمْ هُمُ الْخَالِقُونَ (35)
*/
#include <bits/stdc++.h>
using namespace std;
#define i64 long long
const i64 inf = 1e18 ;
const int MOD = 1e9 + 7 ;
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
void solve(){
	int n , m ; cin >> n >> m ;
	vector<vector<i64>>dp(n + 1,vector<i64>(m + 1,inf)) ;
	for(int i = 1 ; i <= min(n,m) ;i ++) dp[i][i] = 0 ;
	for(int i = 1 ;i <= n ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			if(i != j){
				for(int k = 1 ; k <= max(i,j) ; k ++){
					if(k < i) dp[i][j] = min(dp[i][j],1 + dp[k][j] + dp[i - k][j]) ;
					if(k < j) dp[i][j] = min(dp[i][j],1 + dp[i][j - k] + dp[i][k]) ;
				}
			}
		}
	}
	cout << dp[n][m] << "\n" ;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int tc = 1 ;
//	cin >> tc ;
	while(tc--){
		solve() ;
	}
	return 0;
}