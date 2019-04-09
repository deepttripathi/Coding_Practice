#include<iostream>
using namespace std;

int q[100], n = 100, front = 0, back = -1;

void queue(int i){
  back++;
  q[back] = i;
}

int dequeue(){
  if(front>back){
    return -10;
  }
  int frontValue = q[front];
  front++;
  return frontValue;
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
        cout << "The value popped is : "<<dequeue();
        break;
    }
  }while(choice!=3);
  return 0;
}
