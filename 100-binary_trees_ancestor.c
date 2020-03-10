#include "binary_trees.h"

int contains_node(const binary_tree_t *node, const binary_tree_t *searched)
{
        if (node == searched)
                return (1);
        if (node && node->left && node->right)
                return (1 && (contains_node(node->left, searched)
                || contains_node(node->right, searched)));
        return (0);
}

binary_tree_t *ancestor_contain(const binary_tree_t *origin, binary_tree_t *ancestor, const binary_tree_t *searched)
{
        binary_tree_t *ls_tree, *rs_tree;

        if (!ancestor)
                return (NULL);
        if (ancestor == searched)
                return (ancestor);

        ls_tree = (ancestor->left == origin) ? NULL : ancestor->left;
        rs_tree = (ancestor->right == origin) ? NULL : ancestor->right;
        
        if (contains_node(ls_tree, searched) || contains_node(rs_tree, searched))
                return (ancestor);
        return (ancestor_contain(ancestor, ancestor->parent, searched));
}

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
        if (!first || !second)
                return (NULL);
        if (contains_node(first, second))
                return ((binary_tree_t *)first);

        return (ancestor_contain(first, first->parent, second));
}