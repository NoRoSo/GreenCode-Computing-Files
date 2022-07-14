#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int tc; cin >> tc;
    int testNum = 1;
    
    while (tc--) {
        cout << "CASE #" << (testNum++) << ": ";
        string s;
        cin >> s;
        if (next_permutation(s.begin(), s.end()))
            cout << s << endl;
        else
            cout << "no answer" << endl;
    }
    return 0;
}
