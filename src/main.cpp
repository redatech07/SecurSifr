#include <iostream>
#include <string>
#include "FileManager.hpp"
#include "KeyManager.hpp"
#include "ArgumentParser.hpp"
#include "Crypt.hpp"
#include "SFCFormat.hpp"
using namespace std;



void chiffrerFichier(const string& nomFichier, string& nomCle)
{
    cout << "\n========== CHIFFREMENT ==========\n";

    cout << "[INFO] Ouverture du fichier : " << nomFichier << '\n';

    FileManager F(nomFichier);
    KeyManager K;
    CryptoEngine C;
    SFCFormat Fo;

    string fichierlu = F.lireTout();

    if (fichierlu.empty())
    {
        cout << "[ATTENTION] Le fichier est vide ou n'a pas pu etre lu.\n";
    }
    else
    {
        cout << "[OK] Contenu du fichier lu avec succes.\n";
    }

    cout << "[INFO] Generation de la cle de chiffrement...\n";
    K.CleAlea(fichierlu.size());
    cout << "[OK] Cle generee avec succes.\n";

    if (nomCle == "")
    {
        nomCle = nomFichier.substr(0, nomFichier.find_last_of('.'));
        cout << "[INFO] Nom de la cle defini automatiquement : " << nomCle << '\n';
    }

    cout << "[INFO] Sauvegarde de la cle...\n";
    K.sauvegarderCle(nomCle);
    cout << "[OK] Sauvegarde de la cle terminee.\n";

    cout << "[INFO] Chiffrement du contenu...\n";
    string crypter = C.encrypt(fichierlu, K.getCle());
    cout << "[OK] Contenu chiffre avec succes.\n";

    string nomSortieSfc = "encrypted_file/" + nomFichier.substr(nomFichier.find_last_of('/') + 1, nomFichier.find_last_of('.') - nomFichier.find_last_of('/') - 1) + Fo.getExtensionSFC();

    cout << "[INFO] Fichier chiffre : " << nomSortieSfc << '\n';

    FileManager chiffre(nomSortieSfc);

    Fo.extraireExtension(nomFichier);

    cout << "[INFO] Enregistrement de l'extension d'origine...\n";

    ofstream fichierSortie(nomSortieSfc, ios::binary);

    if (fichierSortie.is_open())
    {
        Fo.ecrireExtension(fichierSortie);
        fichierSortie.close();

        cout << "[OK] Extension d'origine enregistree.\n";
    }
    else
    {
        cout << "[ERREUR] Impossible de creer le fichier SFC.\n";
        return;
    }

    cout << "[INFO] Ecriture du contenu chiffre...\n";
    chiffre.ecrire(crypter, true);

    cout << "[OK] Contenu chiffre enregistre.\n";
    cout << "\n========== CHIFFREMENT TERMINE ==========\n";
    cout << "[OK] Fichier cree : " << nomSortieSfc << '\n';
    cout << "[OK] Cle associee : " << nomCle << '\n';
}



void dechiffrerFichier(const string& nomFichier, const string& nomCle)
{
    cout << "\n========== DECHIFFREMENT ==========\n";

    cout << "[INFO] Ouverture du fichier chiffre : "
         << nomFichier << '\n';

    FileManager F(nomFichier);
    KeyManager K;
    CryptoEngine C;
    SFCFormat Fo;

    ifstream fcrypt(nomFichier, ios::binary);

    if (!fcrypt.is_open())
    {
        cout << "[ERREUR] Impossible d'ouvrir le fichier SFC.\n";
        return;
    }

    cout << "[OK] Fichier SFC ouvert avec succes.\n";

    cout << "[INFO] Lecture de l'extension d'origine...\n";
    Fo.lireExtension(fcrypt);

    cout << "[OK] Extension d'origine recuperee : " << Fo.getExtensionDorigine() << '\n';

    fcrypt.close();

    cout << "[INFO] Lecture du contenu chiffre...\n";
    string fichiercrypter = F.lireTout(true);
    cout << "[OK] Contenu chiffre lu avec succes.\n";

    cout << "[INFO] Chargement de la cle : " << nomCle << '\n';

    bool charger = K.chargerCle(nomCle);

    if (!charger)
    {
        cout << "[ERREUR] Impossible de charger la cle.\n";
        cout << "[INFO] Verifiez le nom et l'emplacement de la cle.\n";
        return;
    }

    cout << "[OK] Cle chargee avec succes.\n";

    string cle = K.getCle();

    cout << "[INFO] Dechiffrement du contenu...\n";
    string decrypt = C.decrypt(fichiercrypter, cle);
    cout << "[OK] Contenu dechiffre.\n";
    string nomFichierSortie = "file_to_encrypt/" + nomFichier.substr(nomFichier.find_last_of('/') + 1, nomFichier.find_last_of('.') - nomFichier.find_last_of('/') - 1 ) + Fo.getExtensionDorigine();

    cout << "[INFO] Fichier de sortie : " << nomFichierSortie << '\n';

    FileManager F2(nomFichierSortie);

    cout << "[INFO] Enregistrement du fichier restaure...\n";
    F2.ecrire(decrypt);

    cout << "[OK] Fichier restaure avec succes.\n";
    cout << "\n========== DECHIFFREMENT TERMINE ==========\n";
    cout << "[OK] Fichier restaure : " << nomFichierSortie << '\n';
}

int main(int argc,char *argv[])
{
    ArgumentParser arguments;
    if (!arguments.analyserArguments(argc, argv))
    {
        return 1;
    }
    string mode = arguments.getMode();
    string nomFichier = arguments.getNomFichier();
    string nomCle = arguments.getNomCle();
    cout << "Mode selectionne : " << mode << '\n';
    cout << "Fichier selectionne : " << nomFichier << '\n';

    if (!nomCle.empty())
    {
        cout << "Cle selectionnee : " << nomCle << '\n';
    }

    if(mode == "encrypt" || mode == "chiffrer")
    {
        chiffrerFichier(nomFichier,nomCle);
    }
    else 
    {
        dechiffrerFichier(nomFichier,nomCle);
    }
    
    return 0;

}