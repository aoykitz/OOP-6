#include "Factories.h"

std::string IntelFactory::platformName() const { return "Intel"; }
CPU* IntelFactory::createCPU() const { return new IntelCPU(); }
Motherboard* IntelFactory::createMotherboard() const { return new IntelMotherboard(); }

std::string AMDFactory::platformName() const { return "AMD"; }
CPU* AMDFactory::createCPU() const { return new AMDCPU(); }
Motherboard* AMDFactory::createMotherboard() const { return new AMDMotherboard(); }