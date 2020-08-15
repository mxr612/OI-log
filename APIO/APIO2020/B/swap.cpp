#include "swap.h"

#define MXN (100020)
#define MXM (200020)

#include <math.h>
#include <stdio.h>

#include <vector>

int du[MXM], cer;
bool subtask[10];

int NN, MM;

struct Edge {
    int v, w;
};
std::vector<Edge> edge[MXN];

// Sub1
int mxw;

void init(int N, int M,
          std::vector<int> U, std::vector<int> V, std::vector<int> W) {
    NN = N, MM = M;
    subtask[1] = true;
    for (int i = 0; i < M; ++i) {
        edge[U[i]].push_back(Edge{V[i], W[i]}), edge[V[i]].push_back(Edge{V[i], W[i]});
        mxw = std::max(mxw, W[i]);
        if (++du[U[i]] > 2 || ++du[V[i]] > 2) subtask[1] = false;
    }
    subtask[2] = (M == N - 1) && du[0] == N;
    subtask[3] = (N <= 1000) && (M <= 2000);
    subtask[5] = M == N - 1;
}

int getMinimumFuelCapacity(int X, int Y) {
    if (subtask[1]) {
        if (MM == NN - 1)
            return -1;
        return mxw;
    } else if (subtask[2]) {
        if (Y < X) X ^= Y ^= X ^= Y;
        if (X == 0) {
        }
    }
    return -1;
}