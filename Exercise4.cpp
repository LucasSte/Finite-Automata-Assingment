//
// Created by lucas on 9/23/19.
//

#include "StringTransitions/Automata.h"
#include "StringTransitions/Automata.cpp"

void DecomposeAutomata(Automata & automato, std::vector<Automata> & automatos)
{
    std::vector<int> finalStates;
    automato.getFinalStates(finalStates);

    Automata newAutomata = automato;

    for(int & i : finalStates)
    {
        newAutomata.removeFinal(i);
    }

    for(int & i : finalStates)
    {
        newAutomata.setFinal(i);
        automatos.emplace_back(newAutomata);
        newAutomata.removeFinal(i);
    }
}

int main()
{
    Automata automato;

    std::string path = "../teste4.txt";

    automato.createFromFile(path);

    std::vector<Automata> automatos;

    DecomposeAutomata(automato, automatos);

    std::cout << automatos.size() << std::endl;

    std::vector<std::string> regularExpressions;

    for(Automata & compenent : automatos)
    {
        compenent.addEpsilionBeginning();
        compenent.concatenateEdges();
        compenent.printAutomata();
    }

}
