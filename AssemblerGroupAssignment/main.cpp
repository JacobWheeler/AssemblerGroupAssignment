//
//  main.cpp
//  AssemblerGroupAssignment
//
//  Created by Jacob Wheeler, Gabe Cerritos, Katie Rose on 9/6/19.
//  Copyright © 2019 Jacob Wheeler. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <bitset>
#include "Instruction.h"
using namespace std;


// FUNCTION DECLARATIONS
void readFile(string file);
bitset<4> opcodeConversion(string s);
bitset<2> registerConversion(string s);
bitset<8> immediateConversion(int n);


// MAIN
int main(int argc, const char * argv[]) {
    
    
    return 0;
}


// TODO:    1) Loop through strings in readFile and send the parts to the appropriate
//          functions in order to turn them into binary...
//          2) Shift the bits and | them together with the next assembly instruction
//          3) Output to outStream("Assembler_Converted.bin")
//                  3a) This will store the binary in a .bin file...
//                  3b) If we output a string to the .bin file it will still
//                  act as a .txt file...
//          4) Call functions in main to actually run the program


// FUNCTION DEFINITIONS
void readFile(string file) {
    // Variables
    ifstream myStream(file);
    ofstream outStream("Assembler_Converted.bin");
    
    
    // Get lines of file while not at the end of file
    while (!myStream.eof()) {
        // Create string variable and store line
        string str;
        getline(myStream, str);
        
        
    }
}


// Convert string into 4 bit binary
bitset<4> opcodeConversion(string s) {
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
bitset<2> registerConversion(string s) {
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


// Convert integer into 8 bit Binary
bitset<8> immediateConversion(int n) {
    bitset<8> immediateBin(n);
    return immediateBin;
}
