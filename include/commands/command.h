#ifndef COMMAND_H
#define COMMAND_H
#include "osenv/console.h"

/*
 * Command Table:
 * ALL ARGUMENTS MUST BE 16 DIGITS/CHARACTERS LONG
 * 
 * BASIC ARITHMATIC AND SOME ADVANCED FUNCTIONS
 * ADD  A, B 
 * SUB  A, B 
 * MUL  A, B
 * DIV  A, B
 * MOD  A, B
 * LOG  A, B
 * LN   A, B
 * 
 * LOGIC/BITWISE OPERATIONS
 * AND  A, B
 * OR   A, B
 * XOR  A, B
 * XAND A, B
 * NOT  A, B
 * XNOT A, B
 * SFTL A, B
 * SFTR A, B
 * 
 * USER INTERFACE STUFF
 * PTS  A, B (PRINT TO SCREEN, EACH ARGUMENT DOES NOT HAVE A NEW LINE)
 * EXIT
 * 
 * WILL ADD DEVICE PIN REGISTERS LATER
 */

//

void Help()
{
    Println("Please Read the list of commands.");
}

std::vector<std::string> split(std::string s, std::string delim) {
    std::vector<std::string> res;
    if (s.length() == 0 || s.find(delim) == std::string::npos) {
        return res;
    }

    // Datatype manipulation for algorithm manipulation
    // Println("IN SPLIT FUNCTION");
    char * cs = new char[s.length()];   // Manipulated string
    memcpy(cs, s.c_str(), s.length());  // Allocating string
    char * ptr = std::strtok(cs, " ");  // String Token Algorithm
    std::string val = "";               // Actual string value ot be pushed into vector

    // string value appending to vector manipulation technique/algorithm
    while (ptr != NULL) {
        val.append(ptr);
        res.push_back(val);
        ptr = std::strtok(NULL, " ");
        val.clear();
    }

    // cleanup
    free(cs);
    return res;
}

// Runs the commands into a specific organized fashion
bool runCommand(std::vector<std::string> Cmd) {
    // If the user enters nothing
    if (Cmd.size() == 0) {
        Println(" ");
        return 0;
    }

    // Convert CMD String Array to command variable types
    std::string cmd = Cmd.at(0);
    cmd = toUpper(cmd);

    // Exit Command
    if (cmd == "EXIT")
    {
        Printf("GOOD BYE =)");
        Active_Console = false;
        Cmd = std::vector<std::string>();
        return 1;
    }

    if (cmd == "HELP") {
        Help();
    }
        
    // Just in case they entered the number of arguments
    if (Cmd.size() == 1) {
        Help();
        return 0;
    } 

    // Command Variable Assignments 
    std::string arg1 = Cmd.at(1);
    std::string arg2 = "";
    


    if (arg1.length() > 16) {
        ERROR("ERROR: ARGUMENT 1 IS TOO LONG");
    }

    if (Cmd.size() > 2) {
        arg2 = Cmd.at(2);
        if (arg2.length() > 16) {
            ERROR("ERROR: ARGUMENT 2 IS TOO LONG");
            return 0;
        }
    }
    

    // ADDITION
    if (cmd == "ADD") {
        if (arg1.length() == 0 || arg2.length() == 0) {
            ERROR("NOT ENOUGH ARGUMENTS DETECTED");
            return 0;
        }
        Printf("Value of %d + %d = %d", Str_toI(arg1), Str_toI(arg2), ADD(Str_toI(arg1), Str_toI(arg2)));
        return 1;
    }

    // SUBTRACTION
    else if (cmd == "SUB")
    {
        if (arg1.length() == 0 || arg2.length() == 0) {
            ERROR("NOT ENOUGH ARGUMENTS DETECTED");
            return 0;
        }
        Printf("Value of %d - %d = %d", Str_toI(arg1), Str_toI(arg2), SUB(Str_toI(arg1), Str_toI(arg2)));
        return 1;
    }

    // DIVISION
    else if (cmd == "DIV")
    {
        Printf("Value of %d / %d = %d", Str_toI(arg1), Str_toI(arg2), DIV(Str_toI(arg1), Str_toI(arg2)));
        return 1;
    }

    // MULTIPLICATION
    else if (cmd == "MUL")
    {
        Printf("Value of %d * %d = %d", Str_toI(arg1), Str_toI(arg2), MUL(Str_toI(arg1), Str_toI(arg2)));
        return 1;
    }

    // MODULUS
    else if (cmd == "MOD")
    {
        Printf("Value of %d - %d = %d", Str_toI(arg1), Str_toI(arg2), SUB(Str_toI(arg1), Str_toI(arg2)));
        return 1;
    }

    /*
     * Boolean Algebra
     */
    
    // AND
    else if (cmd == "AND")
    {
        Printf("Value of %d * %d = %d", Str_toI(arg1), Str_toI(arg2), AND(Str_toI(arg1), Str_toI(arg2)));
        return 1;
    }

    // NAND
    else if (cmd == "NAND") {
        Printf("Value of ~(%d * %d) = %d", Str_toI(arg1), Str_toI(arg2), NAND(Str_toI(arg1), Str_toI(arg2)));
        return 1;
    }

    // OR
    else if (cmd == "OR")
    {
        Printf("Value of %d + %d = %d", Str_toI(arg1), Str_toI(arg2), OR(Str_toI(arg1), Str_toI(arg2)));
        return 1;
    }

    // NOR
    else if (cmd == "NOR") {
        Printf("Value of ~(%d + %d) = %d", Str_toI(arg1), Str_toI(arg2), NOR(Str_toI(arg1), Str_toI(arg2)));
        return 1;
    }

    // XOR
    else if (cmd == "XOR")
    {
        Printf("Value of %d (+) %d = %d", Str_toI(arg1), Str_toI(arg2), XOR(Str_toI(arg1), Str_toI(arg2)));
        return 1;
    }

    // // XNOR
    else if (cmd == "XNOR")
    {
        Printf("Value of %d (*) %d = %d", Str_toI(arg1), Str_toI(arg2), XNOR(Str_toI(arg1), Str_toI(arg2)));
        return 1;
    }

    // NOT
    else if (cmd == "NOT") {
        Printf("Value of ~%d = %d", Str_toI(arg1), NOT(Str_toI(arg1)));
        return 1;
    }

    // SHIFT LEFT
    else if (cmd == "SFTL")
    {
        Printf("Value of ");
        Printf("%d", arg1);
        Printf(" << ");
        Printf("%d", arg2);
        Printf(" = %d", shiftLeft(Str_toI(arg1), Str_toI(arg2)));
        return 1;
    }

    // SHIFT RIGHT
    else if (cmd == "SFTR")
    {
        Printf("Value of %d >> %d = %d", arg1, arg2, shiftRight(Str_toI(arg1), Str_toI(arg2)));
        return 1;
    }

    // PRINT TO SCREEN
    else if (cmd == "PTS")
    {
        Printf("%s%s", (arg1, arg2));
        Println(" ");
        return 1;
    }

    else {
        Help();
    }

    Cmd = std::vector<std::string>();
    return 1;
}

#endif