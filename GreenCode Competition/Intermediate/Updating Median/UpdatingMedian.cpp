#include <bits/stdc++.h>

using namespace std;

class MedianFinder{
public:
    priority_queue<double> fhalf; //First half that will store numbers from bigger to smaller
    priority_queue<double, vector<double>, greater<double> > shalf; //Second half that will store numbers from smaller to bigger
    MedianFinder(){

    }

    void addNum(int num){
        if(fhalf.size() == shalf.size()){ //if the sizes of the queues are the same, then we basically can insert the number wherever we want
            if(shalf.empty() && fhalf.empty()){ //if we don't have any numbers yet, then we add numbers to the first half
                fhalf.push(num);
                return;
            }

            if(num >= fhalf.top())//if the number is outside the domain of the first half, then we add it to the second half
                shalf.push(num);
            else
                fhalf.push(num); //if the number is outside the domain of the second half, then we insert it into the first half
            return;
        }

        if(fhalf.size() > shalf.size()){ //if one half is bigger than the other, then we need to make sure that both queues have the same amount of numbers
            if(num >= fhalf.top())
                shalf.push(num);
            else{
                shalf.push(fhalf.top());
                fhalf.pop();
                fhalf.push(num);
            }
        }else{
            if(num <= shalf.top())
                fhalf.push(num);
            else{
                fhalf.push(shalf.top());
                shalf.pop();
                shalf.push(num);
            }
        }
    }

    double findMedian(){
        if(fhalf.size() == shalf.size()) //if both queues have the same amount of elements, it means that the total amount of elements is even, so we return the average of the last items of both queues
            return (fhalf.top() + shalf.top()) / 2.0;
        return fhalf.size() > shalf.size() ? fhalf.top() : shalf.top(); //otherwise, we return the last number of the bigger queue.
    }

};

int main(){
    int Q; cin >> Q;
    int medianCounter = 1;
    MedianFinder mf;
    while(Q--){
        string action; cin >> action;
        if(action == "add"){
            int temp; cin >> temp;
            mf.addNum(temp);
        }else{
            cout << "Median #" << (medianCounter++) << ": " << mf.findMedian() << endl;
        }
    }
}
