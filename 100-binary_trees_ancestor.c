#include "binary_trees.h"

/**
 * contains_node - Evaluates if a subtree contains the given searched node
 * @node: is the root of the subtree
 * @searched: is the searched node
 * Return: 1 if the node subtree contains the searched node, 0 in otherwise.
 */
int contains_node(const binary_tree_t *node, const binary_tree_t *searched)
{
	if (node == searched)
		return (1);
	if (node && node->left && node->right)
		return (1 && (contains_node(node->left, searched)
			      || contains_node(node->right, searched)));
	return (0);
}

/**
 * ancestor_contain - Evaluates if an ancestor tree contains the given searched
 * node. It doesn't evaluates the origin subtree.
 *
 * @origin: is the child subtree that used this function
 * @ancestor: is the root of the parent tree
 * @searched: is the give node to be searched.
 * Return: The node of the ancestor that contains the given node, or NULL if
 * any ancestor contains the node
 */
binary_tree_t *ancestor_contain(const binary_tree_t *origin,
				binary_tree_t *ancestor,
				const binary_tree_t *searched)
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

/**
 * binary_trees_ancestor - It search the lowest common ancestor (LCA) of
 * two nodes of a binary tree.
 *
 * @first: is the first node
 * @second: is the second node
 * Return: The LCA of first and second or NULL if there isn't an LCA
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);
	if (contains_node(first, second))
		return ((binary_tree_t *)first);

	return (ancestor_contain(first, first->parent, second));
}
