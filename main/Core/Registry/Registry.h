#ifndef REGISTRY_H
#define REGISTRY_H

#include "IRegistry.h"
#include <unordered_map>
#include <memory>
#include <string>
#include <typeindex>
#include <vector>

namespace ChemistryReactionCalculator
{
    class Registry
    {
    public:
        static Registry& instance();

        template <typename T>
        void registerRegistry(const std::string& name, std::shared_ptr<IRegistry<T>> registry)
        {
            std::type_index type_idx = std::type_index(typeid(T));
            auto key = std::make_pair(type_idx, name);
            registries_[key] = registry;
        }

        template <typename T>
        std::shared_ptr<IRegistry<T>> getRegistry(const std::string& name) const
        {
            std::type_index type_idx = std::type_index(typeid(T));
            auto key = std::make_pair(type_idx, name);
            auto it = registries_.find(key);
            if (it != registries_.end())
            {
                return std::static_pointer_cast<IRegistry<T>>(it->second);
            }
            return nullptr;
        }

        template <typename T>
        bool hasRegistry(const std::string& name) const
        {
            std::type_index type_idx = std::type_index(typeid(T));
            const auto key = std::make_pair(type_idx, name);
            return registries_.contains(key);
        }

        std::vector<std::string> getAllRegistryNames() const;

        size_t registryCount() const { return registries_.size(); }

    private:
        struct PairHash
        {
            size_t operator()(const std::pair<std::type_index, std::string>& p) const
            {
                return p.first.hash_code() ^ std::hash<std::string>()(p.second);
            }
        };

        Registry() = default;
        Registry(const Registry&) = delete;
        Registry& operator=(const Registry&) = delete;

        std::unordered_map<
            std::pair<std::type_index, std::string>,
            std::shared_ptr<void>,
            PairHash
        > registries_;
    };
} // namespace ChemistryReactionCalculator

#endif // REGISTRY_H
