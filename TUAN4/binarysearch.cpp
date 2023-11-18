/* Node* insert (Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    } else {
        Node* current;
        if (data <= root->data) {
            current = insert(root->left, data);
            root->left = current;
        } else {
            current = insert(root->right, data);
            root->right = current;
        }
        return root;
    }

    */