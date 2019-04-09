#include<iostream>

using namespace std;

int arr[100], top = -1, minValue = -10;

void push(int i){
  if(top<0){
    top++;
    arr[top] = i;
    minValue = i;
  }
  else{
    if(i<minValue){
      top++;
      arr[top] = 2*i - minValue;
      minValue = i;
    }
    else{
      top++;
      arr[top] = i;
    }
  }
}

void pop(){
  if(top<0){
    cout << "Stack is empty.";
    return;
  }
  else{
    if(arr[top] < minValue){
      cout << "The popped element is : " << minValue;
      minValue = 2 * minValue - arr[top];
      top--;
    }
    else{
      cout << "The popped element is : " << arr[top];
      top--;
    }
  }
}

int main(){
  int choice, value;
  cout << "1) Push";
  cout << "2) Pop";
  cout << "3) getMin";
  cout << "4) Exit";
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
      case 3:
        cout << "The min value is : " << minValue;
    }
  }while(choice!=4);
  return 0;
}
