#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;

class node{
    public:
    int data ;
    node* next ;
    node(int val){
        data = val ;
        next = NULL ;
    }
};

void insert(node **head , int data){
    node *temp = new node(data) ;
    if(*head == NULL){
        *head = temp ;
        return ;
    }
    node *last = *head ;
    while(last->next != NULL){
        last = last->next ;
    }
    last->next = temp ;
}

void print(node *head){
    while(head != NULL){
        cout << head->data;
        if(head->next != NULL) cout << " -> " ;
        head = head->next ;
    }
}

void split(node **head , int pos , node **head2){
    node *temp = *head ;
    while(--pos) temp = temp->next ;
    *head2 = temp->next ;
    temp->next = NULL ;
}

int main(){
    int n , pos ; cin >> n >> pos ;
    node *head = NULL , *head2 = NULL;
    for(int i = 0 ; i < n ; i++){
        int data ; cin >> data ;
        insert(&head , data) ;
    }
    print(head) ;
    cout << endl ;
    split(&head , pos , &head2) ;
    print(head) ;
    cout << endl ;
    print(head2) ;
    
}