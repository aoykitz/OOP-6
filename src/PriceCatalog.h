/**
 * @file PriceCatalog.h
 * @brief Singleton - каталог цен на компоненты.
 */
#pragma once
#include <map>
#include <string>
/**
 * @brief Singleton-каталог цен.
 *
 * Хранит соответствие "название компонента -> цена".
 * Существует в единственном экземпляре.
 */
class PriceCatalog {
public:
    /** @brief Получить единственный экземпляр каталога. */
    static PriceCatalog& instance();
    /** @brief Добавить или обновить цену компонента. */
    void addPrice(const std::string& name, double price);
    /** @brief Получить цену компонента (0, если не найден). */
    double getPrice(const std::string& name) const;

private:
    PriceCatalog() {}
    PriceCatalog(const PriceCatalog&) = delete;
    PriceCatalog& operator=(const PriceCatalog&) = delete;
    std::map<std::string, double> prices_;
};