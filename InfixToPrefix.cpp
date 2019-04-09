#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char ch){
  if(ch=='^')
    return 3;
  else if(ch=='*' || ch=='/')
    return 2;
  else if(ch=='+' || ch =='-')
    return 1;
  else
    return -1;
}

void infixToPrefix(string infixExpression){
  stack <char> s;
  string prefixReverseExpression;
  s.push('N');
  for(int i=infixExpression.size()-1; i>=0; i--){
    char op = infixExpression[i];
    cout << op;
    if((op>='a' && op<='z')||(op>='A' && op<='Z')){
      prefixReverseExpression+=op;
    }
    else if(op == ')')
      s.push(op);
    else if(op == '('){
      while(s.top()!='N' && s.top()!=')'){
        prefixReverseExpression+=s.top();
        s.pop();
      }
      if(s.top()==')')
        s.pop();
    }
    else{
      while(precedence(op)<=precedence(s.top()) && s.top()!='N'){
        prefixReverseExpression+=s.top();
        s.pop();
      }
    s.push(op);
    }
  }
  while(s.top()!='N'){
    prefixReverseExpression+=s.top();
    s.pop();
  }
  cout << "The prefix expression is : ";
  for(int i = prefixReverseExpression.size()-1; i >= 0; i--){
    cout << prefixReverseExpression[i];
  }
}

int main(){
  string infixExpression;
  cout << "Enter infix expression : ";
  cin >> infixExpression;
  infixToPrefix(infixExpression);
}
