#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
void jl();
void nuevemayo();
void nuevemayo2();
void jl2();
void ahorcado();

using namespace std;

int main()
{
    int eleccion;
    do
    {
        cout << "Tiene dos opciones" << endl << "1- Guess the word incompleto" << endl << "2- Guess the word corregido" << endl;
        cin >> eleccion;
        switch (eleccion) // switch para casos dependiendo de la opcion elegida
        {
        case 1:
            cout << "Lo que hice en la clase del guess the word (incompleto)" << endl << endl;
            jl();
            break;
        case 2:
            cout << "El que me dijo que si podia corregir lo hiciera" << endl << endl;
            jl2();
            break;
        default:
            cout << "Opcion elegida no valida, seleccione otra opcion" << endl;
            break;
        }
    } while (eleccion > 0 || eleccion < 2);
}

void jl()
{
    vector <string> palabra;
    palabra.push_back("perro");
    palabra.push_back("gato");
    palabra.push_back("pescado");

    string respuesta;
    int vidas = 5;
    random_shuffle(palabra.begin(), palabra.end());
    cout << "Se le va a mostrar una palabra con las letras desordenadas, tiene cinco vidas." << endl;
    cout << "Introduzca la respuesta" << endl;
    cin >> respuesta;
    if (respuesta == "perro" || respuesta == "gato" || respuesta == "pescado")
    {
        cout << "Respuesta correcta" << endl << "Vidas: " << vidas << endl << endl;
    }
    else
    {
        cout << "Respuesta incorrecta" << endl << "Vidas: " << vidas - 1 << endl << endl;
    }
}
void nuevemayo()
{
    vector <string> inventory;
    inventory.push_back("Espada");
    inventory.push_back("Escudo");
    inventory.push_back("Martillo");
    inventory.push_back("Rifle");

    vector <string>::iterator myIterator; // Cambiar datos del vector solo iterator
    vector <string>::const_iterator iter; // Iterador solo para ver datos

    cout << "Tus items: " << endl;
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }

    // Intercambio
    cout << "Intercambiaste tu " << inventory[2] << " por un arco" << endl;
    myIterator = inventory.begin() + 2;
    *myIterator = "Arco";
    cout << "Tus items: " << endl;
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }

    // Size
    cout << "El nombre del item " << *myIterator << " tiene " << (myIterator)->size() << " letras" << endl;

    //Insert
    cout << "Recuperaste la bomba robada " << endl;
    inventory.insert(inventory.begin() + 2, "Bomba");
    cout << "Tus items: " << endl;
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }

    //Delete
    cout << "Tu " << inventory[1] << " fue destruido en batalla" << endl;
    inventory.erase(inventory.begin() + 1);
    cout << "Tus items: " << endl;
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;
    }
}
void nuevemayo2()
{
    const int MAX_ATTEMPTS = 3;
    int attempts = 0;

    vector<string> words;
    words.push_back("COMPUTADORA");
    words.push_back("JUEGO");
    words.push_back("CODIGO");
    words.push_back("REFRIGERADOR");

    srand(time(NULL));
    int randomNumber = rand();
    int wordsRandomIndex = (randomNumber % words.size());
    string wordSelected = words[wordsRandomIndex];

    //cout << wordSelected << endl;

    random_shuffle(wordSelected.begin(), wordSelected.end());
    cout << wordSelected << endl;

    string correctWord;

    do
    {
        cin >> correctWord;
        transform(correctWord.begin(), correctWord.end(), correctWord.begin(), ::toupper);
        //cout << correctWord << endl;

        if (correctWord == words[wordsRandomIndex])
        {
            attempts++;
            cout << "\nAdivinaste la palabra!!!\n";
            break;
        }
        else
        {
            attempts++;
            cout << "Fallaste humano inepto, te quedan " << MAX_ATTEMPTS - attempts << endl;
        }

    } while (attempts != MAX_ATTEMPTS);

    if (attempts == MAX_ATTEMPTS)
    {
        cout << "\nPerdiste, date de baja, la palabra era:  \n";
        cout << words[wordsRandomIndex];
    }
    else
    {
        cout << "\nMUY BIEN!! lo hiciste en: " << attempts << " intentos.";
    }
}
void jl2()
{
    vector <string> palabra;
    palabra.push_back("perro");
    palabra.push_back("gato");
    palabra.push_back("pescado");
    palabra.push_back("loro");
    palabra.push_back("caballo");

    srand(time(NULL));
    int randomNumber = rand();
    int palabraRandomIndex = (randomNumber % palabra.size());
    string palabraseleccionada = palabra[palabraRandomIndex];

    string respuesta;
    int vidas = 5;
    int fallos = 0;
    random_shuffle(palabraseleccionada.begin(), palabraseleccionada.end());
    cout << "Se le va a mostrar una palabra con las letras desordenadas, tiene cinco vidas." << endl;
    cout << palabraseleccionada << endl;
    do
    {
        cout << "Introduzca la respuesta" << endl;
        cin >> respuesta;
        fallos++;
        if (respuesta == palabra[palabraRandomIndex])
        {
            cout << "Respuesta correcta, ganaste" << endl << "Vidas: " << vidas - fallos << endl;
            exit(EXIT_SUCCESS);
        }
        else
        {
            cout << "Respuesta incorrecta" << endl << "Vidas: " << vidas - fallos << endl;
        }
    } while (fallos != vidas);
}
void ahorcado() 
{
    int vidas = 6;

    vector <string> words;
    words.push_back("REPTIL");
    words.push_back("BALLENA");
    words.push_back("IGLESIA");
    words.push_back("MAGIA");
    words.push_back("CIUDAD");

    srand(time(NULL));
    int randomNumber = rand();
    int wordsRandomIndex = (randomNumber % words.size());
    string wordSelected = words[wordsRandomIndex];
    const string Word = wordSelected;

    string letrasfallidas;
    char letra;
    string soFar(Word.size(), '_');
    cout << Word << endl;
    cout << "Bienvenido al ahorcado." << endl;
    cout << soFar << endl;
    cout << "Tienes que ingresar una letra para ir descubriendo la palabra." << endl;
    do
    {
        cout << "Ingresa una letra." << endl;
        cin >> letra;
        letra = toupper(letra);
        if (letra == '0' || letra == '1' || letra == '2' || letra == '3' || letra == '4' || letra == '5' || letra == '6' || letra == '7' || letra == '8' || letra == '9')
        {
            cout << "No se puede ingresar un numero, ingrese una letra" << endl;
        }
        else
        {
            if (Word.find(letra) != string::npos)
            {
                for (int i = 0; i < Word.length(); i++)
                {
                    if (Word[i] == letra)
                    {
                        soFar[i] = letra;
                    }
                }
                vidas = vidas;
                cout << soFar << endl;
            }
            else if (letrasfallidas.find(letra) == string::npos)
            {
                vidas = vidas - 1;
                letrasfallidas.push_back(letra);
                letra = ' ';
                cout << endl;
                cout << endl;
            }
            switch (vidas)
            {
            case 0:
                cout << " +---+" << endl;
                cout << " |   |" << endl;
                cout << " o   |" << endl;
                cout << "|||  |" << endl;
                cout << " |   |" << endl;
                cout << "| |  |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "======" << endl;
                cout << endl;
                cout << "Estas ahorcado. Has perdido." << endl;
                cout << "Vidas restantes: " << vidas << endl;
                break;
            case 1:
                cout << " +---+" << endl;
                cout << " |   |" << endl;
                cout << " o   |" << endl;
                cout << "|||  |" << endl;
                cout << " |   |" << endl;
                cout << "|    |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "======" << endl;
                cout << endl;
                cout << "Vidas restantes: " << vidas << endl;
                if (soFar == Word)
                {
                    cout << "Felicidades!!! Has ganado el juego!!!" << endl;
                }
                break;
                break;
            case 2:
                cout << " +---+" << endl;
                cout << " |   |" << endl;
                cout << " o   |" << endl;
                cout << "|||  |" << endl;
                cout << " |   |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "======" << endl;
                cout << endl;
                cout << "Vidas restantes: " << vidas << endl;
                if (soFar == Word)
                {
                    cout << "Felicidades!!! Has ganado el juego!!!" << endl;
                }
                break;
            case 3:
                cout << " +---+" << endl;
                cout << " |   |" << endl;
                cout << " o   |" << endl;
                cout << "||   |" << endl;
                cout << " |   |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "======" << endl;
                cout << endl;
                cout << "Vidas restantes: " << vidas << endl;
                if (soFar == Word)
                {
                    cout << "Felicidades!!! Has ganado el juego!!!" << endl;
                }
                break;
            case 4:
                cout << " +---+" << endl;
                cout << " |   |" << endl;
                cout << " o   |" << endl;
                cout << " |   |" << endl;
                cout << " |   |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "======" << endl;
                cout << endl;
                cout << "Vidas restantes: " << vidas << endl;
                if (soFar == Word)
                {
                    cout << "Felicidades!!! Has ganado el juego!!!" << endl;
                }
                break;
            case 5:
                cout << " +---+" << endl;
                cout << " |   |" << endl;
                cout << " o   |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "======" << endl;
                cout << endl;
                cout << "Vidas restantes: " << vidas << endl;
                if (soFar == Word)
                {
                    cout << "Felicidades!!! Has ganado el juego!!!" << endl;
                }
                break;
            case 6:
                cout << " +---+" << endl;
                cout << " |   |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "     |" << endl;
                cout << "======" << endl;
                cout << endl;
                cout << "Vidas restantes: " << vidas << endl;
                if (soFar == Word)
                {
                    cout << "Felicidades!!! Has ganado el juego!!!" << endl;
                }
                break;
            }
        }
    } while (vidas > 0 && soFar != Word);
}