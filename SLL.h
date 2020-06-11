#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct Node{
    string data;
    Node* next=NULL;
} Node;

typedef struct SLL{
    int size;
    Node* head=NULL;
    Node* tail=NULL;
} SLL;


Node* createNode(string data){
    Node* newNode=new Node; // (Node *) malloc(sizeof(Node));
    newNode->data=data;
    return newNode;
}



void insertRear(SLL* sll, string data){
    Node* newNode=createNode(data);
    if(sll->head==NULL){
        sll->head=newNode;
        sll->tail=newNode;
        sll->size=0;
    }
    else {
        sll->tail->next=newNode;
        sll->tail=newNode;
    }

    sll->size++;
}

//3>5>6>7
Node* findValue(SLL* sll, string data){
    Node* a=sll->head;
    while(a!=NULL) {
        if(a->data==data){
            return a;
        }
        a=a->next;
    }
    return NULL;
}

void insertFront(SLL* sll, string data){

    Node* newNode=createNode(data);
    if(sll->head==NULL){
        sll->head=newNode;sll->size=0;
        sll->tail=newNode;
    }
    else {
        newNode->next=sll->head;
        sll->head=newNode;
    }
    sll->size++;

}

bool isEmpty(SLL* sll){
    if(sll->head==NULL){
        return true;
    }
    return false;
}

Node* findPreRear(SLL* sll){
    if (sll->head!=NULL && sll->head != sll->tail) {

        Node* a=sll->head;
        while(a->next!=sll->tail){
            a=a->next;
        }

        return a;
    }

   return NULL;
}

string removeFront(SLL* sll){

    string data;
    if(!isEmpty(sll)){
        if(sll->head==sll->tail){

            data=sll->head->data;
            delete sll->head;

            sll->head=NULL;
            sll->tail=NULL;
        }
        else{
            Node* postHead= sll->head->next;
            data=sll->head->data;
            delete sll->head;
            sll->head=postHead;
        }
    sll->size--;
    }
    return data;
}

string removeRear(SLL* sll){
    string data;
    if(!isEmpty(sll)){
        if(sll->head==sll->tail){

            data=sll->head->data;
            delete sll->head;

            sll->head=NULL;
            sll->tail=NULL;
        }
        else{
            Node* preRear= findPreRear(sll);
            data=sll->tail->data;
            delete sll->tail;
            preRear->next=NULL;
            sll->tail=preRear;

        }
        sll->size--;

    }

    return data;
}

void print(SLL* sll){
    Node* n=sll->head;
    while(n!=NULL) {
        cout << n->data << " ";
        n=n->next;
    }
}

void printNL(SLL* sll){
    Node* n=sll->head;
    while(n!=NULL) {
        cout << n->data << endl;
        n=n->next;
    }
}

bool removeValue(SLL* sll, string data){
    Node* a=sll->head;
    Node* pre=NULL;
    while(a!=NULL) {
        if(a->data==data){
            if(pre==NULL){
                removeFront(sll);
            }
            else if(a==sll->tail){
                removeRear(sll);
            }
            else{
                pre->next=a->next;
                delete a;
            }
            sll->size--;
            return true;
        }
        pre=a;
        a=a->next;
    }
    return false;
}

void printReverse(SLL* sll){

    string *a = new string[sll->size];
    int i=0;


    Node* n=sll->head;
    while(n!=NULL) {
        a[i]=n->data;
        n=n->next;
        i++;
    }
    for(int j=sll->size-1; j>=0; j--){
        cout<<a[j]<<"  ";
    }

    delete []a;

}

Node* sonrakiNode(SLL* sll, Node* a){ //Node structlari SLL'e ait oldugu icin
    return a->next;
}

Node* datadanNodeBul2(SLL* sll, string data){
    Node* a=sll->head;
    int i=1;
    while(a->data!=data&&i+1<=sll->size){
        if(a->next!=NULL){
                a=a->next;
        }
        i++;
    }
    if(i+1==sll->size){
        cout<<"Data bulunamadi";
        return 0;
    }
    return a;
}

string bottom(SLL* sll){
    if(!isEmpty(sll)){
        return sll->tail->data;
    }
    return NULL;
}

//1->3->7->8
int datadanNodeBul(SLL* sll, string data){
    Node* a=sll->head;

    int i=1;
    while(a != NULL ){

        if(data <= a->data ){
            return i;
        }

        i++;
        a =sonrakiNode(sll, a);
    }

    return 1;
}


void arayaSiradanEkle(SLL* sll, int sira, string data){

    if(sira>sll->size){
        cout<<endl<<"gecersiz istek";
    }
    else{
        Node* a=sll->head;
        for(int i=1; i<sira; i++){
            a=sonrakiNode(sll, a);
        }
        //2
        Node* newNode=createNode(data);

        if (a == sll->head) {
            newNode->next = a;
            sll->head = newNode;
        }
        else {
            Node* aSonraki= a->next;
            a->next=newNode;
            newNode->next=aSonraki;
        }

    }
    sll->size++;

}

void freeSLL(SLL* sll) {
    Node* n=sll->head;
    while(n!=NULL) {
        Node * t = n;
        n=n->next;

        delete t;
    }
    sll->head=NULL;
    sll->tail = NULL;
    sll->size=0;
}

void printReverse2(SLL* sll){

    SLL temp;

    Node* n=sll->head;
    while(n!=NULL) {
        insertFront(&temp, n->data);

        n=n->next;
    }
    print(&temp);
    freeSLL(&temp);
}


void printReverse3(SLL* sll){

    string *a = new string[sll->size];

    Node* n=sll->head;
    while(n!=NULL) {
            cout << a << "-";
        *a=n->data;
        n=n->next;
        a++;
    }
    for(int j=0; j<sll->size; j++){
        cout<<a<<"  ";
        a--;
    }

    delete []a;

}

void DatadanSonrakineEkle(SLL* sll, string hedefData){//ilk bulunandan sonrakine ekler
    int i=datadanNodeBul(sll, hedefData);
    arayaSiradanEkle(sll, i, hedefData);

}

string top(SLL* sll){
    if(sll->head==NULL){
        return NULL;
    }
    return sll->head->data;
}

#endif // SLL_H_INCLUDED
