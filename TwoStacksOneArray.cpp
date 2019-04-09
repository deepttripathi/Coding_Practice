#include<iostream>

 using namespace std;

 int arr[100], top1 = -1, top2 = 100;

 void push(int i, bool firstStack){
   if(top1 >= top2){
     cout << "Array is full.";
     return;
   }
   if(firstStack){
     top1++;
     arr[top1] = i;
   }
   else{
     top2--;
     arr[top2] = i;
   }
 }

 void pop(bool firstStack){
   if(firstStack){
     if(top1<0){
       cout << "Stack is empty.";
       return;
     }
     cout << "Popped : " << arr[top1];
     top1--;
   }
   else{
     if(top2>99){
       cout << "Stack is empty.";
       return;
     }
     cout << "Popped : " << arr[top2];
     top2++;
   }
 }

 int main(){
   int choice, value;
   cout << "1) Push to Stack 1\n";
   cout << "2) Pop to Stack 1\n";
   cout << "3) Push to Stack 2\n";
   cout << "4) Pop to Stack 2\n";
   cout << "5) Exit\n";
   do{
     cout << "Enter choice.";
     cin >> choice;
     switch(choice){
       case 1:
         cout << "Enter the value to be pushed : ";
         cin >> value;
         push(value, true);
         break;
       case 2:
         pop(true);
         break;
       case 3:
         cout << "Enter the value to be pushed : ";
         cin >> value;
         push(value, false);
         break;
       case 4:
         pop(false);
         break;
     }
   }while(choice!=5);
   return 0;
 }
