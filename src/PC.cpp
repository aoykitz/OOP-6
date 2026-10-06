/**
 * @file PC.cpp
 * @brief Реализация PC и Builder.
 */
#include "PC.h"
#include <iostream>
#include <stdexcept>

PC::PC() : cpu_(0), mb_(0) {}
PC::~PC() { delete cpu_; delete mb_; }

void PC::setPlatform(const std::string& p) { platform_ = p; }
void PC::setCPU(CPU* c) { delete cpu_; cpu_ = c; }
void PC::setMotherboard(Motherboard* m) { delete mb_; mb_ = m; }

double PC::totalPrice() const {
    double t = 0;
    if (cpu_) t += cpu_->price();
    if (mb_)  t += mb_->price();
    return t;
}

void PC::print() const {
    std::cout << "Платформа: " << platform_ << "\n";
    if (cpu_) std::cout << "CPU:   " << cpu_->name() << " (" << cpu_->socket() << ") - $" << cpu_->price() << "\n";
    if (mb_)  std::cout << "Плата: " << mb_->name()  << " (" << mb_->socket()  << ") - $" << mb_->price()  << "\n";
    std::cout << "Итого: $" << totalPrice() << "\n";
}

PCBuilder::PCBuilder() : cpu_(0), mb_(0) {}
PCBuilder::~PCBuilder() { delete cpu_; delete mb_; }

void PCBuilder::setPlatform(const std::string& p) { platform_ = p; }
void PCBuilder::setCPU(CPU* c) { delete cpu_; cpu_ = c; }
void PCBuilder::setMotherboard(Motherboard* m) { delete mb_; mb_ = m; }

bool PCBuilder::validate() const {
    if (!cpu_ || !mb_) return false;
    return cpu_->socket() == mb_->socket();
}

PC* PCBuilder::build() {
    if (!validate())
        throw std::runtime_error("Несовместимые сокеты");
    PC* pc = new PC();
    pc->setPlatform(platform_);
    pc->setCPU(cpu_);
    pc->setMotherboard(mb_);
    cpu_ = 0;
    mb_ = 0;
    return pc;
}