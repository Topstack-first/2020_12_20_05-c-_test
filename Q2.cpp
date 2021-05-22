// CS 115 Final Exam -- U of R Fall 2020
// Solution for Question 2
// Instructor: Gurmail Singh
// Student Name:
// Student ID:

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Thing {
	public:
		// fill in the members
		int ID;
		int type;
		string Name;
};

// create the other 3 classes
// remember - public inheritance from Thing

class Player: public Thing {
public:
	int HP;
	int XP;
};
class Item : public Thing {
public:
	int weight;
	int cost;
};
class Chest : public Thing {
public:
	vector<Item> Loot;
	int lockLevel;
};
int main() {
	// create instances of various classes here
	// get a player, an item, and then a chest that will contain that item
	Player player;
	player.ID = 0;
	player.type = 0;
	player.Name = "Player 1";
	player.HP = 35;
	player.XP = 0;

	Item item;
	item.ID = 1;
	item.type = 2;
	item.Name = "Iron club";
	item.weight = 10;
	item.cost = 1;

	Chest chest;
	chest.ID = 2;
	chest.type = 1;
	chest.Name = "Wooden chest";
	chest.Loot.push_back(item);
	chest.lockLevel = 5;

	
	// you may want to print the instance info as you go
	cout << "name=" << player.Name << ", ID=" << player.ID << ",type=" << player.type << ", HP=" << player.HP << ", XP=" << player.XP<<endl;
	cout << "name=" << item.Name << ", ID=" << item.ID << ",type=" << item.type << ", weght=" << item.weight << ", cost=" << item.cost << endl;
	cout << "name=" << chest.Name << ", ID=" << chest.ID << ",type=" << chest.type << ", Loot Count=" << chest.Loot.size() << ", lockLevel=" << chest.lockLevel << endl;


	cin.ignore();
	cin.get();
	return 0;
}
