/*
 * Description : Minimum Spanning Tree - MST
 * source : @Tesla
 * Verification : https://cses.fi/problemset/task/1675
 */
struct DSU{
	vector<int> sz,par;
	DSU(int N) {
		sz = vector<int>(N,1);
		for(int i = 0 ; i < N ; i ++) par.push_back(i) ;
	}
	int find(int u) { return par[u] == u ? u : par[u] = find(par[u]); }
	bool inOneSet(int A, int B) { return find(A) == find(B); }
	int size(int u) { return sz[find(u)]; }
	int sizeU(int u){return sz[u] ;}
	int Union(int A, int B){
		A = find(A);
		B = find(B);
		if (A == B) return 0;
		if (sz[A] < sz[B]) swap(A, B);
		sz[A] += sz[B];
		par[B] = A ;
		return 1;
	}
};
void solve() {
	int n , m ; cin >> n >> m ;
	vector<array<int,3>>edges(m) ; // edges[i] = {w,u,v}
	for(int i = 0 ; i < m ; i ++){
		cin >> edges[i][1] >> edges[i][2] >> edges[i][0] ;
		edges[i][1] -- ; edges[i][2] -- ;
	}
	sort(begin(edges),end(edges)) ;
	DSU d(n) ;
	int ans = 0 , V = 0;
	// adj[u] = {v,w}
	vector<array<int,2>>adj[n] ;
	for(auto [w,u,v] : edges){
		int cr = d.Union(u,v) ;
		ans += cr * w ;
		V += cr ;
	}
	if(V != n - 1) cout << "IMPOSSIBLE\n" ;
	else cout << ans << '\n' ;
}