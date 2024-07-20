/*
أَمْ خُلِقُوا مِنْ غَيْرِ شَيْءٍ أَمْ هُمُ الْخَالِقُونَ (35)
*/
#include <bits/stdc++.h>
using namespace std;
#define i64 long long
const i64 inf = 1e18 ;
const int MOD = 1e9 + 7 ;
void solve(){
	int n , x ; cin >> n >> x ;
	vector<int>w(n) ;
	for(auto &i : w) cin >> i ;
	vector<pair<int,int>>dp(1 << n) ;
	dp[0] = make_pair(1,0) ;
	for(int s = 1 ; s < 1 << n ; s ++){
		dp[s] = make_pair(n + 1,0) ;
		for(int it = 0 ; it < n ; it ++){
			if(s & (1 << it)){
				auto opt = dp[s ^ (1 << it)] ;
				if(opt.second + w[it] <= x){
					opt.second += w[it] ;
				}else{
					opt.first ++ ;
					opt.second = min(w[it],opt.second) ; // always opt.second = w[it]
				}
				dp[s] = min(dp[s],opt) ;
			}
		}
	}
	cout << dp[(1 << n) - 1].first << '\n' ;
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