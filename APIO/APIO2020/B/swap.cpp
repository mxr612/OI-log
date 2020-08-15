#include "swap.h"

#define MXN (100020)
#define MXM (200020)

#include <math.h>
#include <stdio.h>

#include <set>
#include <vector>

int du[MXM], cer;
bool subtask[10];

int NN, MM;

struct Edge {
    int v, w;
};
std::vector<Edge> edge[MXN];

// Sub1Sub2
std::multiset<int> edgew;
// Sub2
int To[MXN];

void init(int N, int M,
          std::vector<int> U, std::vector<int> V, std::vector<int> W) {
    NN = N, MM = M;
    subtask[1] = true;
    for (int i = 0; i < M; ++i) {
        edge[U[i]].push_back(Edge{V[i], W[i]}), edge[V[i]].push_back(Edge{V[i], W[i]});
        edgew.insert(W[i]), To[V[i]] = W[i];
        if (++du[U[i]] > 2 || ++du[V[i]] > 2) subtask[1] = false;
    }
    subtask[2] = (M == N - 1) && du[0] == N - 1;
    subtask[3] = (N <= 1000) && (M <= 2000);
    subtask[5] = M == N - 1;
}

int getMinimumFuelCapacity(int X, int Y) {
    if (subtask[1]) {
        if (MM == NN - 1)
            return -1;
        return *edgew.rbegin();
    } else if (subtask[2]) {
        int ans, ed;
        if (Y < X) X ^= Y ^= X ^= Y;
        if (X == 0) {
            edgew.erase(edgew.find(To[Y]));
            ans = std::max(To[Y], ed = (*(edgew.begin()))), edgew.erase(edgew.find(ed));
            ans = std::max(ans, *edgew.begin());
            edgew.insert(To[Y]), edgew.insert(ed);
            return ans;
        } else {
            edgew.erase(edgew.find(To[X])), edgew.erase(edgew.find(To[Y]));
            ans = std::max(std::max(To[X], To[Y]), *edgew.begin());
            edgew.insert(To[X]), edgew.insert(To[Y]);
            return ans;
        }
    } else if (subtask[5]) {
    }

    return -1;
}