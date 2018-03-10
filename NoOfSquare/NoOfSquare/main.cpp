//
//  main.cpp
//  NoOfSquare
//
//  Created by Maquina on 30/04/16.
//  Copyright © 2016 Maquina. All rights reserved.
//

#include <iostream>

#define cin		std::cin
#define cout	std::cout
#define endl	std::endl

#define MAX_SQ 100

int noOfSquare(int n){
    int nos = 0;
    for (int i = 0; i <= n; i++){
        nos += i*i;
    }
    
    return nos;
}

int main(){
    int n;
    int tc = 0;
    int *result = new int[MAX_SQ];
    do{
        cin >> n;
        if (n == 0)	break;
        result[tc++] = noOfSquare(n);
    } while (n != 0);
    
    for (int i = 0; i < tc; i++){
        cout << result[i] << endl;
    }
}