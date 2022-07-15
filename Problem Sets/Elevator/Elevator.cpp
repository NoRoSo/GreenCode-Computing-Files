//multiset data structure (a set that stores duplicates)
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Checks if the Lift is empty (goes through each floor queue and checks to see that it is empty)
bool isEmpty(const vector<vector<int>>& queues)
{
    for (int i = 0; i < queues.size(); i++)
    {
        if (queues[i].empty() == false)
        {
            return false;
        }
    }
    return true;
}

vector<int> the_lift(vector<vector<int>> queues, int capacity)
{
    // No matter the case, the lift always starts at the ground level
    vector<int> floorsVisited{ 0 };

    // Bool variable to keep track of the direction of the lift
    bool goUp = false;
    // Multiset to keep track of who is currently on the lift.
    unordered_multiset<int> onLift;

    // Start at floor 0
    int floor = 0;

    // Keep visiting floors while there are still people in the floor queue or on the elevator
    while (!(isEmpty(queues) == true && onLift.empty() == true))
    {
        // Variable that keeps track if the lift actually stopped at that floor (either to pick someone up or drop someone off)
        bool didStop = false;

        // Once you hit the first or top floors, change the lift's direction
        if (floor == 0 || floor == queues.size() - 1)
        {
            goUp = !goUp;
        }

        // If there are people on the lift who want to get out at the current floor, let them get out
        while (onLift.find(floor) != onLift.end())
        {
            didStop = true;
            onLift.erase(floor);
        }


        // Traverse the current queue to see if there is someone who can get on if there is space in the lift
        vector<int> newQueue;
        for(int i = 0; i < queues[floor].size(); i++)
        {

            // If the lift is going up, only stop for people who want to go up
            if (goUp == true)
            {
                if (queues[floor][i] > floor)
                {
                    didStop = true;

                    // If there is no space, but there are people on the floor who want to go up, you still stopped at the floor, you just can't take them on the lift
                    if (onLift.size() < capacity)
                    {
                        onLift.insert(queues[floor][i]);
                    }

                    // So, they remain in the queue
                    else
                    {
                        newQueue.push_back(queues[floor][i]);
                    }
                }

                // If they aren't going in the same direction as the lift, leave them in the queue
                else
                {
                    newQueue.push_back(queues[floor][i]);
                }
            }

            // If the lift is going down, only stop for people who want to go down
            else
            {
                if (queues[floor][i] < floor)
                {
                    didStop = true;

                    // If there is no space, but there are people on the floor who want to go up, you still stopped at the floor, you just can't take them on the lift
                    if (onLift.size() < capacity)
                    {
                        onLift.insert(queues[floor][i]);
                    }

                    // So, they remain in the queue
                    else
                    {
                        newQueue.push_back(queues[floor][i]);
                    }
                }

                // If they aren't going in the same direction as the lift, leave them in queue
                else
                {
                    newQueue.push_back(queues[floor][i]);
                }
            }
        }

        // If you stopped at the floor, change the queue accordingly (if no one was allowed to get on, the queue will be the same as originally; if people were
        // allowed to get on, then the newQueue vector will only contain people who weren't allowed to get on in their relative position in the original queue for that floor)
        if (didStop == true)
        {
            queues[floor] = newQueue;

            // If the current floor is the last floor you visited, (i.e. you are now travelling in the opposite direction) then don't add the floor to the previously visited floors
            if (floorsVisited.back() != floor)
            {
                floorsVisited.push_back(floor);
            }
        }
        (goUp) ? floor++ : floor--;
    }

    // If the last floor visited was the bottom (and there are no more floors to visit), then don't add 0 to the queue. If the last visited floor wasn't 0 (and there are no more floors
    // to visit), then add 0 to the queue since the lift will return to the ground floor once it is finished
    if (floorsVisited.back() != 0)
    {
        floorsVisited.push_back(0);
    }
    return floorsVisited;
}

int main(){
    int floors, capacity; cin >> floors >> capacity;

    vector<vector<int>> queues;
    for(int f = 0; f < floors; f++){ //getting input
        int people; cin >> people;
        vector<int> temp;
        temp.empty();
        if(people != 0){
            while(people--){
                int person; cin >> person;
                temp.push_back(person);
            }
        }
        queues.push_back(temp);
    }

    //calling function
    vector<int> finished = the_lift(queues, capacity);

    //printing solution
    for(int i = 0; i < finished.size(); i++){
        cout << finished[i] << " ";
    }
}
