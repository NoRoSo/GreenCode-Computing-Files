//disjoint set
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findset(int x, vector <int> &r) {
    if (r[x]==x)
        return(x);
    else
        return(findset(r[x],r));
}

int main() {
    int n;
    cin >> n;
    vector <int> root(2*n+1);
    vector <int> count(2*n+1);

    for (int i=1;i<=2*n;i++) {
        root[i]=i;
        count[i]=1;
    }

    for (int i=0;i<n;i++) {
        int g,b;
        cin >> g >> b;

        // find root of g & b
        int rg=findset(g,root);
        int rb=findset(b,root);
        if (rg==rb) continue;

        // union without ranking
        root[rb]=rg;
        count[rg]+=count[rb];
        count[rb]=0;
    }

    // find min and max
    int min=2*n+1;
    int max=0;
    for (int i=1;i<=2*n;i++) {
        if (count[i]>1 && count[i]<min)
            min=count[i];
        if (count[i]>max)
            max=count[i];
    }
    cout << "Smallest: " << min << " Largest: " << max;

    return 0;
}
