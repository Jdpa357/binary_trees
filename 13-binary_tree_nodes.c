#include "binary_trees.h"

/**
 * 
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
        size_t size = 0;

        if (!tree || (!tree->left && !tree->right))
                return (0);

        size += binary_tree_nodes(tree->left);
        size += binary_tree_nodes(tree->right);
        return (size + 1);
}