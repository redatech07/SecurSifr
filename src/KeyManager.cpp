#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "KeyManager.hpp"

using namespace std;


    KeyManager::KeyManager()
    {
        srand(time(NULL));
    }
    void KeyManager::CleAlea(const int &taille)
    {
        cleStockee.clear();
        unsigned char octetAlea;
        for (int i = 0; i < taille; i++)
        {
        octetAlea = rand() % 256;
        cleStockee += static_cast<char>(octetAlea);
        }
    }
    string KeyManager::getCle() const {
        return cleStockee;
    }
    bool KeyManager::chargerCle(const string& nomFichier)
    {
    ifstream fichier;
    fichier.open("./keys/" + nomFichier + ".key", ios::binary);
    if (fichier.is_open())

    {
        stringstream buffer;
        buffer << fichier.rdbuf();
        cleStockee = buffer.str();
        fichier.close();
        return !cleStockee.empty();

    }
    cout << "ERREUR : Impossible de charger la cle.\n";
    return false;
    }
    void KeyManager::sauvegarderCle(const string& nomFichier)
{
    ofstream fichier;
    fichier.open("./keys/" + nomFichier + ".key", ios::binary);
    cout << "Sauvegarde de la clé en cours ......\n";
    if (fichier.is_open())
    {
        fichier.write(cleStockee.data(), cleStockee.size());
        fichier.close();

        cout << "Cle sauvegarde avec succes.\n";
        cout << "Chemin du fichier cle : keys/" << nomFichier << ".key\n";
    }
    else
    {
        cout << "ERREUR : Impossible de sauvegarder la cle.\n";
    }
}
