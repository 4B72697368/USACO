#include <iostream> 
using namespace std; 

int main() 
{
    int T; cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        int N, A, B; cin >> N >> A >> B;

        bool original[N][N];
        int superimposed[N][N];
        int counter = 0;
        bool invalid = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char pixel; cin >> pixel;
                if (pixel == 'B') {
                    superimposed[j][i] = 2;
                } else if (pixel == 'G') {
                    superimposed[j][i] = 1;
                } else {
                    superimposed[j][i] = 0;
                }

                original[j][i] = false;
            }
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (superimposed[x][y] == 2) {
                    counter++;
                    original[x][y] = true;
                    if (x - A < 0 || y - B < 0 || original[x-A][y-B] == false) {
                        invalid = true;
                    }
                } else if (superimposed[x][y] == 1) {
                    if ((x + A < N && y + B < N && superimposed[x+A][y+B] == 2) || x-A < 0 || y-B < 0 || original[x-A][y-B] == false) {
                        counter++;
                        original[x][y] = true;
                    }
                }
            }
        }

        if (invalid) {
            cout << -1 << endl;
        } else {
            cout << counter << endl;
        }
    }
    return 0; 
} 