/*
O(NlogN)
It's possible to pass the tests by checking every single combination but it's quicker to sort then pick the smallest until it terminates.
Most beginners will just brute force it unless they notice the pattern.
*/
#include <bits/stdc++.h>
using namespace std;

int T, N, arr[1000005];

int main() {
    scanf("%d", &T); //getting input
    for (int tc = 1; tc <= T; tc++) { // test cases
        scanf("%d", &N); //input
        for (int i = 0; i < N; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr + N);
        int cur = 1;
        for (int i = 0; i < N; i++) {
            if (arr[i] < cur) continue;
            cur++;
        }
        printf("Case #%d: %d\n", tc, cur - 1);
    }
}
