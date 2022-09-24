#include <bits/stdc++.h>
using namespace std;

class FreqStack {
private:
    unordered_map <int, int> hashmap;               //To store the value along with its frequency
    vector <int> arr;                               //To store the values
    int size;

public:

    FreqStack() {
        size = 0;
    }

    void push(int val) {

        arr.push_back (val);

        if (hashmap.count (val) <= 0)
            hashmap.insert (make_pair (val,1));
        else
            hashmap [val] += 1;

        size++;
    }

    int pop() {

        int maxfreq = 0;
        for (auto it = hashmap.begin(); it != hashmap.end();++it)
        {
            if (it->second > maxfreq)
                maxfreq = it->second;
        }
        /*At this point we have calculated the maximum frequency that is currently in the stack.
        Now there might be many such elements with this frequency.
        To solve this we start iterating from the end of the vector and
        the first element that we encounter with that frequency is the one that is needed to popped.*/

        for (int i = size-1; i >= 0; i--)
        {
            int num = arr[i];

            if (hashmap [num] == maxfreq)
            {
                vector<int>::iterator it;
                it = arr.begin() + i;

                arr.erase (it); //Deleting that element from the vector

                hashmap [num] -= 1; //Decreasing its frequency in the map

                if (hashmap [num] == 0)
                    hashmap.erase (num);

                size--;

                return num;
            }
        }
        return -1;

    }
};


int main(){
    int N, pops; cin >> N >> pops;
    FreqStack fs;

    for(int i = 0; i < N; i++){
        int temp; cin >> temp;
        fs.push(temp);
    }

    for(int i = 1; i <= pops; i++){
        cout << "Pop #" << i << ": " << fs.pop() << endl;
    }

    return 0;
}
