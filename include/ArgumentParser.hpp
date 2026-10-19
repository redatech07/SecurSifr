#ifndef ARGUMENTPARSER_HPP
#define ARGUMENTPARSER_HPP

#include <string>

using namespace std;

class ArgumentParser
{
    private:
    string mode;
    string nomFichier;
    string nomCle;

    public:
    ArgumentParser();
    bool analyserArguments(int argc, char* argv[]);
    string getMode() const;
    string getNomFichier() const;
    string getNomCle() const;
};

#endif