#ifndef DATATYPE_H
#define DATATYPE_H
#include <map>
#include <string>

struct Element
{
    std::string symbol;
    std::string name;
    double atomicMass;
    int atomicNumber;
};

struct Compound
{
    std::string formula;
    std::string name;
    std::string molarMass;
    std::map<std::string, int> composition;
    int charge;
};

struct ThermodynamicData
{
    double deltaHf;
    double deltaGf;
    double S;
};

struct ReactionResult
{
    bool isValid;
    std::string reactionType;
    std::string explanation;

};
#endif
