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
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include "Instruction.h"
using namespace std;


// FUNCTION DECLARATIONS
vector <string> readFile(string file, vector <string> v);
bitset<4> opcodeConversion(string s);
bitset<2> registerConversion(string s);
bitset<8> immediateConversion(int n);


// MAIN
int main(int argc, const char * argv[]) {
    vector <string> inputStrings;
    vector <string> z = readFile("gcd.s", inputStrings);
  
    for(int i = 0; i < z.size(); i++){
        cout << z[i];
    }
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
vector<string> readFile(string file, vector<string> v) {
    // Variables
    ifstream myStream(file);
    ofstream outStream("Assembler_Converted.bin");
    stringstream sstr;
    
    // Get lines of file while not at the end of file
    
    // Create string variable and store line
    string line;
    while (getline(myStream, line)) {
        stringstream splitter(line);
        string name;
        string arg1;
        string arg2;
        string arg3;
        splitter >> name;
        splitter >> arg1;
        splitter >> arg2;
        splitter >> arg3;
//        cout << name << endl << arg1<< endl << arg2 << endl << arg3 << endl;
        bitset<16> completeBinary;
        bitset<16> opcode = (bitset<16>)(opcodeConversion(name).to_ulong());
        opcode <<= 12;
        completeBinary |= opcode;
        if(arg1[0] == '$'){
            bitset<16> reg1 = (bitset<16>)(registerConversion(arg1).to_ulong());
            reg1 <<= 10;
            completeBinary |= reg1;
        }else{
            int imm = stoi(arg1);
            bitset<16> imm1 = (bitset<16>)(immediateConversion(imm).to_ulong());
            imm1 <<= 4;
            completeBinary |= imm1;
        }
        if(!(arg2.empty())){
            if(arg2[0] == '$'){
                bitset<16> reg2 = (bitset<16>)(registerConversion(arg2).to_ulong());
                reg2 <<= 8;
                completeBinary |= reg2;
            }else{
                int imm = stoi(arg2);
                bitset<16> imm1 = (bitset<16>)(immediateConversion(imm).to_ulong());
                imm1 <<= 2;
                completeBinary |= imm1;
            }
        }
        if(!(arg3.empty())){
            if(arg3[0] == '$'){
                bitset<16> reg3 = (bitset<16>)(registerConversion(arg3).to_ulong());
                reg3 <<= 6;
                completeBinary |= reg3;
            }else{
                int imm = stoi(arg3);
                bitset<16> imm1 = (bitset<16>)(immediateConversion(imm).to_ulong());
                completeBinary |= imm1;
            }
        }
        ofstream outStream("Assembler_Converted.bin");
        outStream << completeBinary << endl;
        cout << completeBinary << endl;
    }
    
    
    return v;
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
