// Here is an implementation for directed graph.
int n;
vector<vector<int>> adj;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
	color[v] = 1;
	for (int u : adj[v]) {
		if (color[u] == 0) {
			parent[u] = v;
			if (dfs(u))
				return true;
		} else if (color[u] == 1) {
			cycle_end = v;
			cycle_start = u;
			return true;
		}
	}
	color[v] = 2;
	return false;
}

void find_cycle() {
	color.assign(n, 0);
	parent.assign(n, -1);
	cycle_start = -1;

	for (int v = 0; v < n; v++) {
		if (color[v] == 0 && dfs(v))
			break;
	}

	if (cycle_start == -1) {
		cout << "Acyclic" << endl;
	} else {
		vector<int> cycle;
		cycle.push_back(cycle_start);
		for (int v = cycle_end; v != cycle_start; v = parent[v])
			cycle.push_back(v);
		cycle.push_back(cycle_start);
		reverse(cycle.begin(), cycle.end());

		cout << "Cycle found: ";
		for (int v : cycle)
			cout << v << " ";
		cout << endl;
	}
}

// undirected graph
int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v, int par) { // passing vertex and its parent vertex
	visited[v] = true;
	for (int u : adj[v]) {
		if(u == par) continue; // skipping edge to parent vertex
		if (visited[u]) {
			cycle_end = v;
			cycle_start = u;
			return true;
		}
		parent[u] = v;
		if (dfs(u, parent[u]))
			return true;
	}
	return false;
}

void find_cycle() {
	visited.assign(n, false);
	parent.assign(n, -1);
	cycle_start = -1;

	for (int v = 0; v < n; v++) {
		if (!visited[v] && dfs(v, parent[v]))
			break;
	}

	if (cycle_start == -1) {
		cout << "Acyclic" << endl;
	} else {
		vector<int> cycle;
		cycle.push_back(cycle_start);
		for (int v = cycle_end; v != cycle_start; v = parent[v])
			cycle.push_back(v);
		cycle.push_back(cycle_start);

		cout << "Cycle found: ";
		for (int v : cycle)
			cout << v << " ";
		cout << endl;
	}
}
// all Critical Connections
// A critical connection refers to an edge that, upon removal,
// will make it impossible for certain nodes to reach each other through any path.
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
class Solution {
public:
	vector<vector<int>>criticalConnections(int N, vector<int> adj[]){
		DSU d(N) ;
		vector<int> col(N);
		vector<int> s;
		function<void(int,int)> dfs = [&](int u,int p)->void{
			col[u] = 1;
			s.push_back(u) ;
			for (int v : adj[u]) {
				if(v == p) continue; // skipping edge to parent vertex
				else if(col[v] == 1) {
					int i = s.size() - 1 ;
					int x = v ;
					while(i >= 0 and s[i] != v){
						d.Union(x,s[i]) ;
						x = s[i--] ;
					}
				}else if(col[v] == 0) dfs(v,u) ;
			}
			col[u] = 2 ;
			s.pop_back() ;
		};
		dfs(0,-1) ;
		set<vector<int>>st ;
		for(int u = 0 ; u < N ; u ++){
			for(auto v : adj[u]){
				if(!d.inOneSet(u,v)){
					st.insert({min(u,v),max(u,v)}) ;
				}
			}
		}
		vector<vector<int>>ans ;
		for(auto v : st)
			ans.push_back(v) ;
		return ans ;
	}
};