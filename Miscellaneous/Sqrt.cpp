/*
 * Description : Square Root Decomposition
 * source : @USACO Guide
 * Verification : https://cses.fi/problemset/task/1648
 */
struct Sqrt{
	int b_sz;
	vector<int>a,b;
	Sqrt(int sqrtn,vector<int>&tmp):b_sz(sqrtn),b(sqrtn,0),a(tmp){
		for(int i = 0 ; i < a.size() ; i ++){
			b[i/b_sz] += a[i] ;
		}
	}
	/** O(1) update to set nums[x] to v */
	void update(int x,int v){
		b[x/b_sz] += -a[x] + v;
		a[x] = v ;
	}
	/** O(sqrt(n)) query for sum of [0, r) */
	int query(int r){
		int ans = 0 ;
		for(int i = 0  ; i < r/b_sz ; i ++) ans += b[i] ;
		for(int i = (r/b_sz) * b_sz ; i < r ; i ++)
			ans += a[i] ;
		return ans ;
	}
	/** O(sqrt(n)) query for sum of [l, r) */
	int query(int l,int r){return query(r) - query(l - 1) ;}
};
