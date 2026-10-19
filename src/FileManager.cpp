#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "FileManager.hpp"

using namespace std;

    FileManager::FileManager(const string &chemin)
    {
        cheminFichier = chemin;
    }

    string FileManager::lireTout(bool sautligne) 
    {
        ifstream fichier;
        fichier.open(cheminFichier, ios::binary);
        stringstream buffer;
        if(fichier.is_open())
        {
            if (sautligne)
            {
                string ligne;
                getline(fichier, ligne);
            }
        buffer << fichier.rdbuf();
        return buffer.str();
        }
        else {
            cout << "ERREUR : Impossible d'ouvrir le fichier\n";
        return "";
        }
    }

    void FileManager::ecrire(const string &contenu, bool append) {
        ofstream fichier;
        if (append)
        {
            fichier.open(cheminFichier, ios::binary | ios::app);
        }
        else
        {
        fichier.open(cheminFichier, ios::binary);
        }
        if(fichier.is_open())
        {
        fichier.write(contenu.data(), contenu.size());
        }
        else {
            cout << "ERREUR : Impossible d'ouvrir le fichier\n";
        return;
        }
    }

