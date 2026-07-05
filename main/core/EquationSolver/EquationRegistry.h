#ifndef EQUATION_REGISTRY_H
#define EQUATION_REGISTRY_H

#include "Equation.h"
#include <memory>
#include <unordered_map>
#include <string>
#include <vector>

namespace ChemistryReactionCalculator {

class EquationRegistry {
public:
    static EquationRegistry& instance();

    void registerEquation(const std::string& name, std::shared_ptr<Equation> equation);

    [[nodiscard]] std::shared_ptr<Equation> getEquation(const std::string& name) const;

    [[nodiscard]] bool hasEquation(const std::string& name) const;

    [[nodiscard]] std::vector<std::string> getAllEquationNames() const;

private:
    EquationRegistry() = default;
    std::unordered_map<std::string, std::shared_ptr<Equation>> equations_;
};

inline void registerEquation(const std::string& name, std::shared_ptr<Equation> eq) {
    EquationRegistry::instance().registerEquation(name, std::move(eq));
}

inline std::shared_ptr<Equation> getEquation(const std::string& name) {
    return EquationRegistry::instance().getEquation(name);
}

void registerDefaultEquations();

} // namespace ChemistryReactionCalculator

#endif // EQUATION_REGISTRY_H