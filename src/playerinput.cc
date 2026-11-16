#include <iostream>
#include "playerinput.h"
#include "state.h"
using namespace std;

Command PlayerInput::getCommand() {
    string command;
    while (true) {
        cin >> command;
        if (command == "board") return Command::Board;
        else if (command == "status") return Command::Status;
        else if (command == "roll") return Command::Roll;
        else if (command == "criteria") return Command::Criteria;
        else if (command == "achieve") return Command::Achieve;
        else if (command == "complete") return Command::Complete;
        else if (command == "improve") return Command::Improve;
        else if (command == "trade") return Command::Trade;
        else if (command == "next") return Command::Next;
        else if (command == "save") return Command::Save;
        else if (command == "help") return Command::Help;
        else if (command == "load") return Command::DiceLoad;
        else if (command == "fair") return Command::DiceFair;
        else if (command == "quit") return Command::Quit;

        cin.ignore(1, '\n');
        if (cin.eof()) return Command::Quit;
    }
}

int PlayerInput::getLoadedDice(const int min, const int max) {
    int value;
    while (true) {
        if (cin >> value) {
            if (value >= min && value <= max) return value;
        } else {
            cin.clear();
            cin.ignore(1, '\n');
        }
    }
}

int PlayerInput::getCriterionPlacement(const int min, const int max) {
    int index;
    while (true) {
        if (cin >> index) {
            if (index >= min && index <= max) return index;
        } else {
            cin.clear();
            cin.ignore(1, '\n');
        }
    }
}

int PlayerInput::getGoalPlacement(const int min, const int max) {
    int index;
    while (true) {
        if (cin >> index) {
            if (index >= min && index <= max) return index;
        } else {
            cin.clear();
            cin.ignore(1, '\n');
        }
    }
}

int PlayerInput::getTile(const int min, const int max) {
    int index;
    while (true) {
        if (cin >> index) {
            if (index >= min && index <= max) return index;
        } else {
            cin.clear();
            cin.ignore(1, '\n');
        }
    }
}

TradeInfo PlayerInput::getTrade() {
    string input;
    Resource r_1, r_2;
    Colour c;

    while (true) {
        cin >> input;
        if (input == "Blue" || input == "blue") c = Colour::Blue;
        else if (input == "Red" || input == "red") c = Colour::Red;
        else if (input == "Orange" || input == "orange") c = Colour::Orange;
        else if (input == "Yellow" || input == "yellow") c = Colour::Yellow;
        else { getline(cin, input); continue; }

        cin >> input;
        if (input == "TUTORIAL" || input == "tutorial") r_1 = Resource::TUTORIAL;
        else if (input == "LECTURE" || input == "lecture") r_1 = Resource::LECTURE;
        else if (input == "STUDY" || input == "study") r_1 = Resource::STUDY;
        else if (input == "CAFFEINE" || input == "caffeine") r_1 = Resource::CAFFEINE;
        else if (input == "LAB" || input == "lab") r_1 = Resource::LAB;
        else { getline(cin, input); continue; }

        cin >> input;
        if (input == "TUTORIAL" || input == "tutorial") r_2 = Resource::TUTORIAL;
        else if (input == "LECTURE" || input == "lecture") r_2 = Resource::LECTURE;
        else if (input == "STUDY" || input == "study") r_2 = Resource::STUDY;
        else if (input == "CAFFEINE" || input == "caffeine") r_2 = Resource::CAFFEINE;
        else if (input == "LAB" || input == "lab") r_2 = Resource::LAB;
        else { getline(cin, input); continue; }

        break;
    }
    return {c, r_1, r_2};
}

Response PlayerInput::getResponse() {
    string input;
    while (true) {
        cin >> input;
        if (input == "Yes" || input == "yes") return Response::Yes;
        else if (input == "No" || input == "no") return Response::No;

        cin.clear();
        cin.ignore(1, '\n');
    }
}

string PlayerInput::getSaveFile() {
    string input;
    cin >> input;
    return input;
}

Colour PlayerInput::getStealChoice(const std::vector<Colour>& choices) {
    string input;
    Colour c;
    while (true) {
        cin >> input;
        if (input == "Blue" || input == "blue") c = Colour::Blue;
        else if (input == "Red" || input == "red") c = Colour::Red;
        else if (input == "Orange" || input == "orange") c = Colour::Orange;
        else if (input == "Yellow" || input == "yellow") c = Colour::Yellow;
        else { getline(cin, input); continue; }

        for (Colour cl : choices) {
            if (cl == c) return c;
        }
        cin.ignore(1, '\n');
    }
}
