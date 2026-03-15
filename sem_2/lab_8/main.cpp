#include <iostream>
#include <string>
using namespace std;

struct State {
    string name;
    string capital;
    int population;
    int area;
};

void deleteByPopulation(State* states, int& n, int minPopulation) {
    for(int i = 0; i < n; i++) {
        if(states[i].population < minPopulation) {
            for(int j = i; j < n-1; j++) {
                states[j] = states[j+1];
            }
            n--;
            i--;
        }
    }
}

void insertAfter(State* states, int& n, int pos, State newState) {
    if(pos >= 0 && pos < n) {
        for(int i = n; i > pos; i--) {
            states[i] = states[i-1];
        }
        states[pos+1] = newState;
        n++;
    }
}

int main() {
    State states[300];
    int n = 3;
    
    states[0] = {"Россия", "Москва", 146000000, 17098246};
    states[1] = {"США", "Вашингтон", 331000000, 9833517};
    states[2] = {"Китай", "Пекин", 1402000000, 9596961};
    
    int minPopulation = 500000000;
    int insertPos = 1;
    deleteByPopulation(states, n, minPopulation);
    insertAfter(states, n, insertPos, {"Беларусь", "Минск", 9109280, 2076000});
    
    for(int i = 0; i < n; i++) {
        cout << states[i].name << " " << states[i].population << endl;
    }
    
    return 0;
}
