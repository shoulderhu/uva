#include <iostream>
#include <vector>

using namespace std;

struct person {

	int o, g;
}p;

vector<person> persons;

int getRoot(int i) {

	if (persons[i].g == i) { return i; }
	else {

		return persons[i].g = getRoot(persons[i].g);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, n, m, x, y;
	bool isPossible;

	cin >> N;

	for (int i = 0; i < N; ++i) {

		cin >> n >> m;
		persons.clear();
		isPossible = true;

		for (int j = 0; j < n; ++j) {

			cin >> p.o;
			p.g = j;
			persons.push_back(p);
		}

		for (int j = 0; j < m; ++j) {

			cin >> x >> y;
			x = getRoot(x);
			y = getRoot(y);
			
			if (x != y) {

				persons[y].g = x;
				persons[x].o += persons[y].o;
			}
		}

		for (int j = 0; j < persons.size(); ++j) {

			if (persons[j].g == j && persons[j].o != 0) {

				cout << "IMPOSSIBLE\n";
				isPossible = false;
				break;
			}
		}

		if (isPossible) {

			cout << "POSSIBLE\n";
		}
	}

	return 0;
}
