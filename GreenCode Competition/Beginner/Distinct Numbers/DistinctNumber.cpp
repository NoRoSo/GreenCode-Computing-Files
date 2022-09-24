#include <iostream>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<int> s;

    while(n--){
        int temp;
        cin >> temp;
        s.insert(temp);
    }

    cout << s.size();
}
