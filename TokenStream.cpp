/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TokenStream.cpp
 * Author: stimpy
 * 
 * Created on May 16, 2017, 3:07 AM
 */


#include <stdexcept>
#include "TokenStream.hpp"


namespace arithmetic_parser {

    
    TokenStream::TokenStream()
    : full(false), buffer(0) {}

    
    TokenStream::TokenStream(const TokenStream& orig)
    : full(orig.full), buffer(orig.buffer) {}

    
    TokenStream::~TokenStream() {
    }

    
    void TokenStream::putback(Token tk) {
        if (full) 
            throw std::runtime_error("putback() into a full buffer");
        buffer = tk;
        full = true;
    }


    Token TokenStream::get() {
        if (full) {
            full = false;
            return buffer;
        }
        char ch;
        std::cin >> ch;
        switch(ch) {
            case PRINT:  case QUIT:
            case '(':  case ')':  case '{':  case '}':
            case '!':
            case '+':  case '-':  case '*':  case '/':
                return Token(ch);
            case '.':  case '0':  case '1':  case '2':  case '3':  case '4':
            case '5':  case '6':  case '7':  case '8':  case '9': {
                std::cin.putback(ch);
                double val;
                std::cin >> val;
                return Token('8', val);
            }
            default:
                throw std::runtime_error("Bad token");
        }
    }
    

} // arithmetic_parser
