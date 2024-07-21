/*
أَمْ خُلِقُوا مِنْ غَيْرِ شَيْءٍ أَمْ هُمُ الْخَالِقُونَ (35)
*/
#include <bits/stdc++.h>
using namespace std;
#define i64 long long
const i64 inf = 1e18 ;
const int MOD = 1e9 + 7 ;
void solve(){
	int n , m ; cin >> n >> m ;
	vector<int>a(n) ;
	for(int &i : a) cin >> i ;
	vector<vector<mi>>dp(n,vector<mi>(m + 2,0)) ;
	if(a[0]) dp[0][a[0]] = 1 ;
	else{
		for(int i = 1 ; i <= m ; i ++) dp[0][i] = 1 ;
	}
	for(int i = 1; i < n ; i ++){
		if(a[i]) dp[i][a[i]] = (dp[i - 1][a[i]]) + (dp[i - 1][a[i] - 1]) + (dp[i - 1][a[i] + 1]) ;
		else{
			for(int j = 1 ; j <= m ; j ++){
				dp[i][j] = (dp[i - 1][j]) + (dp[i - 1][j - 1]) + (dp[i - 1][j + 1]) ;
			}
		}
	}
	mi ans = accumulate(begin(dp[n - 1]), end(dp[n - 1]),mi(0));
	cout << ans << '\n' ;
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