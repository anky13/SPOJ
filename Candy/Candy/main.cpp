//
//  main.cpp
//  Candy
//
//  Created by Maquina on 30/04/16.
//  Copyright © 2016 Maquina. All rights reserved.
//

#include <iostream>

#define cin		std::cin
#define cout	std::cout
#define endl	std::endl

#define LIMIT 1000

int main(){
    int tc = 0;
    int nPackets;
    int *result = new int[LIMIT];
    
    while (true){
        cin >> nPackets;
        
        if (nPackets == -1){// End of Input
            break;
        }
        
        int *candy = new int[nPackets];
        int totalCandy = 0;
        for (int i = 0; i < nPackets; ++i){
            cin >> candy[i];
            totalCandy += candy[i];
        }
        
        int candyToGet = (totalCandy / nPackets);
        if (totalCandy % nPackets != 0){// Cant be divided equally
            result[tc] = -1;
        }
        else{
            int moves = 0;
            for (int i = 0; i < nPackets; ++i){
                if (candy[i] < candyToGet){
                    moves += (candyToGet - candy[i]);
                }
            }
            result[tc] = moves;
        }
        ++tc;
    }
    
    //Print Result
    for (int i = 0; i < tc; ++i){
        cout << result[i] << endl;
    }
}
