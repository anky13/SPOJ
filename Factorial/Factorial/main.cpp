//
//  main.cpp
//  Factorial
//
//  Created by Maquina on 30/04/16.
//  Copyright © 2016 Maquina. All rights reserved.
//

#include <iostream>
#include <cmath>

#define cin     std::cin
#define cout    std::cout
#define endl    std::endl

int trailingZeros(int n){
    int count = 0;
    for(int i = 1;;i++){
        int jump = ceil(pow(5,i));
        if(jump <= n){
            //cout<<i<<" : No of multiples of "<<jump<<" = "<<(n/jump)<<endl;
            count += (n/jump);
        }else{
            break;
        }
    }
    return count;
}

int main(){
    int tc;
    cin>>tc;
    
    int result[tc];
    
    for(int i = 0; i < tc; i++){
        long n;
        cin>>n;
        
        //cout<<"int : "<<sizeof(int)<<"\tlong : "<<sizeof(long)<<endl;
        result[i] = trailingZeros(n);
    }
    
    for(int i = 0; i < tc; i++){
        cout<<result[i]<<endl;
    }
}
