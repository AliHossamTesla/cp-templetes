/*
أَمْ خُلِقُوا مِنْ غَيْرِ شَيْءٍ أَمْ هُمُ الْخَالِقُونَ (35)
*/
#include <bits/stdc++.h>
using namespace std;
#define i64 long long
const i64 inf = 1e18 ;
const int MOD = 1e9 + 7 ;
void solve(){
	int n ; cin >> n ;
	vector<int>a(n);
	for(auto &i : a) cin >> i ;
	// dp[i][j] is max score from i to j
	vector<vector<i64>>dp(n,vector<i64>(n)) ;
	for(int l = n - 1;l >= 0 ;l --){
		for(int r = l ; r < n ; r ++){
			if(l == r) dp[l][r] = a[l] ;
			else dp[l][r] = max(a[l] - dp[l + 1][r],a[r] - dp[l][r - 1]) ;
		}
	}
	// x + y == sum , x - y = dif so 2x = (sum + dif) where dif = dp[0][n - 1]
	cout << (accumulate(begin(a),end(a),0LL) + dp[0][n - 1])/2 << '\n' ;
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