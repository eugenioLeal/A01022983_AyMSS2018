#include <bits/stdc++.h>
using namespace std;


class VideoGame {
public:
	virtual VideoGame* clone() = 0;
};

class StrategyGame : public VideoGame {
public:
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
	Inventory() {
	}
	Invoker* remoteControl;
	Receiver* receiverBox;
private:
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
	void addVideoGame() {
		printf("Adding VideoGame...\n");
	}
	void deleteVideoGame() {
		printf("Deleting VideoGame...\n");
	}
};


//----------------------//
//-- Concrete Command --//
//----------------------//
class AddVideoGame : public Command {
private:
	Receiver* receiver;
public:
	AddVideoGame(Receiver* receiver) {
		this->receiver = receiver;
	}
	void execute() {
		receiver->addVideoGame();
	}
	void undo() {
		receiver->deleteVideoGame();
	}
};

//----------------------//
//-- Concrete Command --//
//----------------------//
class DeleteVideoGame : public Command {
private:
	Receiver* receiver;
public:
	DeleteVideoGame(Receiver* receiver) {
		this->receiver = receiver;
	}
	void execute() {
		receiver->deleteVideoGame();
	}
	void undo() {
		receiver->addVideoGame();
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
	VideoGame *juego = new StrategyGame;
	VideoGame *another = juego->clone();

	Invoker* remoteControl = new Invoker;
	Receiver* box = new Receiver;

	remoteControl->setCommand(new AddVideoGame(box));
	remoteControl->executeButton();
	remoteControl->executeButton();
	remoteControl->executeButton();
	remoteControl->executeButton();
	remoteControl->executeButton();
	remoteControl->executeButton();

	cout << "Number of buttons pressed: " << remoteControl->getSizeOfCommands() << endl;

	remoteControl->setCommand(new DeleteVideoGame(box));
	remoteControl->executeButton();
	remoteControl->executeButton();
	remoteControl->executeButton();

	cout << "Number of buttons pressed: " << remoteControl->getSizeOfCommands() << endl;

	remoteControl->revert(3);

	cout << "Number of buttons pressed: " << remoteControl->getSizeOfCommands() << endl;

	remoteControl->revert(9);

	cout << "Number of buttons pressed: " << remoteControl->getSizeOfCommands() << endl;




	// free memory
	delete juego;
	delete another;
	return 0;
}