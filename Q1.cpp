// CS 115 Final Exam -- U of R Fall 2020
// Solution for Question 1
// Instructor: Gurmail Singh
// Student Name:
// Student ID:

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// DO NOT EDIT AREA -- BEGIN
struct record {
	int CID; // client ID
	string area; // billing area
	string type; // billing type
	int units; // power units spent
	float bill; // billing amount due
	float ecpu; // effective cost per unit

};
// a vector that stores the report table
vector<record> records;
// returns INDEX of the record with Min/Max field value
// works only for fields bill/ecpu (floats)
// to get maximum - pass getMin as FALSE
// to get minimum - pass getMin as TRUE
// to work on Billing Amount field - getBill must be TRUE
// to work on ECPU field - getBill must be FALSE
int getMinOrMax(bool getMin, vector<record> R, bool getBill) {
	float min = R[0].bill;
	float max = 0.0;
	int index = 0;
	for (unsigned int i = 0; i < R.size(); i++) {
		if (getMin) { // getting minimum
			if (getBill) { // checking Billing Amount field
				if (min > R[i].bill) {
					min = R[i].bill;
					index = i;
				}
			}
			else { // checking ECPU field
				if (min > R[i].ecpu) {
					min = R[i].ecpu;
					index = i;
				}
			}
		}
		else { // getting maximum
			if (getBill) { // checking Billing Amount field
				if (max < R[i].bill) {
					max = R[i].bill;
					index = i;
				}
			}
			else { // checking ECPU field
				if (max < R[i].ecpu) {
					max = R[i].ecpu;
					index = i;
				}
			}
		}
	}
	return index;
}
void printTable(vector<record> &R) {
	cout << "[CID]" << setw(10) << "[Area]" << setw(15) << "[Bill Type]" << setw(14) << "[Power Units]" << setw(10) << "[Amount]" << setw(10) << "[ECPU]" << endl;
	for (unsigned int i = 0; i < R.size(); i++) {
		cout << R[i].CID << setw(15) << R[i].area << setw(15) << R[i].type << setw(10) << R[i].units << setw(10) << R[i].bill << setw(10) << R[i].ecpu << endl;
	}
	return;
}
// DO NOT EDIT AREA -- END

// TO DO -- complete the two smaller functions
float updateBA(record R) {
	float newBill = 0.0;
	// calculate the new Bill Amount and return it

	//calculate best charges
	switch (R.area[0])
	{
	case 'R'://Regina
		newBill += 20.0f;
		break;
	case 'S'://SakatoonMoose jaw
		newBill += 25.0f;
		break;
	case 'M':
		newBill += 15.0f;
		break;
	default:
		break;
	}

	switch (R.type[0])
	{
	case 'I':
		if (R.units <= 100)
		{
			newBill += R.units * 0.3f;
		}
		else {
			newBill += 100.0f * 0.3f+(R.units - 100)* 0.5f ;
		}
		break;
	case 'R':
		if (R.units <= 50)
		{
			newBill += R.units * 0.15;
		}
		else {
			newBill += 50 * 0.15 + (R.units - 50) * 1;
		}
		break;
	default:
		break;
	}

	return newBill;
}

float updateECPU(record R) {
	float newECPU = 0.0;
	// calculate the new ECPU and return it
	newECPU = R.bill / R.units;

	return newECPU;
}

// DO NOT EDIT AREA -- BEGIN
// this function runs through all fields and updates them
// it needs the two smaller functions above to work
void updateBilling(vector<record> &R) {
	for (unsigned int i = 0; i < R.size(); i++) {
		R[i].bill = updateBA(R[i]);
		R[i].ecpu = updateECPU(R[i]);
	}
	return;
}
// DO NOT EDIT AREA -- END

int main() {

	// DO NOT EDIT AREA -- BEGIN
	records.push_back({ 1, "Regina", "Industrial", 135, 0.0, 0.0 });
	records.push_back({ 2, "Regina", "Residential", 62, 0.0, 0.0 });
	records.push_back({ 3, "Saskatoon", "Residential", 78, 0.0, 0.0 });
	records.push_back({ 4, "Saskatoon", "Industrial", 100, 0.0, 0.0 });
	records.push_back({ 5, "Moose Jaw", "Industrial", 91, 0.0, 0.0 });
	records.push_back({ 6, "Moose Jaw", "Residential", 53, 0.0, 0.0 });
	// to access: records[i].CID or other members
	// DO NOT EDIT AREA -- END

	// do some processing here - calculate billing amounts and ECPU's
	updateBilling(records);

	// print the completed report table
	printTable(records);

	// now, print the Client ID with the LARGEST bill amount
	int i = getMinOrMax(0, records, 1);
	cout << "The Client ID [" << records[i].CID << "] has the largest bill of [" << records[i].bill << "]" << endl;

	// now, also print Client ID with the SMALLEST ECPU
	i = getMinOrMax(1, records, 0);
	cout << "The Client ID [" << records[i].CID << "] has the smallest ECPU of [" << records[i].ecpu << "]" << endl;

	cin.ignore();
	cin.get();
	return 0;
}
