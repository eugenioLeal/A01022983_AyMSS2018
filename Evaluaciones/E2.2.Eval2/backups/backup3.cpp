#include <bits/stdc++.h>
using namespace std;


class VideoGame {
public:
	virtual VideoGame* clone() = 0;
	int getId() {
		return id;
	}
	string getName() {
		return name;
	}
	float getPrice() {
		return price;
	}
protected:
	int id;
	string name;
	float price;
};

class StrategyGame : public VideoGame {
public:
	StrategyGame(int id, string name, float price) {
		this->id = id;
		this->name = name;
		this->price = price;
	}
	VideoGame* clone() {
		return new StrategyGame(*this);
	}
private:
	string period;
	bool supportsMultiplayer;
	int numberOfOponents;
};

class AdventureGame : public VideoGame {
public:
	AdventureGame(int id, string name, float price) {
		this->id = id;
		this->name = name;
		this->price = price;
	}
	VideoGame* clone() {
		return new AdventureGame(*this);
	}
private:
	string protagonistName;
	string storyDescription;
	int numberOfPuzzles;
};

class LearningGame : public VideoGame {
public:
	LearningGame(int id, string name, float price) {
		this->id = id;
		this->name = name;
		this->price = price;
	}
	VideoGame* clone() {
		return new LearningGame(*this);
	}
private:
	string subject;
	string skill;
	string teacherName;
};

class Receiver;
class Invoker;

class Inventory {
public:
	Invoker* remoteControl;
	Receiver* receiverBox;
	int getSizeOfInventory() {
		return videogames.size();
	}

	bool sortFunction(VideoGame* i, VideoGame* j) {
		return(i->getPrice() < j->getPrice());
	}
	void sort() {

	}
protected:
	std::vector<VideoGame*> videogames;
};

//-------------//
//-- Command --//
//-------------//
class Command {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
};

//--------------//
//-- Receiver --//
//--------------//
class Receiver : public Inventory {
public:
	void addVideoGame(VideoGame* videogame) {
		cout << "Adding Videogame: " << videogame->getId() << " " << videogame->getName() << " " << videogame->getPrice() << endl;
		videogames.push_back(videogame);
	}
	void deleteVideoGame(VideoGame* videogame) {
		cout << "Deleting Videogame: " << videogame->getId() << " " << videogame->getName() << " " << videogame->getPrice() << endl;
	}
	void printInventory() {
		printf("+------------+\n");
		printf("| Inventory  |\n");
		printf("+------------+\n");
		printf("+------------+\n");
		printf("| Videogames |\n");
		printf("+------------+\n");
		for (int i = 0; i < videogames.size(); ++i)
		{
			cout << "Id: " << videogames[i]->getId() << " Name: " << videogames[i]->getName() << endl;
		}
	}
};


//----------------------//
//-- Concrete Command --//
//----------------------//
class AddVideoGame : public Command {
private:
	Receiver* receiver;
	VideoGame* videogame;
public:
	AddVideoGame(Receiver* receiver, VideoGame* videogame) {
		this->receiver = receiver;
		this->videogame = videogame;
	}
	void execute() {
		receiver->addVideoGame(videogame);
	}
	void undo() {
		receiver->deleteVideoGame(videogame);
	}
};

//----------------------//
//-- Concrete Command --//
//----------------------//
class DeleteVideoGame : public Command {
private:
	Receiver* receiver;
	VideoGame* videogame;
public:
	DeleteVideoGame(Receiver* receiver, VideoGame* videogame) {
		this->receiver = receiver;
		this->videogame = videogame;
	}
	void execute() {
		receiver->deleteVideoGame(videogame);
	}
	void undo() {
		receiver->addVideoGame(videogame);
	}
};

//-------------//
//-- Invoker --//
//-------------//
class Invoker {
public:
	void setCommand(Command* command) {
		this->command = command;
	}
	void executeButton() {
		commands.push_back(command);
		command->execute();
	}
	void undoButton() {
		commands.push_back(command);
		command->undo();
	}
	long unsigned int getSizeOfCommands() {
		return commands.size();
	}
	void revert(int n) {
		if(n > commands.size()) {
			cout << "Error: can't insufficient commands to revert!" << endl;
		} else {
			cout << "Reverting " << n << " times..." << endl;
			for (int i = 0; i < n; ++i)
			{
				(commands.back())->undo();
				commands.pop_back();
			}
		}
	}
private:
	Command* command;
	std::vector<Command*> commands;
};




int main(int argc, char const *argv[])
{
	Inventory* inventory = new Inventory();
	inventory->remoteControl = new Invoker;
	inventory->receiverBox = new Receiver;

	VideoGame* age_of_empires = new StrategyGame(1, "Age of Empires", 100);
	VideoGame* age_of_empires_2 = age_of_empires->clone();
	VideoGame* starcraft = new StrategyGame(2, "Starcraft", 50);
	VideoGame* starcraft2 = new StrategyGame(3, "Starcraft 2", 60);
	VideoGame* civilization = new StrategyGame(4, "Civilization", 60.5);



	inventory->remoteControl->setCommand(new AddVideoGame(inventory->receiverBox, age_of_empires));
	inventory->remoteControl->executeButton();

	inventory->remoteControl->setCommand(new AddVideoGame(inventory->receiverBox, starcraft));
	inventory->remoteControl->executeButton();

	inventory->remoteControl->setCommand(new AddVideoGame(inventory->receiverBox, starcraft2));
	inventory->remoteControl->executeButton();

	inventory->remoteControl->setCommand(new AddVideoGame(inventory->receiverBox, civilization));
	inventory->remoteControl->executeButton();

	inventory->receiverBox->printInventory();
	cout << inventory->receiverBox->getSizeOfInventory() << endl;

	//inventory->remoteControl->revert();
	// cout << "Number of buttons pressed: " << inventory->remoteControl->getSizeOfCommands() << endl;




	// free memory
	delete age_of_empires;
	delete age_of_empires_2;
	delete starcraft;
	delete inventory;
	return 0;
}