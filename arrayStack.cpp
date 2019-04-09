#include<iostream>
using namespace std;

int stack[100], n=100, top = -1;

void push(int i){
  top++;
  stack[top] = i;
}

int pop(){
  if(top==-1){
    return -10;
  }
  int topVal = stack[top];
  top--;
  return topVal;
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
        cout << "The value popped is : "<<pop();
        break;
    }
  }while(choice!=3);
  return 0;
}
