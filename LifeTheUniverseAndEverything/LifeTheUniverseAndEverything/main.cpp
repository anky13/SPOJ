//
//  main.cpp
//  LifeTheUniverseAndEverything
//
//  Created by Maquina on 30/04/16.
//  Copyright © 2016 Maquina. All rights reserved.
//

#include<iostream>

#include<cstdlib>
using namespace std;

int checkNoOfDigitInInput(int num)
{
    int i=0;
    while(num>0)
    {
        
        num/=10;
        i++;
        
        
    }
    if(i<=2) return 1;
    else return 0;
    
}

int main()
{
    int count = 0, loop=0, noOfDigit;
    int *array = NULL;
    while(1)
    {
        int input;
        cin>>input;
        if(input==42)
            break;
        else
        {
            noOfDigit = checkNoOfDigitInInput(input);
            if(noOfDigit)
            {
                count+=10;
                array = (int *)realloc(array, count*sizeof(int));
                array[loop] = input;
                loop++;
                
            }
            else break;
            
        }
        
    }
    for(int i=0;i<loop;i++)
    {
        
        cout<<array[i]<<endl;
    }
    // cout<<output
    return 0;
}
