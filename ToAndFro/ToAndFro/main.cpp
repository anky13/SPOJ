//
//  main.cpp
//  ToAndFro
//
//  Created by Maquina on 30/04/16.
//  Copyright © 2016 Maquina. All rights reserved.
//

#include <iostream>
#include <string>

#define cin		std::cin
#define cout	std::cout
#define endl	std::endl
#define string	std::string

#define LIMIT 200

string decipher(string cipher, int column){
    string decipherMsg = "";
    
    int row = cipher.length() / column;
    
    char **matrix = new char*[row];
    for (int i = 0; i < row; ++i){
        matrix[i] = new char[column];
    }
    
    //Populate matrix with cipher text to and fro
    bool isReverse = false;
    int textCount = 0;
    for (int i = 0; i < row; ++i){
        if (isReverse){// Populate in decreasing order of column(higher->lower)
            for (int j = column - 1; j >= 0; --j){
                matrix[i][j] = cipher[textCount++];
            }
            isReverse = false;
        }
        else{// Populate in increasing order of column(lower->higher)
            for (int j = 0; j < column; ++j){
                matrix[i][j] = cipher[textCount++];
            }
            isReverse = true;
        }
    }
    
    //Read from matrix column-wise to get decipher message
    for (int i = 0; i < column; ++i){
        for (int j = 0; j < row; ++j){
            decipherMsg += matrix[j][i];
        }
    }
    
    return decipherMsg;
}


int main(){
    
    int tc = 0;
    int col;
    
    string *result = new string[LIMIT];
    
    while (true){
        cin >> col;
        
        if (col == 0){//End of Input
            break;
        }
        
        string cipher;
        cin >> cipher;
        
        result[tc++] = decipher(cipher, col);
    }
    
    //Print Result
    for (int i = 0; i < tc; ++i){
        cout << result[i] << endl;
    }
    
    // Hold output scree
    int j;
    cin >> j;
}