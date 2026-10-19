#ifndef KEYMANAGER_HPP
#define KEYMANAGER_HPP

#include <string>

using namespace std;

class KeyManager
{
private:
string cleStockee;

public:
KeyManager();
void CleAlea(const int& taille);
string getCle()const;
bool chargerCle(const string& nomFichier);
void sauvegarderCle(const string& nomFichier);
};

#endif