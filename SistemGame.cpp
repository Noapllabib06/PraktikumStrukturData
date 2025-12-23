#include <iostream>
#include <string>
using namespace std;

// Structure ITEM
struct Item {
    int id;
    string name;
    int power;
};

// BST Node
struct BSTNode {
    Item data;
    BSTNode* left;
    BSTNode* right;
};

// MLL Node
struct ItemNode {
    Item data;
    ItemNode* next;
};

struct NPCNode {
    string name;
    ItemNode* itemHead;
    NPCNode* next;
};

struct AreaNode {
    string name;
    NPCNode* npcHead;
    AreaNode* next;
};


//Prototype
// BST
BSTNode* insertBST(BSTNode* root, Item item);
BSTNode* searchBST(BSTNode* root, int id);
void inorderBST(BSTNode* root);

// MLL
void tambahArea(AreaNode*& head, string nama);
AreaNode* cariArea(AreaNode* head, string nama);

void tambahNPC(AreaNode* area, string namaNPC);
NPCNode* cariNPC(AreaNode* area, string namaNPC);

void tambahItem(NPCNode* npc, Item item);
void tampilDunia(AreaNode* head);

//BST 
BSTNode* insertBST(BSTNode* root, Item item) {
    if (!root) {
        BSTNode* newNode = new BSTNode;
        newNode->data = item;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (item.id < root->data.id)
        root->left = insertBST(root->left, item);
    else if (item.id > root->data.id)
        root->right = insertBST(root->right, item);

    return root;
}

BSTNode* searchBST(BSTNode* root, int id) {
    if (!root || root->data.id == id)
        return root;

    if (id < root->data.id)
        return searchBST(root->left, id);

    return searchBST(root->right, id);
}

void inorderBST(BSTNode* root) {
    if (root) {
        inorderBST(root->left);
        cout << root->data.id << " "
             << root->data.name << " "
             << root->data.power << endl;
        inorderBST(root->right);
    }
}


//MLL 
//Tambah Area
void tambahArea(AreaNode*& head, string nama) {
    AreaNode* newNode = new AreaNode;
    newNode->name = nama;
    newNode->npcHead = NULL;
    newNode->next = NULL;

    if (!head) {
        head = newNode;
    } else {
        AreaNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

//Cari Area
AreaNode* cariArea(AreaNode* head, string nama) {
    while (head) {
        if (head->name == nama)
            return head;
        head = head->next;
    }
    return NULL;
}

//Tambah NPC
void tambahNPC(AreaNode* area, string namaNPC) {
    NPCNode* newNode = new NPCNode;
    newNode->name = namaNPC;
    newNode->itemHead = NULL;
    newNode->next = NULL;

    if (!area->npcHead) {
        area->npcHead = newNode;
    } else {
        NPCNode* temp = area->npcHead;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

//Cari NPC
NPCNode* cariNPC(AreaNode* area, string namaNPC) {
    NPCNode* temp = area->npcHead;
    while (temp) {
        if (temp->name == namaNPC)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

//Tambah Item ke NPC
void tambahItem(NPCNode* npc, Item item) {
    ItemNode* newNode = new ItemNode;
    newNode->data = item;
    newNode->next = NULL;

    if (!npc->itemHead) {
        npc->itemHead = newNode;
    } else {
        ItemNode* temp = npc->itemHead;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

//Tampil Dunia Game
void tampilDunia(AreaNode* head) {
    while (head) {
        cout << "Area: " << head->name << endl;
        NPCNode* npc = head->npcHead;

        while (npc) {
            cout << "  NPC: " << npc->name << endl;
            ItemNode* item = npc->itemHead;

            while (item) {
                cout << "    Item: "
                     << item->data.name
                     << " (ID " << item->data.id
                     << ", Power " << item->data.power << ")\n";
                item = item->next;
            }
            npc = npc->next;
        }
        head = head->next;
    }
}

int main() {
    AreaNode* world = NULL;
    BSTNode* itemTree = NULL;
    int pilihan;

    do {
        cout << "\n=== MENU GAME ===\n";
        cout << "1. Tambah Area\n";
        cout << "2. Tambah NPC\n";
        cout << "3. Tambah Item\n";
        cout << "4. Tampilkan Dunia Game\n";
        cout << "5. Cari Item\n";
        cout << "6. Tampilkan Item Terurut\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string nama;
            cout << "Nama Area: ";
            cin >> nama;
            tambahArea(world, nama);
        }

        else if (pilihan == 2) {
            string areaNama, npcNama;
            cout << "Nama Area: ";
            cin >> areaNama;
            AreaNode* area = cariArea(world, areaNama);

            if (area) {
                cout << "Nama NPC: ";
                cin >> npcNama;
                tambahNPC(area, npcNama);
            } else {
                cout << "Area tidak ditemukan!\n";
            }
        }

        else if (pilihan == 3) {
            string areaNama, npcNama;
            Item item;

            cout << "Nama Area: ";
            cin >> areaNama;
            AreaNode* area = cariArea(world, areaNama);
            if (!area) {
                cout << "Area tidak ditemukan!\n";
                continue;
            }

            cout << "Nama NPC: ";
            cin >> npcNama;
            NPCNode* npc = cariNPC(area, npcNama);
            if (!npc) {
                cout << "NPC tidak ditemukan!\n";
                continue;
            }

            cout << "ID Item: ";
            cin >> item.id;

            if (searchBST(itemTree, item.id)) {
                cout << "ID Item sudah ada!\n";
                continue;
            }

            cout << "Nama Item: ";
            cin >> item.name;
            cout << "Power Item: ";
            cin >> item.power;

            tambahItem(npc, item);
            itemTree = insertBST(itemTree, item);
        }

        else if (pilihan == 4) {
            tampilDunia(world);
        }

        else if (pilihan == 5) {
            int id;
            cout << "Masukkan ID Item: ";
            cin >> id;
            BSTNode* hasil = searchBST(itemTree, id);

            if (hasil) {
                cout << "Item ditemukan: "
                     << hasil->data.name
                     << " (Power " << hasil->data.power << ")\n";
            } else {
                cout << "Item tidak ditemukan!\n";
            }
        }

        else if (pilihan == 6) {
            inorderBST(itemTree);
        }

    } while (pilihan != 0);

    return 0;
}