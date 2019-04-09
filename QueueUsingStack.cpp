#include<iostream>
#include<stack>

using namespace std;

stack <int> s1;
stack <int> s2;

void enqueue(int i){

    while(!s1.empty()){
      s2.push(s1.top());
      s1.pop();
    }

    s1.push(i);

    while(!s2.empty()){
      s1.push(s2.top());
      s2.pop();
    }
}

void dequeue(){
  if(s1.empty()){
    cout << "Queue is empty.";
    return;
  }
  cout << "The dequeues element is : " << s1.top();
  s1.pop();
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
        enqueue(value);
        break;
      case 2:
        dequeue();
        break;
    }
  }while(choice!=3);
  return 0;
}
