//organize when done
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "animal.h"
using namespace std;


class Zoo{
    public:
    vector<Animal> animals = {};
    vector<Animal> rdm_animals;
    Zoo(){
        rdm_animals = {Animal("ben","racoon",rand()%10+1), Animal("juju","leopard",rand()%10+1), Animal("joe","tiger",rand()%10+1)};
    }
    void fill_up_zoo(){
        for(int i = 0; i < 30; i++){
            int x = rand() % 3;
            animals.push_back(rdm_animals.at(x));
        }
    }

    void add_animal(){
        string t_name;
        string t_species;
        int t_age;

        cout << "What is the animal's name: " << endl;
        cin >> t_name;

        cout << "What is the animal's species: " << endl;
        cin >> t_species;

        cout << "What is the animal's age: " << endl;
        cin >> t_age;
        animals.push_back(Animal(t_name,t_species,t_age));
    }

    void animal_eat(){
        cout << "Here are the animals and their location: " << endl;
        for(int i = 0; i < animals.size();i++){
            cout << i+1 << ". Name: " << animals[i].name  << ", Species: " << animals[i].species << ", Age: " << animals[i].age << endl;
        }
        cout << "What number do you want to eat" << endl;
        int x;
        cin >> x;
        Animal temp = animals[x-1];
        cout << temp.name << " is eating beans!" << endl;
    }

    void kill_animal(){
        cout << "Here are the animals and their location: " << endl;
        for(int i = 0; i < animals.size();i++){
            cout << i+1 << ". Name: " << animals[i].name  << ", Species: " << animals[i].species << ", Age: " << animals[i].age << endl;
        }
        cout << "What number do you want to delete" << endl;
        int x;
        cin >> x;
        vector<Animal>::iterator it = animals.begin();
        animals.erase(it+(x-1));
    }

    void kill_all_animals(){
        animals.clear();
    }

    void display_zoo(){
        for(int i = 0; i < animals.size();i++){
            cout << i+1 << ". Name: " << animals[i].name  << ", Species: " << animals[i].species << ", Age: " << animals[i].age << endl;
        }
    }
};

int main(){
    //making my own zoo!!!
    srand(time(NULL));
    bool active = true;
    int x;
    string name;
    cout << "Welcome to your Zoo!" << endl;
    cout << "What is the name of your zoo" << endl;
    getline(cin,name);
    Zoo myzoo;

    while (active){
        cout << "Choose one of the following:" << endl;
        cout << "1. Fill up Zoo with 30 random animals" << endl;
        cout << "2. Add one animal" << endl;
        cout << "3. Make an animal eat" << endl;
        cout << "4. Kill an animal" << endl;
        cout << "5. Kill all animals" << endl;
        cout << "6. Display zoo animals" << endl;
        cout << "7. Quit" << endl;
        cin >> x;
        switch(x){
            case 1:
                myzoo.fill_up_zoo();
                break;
            case 2:
                myzoo.add_animal();
                break;
            case 3:
                myzoo.animal_eat();
                break;
            case 4:
                myzoo.kill_animal();
                break;
            case 5:
                myzoo.kill_all_animals();
                break;
            case 6:
                myzoo.display_zoo();
                break;
            case 7:
                active = false;
                break;
            default:
                cout << "Invalid awnser" << endl;
                break;
        }
    }

    return 0;
}