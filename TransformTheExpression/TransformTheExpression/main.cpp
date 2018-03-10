//
//  main.cpp
//  TransformTheExpression
//
//  Created by Maquina on 30/04/16.
//  Copyright © 2016 Maquina. All rights reserved.
//

#include <iostream>
#include <string>

#define cin     std::cin
#define cout    std::cout
#define endl    std::endl
#define string  std::string

#define EXP 400
#define STACK_SIZE 300

char priority[] = {'+', '-', '*', '/', '^'};

class Stack{
    
    char *arr;
    int top;
    int MAX;
    int MIN;
    
public:
    Stack(int arr_len){
        this->arr = new char[arr_len];
        this->top = -1;
        this->MAX = arr_len;
        this->MIN = -1;
    }
    
    void push(char operators){
        if(this->top >= this->MAX){
            // Stack Overflow
        }else{
            ++(this->top);
            arr[this->top] = operators;
        }
    }
    
    char pop(){
        char c;
        if(this->top <= this->MIN){
            // Stack Underflow
            c = '\0';
        }else{
            c = arr[this->top];
            --(this->top);
        }
        
        return c;
    }
    
    char peek(){
        char c;
        if(this->top <= this->MIN){
            // Stack Underflow
            c = '\0';
        }else{
            c = this->arr[this->top];
        }
        
        return c;
    }
    
    bool isEmpty(){
        bool isEmpty = true;
        if(this->top > this->MIN){
            isEmpty = false;
        }
        return isEmpty;
    }
    
    void printStack(){
        for(int i = this->top; i > this->MIN; --i){
            cout<<this->arr[i]<<" ";
        }
        cout<<endl;
    }
};

string transformExp(string s){
    Stack st(STACK_SIZE);
    string newExp = "";
    
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '('){// Push
            st.push(s[i]);
            //cout<<"Push : "<<s[i]<<endl;
        }else if(s[i] == ')'){
            //cout<<"Closing Paranthesis\t";
            //st.printStack();
            while(!st.isEmpty() && st.peek() != '('){
                char c =(st.pop());
                //cout<<"Before Break : "<<c<<endl;
                if(c == '\0'){
                    break;
                }
                //cout<<"Popped : "<<c<<endl;
                newExp = newExp + c;
                //cout<<"New Exp : "<<newExp<<endl;
            }
            //Pop opening paranthesis
            st.pop();
        }else if(s[i] == '+' || s[i] == '*' || s[i] == '-' || s[i] == '/' || s[i] == '^'){
            st.push(s[i]);
            //cout<<"Push : "<<s[i]<<endl;
        }else{// Operands, Append in new expression
            //cout<<"Pushing "<<s[i]<<endl;
            newExp = newExp + s[i];
            //cout<<"Found : "<<s[i]<<"\t new Expression"<<newExp<<endl;
        }
    }
    //cout<<"Final Exp : "<<newExp<<endl;
    return newExp;
}

int main(){
    int tc;
    cin>>tc;
    
    string *result = new string[tc];
    
    for(int i = 0; i < tc; i++){
        
        string s;
        cin>>s;
        //cout<<s;
        
        result[i] = transformExp(s);
    }
    
    for(int i = 0; i < tc; ++i){
        cout<<result[i]<<endl;
    }
}
