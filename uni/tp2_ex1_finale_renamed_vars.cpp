#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
struct produit
{
    string des, code, um;
    double pua_ht, qte, tva;
    produit *next;
};
produit *tete = NULL;
void ajouter()
{
    produit *new_prod = new produit;

    cout << "entrer les infos du produit : " << endl;
    cout << "code : ";
    cin >> new_prod->code;
    cout << "designation : ";
    cin >> new_prod->des;
    cout << "unite de mesure : ";
    cin >> new_prod->um;
    cout << "prix unitaire : ";
    cin >> new_prod->pua_ht;
    cout << "quantite : ";
    cin >> new_prod->qte;
    cout << "tax(tva) : ";
    cin >> new_prod->tva;

    new_prod->next = tete;
    tete = new_prod;
}
void afficher()
{
    produit *prod;
    prod = tete;
    int i = 0;

    if (tete == NULL)
    {
        cout << "liste d'achat vide !!";
    }
    else
    {

        cout << "\n************  affichage de la liste des produits achetes  **************";
        while (prod != NULL)
        {
            i++;
            cout << "\nles infos du produit " << i << " : " << endl;
            cout << "code : ";
            cout << prod->code;
            cout << "\ndesignation : ";
            cout << prod->des;
            cout << "\nunite de mesure : ";
            cout << prod->um;
            cout << "\nprix unitaire : ";
            cout << prod->pua_ht;
            cout << "\nquantite : ";
            cout << prod->qte;
            cout << "\ntax(tva) : ";
            cout << prod->tva;
            prod = prod->next;
        }
    }
}
void facture(bool payb)
{
    produit *prod;

    double somme_horstx = 0, somme_avec_tva = 0, total_tva = 0, montant_py, deffirence; // sommme
    int nbreprod = 0;
    if (tete == NULL)
    {
        cout << "liste d'achat vide !!";
    }
    else
    {

        prod = tete;

        cout << "\n************  affichage de la facture  **************\n";
        while (prod != NULL)
        {
            somme_horstx = somme_horstx + prod->pua_ht * prod->qte;
            total_tva = total_tva + (prod->pua_ht * prod->tva) * prod->qte;

            nbreprod++;
            prod = prod->next;
        }
        somme_avec_tva = somme_horstx + total_tva;
        cout << "\nnombre du produit achetes : " << nbreprod;
        cout << "\nmontant total hors taxe : " << somme_horstx << " Dzd";
        cout << "\ntotal des tva : " << total_tva << " Dzd";
        cout << "\nnet a payes : " << somme_avec_tva << " Dzd";

        if (payb)
        {
            // def du montants

            cout << "\nentrer la montant paye : ";
            cin >> montant_py;
            deffirence = montant_py - somme_avec_tva;
            if (deffirence == 0)
            {
                cout << "achat valide!";
            }
            else if (deffirence > 0)
            {
                cout << "retourne : " << (deffirence) << " Dzd au client.";
            }
            else
            {
                cout << "client doit ajouter : " << -(deffirence) << " Dzd .";
            }
        }
    }
}
void min_max(double &min, double &max)
{
    produit *prod;
    prod = tete;
    min = prod->pua_ht;
    max = prod->pua_ht;
    if (tete == NULL)
    {
        cout << "\nliste vide !";
    }
    else
    {
        while (prod != NULL)
        {
            if (prod->pua_ht >= max)
            {
                max = prod->pua_ht;
            }
            else if (min > prod->pua_ht)
            {
                min = prod->pua_ht;
            };
            prod = prod->next;
        }
        if (min == max)
        {
            cout << " \n la liste contient un seul element! prix : " << min;
        }
        else
        {
            cout << "min : " << min;
            cout << "\nmax : " << max;
        }
    }
};

void suppression()
{

    if (tete == NULL)
    {
        cout << "liste deja vide!";
        return;
    }
    else
    {
        int i = 0;
        produit *current, *prev;
        string des;
        current = tete;
        prev = tete;
        cout << "\nentrer le nom du produit a supprimer (designation) : ";
        cin >> des;
        if (strcmp(current->des.c_str(), des.c_str()) == 0) // str_cmp returns 0 when 2 the strings are equal
        {                                                   //.c_str convert a string to variable type that strcmp can take as parameter

            tete = current->next;
            delete current;
            cout << "\nproduit supprimer...";
            return;
        }
        else
        {
            current = current->next;
            while ((current != NULL) && (strcmp(current->des.c_str(), des.c_str()) != 0))
            {
                prev = current;
                current = current->next;
            };
            if (current == NULL)
            {
                cout << "\nce produit n'existe pas!";
            }
            else
            {
                prev->next = current->next;
                delete current;
                cout << "\nproduit supprimer...";
            }
        }
    }
};
void vider()
{
    produit *prod;

    if (tete == NULL)
    {
        cout << "liste deja vide!";
    }
    else
    {
        while (tete != NULL)
        {
            prod = tete;
            tete = tete->next;
            delete prod;
            cout << "operation termine liste vide...";
        }
    }
};
int main()
{
    int n, choice;
    double min, max;

    do
    {
        cout << "\n**********************     MENU     **********************";
        cout << "\n1. AJOUTER des produits ";
        cout << "\n2. AFFICHER la liste des produits achetes";
        cout << "\n3. AFFICHER la facture";
        cout << "\n4. LA DIFFERENCE entre le montant paye et le net a paye";
        cout << "\n5. SUPPRIMER des produits";
        cout << "\n6. Afficher le prix max et le prix min";
        cout << "\n7. VIDER la liste";
        cout << "\n8. ARRET du programme";
        cout << "\n9. CLEAR the screen ";
        cout << "\nentrer votre choix : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nentrer le nombre des produits a ajouter : ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                ajouter();
            }
            break;
        case 2:
            afficher();
            break;
        case 3:
            facture(false);
            break;
        case 4:
            facture(true);
            break;
        case 5:
            suppression();
            break;
        case 6:
            min_max(min, max);
            break;
        case 7:
            vider();
            break;
        case 8:
            break;
        case 9:
            system("CLS");
            break;
        default:
            cout << "\nentrer un choix valide";
            break;
        }
    } while (choice != 8);
}
