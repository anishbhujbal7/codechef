int minDisturbanceOil(int C, vector<int>& A) {
    int n = A.size();
    int prefix = 0;
    int minPrefix = 0, maxPrefix = 0;

    for (int a : A) {
        prefix += a;
        minPrefix = min(minPrefix, prefix);
        maxPrefix = max(maxPrefix, prefix);
    }

    // Valid range for X that keeps oil within bounds
    int Xmin = max(0, -minPrefix);
    int Xmax = min(C, C - maxPrefix);

    int minDisturbance = INT_MAX;
    int bestX = Xmin;

    for (int X = Xmin; X <= Xmax; X++) {
        int oil = X;
        int disturbance = 0;

        for (int a : A) {
            if (a == 1) {
                if (oil == C) disturbance++;
                else oil++;
            } else {
                if (oil == 0) disturbance++;
                else oil--;
            }
        }

        if (disturbance < minDisturbance) {
            minDisturbance = disturbance;
            bestX = X;
        }
    }

    return bestX;
}
