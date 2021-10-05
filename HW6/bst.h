class Node {
	public:
    int key;			
    Node* left;	
    Node* right;
    Node(int data) {
		key = data; 
		left = NULL; 
		right = NULL; 
	}
};

class BST {
    public:
        BST();
		~BST();
		/* insertion */
        void insert(int data);
        Node* insert(Node* node, int data);
		/* search */
        Node* search(int key);
        Node* search(Node* node, int key);
		/* delection */
        void remove(int key);
        Node* remove(Node* node, int key);
        Node* leftmostNode(Node* node);
		/* in-order traversal */
		void inorder();
        void inorder(Node* node);
	private:
		Node* root;
};

