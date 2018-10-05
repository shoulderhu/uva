#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, X, players;
	bool isLose;

	while (cin >> N >> M) {

		players = 0;

		for (int i = 0; i < N; ++i) {

			isLose = false;

			for (int j = 0; j < M; ++j) {

				cin >> X;
				if (X == 0) { isLose = true; }
			}

			if (!isLose) { ++players; }
		}

		cout << players << endl;
	}

	return 0;
}
