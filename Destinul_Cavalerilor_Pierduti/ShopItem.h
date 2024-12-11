#pragma once
class ShopItem
{
public:
    virtual ~ShopItem() = default; // Add virtual destructor
    ShopItem();
    ShopItem(int stock, int price);
    void setStock(int stock);
    int getStock() const;
    void setPrice(int price);
    int getPrice() const;

private:
    int stock;
    int price;
};
