#ifndef AEDA_UGHEATS_BASE_H
#define AEDA_UGHEATS_BASE_H

#include <string>
#include <vector>
#include <queue>
#include "Location.h"
#include "Vehicle.h"
#include "Worker.h"
#include "tabHWorker.h"
#include "../utils.h"
#include "bst.h"

using namespace std;

class Client;
class Restaurant;
class Admin;
class Worker;
class RepairMan;
class Order;
class Vehicle;

typedef priority_queue<RepairMan*> HEAP_REPAIRMAN;

class Base {
private:
    /** The Admin who manages the Base.
 */
    Admin* manager;
    /** The clients that live in that Base.
 */
    vector<Client> clients;
    /** The restaurants that are located in that Base.
 */
    vector<Restaurant> restaurants;
    /** The workers that work in that Base.
 */
    tabHWorker workers;
    /** All the orders that were made from restaurants located in that Base.
 */
    vector<Order*> orders;
    /** All the municipalities included by that Base: base and border municipalities.
 */
    vector<string> municipalities;
    /** The file that contains the clients of the Base.
 */
    string clientsFile;
    /** The file that contains the restaurants of the Base.
 */
    string restaurantsFile;
    /** The file that contains the workers of the Base.
 */
    string workersFile;
    /** The file that contains the orders of the Base.
 */
    string ordersFile;
    /** The binary search tree for the vehicles of the Base.
 */
    BST<Vehicle> baseVehicles;
    /** The priority queue containing the RepairMan of the Base.
 */
    HEAP_REPAIRMAN repairmen;
protected:
    /** Location of the Base.
 */
    Location location;
public:
    /** Default Constructor.
 */
    Base(): baseVehicles(Vehicle()) {};

    //Metodos Set

    /** Sets the Location of a Base.
      * @param Location is the parameter you want the new Base to have.
*/
    void setBaseLocation(Location location);

    /** Sets the manager of a Base.
      * @param manager is the parameter you want the new Base to have.
*/
    void setBaseManager(Admin* manager);

    /** Sets the clients of a Base.
      * @param clients is the parameter you want the new Base to have.
*/
    void setBaseClients(vector<Client> clients);

    /** Sets the restaurants of a Base.
      * @param restaurants is the parameter you want the new Base to have.
*/
    void setBaseRestaurants(vector<Restaurant> restaurants);

    /** Sets the workers of a Base.
      * @param workers is the parameter you want the new Base to have.
*/
    void setBaseWorkers(vector<Worker*> workers_v);

    /** Sets the orders of a Base.
      * @param orders is the parameter you want the new Base to have.
*/
    void setBaseOrders(vector<Order*> orders);

    /** Sets the municipalities of a Base.
      * @param municipalities is the parameter you want the new Base to have.
*/
    void setBaseMunicipalities(vector<string> municipalities);

    /** Sets the workers'file of a Base.
      * @param workersFile is the parameter you want the new Base to have.
*/
    void setBaseWorkersFile(string workersFile);

    /** Sets the clients'file of a Base.
      * @param clientsFile is the parameter you want the new Base to have.
*/
    void setBaseClientsFile(string clientsFile);

    /** Sets the restaurants'file of a Base.
      * @param restaurantsFile is the parameter you want the new Base to have.
*/
    void setBaseRestaurantsFile(string restaurantsFile);

    /** Sets the orders'file of a Base.
      * @param ordersFile is the parameter you want the new Base to have.
*/
    void setBaseOrdersFile(string ordersFile);

    //Metodos Get

    /**
       * @return the Base's Location.
*/
    Location getBaseLocation() const;

    /**
       * @return the Base's manager.
*/
    Admin* getBaseManager() const;

    /**
       * @return the Base's clients.
*/
    vector<Client> getBaseClients() const;

    /**
       * @return the Base's clients'address.
*/
    vector<Client>* getBaseClientsAddr();

    /**
       * @return the Base's restaurants.
*/
    vector<Restaurant> getBaseRestaurants() const;

    /**
       * @return the Base's restaurants'address.
*/
    vector<Restaurant>* getBaseRestaurantsAddr();

    /**
       * @return the Base's workers.
*/
    vector<Worker*> getBaseWorkers() const;

    /**
       * @return the Base's workers'address.
*/
    tabHWorker* getBaseWorkersAddr();

    /**
       * @return the Base's orders.
*/
    vector<Order*> getBaseOrders() const;

    /**
       * @return the Base's municipalities.
*/
    vector<string> getBaseMunicipalities() const;

    /**
       * @return the Base's workers'file.
*/
    string getBaseWorkersFile() const;

    /**
      * @return the Base's clients'file.
*/
    string getBaseClientsFile() const;

    /**
      * @return the Base's restaurants'file.
*/
    string getBaseRestaurantsFile() const;

    /**
      * @return the Base's orders'file.
*/
    string getBaseOrdersFile() const;

    /** Search for a restaurant in a Base by the name.
        * @param name is how to search for the Restaurant.
        * @return the pointer to the Restaurant wanted or a null pointer if the Restaurant does not exist.
 */
    Restaurant* getRestaurant(const string &name);

    /**
        * @return the repairmen.
 */
    HEAP_REPAIRMAN getBaseRepairmen() const;

    //Other Methods

    /** Adds a Vehicle to the Base.
        * @param v is the Vehicle to add.
 */
    void addVehicle(const Vehicle& v);

    /** Removes a Vehicle from the Base.
       * @param v is the Vehicle to remove.
       * @return true if the Vehicle was removed successfully.
*/
    bool removeVehicle(const Vehicle &v);

    /**
       * @return the vehicle from the Base.
*/
    BST<Vehicle> &getBaseVehicles();

    /** Adds a RepairMan to the Base.
       * @param r is the RepairMan to add.
*/
    void addRepairmanToHeap(RepairMan *r);

    /** Removes a RepairMan from the Base.
       * @param r is the RepairMan to remove.
       * @return true if the RepairMan was removed successfully.
*/
    bool removeRepairmanFromHeap(int nif);

    /** An Admin can send a Vehicle to maintenance.
     * The Admin specifies the minimum number of maintenance done by a RepairMan and then the he is chosen from the priority queue, the one chosen is the RepairMan available earlier.
      * @return true if the Vehicle was sent to maintenance successfully.
*/
    bool vehicleToMaintenance();

    /** Displays the Base in a nice format.
      * @param out is the ostream.
      * @param base is the Base you want to display.
     */
    friend ostream& operator<<(ostream& out, const Base &base);

    /** Updates the clients of a Base.
       * @param client is what you want to add.
*/
    void addClientToBase(const Client &client);

    /** Updates the restaurants of a Base.
       * @param restaurant is what you want to add.
*/
    void addRestaurantToBase(const Restaurant &restaurant);

    /** Updates the workers of a Base.
       * @param worker is what you want to add.
*/
    void addWorkerToBase(Worker *worker);

    /** Removes a Worker, but not from the hash table.
       * @param nif the nif of the worker to remove.
       * @return 1 if the worker was removed successfully.
*/
    size_t removeWorker(int nif);

    /** Updates the orders of a Base.
       * @param order is what you want to add.
*/
    void addOrderToBase(Order* order);

    /** Finds a worker from a Base.
       * @param nif is how you search the worker.
       * @return the pointer to the Worker.
*/
    Worker* findWorker(int nif);

    /** Finds a client from a Base.
       * @param nif is how you search the client.
       * @return the pointer to the Client.
*/
    Client* findClient(int nif);

    /** Finds a Vehicle from a Base.
       * @param licenceplate is how you search the vehicle.
       * @return the Vehicle.
*/
    Vehicle findVehicle(string licenseplate);

    /** Assigns a deliveryperson to an order.
       * @param order_time is the Time the order was made.
       * @param delivery_time is the Time the delivery will be made.
       * @return the nif of the deliveryperson assigned or -1 in the case there isn't any deliveryperson available.
*/
    int assignDelivery(Time order_time, Time& delivery_time);

    /** Updates the BST of vehicles.
       * @param vhc is the Vehicle that updates the BST.
*/
    void updateVehicle(const Vehicle& vhc);

    /** Checks is a Vehicle is available(not under maintenance or doing a delivery).
       * @param licenseplate is how you search the vehicle.
       * @return true if the vehicle is available.
*/
    bool isVehicleOperational(string licenseplate);

    /** Checks is a Vehicle is available(not under maintenance or doing a delivery).
       * @param vhc is the vehicle to check.
       * @return true if the vehicle is available.
*/
    bool isVehicleOperational(const Vehicle& vhc);
};


/** Checks if a municipality exists in a vector of municipalities.
       * @param municipality is the municipality to want to search for.
       * @param municipalities is the vector where we want to look for the municipality.
       * @return true if the municipality exists in the vector.
*/
bool searchbyMunicipality(string municipality, vector<string> municipalities);

/** Checks if a municipality exists in one of the Company's bases.
       * @param bases is the vector where we want to look for the municipality.
       * @param municipality is the municipality you want to search for.
       * @return true if exists a Base.
*/
bool exitsBase(vector<Base> bases, string municipality);

#endif //AEDA_UGHEATS_BASE_H
