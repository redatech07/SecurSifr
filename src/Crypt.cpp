#include <iostream>
#include <string>
#include "Crypt.hpp"
using namespace std;



    string CryptoEngine::encrypt(const string &TexteAChiffrer, const string &key)
    {
        if (TexteAChiffrer.size() != key.size())
        {
            cout << "ERREUR : Le texte et la cle n'ont pas la meme taille !\n";
            return "";
        }

        string resultat = "";

        for (size_t i = 0; i < TexteAChiffrer.size(); i++)
        {
            unsigned char t = static_cast<unsigned char>(TexteAChiffrer[i]);
            unsigned char k = static_cast<unsigned char>(key[i]);

            int c = (t + k) % 256;

            resultat += static_cast<char>(c);
        }

        return resultat;
    }

    string CryptoEngine::decrypt(const string &TexteADechiffrer, const string &key)
    {
        if (TexteADechiffrer.size() != key.size())
        {
            cout << "ERREUR : Le texte chiffre et la cle n'ont pas la meme taille !\n";
            return "";
        }

        string resultat = "";

        for (size_t i = 0; i < TexteADechiffrer.size(); i++)
        {
            unsigned char c = static_cast<unsigned char>(TexteADechiffrer[i]);
            unsigned char k = static_cast<unsigned char>(key[i]);

            int t = (c - k + 256) % 256;

            resultat += static_cast<char>(t);
        }

        return resultat;
    }