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

void insert(node **head , int val){
    node *temp = new node(val) ;
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
        cout << head->data ;
        if(head->next != NULL) cout << " -> " ;
        head = head->next ;
    }
}

void merge2sorted(node **head1 , node **head2){
    node *temp1 = *head1 ;
    node *temp2 = *head2 ;
    node *prev = NULL ;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data < temp2->data){
            prev = temp1 ;
            temp1 = temp1->next ;
        }
        else{
            if(prev != NULL) prev->next = temp2 ;
            prev = temp2 ;
            temp2 = temp2->next ;
            prev->next = temp1 ;
        }
    }
    if(temp1 == NULL) prev->next = temp2 ;
}

int main(){
    int n1 , n2 ; cin >> n1 >> n2 ;
    node *head1 = NULL ;
    node *head2 = NULL ;
    for(int i = 0 ; i < n1 ; i++){
        int val ; cin >> val ;
        insert(&head1 , val) ;
    }
    for(int i = 0 ; i < n2 ; i++){
        int val ; cin >> val ;
        insert(&head2 , val) ;
    }
    merge2sorted(&head1 , &head2) ;
    print(head1) ;
}