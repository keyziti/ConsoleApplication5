#include <iostream>
#include <vector>

// Model
struct Discipline {
    std::string name;
    std::string time;
    std::string dayOfWeek; // Add a field for the day of the week

    Discipline(const std::string& n, const std::string& t, const std::string& dow) : name(n), time(t), dayOfWeek(dow) {}
};

class DisciplineModel {
public:
    std::vector<Discipline> disciplines;

    void addDiscipline(const std::string& name, const std::string& time, const std::string& dayOfWeek) {
        disciplines.emplace_back(name, time, dayOfWeek);
    }
};

// View
class DisciplineView {
public:
    void showDisciplines(const std::vector<Discipline>& disciplines) {
        std::cout << "List of Disciplines:" << std::endl;
        for (size_t i = 0; i < disciplines.size(); i++) {
            std::cout << i + 1 << ". " << disciplines[i].name << " (Day: " << disciplines[i].dayOfWeek << ", Time: " << disciplines[i].time << ")" << std::endl;
        }
    }

    Discipline getUserInput() {
        std::string name, time, dayOfWeek;
        std::cout << "Enter the name of the discipline: ";
        std::cin >> name;
        if (name == "q") {
            return Discipline("q", "", "");
        }
        std::cout << "Enter the day of the week: ";
        std::cin >> dayOfWeek;
        std::cout << "Enter the time for the discipline: ";
        std::cin >> time;
        return Discipline(name, time, dayOfWeek);
    }
};

// Presenter
class DisciplinePresenter {
private:
    DisciplineModel model;
    DisciplineView view;

public:
    void run() {
        while (true) {
            view.showDisciplines(model.disciplines);

            Discipline input = view.getUserInput();
            if (input.name == "q") {
                break;
            }

            model.addDiscipline(input.name, input.time, input.dayOfWeek);
        }
    }
};

int main() {
    DisciplinePresenter presenter;
    presenter.run();
    return 0;
}