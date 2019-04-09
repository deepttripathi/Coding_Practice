#include<iostream>
#include<queue>

using namespace std;

queue <int> q1, q2;

void stackPop(){
  int temp;
  if(q1.empty()){
    cout << "Stack is empty.";
    return;
  }
  while (!q1.empty()) {
    /* code */
    temp = q1.front();
    q1.pop();
    if(!q1.empty())
      q2.push(temp);
  }
  while (!q2.empty()) {
    /* code */
    q1.push(q2.front());
    q2.pop();
  }
  cout << temp;
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
        q1.push(value);
        break;
      case 2:
        stackPop();
        break;
    }
  }while(choice!=3);
  return 0;
}
