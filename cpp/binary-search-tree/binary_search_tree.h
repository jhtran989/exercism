#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

#include <memory>
#include <iostream>

namespace binary_search_tree {

// TODO: add your solution here

template <typename T>
class binary_tree {
private:
    T value{};
    // std::unique_ptr<binary_tree> leftTree{};
    // std::unique_ptr<binary_tree> rightTree{};
    binary_tree* leftTree{};
    binary_tree* rightTree{};

    // added parent for in place traversal
    binary_tree* parentTree{};
    // FIXME: don't actually need visited and related functions...
    bool visited{};

public:
    binary_tree(T value) : value(value), leftTree(nullptr), rightTree(nullptr), parentTree(nullptr), visited(false) {
        // FIXME:
        std::cout << "creating new tree..." << std::endl;
    }

    void insert(T value) {
        // TODO: assume equal elements go to the LEFT
        if (value <= this->value) {
            if (leftTree == nullptr) {
                // FIXME
                std::cout << "inserting new left" << std::endl;
                // leftTree = std::make_unique<binary_tree>(binary_tree(value));
                leftTree = new binary_tree(value);
                leftTree->parentTree = this;
            } else {
                // FIXME
                std::cout << "inserting into left" << std::endl;
                leftTree->insert(value);
            }
        } else {
            if (rightTree == nullptr) {
                // FIXME
                std::cout << "inserting new right" << std::endl;
                // rightTree = std::make_unique<binary_tree>(binary_tree(value));
                rightTree = new binary_tree(value);
                rightTree->parentTree = this;
            } else {
                // FIXME
                std::cout << "inserting into right" << std::endl;
                rightTree->insert(value);
            }
        }
    }

    const T data() {
        return value;
    }

    std::unique_ptr<binary_tree> left() {
        if (this->leftTree == nullptr) {
            return nullptr;
        } else {
            // return std::move(this->leftTree);
            return std::make_unique<binary_tree>(*(this->leftTree));
        }
    }

    std::unique_ptr<binary_tree> right() {
        if (this->rightTree == nullptr) {
            return nullptr;
        } else {
            // return std::move(this->rightTree);
            return std::make_unique<binary_tree>(*(this->rightTree));
        }
    }

    bool terminal() {
        return leftTree == nullptr && rightTree == nullptr;
    }

    binary_tree* getLeftmost() {
        binary_tree* current = this;
        if (current->leftTree != nullptr) {
            current = current->leftTree;
            return current->getLeftmost();
        } else {
            return current;
        }
    }

    bool completelyVisited() {
        return (leftTree == nullptr || leftTree->visited) && (rightTree == nullptr || rightTree->visited);
    }

    void resetVisited() {
        if (leftTree != nullptr) {
            leftTree->visited = false;
        }

        if (rightTree != nullptr) {
            rightTree->visited = false;
        }
    }

    class Iterator {
    private:
        binary_tree* current;
        // T currentValue;
    public:
        Iterator(binary_tree* tree) : current(tree) {}

        T& operator*() { return current->value; }

        Iterator& operator++() {
            // current = current->next;
            // return *this;

            // if (current->terminal() || current->completelyVisited) {
            //     current = current->parentTree;
            //     current->resetVisited();
            // } else if (!current->leftTree->visited) {
            //     current = current->leftTree;
            //     current->visited = true;
            // } else if (!current->rightTree->visited) {
            //     current = current->rightTree;
            //     current->visited = true;
            // } else {
            //     // reached the end
            // }

            if (current->rightTree != nullptr) {
                current = current->rightTree;
                current = current->getLeftmost();
            } else {
                binary_tree* current_parent = current->parentTree;
                while (current_parent != nullptr && current_parent->rightTree == current) {
                    current = current_parent;
                    current_parent = current->parentTree;
                }

                current = current_parent;
            }

            return *this;
        }

        bool operator!=(const Iterator& other) const { return current != other.current; }
    };

    Iterator begin() { return Iterator(this->getLeftmost()); }
    Iterator end() { return Iterator(nullptr); }
};

// FIXME: use only binary_tree instead of node
// template <typename T>
// class node {
// private:
//     T value{};
//     node* left{};
//     node* right{};
// public:
//     node(T value) : value(value) {}

//     void insert(T value) {
//         // TODO: assume equal elements go to the RIGHT
//         if (value < this->value) {
//             if (left == nullptr) {
//                 left = std::make_unique<T>(node(value));
//             } else {
//                 left->insert(value);
//             }
//         } else {
//             if (right == nullptr) {
//                 right = std::make_unique<T>(node(value));
//             } else {
//                 right->insert(value);
//             }
//         }
//     }
// };

// template <typename T>
// class binary_tree {
// private:
//     node<T>* root{};
// public:
//     binary_tree(T rootValue) : root(std::make_unique<T>(rootValue)) {}

//     void insert(T value) {
//         root->insert(value);
//     }

//     const T data() {
//         return root->value;
//     }

//     const T left() {
//         if (root->left == nullptr) {
//             return T{};
//         } else {
//             return root->left->value;
//         }
//     }

//     const T right() {
//         if (root->right == nullptr) {
//             return T{};
//         } else {
//             return root->right->value;
//         }
//     }
// };

}  // namespace binary_search_tree

#endif  // BINARY_SEARCH_TREE_H