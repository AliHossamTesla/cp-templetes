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
	int x ; cin >> x ;
	vector<int>c(n) ;
	for(int &i : c) cin >> i ;
	vector<mi>dp(x + 1,0) ;
	dp[0] = 1;
	for(int i = 1 ; i <= x ; i ++){
		for(int j = 0 ; j < n ; j ++)
			if(i - c[j] >= 0)
				dp[i] += dp[i - c[j]] ;
	}
	cout << dp[x] << '\n' ;
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