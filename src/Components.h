/**
 * @file Components.h
 * @brief Интерфейсы и реализации компонентов ПК.
 */
#pragma once
#include <string>
/**
 * @brief Абстрактный интерфейс материнской платы.
 */
class CPU {
    public:
    virtual ~CPU() {}
    virtual std::string name() const = 0;
    virtual std::string socket() const = 0;
    virtual double price() const = 0;
};
/**
 * @brief Абстрактный интерфейс материнской платы.
 */
class Motherboard {
    public:
    virtual ~Motherboard() {}
    virtual std::string name() const = 0;
    virtual std::string socket() const = 0;
    virtual double price() const = 0;
};
/** @brief Процессор Intel (LGA1700). */
class IntelCPU : public CPU {
    public:
    std::string name() const override;
    std::string socket() const override;
    double price() const override;
};
/** @brief Материнская плата Intel (LGA1700). */
class IntelMotherboard : public Motherboard {
    public:
    std::string name() const override;
    std::string socket() const override;
    double price() const override;
};
/** @brief Процессор AMD (AM5). */
class AMDCPU : public CPU {
    public:
    std::string name() const override;
    std::string socket() const override;
    double price() const override;
};
/** @brief Материнская плата AMD (AM5). */
class AMDMotherboard : public Motherboard {
    public:
    std::string name() const override;
    std::string socket() const override;
    double price() const override;
};