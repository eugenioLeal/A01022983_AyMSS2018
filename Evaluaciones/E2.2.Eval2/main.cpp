// Eugenio Leal A01022983
// Evaluacion Segunddo Parcial
#include <bits/stdc++.h>
using namespace std;


class Visitor;

//----------------------------------------------------------------------------------------------//
//-- Prototype Interface + Element Interface + Methods + Variables = VideoGame Abstract Class --//
//----------------------------------------------------------------------------------------------//
class VideoGame {
public:
	virtual VideoGame* clone() = 0;
  	virtual void accept(Visitor*) = 0;
	int getId() {
		return id;
	}
	string getName() {
		return name;
	}
	float getPrice() {
		return price;
	}
	void setPrice(float price) {
		this->price = price;
	}
protected:
	int id;
	string name;
	float price;
};
//-------------------------------------------//
//-- Concrete Prototype + Concrete Element --//
//-------------------------------------------//
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
	void accept(Visitor* visitor);
private:
	string period;
	bool supportsMultiplayer;
	int numberOfOponents;
};
//-------------------------------------------//
//-- Concrete Prototype + Concrete Element --//
//-------------------------------------------//
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
  void accept(Visitor* visitor);
private:
	string protagonistName;
	string storyDescription;
	int numberOfPuzzles;
};
//-------------------------------------------//
//-- Concrete Prototype + Concrete Element --//
//-------------------------------------------//
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
  void accept(Visitor* visitor);
private:
	string subject;
	string skill;
	string teacherName;
};
//-------------//
//-- Visitor --//
//-------------//
class Visitor {
public:
  virtual void visit(StrategyGame) = 0;
  virtual void visit(AdventureGame) = 0;
  virtual void visit(LearningGame) = 0;
};
//----------------------//
//-- Concrete Visitor --//
//----------------------//
class TaxVisitor : public Visitor {
public:
  void visit(StrategyGame strategy_game) {
  	printf("Taxing Strategy Game...Tax rate for Strategy games: %%16\n");
		strategy_game.setPrice(strategy_game.getPrice() * 1.16);
		cout << "New Price: " << strategy_game.getPrice() << endl;
  }
  void visit(AdventureGame adventure_game) {
  	printf("Taxing Adventure Game...Tax rate for Adventure games: %%30\n");
		adventure_game.setPrice(adventure_game.getPrice() * 1.3);
		cout << "New Price: " << adventure_game.getPrice() << endl;
  }
  void visit(LearningGame learning_game) {
  	printf("Taxing Learning Game...Tax rate for Learning games: %%3\n");
		learning_game.setPrice(learning_game.getPrice() * 1.03);
		cout << "New Price: " << learning_game.getPrice() << endl;
  }
};

void StrategyGame::accept(Visitor* visitor) {
  visitor->visit(*this);
}
void AdventureGame::accept(Visitor* visitor) {
  visitor->visit(*this);
}
void LearningGame::accept(Visitor* visitor) {
  visitor->visit(*this);
}

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
class InventorySystem {
public:
	void addVideoGame(VideoGame* videogame) {
		cout << "Adding Videogame: " << videogame->getId() << " " << videogame->getName() << " " << videogame->getPrice() << endl;
		videogames.push_back(videogame);
	}

	void deleteVideoGame(VideoGame* videogame) {
		cout << "Deleting Videogame: " << videogame->getId() << " " << videogame->getName() << " " << videogame->getPrice() << endl;
		// Linear search by id. Can improve by sorting and doing binary search
		for (unsigned int i = 0; i < videogames.size(); ++i)
		{
			if(videogames[i]->getId() == videogame->getId())
				videogames.erase(videogames.begin() + i);
		}
	}

	static bool sortFunction(VideoGame* i, VideoGame* j) {
		return(i->getPrice() < j->getPrice());
	}

	static bool sortDescendingFunction(VideoGame* i, VideoGame* j) {
		return(i->getPrice() > j->getPrice());
	}

	void sort() {
		printf("Sorting...\n");
		std::sort(videogames.begin(), videogames.end(), sortFunction);
	}

	void sortDescending() {
		printf("Sorting Descending...\n");
		std::sort(videogames.begin(), videogames.end(), sortDescendingFunction);
	}

	void search(int id) {
		printf("Searching...\n");
		// Linear search by id. Can improve by sorting and doing binary search
		for (unsigned int i = 0; i < videogames.size(); ++i)
		{
			if (videogames[i]->getId() == id)
				cout << "Found videogame: " << videogames[i]->getId() << " " << videogames[i]->getName() << " " << videogames[i]->getPrice() << endl;
		}
	}

	int getSizeOfInventory() {
		return videogames.size();
	}

	void printInventory() {
		printf("Printing Inventory...\n");
		printf("+------------+\n");
		printf("| Inventory  |\n");
		printf("+------------+\n");
		printf("+------------+\n");
		printf("| Videogames |\n");
		printf("+------------+\n");
		for (unsigned int i = 0; i < videogames.size(); ++i)
		{
			cout << "Id: " << videogames[i]->getId() << " Name: " << videogames[i]->getName()  << "\tPrice: " << videogames[i]->getPrice() << endl;
		}
	}

	void taxVideoGames(Visitor* visitor) {
		printf("Taxing Videogames...\n");
		printf("test\n");
		for(unsigned int i = 0; i < videogames.size(); i++) {
			printf("Looping through videogames!\n");
			videogames[i]->accept(visitor);
		}
	}
private:
	std::vector<VideoGame*> videogames;
};


//----------------------//
//-- Concrete Command --//
//----------------------//
class AddVideoGame : public Command {
private:
	InventorySystem* inventory_system;
	VideoGame* videogame;
public:
	AddVideoGame(InventorySystem* inventory_system, VideoGame* videogame) {
		this->inventory_system = inventory_system;
		this->videogame = videogame;
	}
	void execute() {
		inventory_system->addVideoGame(videogame);
	}
	void undo() {
		inventory_system->deleteVideoGame(videogame);
	}
};

//----------------------//
//-- Concrete Command --//
//----------------------//
class DeleteVideoGame : public Command {
private:
	InventorySystem* inventory_system;
	VideoGame* videogame;
public:
	DeleteVideoGame(InventorySystem* inventory_system, VideoGame* videogame) {
		this->inventory_system = inventory_system;
		this->videogame = videogame;
	}
	void execute() {
		inventory_system->deleteVideoGame(videogame);
	}
	void undo() {
		inventory_system->addVideoGame(videogame);
	}
};

//----------------------//
//-- Concrete Command --//
//----------------------//
class Sort : public Command {
private:
	InventorySystem* inventory_system;
public:
	Sort(InventorySystem* inventory_system) {
		this->inventory_system = inventory_system;
	}
	void execute() {
		inventory_system->sort();
	}
	void undo() {
		
	}
};

//----------------------//
//-- Concrete Command --//
//----------------------//
class SortDescending : public Command {
private:
	InventorySystem* inventory_system;
public:
	SortDescending(InventorySystem* inventory_system) {
		this->inventory_system = inventory_system;
	}
	void execute() {
		inventory_system->sortDescending();
	}
	void undo() {
		
	}
};

//----------------------//
//-- Concrete Command --//
//----------------------//
class Search : public Command {
private:
	InventorySystem* inventory_system;
	int id;
public:
	Search(InventorySystem* inventory_system, int id) {
		this->inventory_system = inventory_system;
		this->id = id;
	}
	void execute() {
		inventory_system->search(id);
	}
	void undo() {
		
	}
};

//----------------------//
//-- Concrete Command --//
//----------------------//
class GetSizeOfInventory : public Command {
private:
	InventorySystem* inventory_system;
public:
	GetSizeOfInventory(InventorySystem* inventory_system) {
		this->inventory_system = inventory_system;
	}
	void execute() {
		inventory_system->getSizeOfInventory();
	}
	void undo() {
		
	}
};

//----------------------//
//-- Concrete Command --//
//----------------------//
class PrintInventory : public Command {
private:
	InventorySystem* inventory_system;
public:
	PrintInventory(InventorySystem* inventory_system) {
		this->inventory_system = inventory_system;
	}
	void execute() {
		inventory_system->printInventory();
	}
	void undo() {
		
	}
};

//----------------------//
//-- Concrete Command --//
//----------------------//
class TaxVideoGames : public Command {
private:
	InventorySystem* inventory_system;
	Visitor* visitor;
public:
	TaxVideoGames(InventorySystem* inventory_system, Visitor* visitor) {
		this->inventory_system = inventory_system;
		this->visitor = visitor;
	}
	void execute() {
		inventory_system->taxVideoGames(visitor);
	}
	void undo() {
		
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
	void revert(unsigned int n) {
		if(n > commands.size()) {
			cout << "Error: can't insufficient commands to revert!" << endl;
		} else {
			cout << "Undo " << n << " times..." << endl;
			for (unsigned int i = 0; i < n; ++i)
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
//--------------//
//-- Observer --//
//--------------//
class Subscriber {
public:
	virtual void update(string, string) = 0;
	string getName() {
		return name;
	}
protected:
	string name;
};

//-----------------------//
//-- Concrete Observer --//
//-----------------------//
class ConcreteSubscriber : public Subscriber {
public:
	ConcreteSubscriber(string name) {
		this->name = name;
	}
	void update(string company_name, string message) {
		cout << name << " feed: message from " << company_name << ": "  << message << endl;
	}
};


//-------------//
//-- Subject --//
//-------------//
class Company {
public:
	virtual void attach(Subscriber * obs) = 0;
	virtual void detach(Subscriber * obs) = 0;
	virtual void notifyAll() = 0;
	void setMessage(string message) {
		this->message = message;
	}
protected:
	vector<Subscriber*> subscribers;
	string name;
	string message;
};

//----------------------//
//-- Concrete Subject --//
//----------------------//
class VideoGameCompany : public Company {
public:
	VideoGameCompany(string name) {
		this->name = name;
	}
	void attach(Subscriber* subscriber) {
		subscribers.push_back(subscriber);
	}
	void detach(Subscriber* subscriber) {
		for(unsigned int i = 0; i < subscribers.size(); i++) {
			subscribers.erase(subscribers.begin() + i);
		}
	}
	void notifyAll() {
		for (unsigned int i = 0; i < subscribers.size(); ++i)
		{
			subscribers[i]->update(name, message);
		}
	}
};


int main(int argc, char const *argv[])
{
	// Creating Objects
	VideoGameCompany game_stop("Game Stop");
	ConcreteSubscriber subscriber1("Bob");
	ConcreteSubscriber subscriber2("John");
	ConcreteSubscriber subscriber3("Juan");

	Invoker* remoteControl = new Invoker;
	InventorySystem* inventory_system = new InventorySystem;
	TaxVisitor* tax_visitor = new TaxVisitor;

	// Strategy Games
	VideoGame* age_of_empires = new StrategyGame(1, "Age of Empires", 100);
	VideoGame* age_of_empires_2 = age_of_empires->clone();
	VideoGame* starcraft = new StrategyGame(2, "Starcraft", 50);
	VideoGame* starcraft2 = new StrategyGame(3, "Starcraft 2", 60);
	VideoGame* civilization = new StrategyGame(4, "Civilization", 60.5);
	// Adventure Games
	VideoGame* shadow_of_the_colossus = new AdventureGame(5, "Shadow of the Colossus", 300);
	VideoGame* the_last_of_us = new AdventureGame(6, "The Last of Us", 450);
	// Learning Games
	VideoGame* big_brain_academy = new LearningGame(7, "Big Brain Academy", 70);
	VideoGame* smarty_pants = new LearningGame(8, "Smarty Pants", 40);

	// Notifications
	game_stop.attach(&subscriber1);
	game_stop.attach(&subscriber2);
	game_stop.attach(&subscriber3);
	game_stop.setMessage("New Releases! Age of Empires, The Last of Us, etc.");
	game_stop.notifyAll();



	// Adding Videogames
	remoteControl->setCommand(new AddVideoGame(inventory_system, age_of_empires));
	remoteControl->executeButton();
	remoteControl->setCommand(new AddVideoGame(inventory_system, starcraft));
	remoteControl->executeButton();
	remoteControl->setCommand(new AddVideoGame(inventory_system, starcraft2));
	remoteControl->executeButton();
	remoteControl->setCommand(new AddVideoGame(inventory_system, civilization));
	remoteControl->executeButton();
	remoteControl->setCommand(new AddVideoGame(inventory_system, shadow_of_the_colossus));
	remoteControl->executeButton();
	remoteControl->setCommand(new AddVideoGame(inventory_system, the_last_of_us));
	remoteControl->executeButton();
	remoteControl->setCommand(new AddVideoGame(inventory_system, big_brain_academy));
	remoteControl->executeButton();
	remoteControl->setCommand(new AddVideoGame(inventory_system, smarty_pants));
	remoteControl->executeButton();

	// Deleting Videogames
	remoteControl->setCommand(new DeleteVideoGame(inventory_system, civilization));
	remoteControl->executeButton();
	remoteControl->setCommand(new DeleteVideoGame(inventory_system, age_of_empires));
	remoteControl->executeButton();
	remoteControl->setCommand(new DeleteVideoGame(inventory_system, starcraft));
	remoteControl->executeButton();
	// Add deleted videogame
	remoteControl->revert(3);

	remoteControl->setCommand(new PrintInventory(inventory_system));
	remoteControl->executeButton();
	cout << inventory_system->getSizeOfInventory() << endl;

	// Sorting
	remoteControl->setCommand(new Sort(inventory_system));
	remoteControl->executeButton();
	remoteControl->setCommand(new PrintInventory(inventory_system));
	remoteControl->executeButton();
	// Sortind Descendent
	remoteControl->setCommand(new SortDescending(inventory_system));
	remoteControl->executeButton();
	remoteControl->setCommand(new PrintInventory(inventory_system));
	remoteControl->executeButton();

	cout << "Size of inventory: " << inventory_system->getSizeOfInventory() << endl;
	// cout << "Number of buttons pressed: " << inventory->remoteControl->getSizeOfCommands() << endl;

	// Apply taxes
	remoteControl->setCommand(new TaxVideoGames(inventory_system, tax_visitor));
	remoteControl->executeButton();

	// Searching
	remoteControl->setCommand(new Search(inventory_system, 1));
	remoteControl->executeButton();
	remoteControl->setCommand(new Search(inventory_system, 20));
	remoteControl->executeButton();


	// free memory
	delete age_of_empires;
	delete age_of_empires_2;
	delete starcraft;
	delete starcraft2;
	delete civilization;
	delete shadow_of_the_colossus;
	delete the_last_of_us;
	delete big_brain_academy;
	delete smarty_pants;
	delete inventory_system;
	delete remoteControl;
	return 0;
}
