#include <bits/stdc++.h>
using namespace std;
#define int long long
int dx[]{0, 0, -1, 1}, dy[]{1, -1, 0, 0};
const int inf = 1e18;
const int N = 2e5 + 5;
// source : https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
// a * x + b * y = g(where g is gcd(a,b)).
int ext_gcd(int a,int b,int &x,int &y){
	if(b == 0){
		x = 1 , y = 0 ;
		return a ;
	}
	int x1 , y1 ;
	int g = ext_gcd(b,a%b,x1,y1) ;
	x = y1 ;
	y = x1 - a/b * y1 ;
	return g ;
}
void solve() {
	int n , m ; cin >> n >> m ;
	if(n == 1 and m == 1) cout << "1\n" ;
	else if(n == 1 or m == 1) cout << "2\n" ;
	else if(gcd(n,m) != 1) cout << n * m/gcd(n,m) << "\n" ;
	else{
		int x,y ;
		int g = ext_gcd(n,m,x,y) ;
		// https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity
		cout << min({max(n * x,m * y),
		             max(n * (x + m/g),m * (y - n/g)),
		             max(n * (x - m/g),m*(y + n/g))})
		     << "\n" ;
	}
}