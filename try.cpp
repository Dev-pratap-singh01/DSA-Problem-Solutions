#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>

// Removed: <chrono>, <ctime>, <iomanip>, <sstream> as they were only for debug timestamps

using namespace std;

class TreeNode {
public:
    string name;
    TreeNode* parent;
    vector<TreeNode*> children;
    int locked_by;
    int locked_descendant_count;

    TreeNode(string name_) {
        name = name_;
        parent = nullptr;
        locked_by = -1; // -1 means unlocked
        locked_descendant_count = 0;
    }
    // Destructor to prevent memory leaks in a real application
    ~TreeNode() {
        for (TreeNode* child : children) {
            delete child;
        }
    }
};

class TreeLocking {
public:
    TreeNode* root;
    unordered_map<string, TreeNode*> nodes; // Maps node name to TreeNode pointer
    unordered_map<string, int> globally_locked_nodes; // node_name → uid of the locker

    TreeLocking(TreeNode* root_) {
        root = root_;
        nodes[root->name] = root;
    }

    // Destructor for TreeLocking to clean up all dynamically allocated TreeNodes
    ~TreeLocking() {
        if (root) {
            delete root;
            root = nullptr;
            nodes.clear();
        }
    }

    bool lock(const string& node_name, int uid) {
        TreeNode* node = nullptr;
        auto it = nodes.find(node_name);
        if (it == nodes.end()) {
            return false; // Node not found
        }
        node = it->second;

        // Rule 1: Node must not be locked by anyone else
        if (node->locked_by != -1) {
            return false;
        }

        // Rule 2: Node must not have any locked descendants
        if (node->locked_descendant_count > 0) {
            return false;
        }

        // Rule 3: No ancestor should be locked
        TreeNode* current = node->parent;
        while (current) {
            if (current->locked_by != -1) {
                return false;
            }
            current = current->parent;
        }

        // All conditions met, proceed to lock
        node->locked_by = uid;
        globally_locked_nodes[node_name] = uid;

        // Increment locked_descendant_count for all ancestors
        current = node->parent;
        while (current) {
            current->locked_descendant_count++;
            current = current->parent;
        }

        return true;
    }

    bool unlock(const string& node_name, int uid) {
        TreeNode* node = nullptr;
        auto it = nodes.find(node_name);
        if (it == nodes.end()) {
            return false; // Node not found
        }
        node = it->second;

        // Node must be locked and by the same UID
        if (node->locked_by != uid) {
            return false;
        }

        // Unlock the node
        node->locked_by = -1;
        globally_locked_nodes.erase(node_name);

        // Decrement locked_descendant_count for all ancestors
        TreeNode* current = node->parent;
        while (current) {
            current->locked_descendant_count--;
            current = current->parent;
        }
        return true;
    }

    // Helper function to check if descendant is actually a descendant of ancestor
    bool isDescendant(TreeNode* ancestor, TreeNode* descendant) {
        if (ancestor == nullptr || descendant == nullptr) return false;
        if (ancestor == descendant) return false; // A node is not its own descendant for this check's purpose

        TreeNode* curr = descendant;
        while (curr) {
            if (curr == ancestor) return true;
            curr = curr->parent;
        }
        return false;
    }

    bool upgrade(const string& node_name, int uid) {
        TreeNode* node = nullptr;
        auto it_node = nodes.find(node_name);
        if (it_node == nodes.end()) {
            return false; // Node not found
        }
        node = it_node->second;

        // Rule 1: Node must not be locked itself
        if (node->locked_by != -1) {
            return false;
        }

        // Rule 2: No ancestor should be locked
        TreeNode* current = node->parent;
        while (current) {
            if (current->locked_by != -1) {
                return false;
            }
            current = current->parent;
        }

        vector<string> locked_descendants_by_uid; // Stores names of descendants locked by 'uid'
        bool found_any_descendant_locked = false; // To check if any descendant is locked at all

        // Iterate through all globally locked nodes to find relevant descendants
        for (auto const& pair_entry : globally_locked_nodes) {
            string locked_name = pair_entry.first;
            int locked_uid = pair_entry.second;

            TreeNode* descendant = nullptr;
            auto it_desc = nodes.find(locked_name);
            if (it_desc == nodes.end()) {
                continue; // Skip if for some reason a globally locked node isn't in the main node map
            }
            descendant = it_desc->second;

            if (isDescendant(node, descendant)) { // If 'locked_name' is a descendant of 'node'
                found_any_descendant_locked = true; // Mark that we found at least one locked descendant

                // Rule 3: All locked descendants must be locked by the same 'uid' attempting the upgrade
                if (locked_uid != uid) {
                    return false; // Found a descendant locked by a different UID, upgrade fails
                }
                locked_descendants_by_uid.push_back(locked_name); // Add to list if UID matches
            }
        }

        // Rule 4: There must be at least one descendant locked (by the given UID)
        if (locked_descendants_by_uid.empty()) {
            return false;
        }

        // If all conditions met, unlock the relevant descendants
        for (const string& name : locked_descendants_by_uid) {
            unlock(name, uid); // Unlock with the same UID used for upgrade
        }

        // Finally, lock the current node
        return lock(node_name, uid);
    }
};

int main() {
    ios_base::sync_with_stdio(false); // Optimize C++ streams
    cin.tie(NULL); // Untie cin from cout

    int N, m, Q;
    cin >> N >> m >> Q;




//     10 3 7
// A B C D E F G H I J
// 1 H 1
// 1 E 2
// 3 B 2
// 1 B 2
// 1 D 3
// 3 A 2
// 1 A 2 
    vector<string> node_names(N);
    for (int i = 0; i < N; ++i)
        cin >> node_names[i];

    TreeNode* root = new TreeNode(node_names[0]);
    TreeLocking tree(root);
    queue<TreeNode*> que;
    que.push(root);
    int idx = 1;

    // Build the tree (BFS approach)
    while (idx < N) {
        TreeNode* parent = que.front(); que.pop();
        for (int i = 0; i < m && idx < N; ++i) {
            TreeNode* child = new TreeNode(node_names[idx]);
            child->parent = parent;
            parent->children.push_back(child);
            tree.nodes[child->name] = child;
            que.push(child);
            idx++;
        }
    }

    // Process queries
    for (int i = 0; i < Q; ++i) {
        int op_type, uid;
        string node_name;
        cin >> op_type >> node_name >> uid;
        if (op_type == 1) {
            cout << (tree.lock(node_name, uid) ? "true" : "false") << endl;
        } else if (op_type == 2) {
            cout << (tree.unlock(node_name, uid) ? "true" : "false") << endl;
        } else if (op_type == 3) {
            cout << (tree.upgrade(node_name, uid) ? "true" : "false") << endl;
        }
    }

    return 0;
}