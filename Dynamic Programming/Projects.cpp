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
	vector<int>st(n),en(n),mo(n) ;
	map<int,int>com ;
	for(int i = 0 ; i < n ; i ++){
		cin >> st[i] >> en[i] >> mo[i] ;
		en[i] ++ ;
		com[st[i]] , com[en[i]] ;
	}
	int inc = 1 ;
	for(auto &i : com) i.second = inc ++ ;
	vector<vector<pair<int,int>>>proj(inc) ;
	for(int i = 0 ; i < n ; i ++)
		proj[com[en[i]]].emplace_back(com[st[i]],mo[i]) ;
	vector<i64>dp(inc + 1) ;
	for(int i = 0 ; i < inc ; i ++){
		if(i) dp[i] = dp[i - 1] ;
		for(auto j : proj[i]){
			dp[i] = max(dp[i],dp[j.first] + j.second) ;
		}
	}
	cout << dp[inc - 1] << '\n' ;
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