#include <iostream>
using namespace std;
struct  Node {
    int data;
    Node* left;
    Node* right;
};




Node* createNode(int x) {
    Node* newNode = new Node();//sabse pehle ek newnode naam ka variable banega data ke liye
    newNode->data = x;//fhir newnode ke dabbe me x daal do
    newNode->left = newNode->right = NULL;//abhi hamse new node kri h add so uske left right me null hoga 
    return newNode;//Yeh naya ghar (node) ready ho gaya, ab tree ko wapas de do.”
}




Node* insertNode(Node* root, int x) {
    if (root == NULL) return createNode(x);//agr root null h matlb kuch ni krna simpliy createnode wale function me add krdo
    if (x < root->data)//agr x chota h {child} so root ke left wale me insert hoga 
        root->left = insertNode(root->left, x);
    else if (x > root->data)
        root->right = insertNode(root->right, x);//agr bada h toh right wale me hoga
    return root;
}




Node* findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}





Node* deleteNode(Node* root, int x) {
    if (root == NULL) return root;

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else {
        if (root->left == NULL) return root->right;
        else if (root->right == NULL) return root->left;

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}





bool searchNode(Node* root, int x) {
    if (root == NULL) return false;
    if (root->data == x) return true;
    if (x < root->data) return searchNode(root->left, x);
    return searchNode(root->right, x);
}





void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    cout<<"hell";
}




void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}





void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}




int main() {
    Node* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);

    cout << "Inorder: ";
    inorder(root);
    cout << "\nPreorder: ";
    preorder(root);
    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}
