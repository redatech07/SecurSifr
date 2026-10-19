#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <string>

using namespace std;

class FileManager
{
private:
string cheminFichier;

public:
FileManager(const string& chemin);
string lireTout(bool saut = false);
void ecrire(const string& contenu,bool append = false);

};

#endif