#include "Route.h"
#include <iostream>
#include <string>
using namespace std;

Route make_route() {
	string pod;
	string des;
	float tt;
	cout << "place of departure, destination, travel_time" << endl;
	cin >> pod, des, tt;
	Route r(pod, des, tt);
	return r;
}

void print_route(Route r) {
	r.show();
}

int main() {
	Route r1;
	r1.show();
	Route r2("Barda", "Perm", 2.5);
	r2.show();
	Route r3=r2;
	r3.set_pl_of_dep("Barda");
	r3.set_destination("Perm");
	r3.set_travel_time(2.5);
	print_route(r3);
	r1 = make_route();
	r1.show();
	return 0;
}
