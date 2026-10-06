/**
 * @file main.cpp
 * @brief Тесты и демонстрация конфигуратора ПК.
 */
#include <iostream>
#include <string>
#include <stdexcept>

#include "Components.h"
#include "Factories.h"
#include "PriceCatalog.h"
#include "PC.h"

static int g_ok = 0;
static int g_err = 0;

static void check(bool cond, const std::string& msg) {
    if (cond) { std::cout << "OK: " << msg << "\n"; ++g_ok; }
    else      { std::cout << "ERROR: " << msg << "\n"; ++g_err; }
}

static void runTests() {
    std::cout << "Tests:\n";

    check(&PriceCatalog::instance() == &PriceCatalog::instance(), "Singleton returns the same object");

    IntelFactory intel;
    CPU* ic = intel.createCPU();
    Motherboard* im = intel.createMotherboard();
    check(ic->socket() == im->socket(), "Intel CPU and motherboard are compatible");
    delete ic; delete im;

    AMDFactory amd;
    CPU* ac = amd.createCPU();
    Motherboard* am = amd.createMotherboard();
    check(ac->socket() == am->socket(), "AMD CPU and motherboard are compatible");
    delete ac; delete am;

    PCBuilder b1;
    b1.setPlatform("Intel");
    b1.setCPU(intel.createCPU());
    b1.setMotherboard(intel.createMotherboard());
    try {
        PC* pc = b1.build();
        check(pc->getCPU() != 0 && pc->getMotherboard() != 0, "Builder assembled PC");
        delete pc;
    } catch (...) {
        check(false, "Builder assembled PC");
    }

    PCBuilder b2;
    b2.setCPU(intel.createCPU());
    b2.setMotherboard(amd.createMotherboard());
    try {
        PC* pc = b2.build();
        delete pc;
        check(false, "Builder rejected incompatible components");
    } catch (const std::exception&) {
        check(true, "Builder rejected incompatible components");
    }

    PriceCatalog::instance().addPrice("TestCPU", 100);
    check(PriceCatalog::instance().getPrice("TestCPU") == 100, "PriceCatalog stored and returned the price");
    check(PriceCatalog::instance().getPrice("Unknown") == 0, "PriceCatalog returns 0 for unknown component");

    PCBuilder b3;
    b3.setPlatform("Intel");
    b3.setCPU(intel.createCPU());
    b3.setMotherboard(intel.createMotherboard());
    PC* pc = b3.build();
    check(pc->totalPrice() > 0, "PC total price calculated");
    delete pc;

    std::cout << "\nPassed: " << g_ok << ", failed: " << g_err << "\n\n";
}

static void demo() {
    std::cout << "PC Configurator\n";
    std::cout << "1 - Intel\n2 - AMD\nChoose platform: ";
    int ch = 1;
    std::cin >> ch;

    PlatformFactory* f = 0;
    if (ch == 2) f = new AMDFactory();
    else         f = new IntelFactory();

    PCBuilder builder;
    builder.setPlatform(f->platformName());
    builder.setCPU(f->createCPU());
    builder.setMotherboard(f->createMotherboard());

    try {
        PC* pc = builder.build();
        std::cout << "\nSpecification\n";
        pc->print();
        delete pc;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    delete f;
}

int main() {
    runTests();
    demo();
    return g_err == 0 ? 0 : 1;
}