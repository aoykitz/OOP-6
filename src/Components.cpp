#include "Components.h"

std::string IntelCPU::name() const { return "Intel i7-13700k"; }
std::string IntelCPU::socket() const { return "LGA1700"; }
double IntelCPU::price() const { return 400; }

std::string IntelMotherboard::name() const { return "ASUS Z790"; }
std::string IntelMotherboard::socket() const { return "LGA1700"; }
double IntelCPU::price() const { return 250; }

std::string AMDCPU::name() const { return "AMD Ryzen 7 7800X3D"; }
std::string AMDCPU::socket() const { return "AM5"; }
double AMDCPU::price() const { return 450; }

std::string AMDMotherboard::name() const { return "MSI B650"; }
std::string AMDMotherboard::socket() const { return "AM5"; }
double AMDMotherboard::price() const { return 200; }