//
//  main.cpp
//  AddingReversedNumber
//
//  Created by Maquina on 30/04/16.
//  Copyright © 2016 Maquina. All rights reserved.
//

#include<iostream>
#include<cmath>
using namespace std;

int reverseAndSum()
{
    int num1, num2, sum;
    int flag1=0, flag2=0, flagSum=0;
    int rev1 = 0, rev2 = 0, revSum = 0;
    cin>>num1>>num2;
    
    while(num1!=0)
    {
        if( flag1==0 && num1%10==0)
        {
            num1/=10;
        }
        else
        {
            flag1 = 1;
            rev1 = rev1*10 + num1%10;
            num1/=10;
            
        }
        
    }
    
    while(num2!=0)
    {
        if( flag2==0 && num2%10==0)
        {
            num2/=10;
        }
        else
        {
            flag2 = 1;
            rev2 = rev2*10 + num2%10;
            num2/=10;
            
        }
        
    }
    
    sum = rev1+rev2;
    
    
    while(sum!=0)
    {
        if( flagSum==0  && sum%10==0)
        {
            sum/=10;
        }
        else
        {
            flagSum = 1;
            revSum = revSum*10 + sum%10;
            sum/=10;
            
        }
    }
    return revSum;
}

int main()
{
    int testCase,loop=0, *result;
    
    cin>>testCase;
    
    result = new int[testCase];
    
    while(loop<testCase)
    {
        
        result[loop++] = reverseAndSum();
        
    }
    
    for(int i=0;i<testCase;i++)
    {
        cout<<result[i]<<endl;
    }
    
}
