#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;

class hetero_node{
    public:
    int type;
    void *data ;
    hetero_node *next ;
} ;

void insert(hetero_node **head , void *data , int type){
    hetero_node *temp = new hetero_node ;
    if(type == 1){
        temp->type = 1 ;
        temp->data = (int *)data ;
    }
    else if(type == 2){
        temp->type = 2 ;
        temp->data = (char *)data ;
    }
    else if(type == 3){
        temp->type = 3 ;
        temp->data = (float *)data ;
    }
    temp->next = NULL ;

    if(*head == NULL){
        *head = temp ;
        return ;
    }
    hetero_node *last = *head ;
    while(last->next != NULL){
        last = last->next ;
    }
    last->next = temp ;
}

void print(hetero_node *head){
    while(head != NULL){
        if(head->type == 1){
            cout << *(int *)head->data ;
        }
        else if(head->type == 2){
            cout << *(char *)head->data ;
        }
        else if(head->type == 3){
            cout << *(float *)head->data ;
        }
        if(head->next != NULL) cout << " -> " ;
        head = head->next ;
    }
}

int main(){
    int n , t ; cin >> n ;
    hetero_node *head = NULL ;
    for(int i = 0 ; i < n ; i++){
        cin >> t ;
        if(t == 1){
            int *data = new int ;
            cin >> *data ;
            insert(&head , data , 1) ;
        }
        else if(t == 2){
            char *data = new char ;
            cin >> *data ;
            insert(&head , data , 2) ;
        }
        else if(t == 3){
            float *data = new float ;
            cin >> *data ;
            insert(&head , data , 3) ;
        }
    }
    print(head) ;
}