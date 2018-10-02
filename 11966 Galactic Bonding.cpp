#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct star {

    double X, Y, Z;
}s;
vector<star> stars;

double getDistance(star a, star b) {

    return sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
}

int getRoot(int i) {

    if(stars[i].Z == i) { return i; }
    else {

        return stars[i].Z = getRoot(stars[i].Z);
    }
}

int main() {

    int T, N, a, b;
    double D;

    cin >> T;

    for(int i = 1; i <= T; ++i) {

        cin >> N >> D;
        stars.clear();

        for(int j = 0; j < N; ++j) {

            cin >> s.X >> s.Y;
            s.Z = j;
            stars.push_back(s);
        }

        for(int j = 0; j < stars.size(); ++j) {

            for(int k = j + 1; k < stars.size(); ++k) {

                if(getDistance(stars[j], stars[k]) < D) {

                    a = getRoot(j);
                    b = getRoot(k);
                    stars[b].Z = a;
                }
            }
        }

        N = 0;

        for(int j = 0; j < stars.size(); ++j) {

            if(stars[j].Z == j) {

                ++N;
            }
        }

        cout << "Case " << i << ": " << N << '\n';
    }

    return 0;
}
