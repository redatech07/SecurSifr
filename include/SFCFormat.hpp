#ifndef SFCFORMAT_HPP
#define SFCFORMAT_HPP

#include <string>
#include <fstream>
using namespace std;

class SFCFormat
{
    private :
    static const string EXTENSION_SFC;
    string extensionDorigine;

    public :
    SFCFormat();
    string getExtensionSFC() const;
    string getExtensionDorigine() const;
    void extraireExtension(const string &nomFichier);
    void ecrireExtension(ofstream &fichier);
    void lireExtension(ifstream &fichier);

};


#endif