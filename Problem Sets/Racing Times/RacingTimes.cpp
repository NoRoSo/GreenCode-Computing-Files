#include <iostream>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;
    set<int> s;
    while(n--){
        int start, finish;
        cin >> start >> finish;
        for(int i = start; i < finish; i++)
            s.insert(i);
    }

    cout << s.size();

}
