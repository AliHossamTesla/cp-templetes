// v-1 
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
// v-2 
void solve(){
	int n ; cin >> n ;
	int x ; cin >> x ;
	vector<int>c(n) ;
	for(int &i : c) cin >> i ;
	vector<mi>dp(x + 1,0) ;
	dp[0] = 1;
	for(int j = 0 ; j < n ; j ++){
		for(int s = c[j] ; s <= x ; s ++) // have infinite supply (can use 2 twice for example)
			dp[s] += dp[s - c[j]] ;
	}
	cout << dp[x] << '\n' ;
}