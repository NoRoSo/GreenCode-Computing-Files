#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//newish to vectors. Quick function to remove a specific value from a vector.
std::vector<int> deleteSpecificValue(std::vector<int> _vector, int _value) {
  std::vector<int> localVector = _vector;
  for (int i = 0; i < (int)localVector.size(); i++) {
    if (localVector[i] == _value) {
      localVector.erase(localVector.begin() + i);
      return localVector;
    }
  }
}

int maxProfit(vector<int> quotes){
    //First I want a sorted reference of the quotes
    std::vector<int> sortedQuoteCopy = quotes;
    std::sort(sortedQuoteCopy.begin(), sortedQuoteCopy.end());

    //Next initialize a value for the max price:
    int maxValue = 0;

    //make variables for realizedGains, unrealized, and numberOfHeldShares
    long long int totalMoney = 0;
    long long int unrealizedCost = 0;
    long long int numberOfUnrealizedShares = 0;

    //in iterator to go through the vector
    int i = 0;

    //iterate through the quotes deleting values from the sorted
    //copy whenever it is the current max price or an potential sale
    while(i < (int)quotes.size()) {
        //initialize max value for first run
        if (maxValue == 0) {
        maxValue = sortedQuoteCopy.back();
        sortedQuoteCopy.pop_back();
        }
        //when the current quote is the max, sell all shares for profit
        //also, set a new max with the remaining quotes.
        if (quotes[i] == maxValue) {
            totalMoney += ((numberOfUnrealizedShares * quotes[i]) - unrealizedCost);
            unrealizedCost = 0;
            numberOfUnrealizedShares = 0;
            maxValue = sortedQuoteCopy.back();
            sortedQuoteCopy.pop_back();
        }
        else {
            //if value is not == to max (therefore less than), buy a share at that price
            numberOfUnrealizedShares++;
            unrealizedCost += quotes[i];
            sortedQuoteCopy = deleteSpecificValue(sortedQuoteCopy, quotes[i]);
        }
        //iterate to next quote
        i++;
    }
    return totalMoney;
}
int main(){
    int cases; cin >> cases;
    while(cases--){
        int n; cin >> n;
        vector<int> quotes;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            quotes.push_back(temp);
        }
        cout << maxProfit(quotes) << endl;
    }
}
