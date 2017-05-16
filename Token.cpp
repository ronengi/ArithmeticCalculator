/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Token.cpp
 * Author: stimpy
 * 
 * Created on May 15, 2017, 10:08 PM
 */


#include "Token.hpp"


namespace arithmetic_parser {


    Token::Token(char ch)
    : kind(ch), value(0) {}


    Token::Token(char ch, double val)
    : kind(ch), value(val) {}


    Token::Token(const Token& orig)
    : kind(orig.kind), value(orig.value) {}


    Token::~Token() {
    }


    char Token::getKind() const {
        return this->kind;
    }


    double Token::getValue() const {
        return this->value;
    }


    // Helper Functions


    std::ostream& operator<<(std::ostream& os, const Token& tk) {
        return os << "{" << tk.getKind() << ": " << tk.getValue() << "}";
    }


} // arithmetic_parser
