#include <iostream>
#include <vector>

using namespace std;

class disjointSet {

	struct person {

		int o, g;
	}Person;

	vector<person> P;

public:
	inline void init() {

		P.clear();
	}

	inline void push(int o, int g) {

		Person.o = o, Person.g = g;
		P.push_back(Person);
	}

	inline int find(int p) {

		if (P[p].g == p) { return p; }
		else { return P[p].g = find(P[p].g); }
	}

	inline void unit(int x, int y) {

		x = find(x), y = find(y);

		if (x != y) {

			P[y].g = x;
			P[x].o += P[y].o;
		}
	}

	inline bool check() {

		for (int j = 0; j < P.size(); ++j) {

			if (P[j].g == j && P[j].o != 0) {

				return false;
			}
		}

		return true;
	}
}djs;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, n, m, o, x, y;

	cin >> N;

	for (int i = 0; i < N; ++i) {

		cin >> n >> m;
		djs.init();

		for (int j = 0; j < n; ++j) {

			cin >> o;
			djs.push(o, j);
		}

		for (int j = 0; j < m; ++j) {

			cin >> x >> y;
			djs.unit(x, y);
		}

		if (djs.check()) {

			cout << "POSSIBLE\n";
		}
		else { cout << "IMPOSSIBLE\n"; }
	}

	return 0;
}
