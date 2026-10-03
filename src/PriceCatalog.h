#pragma once
#include <map>
#include <string>
class PriceCatalog {
public:
    static PriceCatalog& instance();
    void addPrice(const std::string& name, double price);
    double getPrice(const std::string& name) const;

private:
    PriceCatalog() {}
    PriceCatalog(const PriceCatalog&) = delete;
    PriceCatalog& operator=(const PriceCatalog&) = delete;
    std::map<std::string, double> prices_;
};