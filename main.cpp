#include <iostream>
using namespace std;
template <class t>
// implementing template stack using double linked lists

class DStack{
    struct Dnode{
        t data;
        Dnode* next= nullptr;
        Dnode* prev= nullptr;
    };
private:
    Dnode* top;
    Dnode* rear;
public:
    DStack(){
        top= nullptr;
        rear = nullptr;
    }
    //adding a node at the end of the stack
    void push_back(t value){
        Dnode* newnode = new Dnode;
        //if creating a node for the very first time in the stack
        if(is_empty()){
            rear= newnode;
            top= newnode;
            newnode->next=nullptr;
            newnode->data = value;
            newnode->prev= nullptr;
        }
        //is there is node already exist in the stack
        else {
            rear->next= newnode;
            newnode->prev= rear;
            newnode->data= value;
            rear= newnode;
            newnode->next=nullptr;
        }
    }

    //adding a node at the beginning of the stack
    void push_front(t value) {
        Dnode *newnode = new Dnode;
        //if creating a node for the very first time in the stack
        if (is_empty()) {
            rear = newnode;
            top = newnode;
            newnode->next = nullptr;
            newnode->data = value;
            newnode->prev = nullptr;
        }
            //is there is node already exist in the stack
        else {
            newnode->data= value;
            top->prev= newnode;
            newnode->next= top;
            newnode->prev= nullptr;
            top= newnode;
        }
    }

    //check if the stack is empty
    bool is_empty(){
        if(top== nullptr && rear == nullptr){
            return true;
        }
        return false;
    }

    //removing a node from the end of the stack and returning its value
    t pop_back(t value){
        // check if the stack is empty
        if(is_empty()){
            cout<< "the class is empty on pop";
            return -1;
        }
        else {
            Dnode* oldnode= new Dnode;
            oldnode= rear;
            rear= rear->prev;
            if(rear== nullptr) top= nullptr;
            else rear->next= nullptr;
            return oldnode->data;
        }
    }

    //removing a node from the beginning of the stack
    t pop_front(t value){
        // check if the stack is empty
        if(is_empty()){
            cout<< "the class is empty on pop"<<endl;
            return -1;
        }
        else {
            Dnode* oldnode= new Dnode;
            oldnode= top;
            top = top->next;
            if(top== nullptr) rear = nullptr ;
            else top->prev = nullptr;
            return oldnode->data;
        }
    }

    //printing all the values in the stack;
    void display(){
        if(is_empty()) cout<< "stack is empty";
        else {
            Dnode* temp = new Dnode;
            temp= top;
            cout<<"[ ";
            while (temp != nullptr){
                cout<<temp->data<<" ";
                temp= temp->next;
            }
            cout<<"]"<<endl;
        }
    }

    t get_top(){
        if(is_empty()) return -1;
        else return top->data;
    }
    t get_last(){
        if(is_empty()) return -1;
        else return rear->data;
    }
};

int main() {
    int x;
    DStack<int> s1;
    s1.push_back(5);
    s1.push_back(6);
    s1.push_back(7);
    s1.push_back(8);
    s1.push_back(9);
    s1.push_front(4);
    s1.push_front(3);
    s1.push_front(2);
    s1.push_front(1);
    cout<< s1.get_top();
    return 0;
}
