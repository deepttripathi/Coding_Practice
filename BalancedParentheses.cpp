#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool checkBalance(string str){
  stack <char> s;
  s.push('N');
  for(int i = 0; i < str.size(); i++){
    if(str[i] == '('){
      s.push(str[i]);
    }
    else if(str[i] == ')'){
      if(s.top()=='N')
        return false;
      s.pop();
    }
  }
  if(s.top()!='N')
    return false;
  return true;
}

int main(){
  cout << "Enter the expression : ";
  string str;
  cin >> str;
  if(checkBalance(str))
    cout << "The expression is balanced.";
  else
    cout << "The expression is not balanced.";
}
