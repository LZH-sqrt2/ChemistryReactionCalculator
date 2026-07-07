#ifndef REGISTRY_BUILDER_H
#define REGISTRY_BUILDER_H

#include "IRegistry.h"
#include "Registry.h"
#include <memory>
#include <string>
#include <unordered_map>

namespace ChemistryReactionCalculator
{
    template <typename T>
    class RegistryBuilder
    {
    public:
        static RegistryBuilder<T> create(const std::string& registryName)
        {
            return RegistryBuilder<T>(registryName);
        }

        RegistryBuilder<T>& registerObject(const std::string& name, std::shared_ptr<T> object)
        {
            objects_[name] = std::move(object);
            return *this;
        }

        std::shared_ptr<IRegistry<T>> build()
        {
            if (built_)
            {
                return registry_;
            }

            registry_ = std::make_shared<ConcreteRegistry<T>>(registryName_);

            for (auto& pair : objects_)
            {
                registry_->registerObject(pair.first, std::move(pair.second));
            }
            objects_.clear();

            Registry::instance().registerRegistry(registryName_, registry_);

            built_ = true;
            return registry_;
        }

        std::vector<std::string> getRegisteredNames() const
        {
            std::vector<std::string> names;
            for (const auto& pair : objects_)
            {
                names.push_back(pair.first);
            }
            return names;
        }

    private:
        explicit RegistryBuilder(const std::string& name) : registryName_(name), built_(false)
        {
        }

        template <typename U>
        class ConcreteRegistry final : public IRegistry<U>
        {
        public:
            explicit ConcreteRegistry(const std::string& name) : typeName_(name)
            {
            }

            bool registerObject(const std::string& name, std::shared_ptr<U> object) override
            {
                if (objects_.contains(name))
                {
                    return false;
                }
                objects_[name] = std::move(object);
                return true;
            }

            std::shared_ptr<U> getObject(const std::string& name) const override
            {
                auto it = objects_.find(name);
                if (it != objects_.end())
                {
                    return it->second;
                }
                return nullptr;
            }

            bool hasObject(const std::string& name) const override
            {
                return objects_.contains(name);
            }

            std::vector<std::string> getAllNames() const override
            {
                std::vector<std::string> names;
                names.reserve(objects_.size());
                for (const auto& pair : objects_)
                {
                    names.push_back(pair.first);
                }
                return names;
            }

            std::string getRegistryType() const override { return typeName_; }
            size_t size() const override { return objects_.size(); }

        private:
            std::string typeName_;
            std::unordered_map<std::string, std::shared_ptr<U>> objects_;
        };

        std::string registryName_;
        std::shared_ptr<IRegistry<T>> registry_;
        std::unordered_map<std::string, std::shared_ptr<T>> objects_;
        bool built_;
    };
} // namespace ChemistryReactionCalculator

#endif // REGISTRY_BUILDER_H
