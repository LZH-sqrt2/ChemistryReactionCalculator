#include "Registry.h"

#include <ranges>

namespace ChemistryReactionCalculator
{
    Registry& Registry::instance()
    {
        static Registry instance;
        return instance;
    }

    std::vector<std::string> Registry::getAllRegistryNames() const
    {
        std::vector<std::string> names;
        for (const auto& [fst, snd] : registries_ | std::views::keys)
        {
            names.push_back(snd);
        }
        return names;
    }
} // namespace ChemistryReactionCalculator
