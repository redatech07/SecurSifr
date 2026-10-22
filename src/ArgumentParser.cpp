#include <iostream>
#include <string>
#include "ArgumentParser.hpp"
using namespace std;


    ArgumentParser::ArgumentParser()
    {
        mode ="";
        nomFichier="";
        nomCle="";
    }
    bool ArgumentParser::analyserArguments(int argc, char* argv[]) 
    {
        bool modeDejaDefini = false;
        bool fichierDejaDefini = false;
        bool cleDejaDefinie = false;
        for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];

        if (arg == "-m" || arg == "--mode")
        {
        if (modeDejaDefini)
        {
        cout << "Erreur : le mode a ete precise plusieurs fois.\n";
        return false;
        }
        if (i + 1 >= argc || string(argv[i + 1]).substr(0, 1) == "-")
        {
            cout << "Erreur : valeur manquante pour " << arg << ".\n";
            return false;
        }

        mode = argv[++i];
        modeDejaDefini = true;
        }
        else if (arg == "-f" || arg == "--fichier" || arg == "--file")
        {
        if (fichierDejaDefini)
        {
        cout << "Erreur : le fichier a ete precise plusieurs fois.\n";
        return false;
        }
        if (i + 1 >= argc || string(argv[i + 1]).substr(0, 1) == "-")
        {
            cout << "Erreur : valeur manquante pour " << arg << ".\n";
            return false;
        }

        nomFichier = argv[++i];
        fichierDejaDefini = true;
        }
        else if (arg == "-k" || arg == "-c" || arg == "--cle" || arg == "--key")
        {
        if (cleDejaDefinie)
        {
        cout << "Erreur : la cle a ete precise plusieurs fois.\n";
        return false;
        }
        if (i + 1 >= argc || string(argv[i + 1]).substr(0, 1) == "-")
        {
            cout << "Erreur : valeur manquante pour " << arg << ".\n";
            return false;
        }

        nomCle = argv[++i];
        cleDejaDefinie = true;
        }
        else
        {
        cout << "Erreur : option inconnue : " << arg << '\n';
        return false;
        }
    }
        if (mode.empty() || nomFichier.empty()) {
        cout << "Usage: ./SecureFile --mode <mode> --fichier <nom.extension> [--cle <nom>]\n";
        cout << "\nModes disponibles :\n";
        cout << "  chiffrer, encrypt       Chiffrer un fichier\n";
        cout << "  dechiffrer, decrypt     Dechiffrer un fichier (cle obligatoire)\n";
        cout << "\nOptions :\n";
        cout << "  -m, --mode              Mode de fonctionnement\n";
        cout << "  -f, --fichier, --file   Nom du fichier a traiter\n";
        cout << "  -k, -c, --cle, --key   Nom du fichier contenant la cle ou nom souhaite pour la cle generee\n";
        cout << "\nRemarque : la cle est facultative pour le chiffrement, mais obligatoire pour le dechiffrement.\n";
        return false;
    }
    if (mode != "chiffrer" && mode != "dechiffrer" && mode != "encrypt" && mode != "decrypt") 
    {
        cout << "Erreur : mode invalide. Utilisez 'chiffrer' ou 'dechiffrer' ou 'encrypt' ou 'decrypt'.\n";
        return false;
    }
    if ((mode == "dechiffrer" && nomCle.empty()) || (mode == "decrypt" && nomCle.empty())) 
    {
        cout << "Erreur : vous devez preciser une cle pour dechiffrer.\n";
        return false;
    }
    return true;
    }

    string ArgumentParser::getMode() const 
    { 
        return mode; 
    }
    string ArgumentParser::getNomFichier() const 
    { 
        return nomFichier; 
    }
    string ArgumentParser::getNomCle() const 
    { 
        return nomCle; 
    }