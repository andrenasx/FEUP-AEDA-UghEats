#ifndef AEDA_UGHEATS_ORDER_H
#define AEDA_UGHEATS_ORDER_H

#include <vector>
#include <string>
#include "Restaurant.h"
#include "Date.h"
#include "Product.h"
#include "Worker.h"
#include "Client.h"
#include "Time.h"
#include "../utils.h"

using namespace std;

class Time;

class Order {
protected:
    /** Restaurant the Order was made.
*/
    string restaurant;
    /** The Client's nif who made the Order.
*/
    int client;
    Date date;
    Time orderTime;
    vector<string> products;
    float orderPrice;
public:
    /** Default Constructor.
*/
    Order() = default;
    /** Constructor of an Order from the restaurant, nif of the client who made the order, date, order time, products and order price.
*/
    Order(string restaurant, int client, Date date, Time orderTime, vector<string> products, float orderPrice);
    //Metodos Set
    /** Sets the restaurant of an Order.
       * @param restaurant is the parameter you want the new Order to have.
*/
    void setOrderRestaurant(string restaurant);
    /** Sets the Date of an Order.
       * @param date is the parameter you want the new Order to have.
*/
    void setOrderDate(Date date);
    /** Sets the Time of an Order.
       * @param orderTime is the parameter you want the new Order to have.
*/
    void setOrderTime(Time orderTime);
    /** Sets the products of an Order.
       * @param products is the parameter you want the new Order to have.
*/
    void setOrderProducts(vector<string> products);
    /** Sets the price of an Order.
       * @param orderPrice is the parameter you want the new Order to have.
*/
    void setOrderPrice(float orderPrice);
    /** Sets the nif of the client of an Order.
       * @param restaurant is the parameter you want the new Order to have.
*/
    void setOrderClient(int client);
    //Metodos Get
    /**
       * @return the restaurant.
*/
    string getRestaurant() const;
    /**
       * @return the order Date.
*/
    Date getOrderDate() const;
    /**
       * @return the order Time.
*/
    Time getOrderTime() const;
    /**
       * @return the products.
*/
    vector<string> getOrderProducts() const;
    /**
       * @return the price.
*/
    float getOrderPrice() const;
    /**
       * @return the nif of the client that made de order.
*/
    int getOrderClient() const;
    //Other Methods
    /** Displays the Order in a nice format.
      * @param out is the ostream.
     */
    virtual void print(ostream &out) const;

};

class Delivery: public Order {
private:
    float deliveryPrice;
    int deliveryperson;
    bool success;
    Time deliveryTime;
    string notes;
public:
    /** Constructor default.
*/
    Delivery() = default;
    /** Constructor of a Delivery from the restaurant, nif of the client, date, order time, products, order price, delivery price, nif of the deliveryperson, success, delivery time and notes given.
*/
    Delivery(string restaurant, int client, Date date, Time orderTime, vector<string> products, float orderPrice, float deliveryPrice, int deliveryperson, bool success, Time deliveryTime, string notes);
    //Metodos Set
    /** Sets the price of a Delivery.
       * @param deliveryPrice is the parameter you want the new Delivery to have.
*/
    void setDeliveryPrice(float deliveryPrice);
    /** Sets the nif of the deliveryperson of a Delivery.
       * @param deliveryperson is the parameter you want the new Delivery to have.
*/
    void setDeliveryPerson(int deliveryperson);
    /** Sets if the delivery was successful.
       * @param success is the parameter you want the new Delivery to have.
*/
    void setSuccess(bool success);
    /** Sets the delivery time of a Delivery.
       * @param deliveryTime is the parameter you want the new Delivery to have.
*/
    void setDeliveryTime(Time deliveryTime);
    /** Sets the notes of a Delivery.
       * @param notes is the parameter you want the new Delivery to have.
*/
    void setDeliveryNotes(string notes);
    //Metodos Get
    /**
       * @return the price.
*/
    float getDeliveryPrice() const;
    /**
       * @return the nif of the deliveryperson.
*/
    int getDeliveryPerson() const;
    /**
       * @return if it was successful.
*/
    bool getSuccess() const;
    /**
       * @return the delivery time.
*/
    Time getDeliveryTime() const;
    /**
       * @return the notes of the delivery.
*/
    string getDeliveryNotes() const;
    //Other Methods
    /** Displays the Delivery in a nice format.
      * @param out is the ostream.
      * @param delivery is the Delivery you want to display.
     */
    friend ostream& operator<<(ostream& out, const Delivery &delivery);

};

#endif //AEDA_UGHEATS_ORDER_H
