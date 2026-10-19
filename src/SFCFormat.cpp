#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../include/SFCFormat.hpp"
using namespace std;

const string SFCFormat::EXTENSION_SFC = ".sfc";


    SFCFormat::SFCFormat()
    {
        extensionDorigine = "";
    }
    string SFCFormat::getExtensionSFC() const
{
    return EXTENSION_SFC;
}

string SFCFormat::getExtensionDorigine() const
{
    return extensionDorigine;
}

void SFCFormat::extraireExtension(const string &nomFichier)
{
    size_t position = nomFichier.find_last_of('.');
    if (position != string::npos)
    {
    extensionDorigine = nomFichier.substr(position);
    }
    else
    {
    extensionDorigine = "";
    }
}

void SFCFormat::ecrireExtension(ofstream &fichier)
{
    string extension = extensionDorigine;

    for (int i = 0; i < extension.size(); i++)
    {
    extension[i] = extension[i] ^ 42;
    }
    fichier << extension << '\n';
}

void SFCFormat::lireExtension(ifstream &fichier)
{
    getline(fichier, extensionDorigine);
    for (int i = 0; i < extensionDorigine.size(); i++)
    {
    extensionDorigine[i] = extensionDorigine[i] ^ 42;
    }
}