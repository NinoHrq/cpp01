/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 22:39:17 by marvin            #+#    #+#             */
/*   Updated: 2026/03/03 23:26:34 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RPN.hpp"

#include <stack>
#include <sstream>
#include <cctype>
#include <stdexcept>

int RPN::eval(const std::string& expr)
{
    std::stack<int> st;
    std::istringstream iss(expr);
    std::string token;

    while(iss >> token)
    {
        if(token.length() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
            st.push(token[0] - '0');
        else if(token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
        {
            if(st.size() < 2)
                throw std::runtime_error("Error");
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            int res = 0;
            switch (token[0])
            {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/':
                    if(b == 0)
                        throw std::runtime_error("Error non divisable par zéro \n");
                    res = a / b;
                    break;
                default:
                    throw std::runtime_error("Error");
            }
            st.push(res);
        }
        else
            throw std::runtime_error("Error \n");
    }
    if(st.size() != 1)
        throw std::runtime_error("Error \n");
    return st.top();
}