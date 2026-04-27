#include <iostream>
#include <string>
using namespace std;

class Route {
	string place_of_departure;
	string destination;
	float travel_time;
public:
	Route();
	Route(string, string, float);
	Route(const Route&);
	~Route();
	void set_pl_of_dep(string);
	string get_pl_of_dep();
	void set_destination(string);
	string get_destination();
	void set_travel_time(float);
	float get_travel_time();
	void show();
};
