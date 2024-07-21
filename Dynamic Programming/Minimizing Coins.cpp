/*
أَمْ خُلِقُوا مِنْ غَيْرِ شَيْءٍ أَمْ هُمُ الْخَالِقُونَ (35)
*/
#include <bits/stdc++.h>
using namespace std;
#define i64 long long
const i64 inf = 1e18 ;
const int MOD = 1e9 + 7 ;
void solve(){
	int n , x ;
	cin >> n >> x ;
	vector<int>c(n) ;
	for(auto &i : c) cin >> i ;
	vector<i64>dp(x + 1,inf) ;
	dp[0] = 0 ;
	for(int i = 1 ; i <= x ; i ++){
		for(int j = 0 ; j < n ;j ++){
			if(i - c[j] >= 0)
				dp[i] = min(dp[i],1 + dp[i - c[j]]) ;
		}
	}
	cout << (dp[x] == inf ? -1 : dp[x] ) << '\n' ;
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