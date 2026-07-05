#include "EquationRegistry.h"

EquationRegistry& EquationRegistry::instance() {
    static EquationRegistry registry;
    return registry;
}

void EquationRegistry::registerEquation(const std::string& name,
                                        std::shared_ptr<Equation> equation) {
    if (equations_.contains(name)) {
        //TODO: throw error
    }
    equations_[name] = std::move(equation);
}

std::shared_ptr<Equation> EquationRegistry::getEquation(const std::string& name) const {
    if (const auto it = equations_.find(name); it != equations_.end()) {
        return it->second;
    }
    return nullptr;
}

bool EquationRegistry::hasEquation(const std::string& name) const {
    return equations_.contains(name);
}