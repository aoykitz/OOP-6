#include "PriceCatalog.h"
PriceCatalog& PriceCatalog::instance(){
    static PriceCatalog catalog;
    return catalog;
}
void PriceCatalog::addPrice(const std::string& name, double price){
    prices_[name] = price;
}
double PriceCatalog::getPrice(const std::string& name) const {
    std::map<std::string, double>::const_iterator it = prices_.find(name);
    return it != prices_.end() ? it -> second : 0.0;
}