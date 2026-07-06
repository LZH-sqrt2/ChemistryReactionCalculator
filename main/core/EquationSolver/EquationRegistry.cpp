#include "EquationRegistry.h"
#include "Equations.h"
#include <iostream>
#include <ranges>

namespace ChemistryReactionCalculator
{
    EquationRegistry& EquationRegistry::instance()
    {
        static EquationRegistry registry;
        return registry;
    }

    void EquationRegistry::registerEquation(const std::string& name,
                                            std::shared_ptr<Equation> equation)
    {
        if (equations_.contains(name))
        {
            return;
        }
        equations_[name] = std::move(equation);
    }

    std::shared_ptr<Equation> EquationRegistry::getEquation(const std::string& name) const
    {
        if (const auto it = equations_.find(name); it != equations_.end())
        {
            return it->second;
        }
        return nullptr;
    }

    bool EquationRegistry::hasEquation(const std::string& name) const
    {
        return equations_.contains(name);
    }

    std::vector<std::string> EquationRegistry::getAllEquationNames() const
    {
        std::vector<std::string> names;
        names.reserve(equations_.size());
        for (const auto& key : equations_ | std::views::keys)
        {
            names.push_back(key);
        }
        return names;
    }

    void registerDefaultEquations()
    {
        auto& registry = EquationRegistry::instance();

        registry.registerEquation("gibbs_free_energy",
                                  std::make_shared<GibbsFreeEnergyEquation>());
        registry.registerEquation("vanthoff",
                                  std::make_shared<VantHoffEquation>());
        registry.registerEquation("arrhenius",
                                  std::make_shared<ArrheniusEquation>());
        registry.registerEquation("ideal_gas",
                                  std::make_shared<IdealGasEquation>());
        registry.registerEquation("coulomb_energy",
                                  std::make_shared<CoulombEnergyEquation>());

        std::cout << "[Registry] 6 equation types registered (stub implementations)." << std::endl;
    }
} // namespace ChemistryReactionCalculator
