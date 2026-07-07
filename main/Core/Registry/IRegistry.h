#ifndef IREGISTRY_H
#define IREGISTRY_H

#include <string>
#include <memory>
#include <vector>

namespace ChemistryReactionCalculator
{
    template <typename T>
    class IRegistry
    {
    public:
        virtual ~IRegistry() = default;

        virtual bool registerObject(const std::string& name, std::shared_ptr<T> object) = 0;

        [[nodiscard]] virtual std::shared_ptr<T> getObject(const std::string& name) const = 0;

        [[nodiscard]] virtual bool hasObject(const std::string& name) const = 0;

        [[nodiscard]] virtual std::vector<std::string> getAllNames() const = 0;

        [[nodiscard]] virtual std::string getRegistryType() const = 0;

        [[nodiscard]] virtual size_t size() const = 0;
    };
} // namespace ChemistryReactionCalculator

#endif // IREGISTRY_H
