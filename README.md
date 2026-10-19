# SecurSifr 🔐

## 🇫🇷 Français

### Présentation

SecurSifr permet de chiffrer des fichiers à l'aide d'une clé générée automatiquement, puis de les déchiffrer pour retrouver leur contenu d'origine.

Les fichiers chiffrés utilisent le format personnalisé `.sfc`. Le programme conserve également l'extension du fichier d'origine afin de pouvoir la restaurer lors du déchiffrement.

### Fonctionnalités

- Chiffrement et déchiffrement de fichiers.
- Génération automatique de clés.
- Sauvegarde et chargement des clés.
- Format de fichier personnalisé `.sfc`.
- Conservation de l'extension du fichier d'origine.
- Gestion des arguments avec des options courtes ou longues.
- Manipulation de fichiers en mode binaire.

### Compilation

Depuis le répertoire du projet, exécuter :

```bash
g++ src/*.cpp -I ./include -o SecurSifr
```

### Utilisation

Le programme se lance depuis le terminal et reçoit les informations nécessaires sous forme d'arguments.

#### Options disponibles

| Option | Description |
|---|---|
| `-m`, `--mode` | Définit le mode de fonctionnement. |
| `-f`, `--fichier`, `--file` | Indique le fichier à traiter. |
| `-k`, `-c`, `--cle`, `--key` | Définit le nom de la clé. |

Modes disponibles :

- `chiffrer` ou `encrypt` : chiffre un fichier.
- `dechiffrer` ou `decrypt` : déchiffre un fichier.

Le mode et le fichier sont obligatoires. Le nom de la clé est facultatif pour le chiffrement, mais obligatoire pour le déchiffrement.

### Chiffrer un fichier

Pour chiffrer un fichier, utiliser :

```bash
./SecurSifr --mode chiffrer --fichier document.txt
```

Il est également possible d'utiliser les options courtes :

```bash
./SecurSifr -m chiffrer -f document.txt
```

Par défaut, le programme déduit le nom de la clé du nom du fichier.

Pour choisir un nom de clé :

```bash
./SecurSifr --mode chiffrer --fichier document.txt --cle ma_cle
```

Ou avec les options courtes :

```bash
./SecurSifr -m chiffrer -f document.txt -k ma_cle
```

Le programme :

1. Lit le contenu du fichier.
2. Génère une clé de la même taille que le contenu.
3. Sauvegarde la clé dans un fichier `.key`.
4. Chiffre le contenu à l'aide de la clé.
5. Enregistre le résultat dans un fichier `.sfc`.
6. Stocke l'extension d'origine dans le fichier chiffré.

Exemple de fichiers générés :

```text
document.txt
document.sfc
keys/
└── document.key
```

Si le nom de clé `ma_cle` est choisi, le fichier de clé s'appelle `ma_cle.key`.

### Déchiffrer un fichier

Pour déchiffrer un fichier `.sfc`, indiquer le nom du fichier et celui de la clé correspondante :

```bash
./SecurSifr --mode dechiffrer --fichier document.sfc --cle document
```

Avec les options courtes :

```bash
./SecurSifr -m dechiffrer -f document.sfc -k document
```

Le programme :

1. Ouvre le fichier `.sfc`.
2. Récupère l'extension d'origine.
3. Lit le contenu chiffré.
4. Charge la clé correspondante.
5. Déchiffre le contenu.
6. Recrée le fichier avec son extension d'origine.

Par exemple, le déchiffrement de `document.sfc` permet de recréer `document.txt` si l'extension d'origine était `.txt`.

### Gestion des clés

Les clés sont enregistrées dans des fichiers `.key`. Le nom fourni dans les arguments correspond au nom du fichier de clé, sans l'extension `.key`.

Exemple :

```text
keys/
├── document.key
└── ma_cle.key
```

Il est nécessaire de conserver la clé associée à chaque fichier chiffré pour pouvoir le déchiffrer ultérieurement.

### Organisation du code

| Classe | Rôle |
|---|---|
| `ArgumentParser` | Analyse et valide les arguments de la ligne de commande. |
| `Crypt` | Effectue le chiffrement et le déchiffrement. |
| `FileManager` | Gère la lecture et l'écriture des fichiers. |
| `KeyManager` | Génère, sauvegarde et charge les clés. |
| `SFCFormat` | Gère le format `.sfc` et l'extension d'origine. |

### Limites et sécurité

SecurSifr est un projet étudiant fourni « en l'état », sans garantie de sécurité. Il ne doit pas être utilisé pour protéger des données sensibles ou confidentielles. L'utilisateur doit conserver une copie de ses fichiers originaux et sauvegarder ses clés de chiffrement dans un endroit sûr. La perte d'une clé peut rendre les fichiers chiffrés irrécupérables.

L'auteur décline toute responsabilité concernant les dommages ou pertes résultant de l'utilisation du logiciel, dans les limites prévues par la loi applicable.

---

## 🇬🇧 English

### Overview

SecurSifr is a C++ command-line application for encrypting and decrypting files using automatically generated keys.

Encrypted files use a custom `.sfc` format. The program also preserves the original file extension so it can be restored during decryption.

### Features

- File encryption and decryption.
- Automatic key generation.
- Key storage and loading.
- Custom `.sfc` file format.
- Preservation of the original file extension.
- Short and long command-line options.
- Binary file handling.

### Compilation

From the project directory, run:

```bash
g++ src/*.cpp -I ./include -o SecurSifr
```

### Usage

The program runs from the terminal and accepts command-line arguments.

#### Available options

| Option | Description |
|---|---|
| `-m`, `--mode` | Sets the operating mode. |
| `-f`, `--fichier`, `--file` | Specifies the file to process. |
| `-k`, `-c`, `--cle`, `--key` | Specifies the key name. |

Available modes:

- `chiffrer` or `encrypt`: encrypts a file.
- `dechiffrer` or `decrypt`: decrypts a file.

The mode and file arguments are required. The key name is optional for encryption but mandatory for decryption.

### Encrypt a file

To encrypt a file, run:

```bash
./SecurSifr --mode encrypt --file document.txt
```

You can also use the short options:

```bash
./SecurSifr -m encrypt -f document.txt
```

By default, the program derives the key name from the input filename.

To specify a key name:

```bash
./SecurSifr --mode encrypt --file document.txt --key my_key
```

Or use the short options:

```bash
./SecurSifr -m encrypt -f document.txt -k my_key
```

The program:

1. Reads the file contents.
2. Generates a key matching the content size.
3. Saves the key in a `.key` file.
4. Encrypts the contents using the key.
5. Saves the result in an `.sfc` file.
6. Stores the original file extension in the encrypted file.

Example output:

```text
document.txt
document.sfc
keys/
└── document.key
```

If `my_key` is specified, the key file is named `my_key.key`.

### Decrypt a file

To decrypt an `.sfc` file, provide the filename and the corresponding key name:

```bash
./SecurSifr --mode decrypt --file document.sfc --key document
```

Using short options:

```bash
./SecurSifr -m decrypt -f document.sfc -k document
```

The program:

1. Opens the `.sfc` file.
2. Retrieves the original file extension.
3. Reads the encrypted contents.
4. Loads the corresponding key.
5. Decrypts the contents.
6. Recreates the file with its original extension.

For example, decrypting `document.sfc` recreates `document.txt` if the original extension was `.txt`.

### Key management

Keys are stored in `.key` files. The name provided in the command-line arguments corresponds to the key filename without the `.key` extension.

Example:

```text
keys/
├── document.key
└── my_key.key
```

Keep the key associated with each encrypted file to decrypt it later.

### Code structure

| Class | Responsibility |
|---|---|
| `ArgumentParser` | Parses and validates command-line arguments. |
| `Crypt` | Performs encryption and decryption. |
| `FileManager` | Handles file reading and writing. |
| `KeyManager` | Generates, saves, and loads keys. |
| `SFCFormat` | Handles the `.sfc` format and the original file extension. |

### Security limitations

SecurSifr is a student project provided "as is", without any guarantee of security. It must not be used to protect sensitive or confidential data. Users must keep backups of their original files and store their encryption keys in a safe place. Losing a key may make encrypted files permanently unrecoverable.

The author disclaims liability for any damages or losses resulting from the use of this software, to the extent permitted by applicable law.