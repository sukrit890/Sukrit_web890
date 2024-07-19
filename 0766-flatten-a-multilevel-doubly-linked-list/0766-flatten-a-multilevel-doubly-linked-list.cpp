/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        // Helper function to flatten a node and its children
        flattenNode(head);

        return head;
    }

private:
    Node* flattenNode(Node* node) {
        Node* current = node;
        Node* tail = node; // To keep track of the tail of the flattened list

        while (current != nullptr) {
            if (current->child != nullptr) {
                Node* child = current->child;
                current->child = nullptr;

                // Flatten the child list and get the child list's tail
                Node* childTail = flattenNode(child);

                // Connect the current node to the flattened child
                childTail->next = current->next;
                if (current->next != nullptr) {
                    current->next->prev = childTail;
                }
                current->next = child;
                child->prev = current;

                // Update the tail to be the tail of the merged list
                tail = childTail;
            }

            // Move to the next node in the original list
            current = current->next;
            if (current != nullptr) {
                tail = current; // Update the tail for non-null current nodes
            }
        }

        return tail; // Return the tail of the merged list
    }
};