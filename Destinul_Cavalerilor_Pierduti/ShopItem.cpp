#include <string>
#include "ShopItem.h"

ShopItem::ShopItem() : stock(0), price(0.0) {}

ShopItem::ShopItem(int stock, int price) : stock(stock), price(price) {}

void ShopItem::setStock(int stock)
{
    this->stock = stock;
}

int ShopItem::getStock() const
{
    return this->stock;
}

void ShopItem::setPrice(int price)
{
    this->price = price;
}

int ShopItem::getPrice() const
{
    return this->price;
}
