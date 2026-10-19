#ifndef CRYPT_HPP
#define CRYPT_HPP
#include <string>

using namespace std;

class CryptoEngine
{
    public:
    string encrypt(const string &TexteAChiffrer, const string &key);
    string decrypt(const string &TexteADechiffrer, const string &key);
};

#endif 