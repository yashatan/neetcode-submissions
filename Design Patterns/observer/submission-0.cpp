class Observer {
public:
    virtual void notify(string& itemName) = 0;
};

class Customer : public Observer {
private:
    string name;
    int notifications;

public:
    Customer(string& name) : name(name), notifications(0) {}

    void notify(string& itemName) override {
        notifications += 1;
    }

    int countNotifications() {
        return notifications;
    }
};

class OnlineStoreItem {
private:
    string itemName;
    int stock;
    vector<Observer*> listObserver;
public:
    OnlineStoreItem(string& itemName, int stock) : itemName(itemName), stock(stock) {}

    void subscribe(Observer* observer) {
        listObserver.push_back(observer);
    }

    void unsubscribe(Observer* observer) {
        listObserver.erase(std::remove(listObserver.begin(), listObserver.end(), observer),listObserver.end());
    }

    void updateStock(int newStock) {
        
        if(stock ==0 && newStock>0){
            for(auto observer : listObserver){
                observer->notify(itemName);
            }
        }
        stock = newStock;

    }
};
