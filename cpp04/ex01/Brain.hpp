#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include<iostream>

class Brain {
    protected:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();
        void setIdea(int i, const std::string& s);
        std::string getIdea(int i) const;
};

#endif