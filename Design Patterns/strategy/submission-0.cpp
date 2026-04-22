class Person {
private:
    string lastName;
    int age;
    bool married;

public:
    Person(string lastName, int age, bool married) 
        : lastName(lastName), age(age), married(married) {}

    string getLastName() {
        return lastName;
    }

    int getAge() {
        return age;
    }

    bool isMarried() {
        return married;
    }
};

class PersonFilter {
public:
    virtual ~PersonFilter() {}
    virtual bool apply(Person& person) = 0;
};

class AdultFilter : public PersonFilter {
    public:
    AdultFilter(){};
    bool apply(Person& person) override{
        if (person.getAge() >= 18){
            return true;
        }
        return false;
    }
};

class SeniorFilter : public PersonFilter {
        public:
        SeniorFilter(){};
    bool apply(Person& person) override{
        if (person.getAge() >= 65){
            return true;
        }
        return false;
    }
};

class MarriedFilter : public PersonFilter {
    public:
    MarriedFilter(){

    };
    bool apply(Person& person) override{
        if (person.isMarried()){
            return true;
        }
        return false;
    }
};

class PeopleCounter {
private:
    PersonFilter* filter;

public:
    void setFilter(PersonFilter& filter) {
        this->filter = &filter;
    }

    int count(vector<Person>& people) {
        int res =0;
        for(auto person : people){
            if (filter->apply(person)){
                res++;
            }
        }
        return res;
    }
};
