#ifndef ISOLVER_H
#define ISOLVER_H

#include "Equation.h"
#include <vector>
#include <any>
#include <string>
#include <memory>

struct SolverResult
{
    bool success;
    std::string errorMessage;
    std::any solution;
};

class ISolver
{
public:
    virtual ~ISolver() = default;

    [[nodiscard]] virtual SolverResult solve(
        std::shared_ptr<Equation> equation,
        const std::vector<double>& params
    ) = 0;

    [[nodiscard]] virtual EquationType getSupportedType() const = 0;
    [[nodiscard]] virtual std::string getSolverName() const = 0;
};

#endif //ISOLVER_H
