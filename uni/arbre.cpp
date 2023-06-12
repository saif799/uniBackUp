#include <iostream>
#include <stack>
using namespace std;
struct tree
{
    int data;
    tree *left;
    tree *right;
};
class node
{
    node *top = nullptr;
    node *next;
    int v;
    string f;
    int size = 0;
    node *last = nullptr;

public:
    void push(int x)
    {
        node *n = new node();
        n->v = x;
        if (top == nullptr)
        {
            n->next = nullptr;
            top = n;
            last = n;
        }
        else
        {
            last->next = n;
            last = n;
        }
        size++;
    }
    bool empty()
    {
        bool x;
        if (top == nullptr)
            x = true;
        else
            x = false;
        return x;
    }
    int topp()
    {
        return top->v;
    }
    void pop()
    {

        if (top == nullptr)
        {
            cout << "stack is empty ." << endl;
        }
        else
        {
            node *ppop = top;
            top = top->next;
            delete ppop;
            size--;
        }
    }
    int length()
    {
        return size;
    }
};
// binary search tree
tree *creatNode(int x)
{
    tree *newnode = new tree();
    newnode->data = x;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}
tree *insert(tree *root, int x)
{
    if (root == NULL)
        root = creatNode(x);
    else if (x <= root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}
bool search(tree *root, int data)
{
    if (root == NULL)
        return false;
    else if (data == root->data)
        return true;
    else if (data <= root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}
tree *search2(tree *root, int data)
{
    if (root != NULL)
    {
        if (data == root->data)
            return root;
        else if (data <= root->data)
            return search2(root->left, data);
        else
            return search2(root->right, data);
    }
}
tree *findmin(tree *rppt)
{
    return rppt;
}
tree *Delete(tree *root, int x)
{
    // this is just so you reach the node you want to delete
    if (root == NULL)
        return root;
    else if (x < root->data)
        root->left = Delete(root->left, x);
    else if (x > root->data)
        root->right = Delete(root->right, x);
    else
    { // you reached the node you want to  delete "x==root.data"we are going to delete it now
        if (root->left == NULL && root->right == NULL)
        {
            // case 1 : no child
            delete root;
            root = NULL;
        }
        // case 2 : only one child
        else if (root->left == NULL)
        {
            tree *d = root;
            root = root->right;
            delete d;
        }
        else if (root->right == NULL)
        {
            tree *d = root;
            root = root->left;
            delete d;
        }
        // case three 3 : have two children
        else
        {
            tree *temp = findmin(root);
            root->data = temp->data;
            root->right = Delete(root->right, root->data);
        }
    }
    return root;
}
// exo2
int racine() // return le racine example 1
{
    int tab[3][10] = {{23, 2, 3, 5, 7, 11, 13, 37, 41, 19},
                      {-1, 4, 3, -1, -1, 9, -1, 8, 6, -1},
                      {-1, 5, 0, -1, -1, -1, 2, 1, -1, -1}},
        m, indicator = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == tab[1][j] || i == tab[2][j])
            {
                indicator++;
                j = 10;
            }
        }
        if (indicator == 0)
        {
            m = i;
            i = 10;
        }
        else
        {
            indicator = 0;
        }
    }
    return tab[0][m];
}
void racinee() // example two
{
    int tab[3][10] = {{23, 2, 3, 5, 7, 11, 13, 37, 41, 19},
                      {-1, 4, 3, -1, -1, 9, -1, 8, 6, -1},
                      {-1, 5, 0, -1, -1, -1, 2, 1, -1, -1}};
    bool t[10];
    for (int i = 0; i < 10; i++)
    {
        t[i] = true;
    }
    for (int j = 0; j < 10; j++)
    {
        if (tab[1][j] != -1)
        {
            t[tab[1][j]] = false;
        }
        if (tab[2][j] != -1)
        {
            t[tab[2][j]] = false;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (t[i])
        {
            cout << tab[0][i];
        }
    }
}
// exo3
void feuiles() // give you les feuilles de larbre
{
    int tab[3][10] = {{23, 2, 3, 5, 7, 11, 13, 37, 41, 19},
                      {-1, 4, 3, -1, -1, 9, -1, 8, 6, -1},
                      {-1, 5, 0, -1, -1, -1, 2, 1, -1, -1}};
    for (int i = 0; i < 10; i++)
    {
        if (tab[1][i] == -1 && tab[2][i] == -1)
        {
            cout << tab[0][i] << " ";
        }
    }
}
void Read(tree *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        Read(root->left);
        Read(root->right);
    }
}
int n_noeuds(tree *racine)
{
    if (racine == NULL)
        return 0;
    else
        return 1 + n_noeuds(racine->left) + n_noeuds(racine->right);
}
int somme(tree *racine)
{
    if (racine == NULL)
        return 0;
    else
        return racine->data + somme(racine->left) + somme(racine->right);
}
int n_feuille(tree *racine)
{

    if (racine->left == NULL && racine->right == NULL)
        return 1;
    else
        return n_feuille(racine->right) + n_feuille(racine->left);
}
bool s_feuille(tree *racine)
{
    if (racine != NULL)
        if (racine->left == NULL && racine->right == NULL)
            return true;
        else
            return false;
}
int hauteur(tree *racine)
{
    int hg, hd;
    if (racine == nullptr)
    {
        hd = 0;
        hg = 0;
    }
    else
    {
        hd = hauteur(racine->right) + 1;
        hg = hauteur(racine->left) + 1;
    }
    if (hd > hg)
        return hd;
    else
        return hg;
}
bool balanced(tree *racine)
{
    int hd, hg;
    if (racine == nullptr)
        return true;
    else
    {
        hd = hauteur(racine->right);
        hg = hauteur(racine->left);

        if (abs(hg - hd) <= 1)
        {
            balanced(racine->left);
            balanced(racine->right);
            if (balanced(racine->left) &&
                balanced(racine->right))
            {
                return true;
            }
        }
        else
            return false;
    }
}
void bradth(tree *root)
{
    node *s = new node();
    s->push(root->data);
    tree *p = search2(root, root->data);
    while (!s->empty())
    {
        cout << s->topp() << " ";
        if (p->left != NULL)
            s->push(p->left->data);
        if (p->right != NULL)
            s->push(p->right->data);
        s->pop();
        p = search2(root, s->topp());
    }
}
// exo 4
void parantizi(tree *racine)
{
    if (racine != nullptr)
    {
        if (!s_feuille(racine))
        {
            cout << "{ ";
            parantizi(racine->left);
            cout << racine->data << " ";
            parantizi(racine->right);
            cout << "} ";
        }
        else
            cout << racine->data << " ";
    }
}
// exo 5
void infixi(tree *root)
{
    if (root != nullptr)
    {
        infixi(root->left);
        cout << root->data << " ";
        infixi(root->right);
    }
    else
        cout << "arbre est null";
}
void postfixi(tree *root)
{
    if (root != nullptr)
    {
        postfixi(root->left);
        postfixi(root->right);
        cout << root->data << " ";
    }
}
// prefixi whithout using recursive same result as the Read function
void prefixiboucle(tree *p)
{
    stack<int> d;
    int n = 2 * n_feuille(p);
    tree *h;
    d.push(p->data);
    for (int i = 0; i < n; i++)
    {
        if (!d.empty())
        {
            cout << d.top() << " ";
            h = search2(p, d.top());
            d.pop();
            if (h->right)
                d.push(h->right->data);
            if (h->left)
                d.push(h->left->data);
        }
        else
            i = n + 1;
    }
}
int main()
{
    tree *root = NULL;
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 17);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 5);
    cout << n_feuille(root);
    // cout << " this is your tree" << endl;
    // prefixiboucle(root);
    // //check line 363
    // // Read(root);
    // //    exo related stuff
    // cout.setf(std::ios_base::boolalpha);
    // cout << endl
    //      << racine() << " est la racine ." << endl;
    // cout << "les feuilles sont : ";
    // feuiles();
    // cout << " nombre de nodes : " << n_noeuds(root) << endl;
    // cout << "la somme : " << somme(root) << endl;
    // cout << "nombre de feuille : " << n_feuille(root) << endl;
    // cout << "hauteur : " << hauteur(root) << endl;
    // cout << "larbre parentise : ";
    // parantizi(root);
    // cout << endl
    //      << " balanced : " << balanced(root) << endl;
    // cout << "ordre infixi : ";
    // infixi(root);
    // cout << endl
    //      << "ordre postfixi: ";
    // postfixi(root);
    // root = Delete(root, 1);
    // cout << endl
    //      << "par niveau : ";
    // bradth(root);
}
