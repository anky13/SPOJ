//
//  main.cpp
//  WhatsNext
//
//  Created by Maquina on 30/04/16.
//  Copyright © 2016 Maquina. All rights reserved.
//

#include <iostream>

#define cin		std::cin
#define cout	std::cout
#define endl	std::endl

#define LIMIT	1000

int main(){
    
    int tc = 0;
    int a1, a2, a3;
    int *result = new int[LIMIT];
    bool *isAP = new bool[LIMIT];
    
    while(true){
        cin >> a1 >> a2 >> a3;
        
        if (a1 == 0 && a2 == 0 && a3 == 0){// End of Input
            break;
        }
        
        int diff_factor = a2 - a1;
        
        if (diff_factor == (a3 - a2)){//AP
            isAP[tc] = true;
            result[tc] = a3 + diff_factor;
        } else{//GP
            isAP[tc] = false;
            result[tc] = a3 * (a2 / a1);
        }
        ++tc;
    }
    
    //Print result
    for (int i = 0; i < tc; ++i){
        if (isAP[i]){
            cout << "AP " << result[i] << endl;
        }
        else{
            cout << "GP " << result[i] << endl;
        }
    }
}
