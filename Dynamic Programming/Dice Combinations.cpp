/*
أَمْ خُلِقُوا مِنْ غَيْرِ شَيْءٍ أَمْ هُمُ الْخَالِقُونَ (35)
*/
#include <bits/stdc++.h>
using namespace std;
#define i64 long long
const int MOD = 1e9 + 7 ;
void solve(){
	int n ; cin >> n ;
	vector<mi>dp(n + 1) ;
	dp[0] = 1 ;
	for(int i = 1 ; i <= n ; i ++){
		for(int s = min(i,6) ; s > 0 ; s --){
			dp[i] += dp[i - s] ;
		}
	}
	cout << dp[n] << '\n' ;
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