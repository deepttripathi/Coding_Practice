#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

struct Node* topNode = NULL;

void push(int i){
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = i;
  newNode->next = topNode;
  topNode = newNode;
}

void pop(){
  if(topNode==NULL)
    return;
  cout << "The popped value is : "<< topNode->data;
  topNode = topNode->next;
}

int main(){
  int choice, value;
  cout << "1) Push";
  cout << "2) Pop";
  cout << "3) Exit";
  do{
    cout << "Enter choice.";
    cin >> choice;
    switch(choice){
      case 1:
        cout << "Enter the value to be pushed : ";
        cin >> value;
        push(value);
        break;
      case 2:
        pop();
        break;
    }
  }while(choice!=3);
  return 0;
}
