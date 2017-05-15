/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: stimpy
 *
 * Created on May 15, 2017, 9:53 PM
 */

#include <cstdlib>
#include <iostream>
#include "Token.hpp"


/*
 * 
 */
int main(int argc, char** argv) {

    arithmetic_parser::Token t1('8', 3.00);
    std::cout << t1 << std::endl;

    return 0;
}

