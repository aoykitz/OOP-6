#pragma once
#include <string>
class CPU {
    public:
    virtual ~CPU() {}
    virtual std::string name() const = 0;
    virtual std::string socket() const = 0;
    virtual double price const = 0;
};

class Motherboard {
    public:
    virtual ~Motherboard() {}
    virtual std::string name() const = 0;
    virtual std::string socket() const = 0;
    virtual double price const = 0;
};

class IntelCPU : public CPU {
    public:
    std::string name() const override;
    std::string socket() const override;
    double price() const override;
};
class IntelMotherboard : public Motherboard {
    public:
    std::string name() const override;
    std::string socket() const override;
    double price() const override;
};

class AMDCPU : public CPU {
    public:
    std::string name() const override;
    std::string socket() const override;
    double price() const override;
};
class AMDMotherboard : public Motherboard {
    public:
    std::string name() const override;
    std::string socket() const override;
    double price() const override;
};