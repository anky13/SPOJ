
//
//  main.cpp
//  NSTEPS
//
//  Created by Maquina on 28/04/16.
//  Copyright © 2016 Maquina. All rights reserved.
//

#include <iostream>

#define cin     std::cin
#define cout    std::cout
#define endl    std::endl

int getNumberM(int x, int y){
    int number = -1;
    
    if (x == y){
        if (x % 2 == 0){// Even co-ordinates
            number = x + y;
        }
        else{
            number = (x + y) - 1;
        }
    }
    else if (x > y && (x - y) == 2){
        if (x % 2 == 0 && y % 2 == 0){// Even co-ordinates
            number = x + y;
        }
        else{// One of the coordinate is odd
            if ( (x % 2 == 0 && y % 2 != 0) || (x % 2 != 0 && y % 2 == 0) )
                number = -1;
            else
                number = (x + y) - 1;
        }
    }
    
    return number;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int tc;
    cin >> tc;
    
    int *result = new int[tc];
    
    for (int i = 0; i < tc; i++){
        int x, y;
        cin >> x >> y;
        
        if (x >= y){
            result[i] = getNumberM(x, y);
        }
        else{
            result[i] = -1;
        }
        
    }
    
    // Print Result
    for (int i = 0; i < tc; ++i){
        result[i] == -1 ? cout << "No Number" << endl : cout << result[i] << endl;
    }
    
    int i;
    cin >> i;
    return 0;
}
