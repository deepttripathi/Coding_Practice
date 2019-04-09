#include<iostream>
#include<stack>
#include<string>


using namespace std;

bool isOperator(char op){
  switch (op) {
    case '+':
    case '-':
    case '*':
    case '/':
      return true;
  }
  return false;
}

string PrefixToInfix(string prefixExpression){
  stack <string> s;
  int length = prefixExpression.size();
  for(int i = length - 1 ; i >= 0; i--){
    if(isOperator(prefixExpression[i])){
      string op1 = s.top();
      s.pop();
      string op2 = s.top();
      s.pop();

      string temp = "(" + op1 + prefixExpression[i] + op2 + ")";

      s.push(temp);
    }
    else{
      s.push(string(1,prefixExpression[i]));
    }
  }
  return s.top();
}

int main(){
  cout << "Enter the prefix expression : ";
  string prefixExpression;
  cin >> prefixExpression;
  cout << "Infix : " << PrefixToInfix(prefixExpression);
}
