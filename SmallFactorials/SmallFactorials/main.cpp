//
//  main.cpp
//  SmallFactorials
//
//  Created by Maquina on 30/04/16.
//  Copyright © 2016 Maquina. All rights reserved.
//

#include <iostream>
#include <cmath>

#define cin     std::cin
#define cout    std::cout
#define endl    std::endl

#define LIMIT 200

int main(){
    int tc;
    cin>>tc;
    
    int **fact = new int*[tc];
    for(int i = 0; i < tc; i++){
        fact[i] = new int[LIMIT];
    }
    int *digit = new int[tc];
    
    //Initialize fact list
    for(int i = 0; i < tc; i++){
        for(int j = 0; j < LIMIT; j++){
            fact[i][j] = 0;
        }
    }
    
    for(int i = 0; i < tc; i++){
        int n;
        cin>>n;
        
        // First element must be 1
        fact[i][0] = 1;
        int carry = 0;
        int total_digit = 1;
        int count_digit;
        int k;
        for(int j = 2; j <= n; j++){
            for(k = 0;; k++){
                if(fact[i][k] == 0 && carry == 0){
                    if(k >= total_digit)
                        break;
                }
                
                fact[i][k] *= j;
                fact[i][k] = (carry == 0 ? fact[i][k] : fact[i][k] + carry);
                carry = fact[i][k]/10;
                fact[i][k] %= 10;
                count_digit = k;
            }
            total_digit = k;
        }
        digit[i] = total_digit - 1;
    }
    
    for(int i = 0; i < tc ; ++i){
        for(int j = digit[i]; j >= 0; --j){
            cout<<fact[i][j];
        }
        cout<<endl;
    }
}
