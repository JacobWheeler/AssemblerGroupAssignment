//
//  main.cpp
//  AssemblerGroupAssignment
//
//  Created by Jacob Wheeler, Gabe Cerritos, Katie Rose on 9/6/19.
//  Copyright © 2019 Jacob Wheeler. All rights reserved.
//

// This is a test comment

#include <iostream>
#include <fstream>
#include <bitset>
#include "Instruction.h"
using namespace std;


//void readFile(string file){
//    ifstream mystream;
//    ofstream output;
//    getline()
//
//}


// Convert string into 4 bit binary
bitset<4> opcodeConversion(string s){
    int opcode = 0;
    // If statement to check which opcode to return
    if(s == "addi"){
        opcode = 1;
    }else if(s == "blt"){
        opcode = 2;
    }else if(s == "bne"){
        opcode = 3;
    }else if(s == "j"){
        opcode = 4;
    }else if(s == "mul"){
        opcode = 5;
    }else if(s == "sub"){
        opcode = 6;
    }else if(s == "read"){
        opcode = 7;
    }else if(s == "print"){
        opcode = 8;
    }
    bitset<4> opcodeBin(opcode);
    return opcodeBin;
}

// Convert integer into 2 bit binary
bitset<2> registerConversion(int n){
    bitset<2> registerConversion(string s){
        int registerNum = 0;
        if(s == "$0"){
            registerNum = 0;
        }else if(s == "$1"){
            registerNum = 1;
        }else if(s == "$2"){
            registerNum = 2;
        }else if(s == "$3"){
            registerNum = 3;
        }
        bitset<2> registerBin(registerNum);
        return registerBin;
    }
}

// Convert integer into 8 bit Binary
bitset<8> immediateConversion(int n){
    bitset<8> immediateBin(n);
    return immediateBin;
}

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
