#include <windows.h>

#include <iostream>

signed main() {
    // #ifndef ONLINE_JUDGE
    freopen("HW.in", "r", stdin);
    // #endif
    std::cout << "Hello, world!" << std::endl;

    int a, b;
    std::cin >> a >> b;
    std::cout << a + b;

    return 0;
}