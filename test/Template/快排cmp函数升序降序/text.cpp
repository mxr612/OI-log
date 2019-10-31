#include <stdio.h>
#include <stdlib.h>

int qcmp(const void *a, const void *b) {
	return *(int *)b - *(int *)a;
}

int main(int argc, char const *argv[])
{
	int a[10] = {0,1, 2, 3, 4, 5, 6, 7, 8, 9};
	qsort(&a[0], 10, sizeof(a[0]), qcmp);
	for (int i = 0; i < 10; i++) {
		printf("%2d", a[i]);
	}
	return 0;
}

//a-b升序，b-a降序
