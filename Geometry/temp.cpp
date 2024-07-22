#include<bits/stdc++.h>
#include <cmath>
#include <limits>
#include <vector>
using namespace std;
#define int long long
#define ld long double
const ld PI = 3.1415926535897932385 ;
using ftype = ld; // Change to int if needed, but double is generally preferred for geometric calculations.
const ld inf = 1e18 ;

// 2D Point Structure
struct point2d {
	ftype x, y;

	point2d() : x(0), y(0) {}
	point2d(ftype x, ftype y) : x(x), y(y) {}

	point2d& operator+=(const point2d &t) {
		x += t.x;
		y += t.y;
		return *this;
	}
	point2d& operator-=(const point2d &t) {
		x -= t.x;
		y -= t.y;
		return *this;
	}
	point2d& operator*=(ftype t) {
		x *= t;
		y *= t;
		return *this;
	}
	point2d& operator/=(ftype t) {
		x /= t;
		y /= t;
		return *this;
	}

	point2d operator+(const point2d &t) const {
		return point2d(*this) += t;
	}
	point2d operator-(const point2d &t) const {
		return point2d(*this) -= t;
	}
	point2d operator*(ftype t) const {
		return point2d(*this) *= t;
	}
	point2d operator/(ftype t) const {
		return point2d(*this) /= t;
	}
};

// Scalar multiplication of a point
point2d operator*(ftype a, const point2d &b) {
	return b * a;
}

// 3D Point Structure
struct point3d {
	ftype x, y, z;

	point3d() : x(0), y(0), z(0) {}
	point3d(ftype x, ftype y, ftype z) : x(x), y(y), z(z) {}

	point3d& operator+=(const point3d &t) {
		x += t.x;
		y += t.y;
		z += t.z;
		return *this;
	}
	point3d& operator-=(const point3d &t) {
		x -= t.x;
		y -= t.y;
		z -= t.z;
		return *this;
	}
	point3d& operator*=(ftype t) {
		x *= t;
		y *= t;
		z *= t;
		return *this;
	}
	point3d& operator/=(ftype t) {
		x /= t;
		y /= t;
		z /= t;
		return *this;
	}

	point3d operator+(const point3d &t) const {
		return point3d(*this) += t;
	}
	point3d operator-(const point3d &t) const {
		return point3d(*this) -= t;
	}
	point3d operator*(ftype t) const {
		return point3d(*this) *= t;
	}
	point3d operator/(ftype t) const {
		return point3d(*this) /= t;
	}
};

// Scalar multiplication of a 3D point
point3d operator*(ftype a, const point3d &b) {
	return b * a;
}

// Dot Product (2D)
ftype dot(const point2d &a, const point2d &b) {
	return a.x * b.x + a.y * b.y;
}

// Dot Product (3D)
ftype dot(const point3d &a, const point3d &b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Squared Norm (2D)
ftype norm(const point2d &a) {
	return dot(a, a);
}

// Magnitude (2D)
double abs(const point2d &a) {
	return std::sqrt(norm(a));
}

// Projection of vector a onto vector b (2D)
double proj(const point2d &a, const point2d &b) {
	return dot(a, b) / abs(b);
}

// Angle between two vectors (2D)
double angle(const point2d &a, const point2d &b) {
	return std::acos(dot(a, b) / abs(a) / abs(b));
}

// Cross Product (2D)
ftype cross(const point2d &a, const point2d &b) {
	return a.x * b.y - a.y * b.x;
}

// Cross Product (3D)
point3d cross(const point3d &a, const point3d &b) {
	return point3d(a.y * b.z - a.z * b.y,
	               a.z * b.x - a.x * b.z,
	               a.x * b.y - a.y * b.x);
}

// Triple Product (3D)
ftype triple(const point3d &a, const point3d &b, const point3d &c) {
	return dot(a, cross(b, c));
}

struct Vector {
	ftype x, y;
	Vector() : x(0), y(0) {}
	Vector(ftype x, ftype y) : x(x), y(y) {}
	Vector(point2d a, point2d b) : x(b.x - a.x), y(b.y - a.y) {}

	Vector operator+(const Vector &v) const {
		return Vector(x + v.x, y + v.y);
	}
	Vector operator-(const Vector &v) const {
		return Vector(x - v.x, y - v.y);
	}
	Vector operator*(double scalar) const {
		return Vector(x * scalar, y * scalar);
	}
	Vector operator/(double scalar) const {
		return Vector(x / scalar, y / scalar);
	}
};

ftype dot(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}

ftype cross(Vector a, Vector b) {
	return a.x * b.y - a.y * b.x;
}

ftype length(Vector a) {
	return sqrt(dot(a, a));
}

ftype angleBetweenVectors(Vector a, Vector b) {
	return acos(dot(a, b) / (length(a) * length(b)));
}

// Check if point `p` lies on segment `a-b`
bool onSegment(const point2d &a, const point2d &b, const point2d &p) {
	return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

// Orientation of ordered triplet (p, q, r).
// 0 -> p, q and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(const point2d &p, const point2d &q, const point2d &r) {
	ftype val = cross(q - p, r - q);
	if (val == 0) return 0; // collinear
	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// Function to check if two line segments intersect (2D)
bool segmentsIntersect(const point2d &a1, const point2d &b1, const point2d &a2, const point2d &b2) {
	int o1 = orientation(a1, b1, a2);
	int o2 = orientation(a1, b1, b2);
	int o3 = orientation(a2, b2, a1);
	int o4 = orientation(a2, b2, b1);

	// General case
	if (o1 != o2 && o3 != o4)
		return true;

	// Special cases
	// a1, b1 and a2 are collinear and a2 lies on segment a1b1
	if (o1 == 0 && onSegment(a1, b1, a2)) return true;

	// a1, b1 and b2 are collinear and b2 lies on segment a1b1
	if (o2 == 0 && onSegment(a1, b1, b2)) return true;

	// a2, b2 and a1 are collinear and a1 lies on segment a2b2
	if (o3 == 0 && onSegment(a2, b2, a1)) return true;

	// a2, b2 and b1 are collinear and b1 lies on segment a2b2
	if (o4 == 0 && onSegment(a2, b2, b1)) return true;

	return false; // Doesn't fall in any of the above cases
}


// Function to find the intersection of three planes (3D)
point3d intersect(const point3d &a1, const point3d &n1, const point3d &a2, const point3d &n2, const point3d &a3, const point3d &n3) {
	point3d x(n1.x, n2.x, n3.x);
	point3d y(n1.y, n2.y, n3.y);
	point3d z(n1.z, n2.z, n3.z);
	point3d d(dot(a1, n1), dot(a2, n2), dot(a3, n3));
	return point3d(triple(d, y, z),
	               triple(x, d, z),
	               triple(x, y, d)) / triple(n1, n2, n3);
}

// Function to find the centroid of a polygon (2D)
point2d polygonCentroid(const std::vector<point2d> &points) {
	ftype cx = 0, cy = 0;
	ftype area = 0;
	int n = points.size();

	for (int i = 0; i < n; ++i) {
		int j = (i + 1) % n;
		ftype factor = points[i].x * points[j].y - points[j].x * points[i].y;
		cx += (points[i].x + points[j].x) * factor;
		cy += (points[i].y + points[j].y) * factor;
		area += factor;
	}

	area /= 2.0;
	cx /= (6.0 * area);
	cy /= (6.0 * area);

	return point2d(cx, cy);
}

// Function to check if a point is inside a polygon (2D)
int pointInPolygon(const point2d &p, const std::vector<point2d> &points) {
	int n = points.size();
	bool inside = false;

	for (int i = 0, j = n - 1; i < n; j = i++) {
		// Check if the point is on the edge
		if (orientation(points[i], points[j], p) == 0 && onSegment(points[i], points[j], p)) {
			return 1; // Point is on the edge (tangent)
		}

		if ((points[i].y > p.y) != (points[j].y > p.y) &&
		    p.x < (points[j].x - points[i].x) * (p.y - points[i].y) / (points[j].y - points[i].y) + points[i].x) {
			inside = !inside;
		}
	}

	return inside ? 2 : 0; // 2 if inside, 0 if outside
}

// Function to calculate the area of a polygon (2D)
ftype polygonArea(const vector<point2d> &points) {
	int n = points.size();
	ftype area = 0.0;
	for (int i = 0; i < n; ++i) {
		int j = (i + 1) % n;
		area += points[i].x * points[j].y - points[j].x * points[i].y;
	}
	return fabs(area) / 2.0;
}

// LatticePoints in polygon {boundary,inside}.
pair<int,int> latticePoints(const vector<pair<int,int>> &points) {
	int n = points.size();
	vector<point2d>a(n) ;
	int boundaryPoints = 0;
	for (int i = 0; i < n; ++i) {
		a[i].x = points[i].first , a[i].y = points[i].second ;
		int j = (i + 1) % n;
		boundaryPoints += gcd(1LL * abs(points[j].first - points[i].first), 1LL * abs(points[j].second - points[i].second));
	}
	ftype area = polygonArea(a);
	int interiorPoints = static_cast<int>(area - (ld)boundaryPoints/ 2.0 + 1);
	return {boundaryPoints,interiorPoints};
}

// Function to compute the distance from a point to a line segment (2D)
double pointToLineDistance(const point2d &p, const point2d &a, const point2d &b) {
	point2d ap = p - a;
	point2d ab = b - a;
	ftype u = dot(ap, ab) / dot(ab, ab);
	point2d c = a + ab * u;
	return abs(p - c);
}

// Function to rotate a point around another point (2D)
point2d rotatePoint(const point2d &p, const point2d &center, double angle) {
	double s = std::sin(angle);
	double c = std::cos(angle);

	// Translate point back to origin
	point2d p_trans = p - center;

	// Rotate point
	double xnew = p_trans.x * c - p_trans.y * s;
	double ynew = p_trans.x * s + p_trans.y * c;

	// Translate point back
	return point2d(xnew + center.x, ynew + center.y);
}

// intersection between two circles.
ld calculateIntersectionArea(ld r1, ld r2, ld d) {
	if (d >= r1 + r2) {
		// No intersection
		return 0.0;
	}
	if (d <= fabs(r1 - r2)) {
		// One circle is completely inside the other
		ld r_min = std::min(r1, r2);
		return PI * r_min * r_min;
	}

	ld part1 = r1 * r1 * acos((d * d + r1 * r1 - r2 * r2) / (2 * d * r1));
	ld part2 = r2 * r2 * acos((d * d + r2 * r2 - r1 * r1) / (2 * d * r2));
	ld part3 = 0.5 * sqrt((-d + r1 + r2) * (d + r1 - r2) * (d - r1 + r2) * (d + r1 + r2));

	return part1 + part2 - part3;
}

// sweep-line
struct point {
	int x, y;
	bool operator<(const point &p) const {
		return tie(x, y) < tie(p.x, p.y);
	}
};

int dist2(const point &a, const point &b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void solve() {
	int n;
	cin >> n;
	vector<point> points(n);
	for (int i = 0; i < n; ++i) {
		cin >> points[i].x >> points[i].y;
	}

	// Set initial minimum distance to the maximum possible value of a long long integer
	int minSquareDistance = LLONG_MAX;

	// Sort the points based on their X coordinates
	sort(points.begin(), points.end());

	// Create a set to store active points sorted by their Y coordinates
	set<point> activePoints = {{points[0].y, points[0].x}};

	// Initialize a pointer to keep track of points to be removed from the active set
	int j = 0;

	// Iterate over the points
	for (int i = 1; i < n; i++) {

		// Iterator for the active set
		auto it = activePoints.begin();

		// Calculate the distance threshold as the square root of the minimum distance
		int dd = ceil(sqrt(minSquareDistance));

		// Iterate over points until the distance threshold is met
		// Remove points that are too far away
		while (j < i && points[j].x < points[i].x - dd) {
			activePoints.erase({points[j].y, points[j].x});
			j++;
		}

		// Find the lower bound of Y coordinates
		auto lowerBound = activePoints.lower_bound({points[i].y - dd, 0});

		// Find the upper bound of Y coordinates
		auto upperBound = activePoints.upper_bound({points[i].y + dd, 0});

		// Iterate over points within the bounding box
		for (auto it = lowerBound; it != upperBound; it++) {

			// Update the minimum distance if a closer point is found
			minSquareDistance = min(minSquareDistance, dist2({it->y, it->x}, points[i]));
		}
		// Insert the current point into the active set
		activePoints.insert({points[i].y, points[i].x});
	}
	// Print the minimum square distance
	cout << minSquareDistance;
}

// Convex Hull
#define P complex<int>
#define X real()
#define Y imag()

int cross(P &a, P &b, P &c) {
	P u = c - b;
	P v = a - b;
	int cp = (conj(u) * v).Y;
	return (cp > 0) - (cp < 0);
}

vector<P> hull(vector<P> &v) {
	vector<P> ans = {v[0]};
	for (int i = 1; i < v.size(); i++) {
		while (ans.size() > 1) {
			P b = ans.back();
			ans.pop_back();
			P a = ans.back();
			P c = v[i];
			if (cross(a, b, c) != 1) {
				ans.push_back(b);
				break;
			}
		}
		ans.push_back(v[i]);
	}
	return ans;
}

void solve2(){
	int n;
	cin >> n;
	vector<P> v(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[i] = {x, y};
	}
	sort(v.begin(), v.end(),
	     [] (const P &a, const P &b) {
		     return (a.X == b.X) ? (a.Y < b.Y) : (a.X < b.X);
	     });
	vector<P> v1 = hull(v);

	sort(v.begin(), v.end(),
	     [] (const P &a, const P &b) {
		     return (a.X == b.X) ? (a.Y > b.Y) : (a.X > b.X);
	     });
	vector<P> v2 = hull(v);
	for (int i = 1; i < v2.size(); i++) {
		if (v2[i] == v1[0]) break;
		v1.push_back(v2[i]);
	}
	cout << v1.size() << endl;
	for (auto i: v1)
		cout << i.X << " " << i.Y << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	solve2();
	return 0;
}