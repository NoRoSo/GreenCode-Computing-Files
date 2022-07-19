#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll q;
    cin >> q;
    while(q--) {
        ll n;
        cin >> n;
        ll mn = 2*n; //'n' is the quadrant size, 'mn' is the matrix size.
        ll matrix[mn][mn];

        for (ll i=0;i < mn;i++) { //getting input
            for (ll j=0; j < mn; j++)
                cin >> matrix[i][j];
        }

        ll maxi = -1;
        ll sum = 0;

        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) { //iterate through each cell in the quadrant and finds the maximum possibility that it could be and selects that.
                ll mp = matrix[i][j];
                mp = max(mp, max(matrix[mn-i-1][j], matrix[i][mn-j-1])); //compares with the row flip and column flip possibility.
                mp = max(mp,matrix[mn-i-1][mn-j-1]); //compares with the possibility if you flipped both row and column
                sum += mp;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
