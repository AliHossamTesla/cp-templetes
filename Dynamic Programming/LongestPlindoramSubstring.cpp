int LCS(string s,string t){
	vector<int>dp(t.size() + 1,0);
	for(int i = 1 ; i <= s.size() ; i ++){
		vector<int>ndp(t.size() + 1,0);
		for(int j = 1 ; j <= t.size() ; j ++){
			if(s[i - 1] == t[j - 1])
				ndp[j] = 1 + dp[j - 1];
			else
				ndp[j] = max(ndp[j - 1],dp[j]) ;
		}
		dp = ndp ;
	}
	return dp.back() ;
}
int longestPalinSubseq(string A) {
	string B = A ;
	reverse(begin(A),end(A)) ;
	return LCS(A,B) ;
}
