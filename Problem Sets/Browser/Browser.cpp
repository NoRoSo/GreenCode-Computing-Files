#include <bits/stdc++.h>

using namespace std;

class ListNode{
public:
    string val;
    ListNode* next;
    ListNode* prev;

    ListNode(string data){
        val = data;
        next = NULL;
        prev = NULL;
    }
};

class BrowserHistory{
public:
    int size = 0;
    ListNode* head;
    ListNode* curr;

    BrowserHistory(string homepage){
        head = new ListNode(homepage);
        curr = head;
        size++;
    }

    void visit(string url){
        ListNode* node = new ListNode(url);
        curr->next = node;
        node->prev = curr;
        curr = curr->next;
        size++;
    }

    string back(int steps){
        while(curr->prev && steps){
            curr = curr->prev;
            steps--;
        }

        return curr->val;
    }

    string forward(int steps){
        while(curr->next && steps){
            curr = curr->next;
            steps--;
        }
        return curr->val;
    }
};

int main(){
    int Q; cin >> Q;
    Q--;
    string first;
    cin >> first;cin >> first;
    BrowserHistory bh(first); //initializing with the first visit.

    while(Q--){
        string action; cin >> action;
        if(action == "visit"){
            string URL; cin >> URL;
            bh.visit(URL);
        }
        if(action == "back"){
            int backs; cin >> backs;
            cout << bh.back(backs) << endl;
        }
        if(action == "forward"){
            int forwards; cin >> forwards;
            cout << bh.forward(forwards) << endl;
        }
    }
}
