#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getSil(vector<vector<int>> & b){
    vector<array<int, 2>> heights;
    vector<vector<int>> ans;
    for(int i = 0; i < b.size(); i++){
        array<int, 2> temp1 = {b[i][0], -b[i][2]}; //storing leftmost index & height of each rectangle.
        array<int, 2> temp2 = {b[i][1], b[i][2]};  //storing rightmost index & height of each rectangle.
        heights.push_back(temp1);
        heights.push_back(temp2);
    }
    sort(heights.begin(), heights.end()); //sorting the X-values
    for(array<int, 2> ray : heights)
        cout << "printing == " << ray[0] << " " << ray[1] << endl;

    multiset<int> toplevel = {0};
    int prev = 0, cur = 0;
    //maximize the heights going through the points
    for(int i = 0; i < heights.size(); i++){
        if(heights[i][1] < 0){
            toplevel.insert(abs(heights[i][1]));
        }else{
            toplevel.erase(toplevel.find(heights[i][1])); //remove the height when a particular range has ended
        }
        cur = *toplevel.rbegin(); //maximum height at the point height[i][0].
        cout << "cur == " << cur << " prev == " << prev << endl;
        /*
        We don't add the {point with the height} because we skip when a range
        hasn't ended and current maxheight is still the previous maximum.
        */
        if(cur != prev){
            vector<int> temp = {heights[i][0], cur};
            ans.push_back(temp);
            prev = cur;
        }
    }
    return ans;
}

int main(){
    int blocks; cin >> blocks;
    vector<vector<int>> v;
    for(int i = 0; i < blocks; i++){ //input
        vector<int> temp;
        int leftX, rightX, height; cin >> leftX >> rightX >> height;
        temp.push_back(leftX); temp.push_back(rightX); temp.push_back(height);
        v.push_back(temp);
    }

    vector<vector<int>> fin = getSil(v); //calling function

    for(int i = 0; i < fin.size(); i++){ //printing output
        cout << fin[i][0] << " " << fin[i][1] << endl;
    }
    return 0;
}
