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

string PostfixToInfix(string postfixExpression){
  stack <string> s;
  int length = postfixExpression.size();
  for(int i = 0 ; i < length; i++){
    if(isOperator(postfixExpression[i])){
      string op1 = s.top();
      s.pop();
      string op2 = s.top();
      s.pop();

      string temp = "(" + op2 + postfixExpression[i] + op1 + ")";

      s.push(temp);
    }
    else{
      s.push(string(1,postfixExpression[i]));
    }
  }
  return s.top();
}

int main(){
  cout << "Enter the postfix expression : ";
  string postfixExpression;
  cin >> postfixExpression;
  cout << "Infix : " << PostfixToInfix(postfixExpression);
}
