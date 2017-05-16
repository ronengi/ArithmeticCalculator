/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArithmeticParser.cpp
 * Author: stimpy
 * 
 * Created on May 16, 2017, 3:14 PM
 */

#include "ArithmeticParser.hpp"


namespace arithmetic_parser {


    ArithmeticParser::ArithmeticParser()
    : ts() {
        parse_input();
    }

    
    ArithmeticParser::ArithmeticParser(const ArithmeticParser& orig)
       : ts(orig.ts) {}
    

    ArithmeticParser::~ArithmeticParser() {
    }


    
    double ArithmeticParser::primary() {
        double d = 0;
        Token tk = ts.get();
        switch (tk.getKind()) {
            case '-':
                d = primary() * (-1);
                break;
            case '(':
                d = expression();
                tk = ts.get();
                if (tk.getKind() != ')')
                    throw std::runtime_error("')' expected");
                break;
            case '{':
                d = expression();
                tk = ts.get();
                if (tk.getKind() != '}')
                    throw std::runtime_error("'}' expected");
                break;
            case '8':
                d = tk.getValue();
                break;
            default:
                throw std::runtime_error("primary expected");
        }

        // factorial rule
        tk = ts.get();
        if (tk.getKind() == '!') {
            double f = 1;
            for (int i=1; i<=d; ++i)
                f *= i;
            return f;
        }
        else {
            ts.putback(tk);
            return d;
        }
    }


    double ArithmeticParser::term() {
        double left = primary();
        double right = 0.0;
        Token tk = ts.get();
        while(true) {
            switch (tk.getKind()) {
                case '*':
                    left *= primary();
                    tk = ts.get();
                    break;
                case '/':
                    right = primary();
                    if (right == 0)
                        throw std::runtime_error("divide by zero");
                    left /= right;
                    tk = ts.get();
                    break;
                default:
                    ts.putback(tk);
                    return left;
            }
        }
    }


    double ArithmeticParser::expression() {
        double left = term();
        Token tk = ts.get();
        while (true) {
            switch (tk.getKind()) {
                case '+':
                    left += term();
                    tk = ts.get();
                    break;
                case '-':
                    left -= term();
                    tk = ts.get();
                    break;
                default:
                    ts.putback(tk);
                    return left;
            }
        }
    }


    int ArithmeticParser::parse_input() {
        std::cout << "Welcome to calculator!" << std::endl;
        std::cout << "Use: numbers + = * / ( ) { }" << std::endl;
        std::cout << "Use: '" << QUIT << "' to quit" << std::endl;
        std::cout << "Use: '" << PRINT << "' to print result" << std::endl;
        std::cout << PROMPT;
        
        try {
            double val = 0;
            bool mem = true;

            while (std::cin) {
                Token tk = ts.get();

                if (tk.getKind() == QUIT) {
                    std::cout << std::endl << "Goodbye!" << std::endl;
                    return 0;
                }
                else if (tk.getKind() == PRINT) {
                    if (mem)
                        std::cout << "mem= " << val << std::endl;
                    else
                        std::cout << "= " << val << std::endl;
                   std::cout << PROMPT;
                   mem = true;
                }
                else {
                    ts.putback(tk);
                    val = expression();
                    mem = false;
                }
            }
        }
        catch(std::exception& e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }
        catch(...) {
            std::cerr << "exception" << std::endl;
            return 2;
        }

        return 0;
    }


} // arithmetic_parser