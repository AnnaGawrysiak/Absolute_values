#include <iostream>

using namespace std;

int najmniejsza(int arr[], int const dimension);

int main()
{
    int const rozmiar = 5;

    int arr[rozmiar] = {3, 1, 2, 4, 3};

    cout << "Minimalna roznica, jaka mozna uzyskac: " << najmniejsza(arr, rozmiar) << endl;

    return 0;
}

int najmniejsza(int arr[], int const dimension)
{
    int tab[dimension];
    int tab2[dimension];

    int pierwsza_czesc = 0;
    int pozostala_czesc = 0;

    int j = 5;

    for (int i = 0; i < dimension; i++)
    {
        pierwsza_czesc = pierwsza_czesc + arr[i];
        tab[i] = pierwsza_czesc;
    }


    int m = 0;

    for (int j = 1; j < dimension; j++)
       {

           for (int k = j; k < dimension; k++)
           {
                pozostala_czesc = pozostala_czesc + arr[k];
           }

         tab2[m] = pozostala_czesc;
         m++;
         pozostala_czesc = 0;
       }

    int wartosci_bezwzgledne[dimension];


    for (int p = 0; p < dimension; p++)
    {
        if (tab[p] - tab2[p] > 0)
            wartosci_bezwzgledne[p] = tab[p] - tab2[p];

        else
            wartosci_bezwzgledne[p] = tab2[p] - tab[p];
    }

    for (int i = 0; i < dimension; i++)
    {
       cout << "wartosci bezwzgledne: " << wartosci_bezwzgledne[i] << endl;
    }

    int najmniejsza_wartosc = wartosci_bezwzgledne[0];

    for (int l = 0; l < dimension; l++)
    {
        if (wartosci_bezwzgledne[l] > wartosci_bezwzgledne[l+1])
            najmniejsza_wartosc = wartosci_bezwzgledne[l+1];
    }

    return najmniejsza_wartosc;
}
