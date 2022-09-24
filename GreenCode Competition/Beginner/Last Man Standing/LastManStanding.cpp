#include <iostream>
#include <vector>
using namespace std;

void survivor(vector<int> circle, int c, int index){
    if(circle.size() == 1){
        cout << circle[0];
        return;
    }

    index = ((index + c) % circle.size());

    circle.erase(circle.begin() + index);

    survivor(circle, c, index);
}

int main(){
    int players, c;
    cin >> players >> c;
    c--; // (c-1)th person will be killed because of indexing
    vector<int> circle;
    for(int i = 1; i <= players; i++){
        circle.push_back(i);
    }
    survivor(circle, c, 0);

}
