struct BST {
    int data;
    BST *left, *right;

    // Constructor to initialize the node
    BST(int data = 0) {
        this->data = data;
        left = right = nullptr;
    }

    // Function to insert a new node with the given value
    BST* Insert(BST* root, int val) {
        // If the tree is empty, create a new node and return it
        if (!root) return new BST(val);

        // Otherwise, recur down the tree
        if (val > root->data)
            root->right = Insert(root->right, val);
        else
            root->left = Insert(root->left, val);

        // Return the (unchanged) node pointer
        return root;
    }

    // Function to perform inorder traversal (left-root-right)
    void Inorder(BST* root) {
        if (!root) return;
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }

    // Function to perform preorder traversal (root-left-right)
    void Preorder(BST* root) {
        if (!root) return;
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }

    // Function to perform postorder traversal (left-right-root)
    void Postorder(BST* root) {
        if (!root) return;
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }

    // Function to perform level order traversal
    void Level_Order(BST* root) {
        if (!root) return;

        queue<BST*> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            BST* curr = bfs.front();
            bfs.pop();

            cout << curr->data << " ";

            if (curr->left)
                bfs.push(curr->left);
            if (curr->right)
                bfs.push(curr->right);
        }
    }

    // Function to search for a node with the given value
    bool Search(BST* root, int val) {
        if (!root) return false;
        if (root->data == val) return true;
        if (val > root->data) return Search(root->right, val);
        return Search(root->left, val);
    }

    // Function to find the node with the minimum value in the BST
    BST* minValueNode(BST* node) {
        BST* current = node;

        // Loop to find the leftmost leaf
        while (current && current->left != nullptr) 
            current = current->left;

        return current;
    }

    // Function to find the node with the maximum value in the BST
    BST* maxValueNode(BST* node) {
        BST* current = node;

        // Loop to find the rightmost leaf
        while (current && current->right != nullptr) 
            current = current->right;

        return current;
    }

    // Function to calculate the height of the BST
    int height(BST* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    // Function to delete a node with the given key
    BST* Delete_Node(BST* root, int key) {
        if (!root) return root;

        // Recur down the tree
        if (key < root->data)
            root->left = Delete_Node(root->left, key);
        else if (key > root->data)
            root->right = Delete_Node(root->right, key);
        else {
            // Node with only one child or no child
            if (!root->left) {
                BST* temp = root->right;
                free(root);
                return temp;
            }
            else if (!root->right) {
                BST* temp = root->left;
                free(root);
                return temp;
            }

            // Node with two children: get the inorder successor (smallest in the right subtree)
            BST* temp = minValueNode(root->right);

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = Delete_Node(root->right, temp->data);
        }
        return root;
    }
};