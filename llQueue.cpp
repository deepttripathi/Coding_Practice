#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

Node* frontNode = NULL;
Node* endNode = NULL;

void queue(int i){
  Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = i;
  newNode->next = NULL;
  if(frontNode==NULL){
    frontNode = newNode;
    endNode = newNode;
  }
  else{
    endNode->next = newNode;
    endNode = newNode;
  }
}

void dequeue(){
  if(frontNode==NULL)
    return;
  cout << "The dequeues element is : " << frontNode->data;
  frontNode = frontNode->next;
}

int main(){
  int choice, value;
  cout << "1) queue";
  cout << "2) Dequeue";
  cout << "3) Exit";
  do{
    cout << "Enter choice.";
    cin >> choice;
    switch(choice){
      case 1:
        cout << "Enter the value to be pushed : ";
        cin >> value;
        queue(value);
        break;
      case 2:
        dequeue();
        break;
    }
  }while(choice!=3);
  return 0;
}
