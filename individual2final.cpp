/**
Course:  CS213 - Programming II  - 2018
Title:   Assignment 2 - Individual Task - problem 2, page 884
Program: CS213-2018-A1-T1-P0
Purpose: Inheritance and friend classes
Author: Name :- Hanan Mohamed Abdelrahim ...... ID :- 20170375
Date:    29 October 2018
*/

#include <iostream>

using namespace std;

class Person //provided class
{
public:
    friend class vehicle;
    Person() //default constructor
    {
        name = "";
    }
    Person(string the_name) //parameterized constructor
    {
        name = the_name;
    }

    Person(const Person& the_object) //copy constructor
    {
        name = the_object.name;
    }

    //accessor
    string get_name() const
    {
        return name;
    }

    Person& operator = (string word) //overloaded operator=
    {
        name = word;
        return *this;
    }

    friend istream& operator >> (istream& in_stream, Person& person_object) //overloaded operator>>
    {
        in_stream >> person_object.name;
        return in_stream;
    }

    friend ostream& operator <<(ostream& out_stream, const Person& person_object) //overloaded operator<<
    {
        out_stream << person_object.name;
        return out_stream;
    }

private:
    string name;

};

class vehicle
{
    friend class Person;
protected:
    string manName;
    int cylinNum;
    Person owner; //owner of type person(a friend class)

public:
    // friend class Person; //friend class

    vehicle() //default constructor to initialize protected members
    {

        manName = "No Manufacturer";
        cylinNum = 0;
        owner = "No Owner";
    }

    vehicle(string name, int cylinNumber, string ownerName) //parameterized constructor
    {
        manName = name;
        cylinNum = cylinNumber;
        owner = ownerName;
    }

    vehicle(const vehicle& theVehicle) //copy constructor
    {
        manName = theVehicle.manName;
        cylinNum = theVehicle.cylinNum;
        owner = theVehicle.owner;
    }

    vehicle& operator =(const vehicle& theVehicle) //overloaded operator= function
    {
        this->manName = theVehicle.manName;
        this->cylinNum = theVehicle.cylinNum;
        this->owner = theVehicle.owner;
        return *this;
    }
    //accessors
    string getmanName()
    {
        return manName;
    }

    int getCylinNum()
    {
        return cylinNum;
    }

    Person getOwner()
    {
        return owner;
    }
};

class Truck: public vehicle  //class Truck inherited class vehicle
{
private:
    double loadCapacity;
    int towingCapacity;

public:
    Truck() //default constructor to initialize private members
    {
        loadCapacity = 0.0;
        towingCapacity = 0;
    }

    Truck(double capTons, int capPounds, string Name, int numCyl, string ownerName) //parameterized constructor
    {
        loadCapacity = capTons;
        towingCapacity = capPounds;
        manName = Name;
        cylinNum = numCyl;
        owner = ownerName;
    }
    Truck(const Truck& theTruck) //copy constructor that takes an object from the truck class
    {
        loadCapacity = theTruck.loadCapacity;
        towingCapacity = theTruck.towingCapacity;
        manName = theTruck.manName;
        cylinNum = theTruck.cylinNum;
        owner = theTruck.owner;
    }
    Truck& operator =(const Truck& theTruck) //overloaded operator= function
    {
        this->loadCapacity = theTruck.loadCapacity;
        this->towingCapacity = theTruck.towingCapacity;
        this->manName = theTruck.manName;
        this->cylinNum = theTruck.cylinNum;
        this->owner = theTruck.owner;
    }
    //accessors
    double getCapTons()
    {
        return loadCapacity;
    }
    int getCapPounds()
    {
        return towingCapacity;
    }
};



int main()
{
    vehicle v1("Honda", 4, "Hanan Mohamed"); //parameterized constructor from vehicle class

    cout << "First Vehicle Data: " << endl;
    cout << "Manufacturer's Name: " << v1.getmanName() << endl;
    cout << "Number of Cylinders: " << v1.getCylinNum() << endl;
    cout << "Owner: " << v1.getOwner() << endl;
    cout<<endl;

    Truck t1(72.0, 18000, "Ford", 8, "Ahmed Mohamed"); //parameterized constructor from Truck class

    cout << "First Truck Data: " << endl;
    cout << "Manufacturer's Name: " << t1.getmanName()<<endl;
    cout << "Number of Cylinders: " << t1.getCylinNum()<<endl;
    cout << "Owner: " << t1.getOwner() << endl;
    cout << "Load Capacity (Tons): " << t1.getCapTons()<<endl;
    cout << "Towing Capacity (Pounds): " << t1.getCapPounds()<<endl;
}

