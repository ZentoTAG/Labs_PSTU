#include "Route.h"
#include <iostream>
#include <string>
using namespace std;

Route::Route() {
	place_of_departure = "Barda";
	destination = "Perm";
	travel_time = 2.5;
	cout << "construktor bes parametrov dlya object" << this << endl;
}

Route::Route(string p, string d, float t) {
	place_of_departure = p;
	destination = d;
	travel_time = t;
	cout << "construktor s parametrami dlya object" << this << endl;
}

Route::Route(const Route &t) {
	place_of_departure = t.place_of_departure;
	destination = t.destination;
	travel_time = t.travel_time;
	cout << "construktor kopirovaniya dlya object" << this << endl;
}

Route::~Route() {
	cout << "destruktor dlya objecta" << this << endl;
}

string Route::get_pl_of_dep() {
	return place_of_departure;
}

string Route::get_destination() {
	return destination;
}

float Route::get_travel_time() {
	return travel_time;
}

void Route::set_pl_of_dep(string pod) {
	place_of_departure = pod;
}

void Route::set_destination(string des) {
	destination = des;
}

void Route::set_travel_time(float t) {
	travel_time = t;
}

void Route::show() {
	cout << place_of_departure << endl << destination << endl << travel_time << endl;
}

