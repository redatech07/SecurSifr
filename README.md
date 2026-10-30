# SecurSifr 🔐

## 🇫🇷 Français

### Présentation

SecurSifr permet de chiffrer des fichiers à l'aide d'une clé générée automatiquement, puis de les déchiffrer pour retrouver leur contenu d'origine.

Le projet est organisé autour de dossiers spécifiques situés à la racine :
- `build/` : Dossier dédié à l'exécutable du programme.
- `file_to_encrypt/` : Dossier dédié contenant les fichiers d'origine que vous souhaitez chiffrer.
- `encrypted_file/` : Dossier dédié où seront directement stockés les fichiers chiffrés.
- `keys/` : Dossier contenant les clés de chiffrement générées.

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

Depuis le répertoire du projet, exécutez la commande suivante pour générer l'exécutable dans le dossier `build/` :

```bash
g++ src/*.cpp -I ./include -o build/SecurSifr
```

### Utilisation

Le programme se lance depuis le terminal et reçoit les informations nécessaires sous forme d'arguments. 

* **Chiffrement :** Les fichiers à chiffrer doivent obligatoirement se trouver dans le dossier `file_to_encrypt/`.
* **Stockage :** Le fichier chiffré généré sera automatiquement enregistré dans le dossier `encrypted_file/`.

#### Options disponibles

| Option | Description |
|---|---|
| `-m`, `--mode` | Définit le mode de fonctionnement. |
| `-f`, `--fichier`, `--file` | Indique le nom du fichier à traiter. |
| `-k`, `-c`, `--cle`, `--key` | Définit le nom de la clé. |

Modes disponibles :

- `chiffrer` ou `encrypt` : chiffre un fichier.
- `dechiffrer` ou `decrypt` : déchiffre un fichier.

Le mode et le fichier sont obligatoires. Le nom de la clé est facultatif pour le chiffrement, mais obligatoire pour le déchiffrement.

### Chiffrer un fichier

Pour chiffrer un fichier présent dans le dossier `file_to_encrypt/`, utiliser :

```bash
./build/SecurSifr --mode chiffrer --fichier document.txt
```

Il est également possible d'utiliser les options courtes :

```bash
./build/SecurSifr -m chiffrer -f document.txt
```

Par défaut, le programme déduit le nom de la clé du nom du fichier.

Pour choisir un nom de clé personnalisé :

```bash
./build/SecurSifr -m chiffrer -f document.txt -k ma_cle
```

Le programme :

1. Lit le contenu du fichier situé dans `file_to_encrypt/`.
2. Génère une clé de la même taille que le contenu.
3. Sauvegarde la clé dans le dossier `keys/`.
4. Chiffre le contenu à l'aide de la clé.
5. Enregistre le résultat directement dans le dossier `encrypted_file/` au format `.sfc`.
6. Stocke l'extension d'origine dans le fichier chiffré.

Exemple de fichiers générés :

```text
build/
└── SecurSifr
file_to_encrypt/
└── document.txt
encrypted_file/
└── document.sfc
keys/
└── document.key
```

### Déchiffrer un fichier

Pour déchiffrer un fichier présent dans le dossier `encrypted_file/`, indiquer le nom du fichier chiffré ainsi que le nom de la clé correspondante :

```bash
./build/SecurSifr --mode dechiffrer --fichier document.sfc --cle document
```

Avec les options courtes :

```bash
./build/SecurSifr -m dechiffrer -f document.sfc -k document
```

Le programme :

1. Ouvre le fichier `.sfc` présent dans `encrypted_file/`.
2. Récupère l'extension d'origine.
3. Lit le contenu chiffré.
4. Charge la clé correspondante depuis le dossier `keys/`.
5. Déchiffre le contenu.
6. Recrée le fichier et l'enregistre directement dans le dossier `file_to_encrypt/` au format d'origine.

### Gestion des clés

Les clés sont enregistrées dans des fichiers `.key` à l'intérieur du dossier `keys/`. Le nom fourni dans les arguments correspond au nom du fichier de clé, sans l'extension `.key`.

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

SecurSifr est un projet étudiant fourni « en l'état », sans garantie de sécurité. Il ne doit pas être utilisé pour protéger des données sensibles ou confidentielles. 

L'utilisateur doit conserver une copie de ses fichiers originaux et sauvegarder ses clés de chiffrement dans un endroit sûr. La perte d'une clé peut rendre les fichiers chiffrés irrécupérables.

Avant de déchiffrer un fichier, vérifiez qu'aucun fichier portant le même nom n'existe déjà dans `file_to_encrypt/`. Si c'est le cas, déplacez ou renommez le fichier existant pour éviter qu'il soit remplacé.

L'auteur décline toute responsabilité concernant les dommages ou pertes résultant de l'utilisation du logiciel, dans les limites prévues par la loi applicable.


---

## 🇬🇧 English

### Overview

SecurSifr is a C++ command-line application for encrypting and decrypting files using automatically generated keys.

The project is organized with specific folders at the root level:
- `build/`: Dedicated directory for the program executable.
- `file_to_encrypt/`: Dedicated folder containing the original files you want to encrypt.
- `encrypted_file/`: Dedicated folder where encrypted files will be directly stored.
- `keys/`: Folder containing the generated encryption keys.

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

From the project directory, run the following command to compile the program into the `build/` folder:

```bash
g++ src/*.cpp -I ./include -o build/SecurSifr
```

### Usage

The program runs from the terminal and accepts command-line arguments.

* **Encryption:** Files to encrypt must be placed inside the `file_to_encrypt/` folder.
* **Storage:** The resulting encrypted file will be automatically stored inside the `encrypted_file/` folder.

#### Available options

| Option | Description |
|---|---|
| `-m`, `--mode` | Sets the operating mode. |
| `-f`, `--fichier`, `--file` | Specifies the filename to process. |
| `-k`, `-c`, `--cle`, `--key` | Specifies the key name. |

Available modes:

- `chiffrer` or `encrypt`: encrypts a file.
- `dechiffrer` or `decrypt`: decrypts a file.

The mode and file arguments are required. The key name is optional for encryption but mandatory for decryption.

### Encrypt a file

To encrypt a file located inside the `file_to_encrypt/` folder, run:

```bash
./build/SecurSifr --mode encrypt --file document.txt
```

You can also use the short options:

```bash
./build/SecurSifr -m encrypt -f document.txt
```

By default, the program derives the key name from the input filename.

To specify a custom key name:

```bash
./build/SecurSifr -m encrypt -f document.txt -k my_key
```

The program:

1. Reads the file contents from `file_to_encrypt/`.
2. Generates a key matching the content size.
3. Saves the key in the `keys/` folder.
4. Encrypts the contents using the key.
5. Saves the result directly inside the `encrypted_file/` folder with the `.sfc` extension.
6. Stores the original file extension in the encrypted file.

Example of generated files and structure:

```text
build/
└── SecurSifr
file_to_encrypt/
└── document.txt
encrypted_file/
└── document.sfc
keys/
└── document.key
```

### Decrypt a file

To decrypt an `.sfc` file located inside the `encrypted_file/` folder, provide the encrypted filename and the corresponding key name:

```bash
./build/SecurSifr --mode decrypt --file document.sfc --key document
```

Using short options:

```bash
./build/SecurSifr -m decrypt -f document.sfc -k document
```

The program:

1. Opens the `.sfc` file inside `encrypted_file/`.
2. Retrieves the original file extension.
3. Reads the encrypted contents.
4. Loads the corresponding key from the `keys/` folder.
5. Decrypts the contents.
6. Restores the original file and saves it directly in the `file_to_encrypt/` directory, preserving its original filename and extension.

### Key management

Keys are stored in `.key` files inside the `keys/` folder. The name provided in the command-line arguments corresponds to the key filename without the `.key` extension.

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

SecurSifr is a student project provided "as is", without any guarantee of security. It must not be used to protect sensitive or confidential data. 

Users must keep backups of their original files and store their encryption keys in a safe place. Losing a key may make encrypted files permanently unrecoverable.

Before decrypting a file, make sure that no file with the same name already exists in `file_to_encrypt/`. If one does, move or rename the existing file to prevent it from being overwritten.

The author disclaims liability for any damages or losses resulting from the use of this software, to the extent permitted by applicable law.
