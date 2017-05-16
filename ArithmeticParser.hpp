/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArithmeticParser.hpp
 * Author: stimpy
 *
 * Created on May 16, 2017, 3:14 PM
 */

#ifndef ARITHMETICPARSER_HPP
#define ARITHMETICPARSER_HPP


#define PROMPT "enter expression:  "


#include "TokenStream.hpp"

namespace arithmetic_parser {

    class ArithmeticParser {
    public:
        ArithmeticParser();
        ArithmeticParser(const ArithmeticParser& orig);
        virtual ~ArithmeticParser();
    private:
        TokenStream ts;

        double primary();
        double term();
        double expression();

        int parse_input();
    };


    


    
} // arithmetic_parser


#endif /* ARITHMETICPARSER_HPP */

