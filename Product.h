#ifndef AEDA_UGHEATS_PRODUCT_H
#define AEDA_UGHEATS_PRODUCT_H

#include <string>
using namespace std;

class Product {
private:
    string name;
    string cuisine;
    float price;

public:
    //Metodos Set
    void setProductName(string name);
    void setCuisine(string cuisine);
    void setPrice(float price);
    //Metodos Get
    string getProductName() const;
    string getCuisine() const;
    float getPrice() const;
};


#endif //AEDA_UGHEATS_PRODUCT_H