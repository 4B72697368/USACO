#include <iostream> 
using namespace std; 

int main() 
{
    int N; cin >> N;
    int position[N];
    int desired[N];
    int distinct_operations[N+1] = {};

    for (int i = 0; i < N; i++) {
        cin >> position[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> desired[i];
    }

    for (int start = 0; start < N; start++) {
        for (int length = 1; length <= N-start; length++) {
            int after_operation[N];

            for (int i = 0; i < start; i++) {
                after_operation[i] = position[i];
            }

            for (int i = start; i < start+length; i++) {
                after_operation[i] = position[start+length-i];
            }

            for (int i = start+length; i < N; i++) {
                after_operation[i] = position[i];
            }

            int checked_cows = 0;

            for (int i = 0; i < N; i++) {
                if (after_operation[i] == desired[i]) {
                    checked_cows++;
                }
            }

            distinct_operations[checked_cows]++;
        }
    }

    for (int i = 0; i <= N; i++) {
        cout << distinct_operations[i] << endl;
    }

    return 0; 
}