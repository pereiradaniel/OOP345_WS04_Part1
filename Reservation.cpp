#include <iomanip>
#include "Reservation.h"

namespace sdds {
	/* A constructor that receives the reservation as a string; this constructor is responsible for extracting information about the reservation from the stringand storing the tokens in the instance's attributes. */
	Reservation::Reservation(const std::string& res) {
		// Temporary strings to hold info:
		string _id, _name, _email, _people, _day, _hour;
		
		// Store reservation as string:
		string _res = res;

		// Find and erase ":" and "," from fields:
		// ID
		_id = _res.substr(0, _res.find(':'));
		_res.erase(0, _res.find(':') + 1);
		//NAME
		_name = _res.substr(0, _res.find(','));
		_res.erase(0, _res.find(',') + 1);
		// EMAIL
		_email = _res.substr(0, _res.find(','));
		_res.erase(0, _res.find(',') + 1);
		// PEOPLE
		_people = _res.substr(0, _res.find(','));
		_res.erase(0, _res.find(',') + 1);
		// DAY
		_day = _res.substr(0, _res.find(','));
		_res.erase(0, _res.find(',') + 1);
		// HOUR
		_hour = _res.substr(0, _res.find(','));
		_res.erase(0, _res.find(',') + 1);

		// Trim whitespace
		// ID
		_id.erase(0, _id.find_first_not_of(' '));
		_id.erase(_id.find_last_not_of(' ') + 1);
		// NAME
		_name.erase(0, _name.find_first_not_of(' '));
		_name.erase(_name.find_last_not_of(' ') + 1);
		// EMAIL
		_email.erase(0, _name.find_first_not_of(' '));
		_email.erase(_name.find_last_not_of(' ') + 1);

		// Assign info to fields.
		res_id = _id;
		res_name = _name;
		res_email = _email;
		res_people = stoi(_people);	// stoi!!
		res_day = stoi(_day);
		res_hour = stoi(_hour);
	}
}