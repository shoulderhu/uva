#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class disjointSet {

	struct people {

		int t;
		string g;
	}peo;
	string A, B;
	unordered_map<string, people> P;

public:

	inline void init() {

		P.clear();
	}

	inline void check(const string &p) {

		if (P.find(p) == P.end()) {

			peo.g = p, peo.t = 1;
			P[p] = peo;
		}
	}

	inline string find(const string &p) {

		if (P[p].g == p) { return p; }
		else { return P[p].g = find(P[p].g); }
	}

	inline int unit(const string &a, const string &b) {

		A = find(a), B = find(b);

		if (A != B) {

			P[B].g = A;
			P[A].t += P[B].t;
		}

		return P[A].t;
	}
}djs;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, F;
	string a, b;

	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> F;
		djs.init();

		for (int j = 0; j < F; ++j) {

			cin >> a >> b;
			djs.check(a);
			djs.check(b);
			cout << djs.unit(a, b) << '\n';
		}
	}

	return 0;
}
