#ifndef EQUATIONS_H
#define EQUATIONS_H

#include "Equation.h"
#include <string>

namespace ChemistryReactionCalculator
{
    class GibbsFreeEnergyEquation final : public Equation
    {
    public:
        [[nodiscard]] EquationType getType() const override { return EquationType::Transcendental; }
        [[nodiscard]] std::string getEquationName() const override { return "Gibbs Free Energy"; }

        [[nodiscard]] std::string getOriginalDescription() const override
        {
            return R"(\Delta G = \Delta H - T \cdot \Delta S)";
        }

        SolverResult solve(const std::vector<double>& params) override
        {
            SolverResult result;
            result.success = false;
            result.errorMessage = "Not implemented yet. Will be handled by solver.";
            return result;
        }
    };

    class VantHoffEquation final : public Equation
    {
    public:
        [[nodiscard]] EquationType getType() const override { return EquationType::Transcendental; }
        [[nodiscard]] std::string getEquationName() const override { return "Van't Hoff Equation"; }

        [[nodiscard]] std::string getOriginalDescription() const override
        {
            return R"(\ln\frac{K_2}{K_1} = -\frac{\Delta H}{R}\left(\frac{1}{T_2} - \frac{1}{T_1}\right))";
        }

        SolverResult solve(const std::vector<double>& params) override
        {
            SolverResult result;
            result.success = false;
            result.errorMessage = "Not implemented yet. Will be handled by solver.";
            return result;
        }
    };

    class ArrheniusEquation final : public Equation
    {
    public:
        [[nodiscard]] EquationType getType() const override { return EquationType::Transcendental; }
        [[nodiscard]] std::string getEquationName() const override { return "Arrhenius Equation"; }

        [[nodiscard]] std::string getOriginalDescription() const override
        {
            return R"(k = A \cdot e^{-\frac{E_a}{RT}})";
        }

        SolverResult solve(const std::vector<double>& params) override
        {
            SolverResult result;
            result.success = false;
            result.errorMessage = "Not implemented yet. Will be handled by solver.";
            return result;
        }
    };

    class IdealGasEquation final : public Equation
    {
    public:
        [[nodiscard]] EquationType getType() const override { return EquationType::Transcendental; }
        [[nodiscard]] std::string getEquationName() const override { return "Ideal Gas Law"; }

        [[nodiscard]] std::string getOriginalDescription() const override
        {
            return R"(P \cdot V = n \cdot R \cdot T)";
        }

        SolverResult solve(const std::vector<double>& params) override
        {
            SolverResult result;
            result.success = false;
            result.errorMessage = "Not implemented yet. Will be handled by solver.";
            return result;
        }
    };

    class CoulombEnergyEquation final : public Equation
    {
    public:
        [[nodiscard]] EquationType getType() const override { return EquationType::Transcendental; }
        [[nodiscard]] std::string getEquationName() const override { return "Coulomb Energy"; }

        [[nodiscard]] std::string getOriginalDescription() const override
        {
            return R"(E = k_e \frac{q_1 q_2}{r})";
        }

        SolverResult solve(const std::vector<double>& params) override
        {
            SolverResult result;
            result.success = false;
            result.errorMessage = "Not implemented yet. Will be handled by solver.";
            return result;
        }
    };
} // namespace ChemistryReactionCalculator

#endif // EQUATIONS_H
