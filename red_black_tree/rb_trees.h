#ifndef _RB_TREES_H_
#define _RB_TREES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * enum rb_color_e - Possible color of a Red-Black tree
 *
 * @RED: 0 -> Red node
 * @BLACK: 1 -> Black node
 * @DOUBLE_BLACK: 2 -> Double-black node (used for deletion)
 */
typedef enum rb_color_e
{
	RED = 0,
	BLACK,
	DOUBLE_BLACK
} rb_color_t;

/**
 * struct rb_tree_s - Red-Black tree node structure
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 * @color: Color of the node (RED or BLACK)
 */
typedef struct rb_tree_s
{
	int n;
	rb_color_t color;
	struct rb_tree_s *parent;
	struct rb_tree_s *left;
	struct rb_tree_s *right;
} rb_tree_t;

rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color);
int rb_tree_is_valid(const rb_tree_t *tree);

int is_valid_rbt(const rb_tree_t *tree, int black_count, rb_color_t prev_color);
rb_tree_t *array_to_rb_tree(int *array, size_t size);

rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value);
void fix_rb_insert(rb_tree_t **tree, rb_tree_t *new_node);
void handle_case_right(rb_tree_t **tree, rb_tree_t **new_node, rb_tree_t *parent, rb_tree_t *grandparent, rb_tree_t *uncle);
void handle_case_left(rb_tree_t **tree, rb_tree_t **new_node, rb_tree_t *parent, rb_tree_t *grandparent, rb_tree_t *uncle);

void swap_colors(rb_tree_t *parent, rb_tree_t *grandparent);
void rotate_right(rb_tree_t **tree, rb_tree_t *grandparent);
void rotate_left(rb_tree_t **tree, rb_tree_t *parent);

rb_tree_t *array_to_rb_tree(int *array, size_t size);

rb_tree_t *rb_tree_remove(rb_tree_t *root, int n);

#endif /* _RB_TREES_H_ */
