#include <bits/stdc++.h>

using namespace std;

string sumString(string a, string b){
    if(a.size() < b.size()){
        swap(a, b);
    }

    int j = a.size() - 1;
    for(int i = b.size() - 1; i >= 0; i--, j--){
        a[j] += (b[i] - '0');
    }

    for(int i = a.size() - 1; i > 0; i--){
        if(a[i] > '9'){
            int d = a[i] - '0';
            a[i - 1] = ((a[i - 1] - '0') + d/10) + '0';
            a[i] = (d%10) + '0';
        }
    }
    if(a[0] > '9'){
        string k;
        k += a[0];
        a[0] = ((a[0] - '0') % 10) + '0';
        k[0] = ((k[0] - '0') / 10) + '0';
        a += k;
    }

    return a;
}


int main(){
    int target = 10000;
    vector<string> vect;

    vect.push_back("0");
    vect.push_back("1");
    vect.push_back("1");

    while(vect.size() != target){
        string a = vect[vect.size() - 1], b = vect[vect.size() - 2], c = vect[vect.size() - 3];
        vect.push_back(sumString(sumString(a, b), c));
    }

    cout << vect[target - 1].substr(vect[target - 1].length() - 10) << endl;
}
