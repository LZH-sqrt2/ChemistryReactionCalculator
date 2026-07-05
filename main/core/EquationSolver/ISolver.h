#ifndef ISOLVER_H
#define ISOLVER_H

#include "Equation.h"
#include <vector>
#include <string>
#include <memory>

namespace ChemistryReactionCalculator {

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

} // namespace ChemistryReactionCalculator

#endif // ISOLVER_H