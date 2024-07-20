/*The blessings of God to the Prophet Muhammad
* Description: Disjoint Set Union with path compression
 	* and union by size. Add edges and test connectivity.
 	* Use for Kruskal's or Boruvka's minimum spanning tree.
 * Time: O(\alpha(N))
 * Source: CSAcademy, KACTL , Jiangly
 * Verification : https://judge.yosupo.jp/problem/unionfind */
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
	bool Union(int A, int B){
		A = find(A);
		B = find(B);
		if (A == B) return 1;
		if (sz[A] < sz[B]) swap(A, B);
		sz[A] += sz[B];
		par[B] = A ;
		return 0 ;
	}
};
struct Edge{
	int u , v , w ;
	bool operator<(Edge &e){
		return w > e.w ;
	}
};