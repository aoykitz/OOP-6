/**
 * @file Factories.h
 * @brief Абстрактная фабрика компонентов платформ.
 */
#pragma once
#include "Components.h"
/**
 * @brief Абстрактная фабрика: создаёт совместимый набор CPU + Motherboard.
 */
class PlatformFactory {
public:
    virtual ~PlatformFactory() {}
    virtual std::string platformName() const = 0;
    virtual CPU* createCPU() const = 0;
    virtual Motherboard* createMotherboard() const = 0;
};
/** @brief Фабрика компонентов Intel. */
class IntelFactory : public PlatformFactory {
public:
    std::string platformName() const override;
    CPU* createCPU() const override;
    Motherboard* createMotherboard() const override;
};
/** @brief Фабрика компонентов AMD. */
class AMDFactory : public PlatformFactory {
public:
    std::string platformName() const override;
    CPU* createCPU() const override;
    Motherboard* createMotherboard() const override;
};