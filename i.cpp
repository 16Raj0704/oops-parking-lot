#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <memory>

using namespace std;

class Car {
public:
    string regNumber;
    string color;

    Car(const string& reg, const string& col) : regNumber(reg), color(col) {}
};

class ParkingLot {
private:
    vector<unique_ptr<Car>> slots;
    int capacity = 0;

public:
    void createParkingLot(int size) {
        if (size <= 0) {
            cout << "Invalid parking lot size." << endl;
            return;
        }
        capacity = size;
        slots = vector<unique_ptr<Car>>(size);
        cout << "Created a parking lot with " << size << " slots" << endl;
    }

    void park(const string& reg, const string& color) {
        for (int i = 0; i < capacity; ++i) {
            if (!slots[i]) {
                slots[i] = make_unique<Car>(reg, color);
                cout << "Allocated slot number: " << i + 1 << endl;
                return;
            }
        }
        cout << "Sorry, parking lot is full" << endl;
    }

    void leave(int slot) {
        if (slot < 1 || slot > capacity) {
            cout << "Invalid slot number: " << slot << endl;
            return;
        }
        if (!slots[slot - 1]) {
            cout << "Slot number " << slot << " is already empty" << endl;
            return;
        }
        slots[slot - 1].reset();
        cout << "Slot number " << slot << " is free" << endl;
    }

    void status() const {
        cout << "Slot No.\tRegistration No\tColour" << endl;
        for (int i = 0; i < capacity; ++i) {
            if (slots[i]) {
                cout << i + 1 << "\t\t" << slots[i]->regNumber << "\t" << slots[i]->color << endl;
            }
        }
    }

    void regByColor(const string& color) const {
        vector<string> regs;
        for (const auto& car : slots) {
            if (car && car->color == color)
                regs.push_back(car->regNumber);
        }
        if (!regs.empty())
            cout << join(regs, ", ") << endl;
        else
            cout << "Not found" << endl;
    }

    void slotByColor(const string& color) const {
        vector<string> slotNums;
        for (int i = 0; i < capacity; ++i) {
            if (slots[i] && slots[i]->color == color)
                slotNums.push_back(to_string(i + 1));
        }
        if (!slotNums.empty())
            cout << join(slotNums, ", ") << endl;
        else
            cout << "Not found" << endl;
    }

    void slotByReg(const string& reg) const {
        for (int i = 0; i < capacity; ++i) {
            if (slots[i] && slots[i]->regNumber == reg) {
                cout << i + 1 << endl;
                return;
            }
        }
        cout << "Not found" << endl;
    }

    static string join(const vector<string>& vec, const string& delimiter) {
        ostringstream oss;
        for (size_t i = 0; i < vec.size(); ++i) {
            oss << vec[i];
            if (i != vec.size() - 1) oss << delimiter;
        }
        return oss.str();
    }
};

// Helper function to split a string by whitespace
vector<string> split(const string& str) {
    vector<string> tokens;
    stringstream ss(str);
    string temp;
    while (ss >> temp) tokens.push_back(temp);
    return tokens;
}

void processCommand(const string& line, ParkingLot& lot) {
    auto parts = split(line);
    if (parts.empty()) return;

    try {
        string cmd = parts[0];

        if (cmd == "create_parking_lot" && parts.size() == 2) {
            lot.createParkingLot(stoi(parts[1]));
        } else if (cmd == "park" && parts.size() == 3) {
            lot.park(parts[1], parts[2]);
        } else if (cmd == "leave" && parts.size() == 2) {
            lot.leave(stoi(parts[1]));
        } else if (cmd == "status") {
            lot.status();
        } else if (cmd == "registration_numbers_for_cars_with_colour" && parts.size() == 2) {
            lot.regByColor(parts[1]);
        } else if (cmd == "slot_numbers_for_cars_with_colour" && parts.size() == 2) {
            lot.slotByColor(parts[1]);
        } else if (cmd == "slot_number_for_registration_number" && parts.size() == 2) {
            lot.slotByReg(parts[1]);
        } else {
            cout << "Invalid command" << endl;
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

int main(int argc, char* argv[]) {
    ParkingLot lot;

    // Help banner
    cout << "🚗 Welcome to the Parking Lot System 🚗\n";
    cout << "Available commands:\n";
    cout << "  create_parking_lot <size>\n";
    cout << "  park <registration_number> <color>\n";
    cout << "  leave <slot_number>\n";
    cout << "  status\n";
    cout << "  registration_numbers_for_cars_with_colour <color>\n";
    cout << "  slot_numbers_for_cars_with_colour <color>\n";
    cout << "  slot_number_for_registration_number <registration_number>\n";
    cout << "Type 'exit' to quit (interactive mode only).\n";
    cout << "--------------------------------------------------\n";

    try {
        if (argc == 2) {
            ifstream file(argv[1]);
            if (!file) {
                cerr << "Could not open file." << endl;
                return 1;
            }
            string line;
            while (getline(file, line)) {
                processCommand(line, lot);
            }
        } else {
            string line;
            while (true) {
                cout << "> ";
                getline(cin, line);
                if (line == "exit") break;
                processCommand(line, lot);
            }
        }
    } catch (const exception& e) {
        cerr << "Unhandled error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
