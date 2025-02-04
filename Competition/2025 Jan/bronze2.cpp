#include <iostream> 
using namespace std; 

typedef long long ll;

int main() 
{
    ll N; cin >> N;
    ll sequence[N];
    ll max = 0;

    for (ll i = 0; i < N; i++) {
        cin >> sequence[i];
        if (sequence[i] > max) {
            max = sequence[i];
        }
    }

    bool records[max][max] = {};

    for (ll i = 0; i < N; i++) {
        bool after_exists = false;
        for (ll after = i+1; after < N; after++) {
            if (sequence[after] == sequence[i]) {
                after_exists = true;
                break;
            }
        }

        if (after_exists) {
            for (ll before = 0; before < i; before++) {
                if (sequence[before] != sequence[i]) {
                    records[sequence[before]-1][sequence[i]-1] = true;
                }
            }
        }
    }

    ll counter = 0;

    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            if (records[i][j]) {
                counter++;
            }
        }
    }

    cout << counter;
    return 0; 
} 