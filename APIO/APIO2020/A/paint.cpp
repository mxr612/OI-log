#include "paint.h"

#define MXK (100020)

#include <vector>

int f[MXK];
bool subtask[10];

int minimumInstructions(
    int N, int M, int K, std::vector<int> C,
    std::vector<int> A, std::vector<std::vector<int>> B) {
    subtask[1] = true;
    for (int i = 0; i < N; ++i)
        if (++f[C[i]] > 1) subtask[1] = false;
    subtask[2] = subtask[3] = (N <= 500) && (M <= 200);
    for (int i = 0, s; subtask[2] && i < N; ++i)
        if ((s += f[i] * f[i]) > 1000) subtask[2] = false;
    subtask[4] = (N <= 20000) && (M <= 2000);
    if (subtask[1]) {
    } else if (subtask[2]) {
    }
    return -1;
}
