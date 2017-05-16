/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TokenStream.hpp
 * Author: stimpy
 *
 * Created on May 16, 2017, 3:07 AM
 */

#ifndef TOKENSTREAM_HPP
#define TOKENSTREAM_HPP


#define PRINT '='
#define QUIT 'x'


#include "Token.hpp"


namespace arithmetic_parser {
    
    class TokenStream {
    public:
        TokenStream();
        TokenStream(const TokenStream& orig);
        virtual ~TokenStream();
        Token get();
        void putback(Token tk);
    private:
        bool full;
        Token buffer;
    };

} // arithmetic_parser


#endif /* TOKENSTREAM_HPP */

