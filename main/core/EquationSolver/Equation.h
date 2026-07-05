#ifndef EQUATION_H
#define EQUATION_H

#include <string>
#include <vector>
#include <any>

namespace ChemistryReactionCalculator {

enum class EquationType
{
    OrdinaryDifferential,
    PartialDifferential,
    Transcendental,
    Polynomial,
    LinearSystem
};

struct SolverResult
{
    bool success;
    std::string errorMessage;
    std::any solution;
};

class Equation
{
public:
    virtual ~Equation() = default;

    [[nodiscard]] virtual EquationType getType() const = 0;
    [[nodiscard]] virtual std::string getEquationName() const = 0;
    [[nodiscard]] virtual std::string getOriginalDescription() const = 0;

    [[nodiscard]] virtual SolverResult solve(const std::vector<double>& params) = 0;
};

} // namespace ChemistryReactionCalculator

#endif // EQUATION_H
