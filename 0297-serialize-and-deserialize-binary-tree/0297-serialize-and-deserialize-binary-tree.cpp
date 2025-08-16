// Class to handle serialization & deserialization
class Codec {
public:
    // -------------------- SERIALIZATION --------------------
    // Function to serialize (convert tree -> string)
    string serialize(TreeNode* root) {
        // If node is NULL, represent it by "#" (marker for null) 
        if (!root) return "#";

        // Convert current node's value to string,
        // then recursively serialize left and right children.
        // Separate values by commas for easy splitting later.
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // -------------------- DESERIALIZATION --------------------
    // Helper function to rebuild the tree from queue of strings
    TreeNode* build(queue<string> &q) {
        // Take the front element from the queue
        string val = q.front(); 
        q.pop();   // Remove it since we are processing it

        // If the value is "#", that means it's a NULL child
        if (val == "#") return NULL;

        // Otherwise, create a new node with this integer value
        TreeNode* node = new TreeNode(stoi(val));

        // Recursively build the left subtree
        node->left = build(q);

        // Recursively build the right subtree
        node->right = build(q);

        // Return the constructed node
        return node;
    }

    // Main deserialization function: (string -> tree)
    TreeNode* deserialize(string data) {
        stringstream ss(data);  // Use stringstream to split by commas
        string item;
        queue<string> q;        // Queue will store tokens in order

        // Split the string by "," and push into queue
        while (getline(ss, item, ',')) {
            q.push(item);
        }

        // Use helper to build the tree from queue
        return build(q);
    }
};
