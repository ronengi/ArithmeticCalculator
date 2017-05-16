/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Token.hpp
 * Author: stimpy
 *
 * Created on May 15, 2017, 10:08 PM
 */

#ifndef TOKEN_HPP
#define TOKEN_HPP


#include <iostream>


namespace arithmetic_parser {

    class Token {
    public:
        Token(char ch);
        Token(char ch, double val);
        Token(const Token& orig);
        virtual ~Token();
        char getKind() const;
        double getValue() const;

    private:
        char kind;
        double value;
    };


    std::ostream& operator<<(std::ostream& os, const Token& tk);

    
} // arithmetic_parser

#endif /* TOKEN_HPP */
