/**
 * @file PC.h
 * @brief PC и Builder для пошаговой сборки.
 */
#pragma once
#include <string>
#include "Components.h"

/**
 * @brief Собранный ПК. Владеет компонентами, освобождает их в деструкторе.
 */
class PC {
public:
    PC();
    ~PC();

    void setPlatform(const std::string& p);
    void setCPU(CPU* c);
    void setMotherboard(Motherboard* m);

    CPU* getCPU() const { return cpu_; }
    Motherboard* getMotherboard() const { return mb_; }

    /** @brief Итоговая стоимость ПК. */
    double totalPrice() const;

    /** @brief Вывести спецификацию в stdout. */
    void print() const;

private:
    CPU* cpu_;
    Motherboard* mb_;
    std::string platform_;
    PC(const PC&);
    PC& operator=(const PC&);
};

/**
 * @brief Builder — пошаговая сборка ПК с проверкой совместимости.
 */
class PCBuilder {
public:
    PCBuilder();
    ~PCBuilder();

    void setPlatform(const std::string& p);
    void setCPU(CPU* c);
    void setMotherboard(Motherboard* m);

    /** @brief Проверить совпадение сокетов. */
    bool validate() const;

    /**
     * @brief Собрать ПК.
     */
    PC* build();

private:
    CPU* cpu_;
    Motherboard* mb_;
    std::string platform_;
    PCBuilder(const PCBuilder&);
    PCBuilder& operator=(const PCBuilder&);
};