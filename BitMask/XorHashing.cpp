#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
 * description: XOR Hashing.
 * explain: https://codeforces.com/blog/entry/85900
 * source of code: https://usaco.guide/gold/hashing?lang=cpp#implementation-2
 * verification: https://atcoder.jp/contests/abc250/tasks/abc250_e
 */
/** @return a random integer between 0 and INT64_MAX */
long long rng() {
	static std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
	return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n ; cin >> n ;
	vector<int>a(n),b(n) ;
	map<int,int>hs ;
	for(auto &i : a){
		cin >> i ;
		if(!hs.count(i))
			hs[i] = rng() ;
	}
	for(auto &i : b){
		cin >> i ;
		if(!hs.count(i))
			hs[i] = rng() ;
	}

	vector<int>a_xor(n),b_xor(n);
	set<int>seen;
	for(int i = 0 ; i < n ; i ++){
		if(!seen.count(a[i])){
			a_xor[i] = hs[a[i]] ;
			seen.insert(a[i]) ;
		}
		if(i > 0) a_xor[i] ^= a_xor[i - 1] ;
	}
	seen.clear() ;
	for(int i = 0 ; i < n ; i ++){
		if(!seen.count(b[i])){
			b_xor[i] = hs[b[i]] ;
			seen.insert(b[i]) ;
		}
		if(i > 0) b_xor[i] ^= b_xor[i - 1] ;
	}

	int q ; cin >> q ;
	while(q--){
		int x , y ; cin >> x >> y ;
		cout << (a_xor[x - 1] == b_xor[y - 1] ? "Yes\n" : "No\n") ;
	}
	return 0;
}
