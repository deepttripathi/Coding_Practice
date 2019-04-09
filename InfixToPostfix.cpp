#include <iostream>
#include <string>
#include <stack>

using namespace std;

int precedence(char ch){
  if(ch == '^')
    return 3;
  else if(ch == '/' || ch == '*')
    return 2;
  else if(ch == '+' || ch == '-')
    return 1;
  else
    return -1;
}

void infixToPostfix(string infixExpression){
  stack <char> s;
  s.push('N');
  string postfixExpression;
  for(int i = 0; i < infixExpression.size(); i++){
    char op = infixExpression[i];
    if((op>='a' && op<='z') || (op>='A' && op<='Z'))
      postfixExpression+=op;
    else if(op=='(')
      s.push(op);
    else if(op == ')'){
      while(s.top()!='N' && s.top()!='('){
        postfixExpression+=s.top();
        s.pop();
      }
      if(s.top()=='(')
        s.pop();
    }
    else{
      while(s.top()!='N' && precedence(op) <= precedence(s.top())){
        postfixExpression+=s.top();
        s.pop();
      }
      s.push(op);
    }
  }
  while(s.top()!='N'){
    postfixExpression+=s.top();
    s.pop();
  }

  cout << "Postfix Expression is : " << postfixExpression << endl;
}

int main(){
  string infixExpression;
  cout << "Enter infix expression : ";
  cin >> infixExpression;
  infixToPostfix(infixExpression);
}
