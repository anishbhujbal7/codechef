#include <iostream>
#include <vector>
using namespace std;

bool canWin(int start, const vector<long long>& villains, int M, long long H) {
    int heroCount = 0;
    long long currentHealth = H;

    for (int i = start; i < villains.size(); ++i) {
        long long v = villains[i];

        if (H > v) {
            // Hero survives with reduced health
            heroCount++;
        } else if (H == v) {
            // Both die
            heroCount++;
        } else {
            // Hero dies, villain lives
            heroCount++;
        }

        if (heroCount > M) return false;
    }
    return true;
}

int main() {
    int N, M;
    long long H;
    cin >> N >> M >> H;

    vector<long long> villains(N);
    for (int i = 0; i < N; ++i) {
        cin >> villains[i];
    }

    int low = 0, high = N, answer = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canWin(mid, villains, M, H)) {
            answer = mid;
            high = mid - 1; // Try fewer removals
        } else {
            low = mid + 1;  // Need to remove more villains
        }
    }

    cout << answer << endl;
    return 0;
}
