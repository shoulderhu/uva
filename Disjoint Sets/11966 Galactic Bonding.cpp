#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class disjointSet {

	int A, B;
	struct star {

		int z;
		double x, y;
	}st;
	vector<star> S;

public:
	inline void init() {

		S.clear();
	}

	inline void push(double x, double y, int z) {

		st.x = x, st.y = y, st.z = z;
		S.push_back(st);
	}

	inline int find(int s) {

		if (S[s].z == s) { return s; }
		else { return S[s].z = find(S[s].z); }
	}

	inline double getDistance(const star &a, const star &b) {

		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}

	inline void unit(double D) {

		for (int j = 0; j < S.size(); ++j) {

			for (int k = j + 1; k < S.size(); ++k) {

				if (getDistance(S[j], S[k]) < D) {

					A = find(j), B = find(k);
					S[B].z = A;
				}
			}
		}
	}

	inline int count() {

		int N = 0;

		for (int j = 0; j < S.size(); ++j) {

			if (S[j].z == j) { ++N; }
		}

		return N;
	}
}djs;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, N;
	double  X, Y, D;

	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> N >> D;
		djs.init();

		for (int j = 0; j < N; ++j) {

			cin >> X >> Y;
			djs.push(X, Y, j);
		}

		djs.unit(D);
		cout << "Case " << i << ": " << djs.count() << '\n';
	}

	return 0;
}
