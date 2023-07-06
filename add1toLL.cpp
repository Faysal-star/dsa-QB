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

void add1(node **head){
    node *temp = *head ;
    node *prev = NULL ;
    while(temp->next != NULL){
        if(temp->data != 9) prev = temp ;
        temp = temp->next ;
    }
    if(temp->data != 9){
        temp->data += 1 ;
        return ;
    }
    else if(prev != NULL){
        prev->data += 1 ;
        prev = prev->next ;
        while(prev != NULL){
            prev->data = 0 ;
            prev = prev->next ;
        }
    }
    else{
        node *newnode = new node(1) ;
        newnode->next = *head ;
        *head = newnode ;
        temp = *head ;
        temp = temp->next ;
        while(temp != NULL){
            temp->data = 0 ;
            temp = temp->next ;
        }
    }
}

int main(){
    int n ; cin >> n ;
    node *head = NULL ;
    for(int i = 0 ; i < n ; i++){
        int num ; cin >> num ;
        insert(&head,num) ;
    }
    cout << "Main : " ;
    print(head) ;
    cout << endl ;
    add1(&head) ;
    cout << "After : " ;
    print(head) ;

}