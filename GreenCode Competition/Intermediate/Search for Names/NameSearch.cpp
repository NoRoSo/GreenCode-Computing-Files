//trie
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
  char data;
  node* next[26] = { NULL }; //sets next to null
  bool delimiter;
  int total;

  node()
  {
    for(int i = 0; i < 26; i ++)
        next[i] = NULL;// initially, sets any subsequent nodes to null.
    delimiter = false; //the end of a path along the tree
    total = 0;
  }

} node;

void Add(node *root, string toadd)
{
    int size = toadd.size();
    for(int i = 0; i < size; i++)
    {
        int index = toadd[i] - 'a'; //ASCII value of letter - 'a' = 0-26
        if(root->next[index] == NULL)
        {
            node *newnode = new node;
            newnode->data = toadd[i];
            newnode->total = newnode->total + 1;
            if(i == size - 1)
                newnode->delimiter = true;
            root->next[index] = newnode;
        }
        else
        {
           node *temp =  root->next[index];
           temp->total = temp->total + 1;
            if(i == size - 1)
                temp->delimiter = true;
        }
        root = root->next[index];
    }
}
void Find(node *root, string tofind)
{
   int size =  tofind.size();
   for(int i = 0; i < size; i++)
   {
       int index = tofind[i] - 'a';
       if(root->next[index] == NULL)
       {
          cout<<0<<endl;
          return;
       }
       else
       {
          root =  root->next[index];
       }
   }
   if(root == NULL)
   {
        cout<<0<<endl;
        return;
   }
    else
        cout<<root->total<<endl;
}

int main() {
    int noofcommands = 0;
    cin>>noofcommands;

    node *root = new node;
    root->data = '#';

    for(int i = 0; i < noofcommands; i++)
    {
        string operation;
        cin>>operation;
        if(operation.compare("add") == 0){
          string toadd;
          cin>>toadd;
          Add(root, toadd);
        }else{

          string tofind;
          cin>>tofind;
          cout << "find " << tofind << ": ";
          Find(root, tofind);
        }
    }
    return 0;
}
