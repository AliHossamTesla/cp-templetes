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
	int n ; cin >> n ;
	vector<int>a(n) ;
	for(auto &i : a) cin >> i ;
	int s = accumulate(begin(a),end(a),0) ;
	vector<int>dp(s + 1,0) ;
	dp[0] = 1;
	set<int>ans ;
	for(int i = 0 ; i < n ; i ++)
		for(int j = s ; j >= a[i] ; j --){
			dp[j] |= dp[j - a[i]] ;
			if(dp[j]) ans.insert(j) ;
		}
	cout << ans.size() << "\n" ;
	for(auto i : ans) cout << i << " " ;
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