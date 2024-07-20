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
	vector<int>a(n) ;
	for(auto &i : a) cin >> i ;
	vector<i64>dp(n + 1,inf),p(n + 1,-1),par(n + 1,-1);
	dp[0] = -inf ;
	for(int i = 0 ; i < n ; i ++){
		i64 l = upper_bound(begin(dp),end(dp),1LL*a[i]) - begin(dp) ;
		if(dp[l - 1] < a[i] and a[i] < dp[l]){
			dp[l] = a[i] ;
			p[l] = i ;
			par[i] = p[l - 1] ;
		}
	}
	int ans = n ,curr = p[n];
	for(int i = 0 ; i <= n ; i ++){
		if(dp[i] == inf){
			ans = i - 1;
			curr = p[i - 1] ;
			break ;
		}
	}
	cout << ans << "\n" ;
//	vector<int>path ;
//	for(;curr != -1 ; curr = par[curr])
//		path.push_back(a[curr]) ;
//	reverse(begin(path),end(path)) ;
//	for(int i : path)
//		cout << i << " " ;
//	cout << '\n' ;

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