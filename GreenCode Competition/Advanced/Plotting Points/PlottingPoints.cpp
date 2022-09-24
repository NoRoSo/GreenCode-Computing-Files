//hashing and graphs
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    return b == 0? a : gcd(b, a % b);
}

int maxPoints(vector<vector<int>> & points){
    int maxCommonPoints = 0;
    int n = points.size();

    //unordered_map<string, int> freq;
    //we don't declare hashmap here because point could be computed multiple times for same slope
    //ex: [[1, 1], [2, 2], [3, 3]]

    for(int i = 0; i < n-1; i++){
        int x1 = points[i][0];
        int y1 = points[i][1];


        unordered_map<string, int> freq;
        for(int j = i + 1; j < n; j++){
            int x2 = points[j][0];
            int y2 = points[j][1];

            int dx  = x2 - x1; //finding slope
            int dy  = y2 - y1;

            int gcdNum = gcd(dx, dy); //we find gcd to find common divisor to prevent quotient floating number

            dx /= gcdNum; //result will still be integer data type (not floating)
            dy /= gcdNum;

            stringstream ss, sss;//converting int to string.
            ss << dx;
            sss << dy;
            //finding how many points share the same slope.
            string hashKey  = ss.str() + '#' + sss.str();
            freq[hashKey]++;
            maxCommonPoints = max(maxCommonPoints, freq[hashKey]);
        }
    }
    return maxCommonPoints + 1; //we are adding one because while considering pairs of points we only counted second element
}

int main(){
    int cases; cin >> cases;
    for(int i = 1; i <= cases; i++){
        int N; cin >> N;
        vector<vector<int> > v;
        for(int x = 0; x < N; x++){
            int tempX, tempY; cin >> tempX >> tempY;
            vector<int> temp; temp.push_back(tempX); temp.push_back(tempY);
            v.push_back(temp);
        }
        cout << "CASE #" << i << ": " << maxPoints(v) << endl;
    }

}
