class Singleton {
private:
    string value;
    inline static Singleton *uniqInstance =nullptr;
    Singleton() {
        //value ="";
    }

public:

    static Singleton *getInstance() {
        if (uniqInstance == nullptr){
            uniqInstance = new Singleton();
        }
        return uniqInstance;
    }

    string getValue() {
        return value;
    }

    void setValue(string &value) {
        this->value = value;
    }
};

//Singleton* Singleton::uniqInstance = nullptr;