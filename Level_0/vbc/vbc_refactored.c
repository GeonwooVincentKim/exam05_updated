#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
    ADD,
    MULTI,
    VAL,
} node_type;

typedef struct node {
    node_type type;
    int val;
    struct node *left;
    struct node *right;
} node;

// Function prototypes
node *parse_expr(char **s);
node *parse_term(char **s);
node *parse_primary(char **s);
node *new_node(node_type type, int val, node *left, node *right);
void destroy_tree(node *n);
void unexpected(char c);
int accept(char **s, char c);
int expect(char **s, char c);

// Create a new node
node *new_node(node_type type, int val, node *left, node *right) {
    node *ret = calloc(1, sizeof(node));
    if (!ret) return NULL;
    ret->type = type;
    ret->val = val;
    ret->left = left;
    ret->right = right;
    return ret;
}

// Destroy the tree and free memory
void destroy_tree(node *n) {
    if (!n) return;
    if (n->type != VAL) {
        destroy_tree(n->left);
        destroy_tree(n->right);
    }
    free(n);
}

// Handle unexpected characters
void unexpected(char c) {
    if (c)
        printf("unexpected %c\n", c);
    else
        printf("unexpected EOF\n");
}

// Accept a character if it matches
int accept(char **s, char c) {
    if (**s == c) {
        (*s)++;
        return 1;
    }
    return 0;
}

// Expect a character, error if not found
int expect(char **s, char c) {
    if (accept(s, c)) return 1;
    unexpected(**s);
    return 0;
}

// Parse expression: term + term + ...
node *parse_expr(char **s) {
    node *ret = parse_term(s);
    if (!ret) return NULL;
    
    while (accept(s, '+')) {
        node *r = parse_term(s);
        if (!r) {
            destroy_tree(ret);
            return NULL;
        }
        ret = new_node(ADD, 0, ret, r);
        if (!ret) {
            destroy_tree(r);
            return NULL;
        }
    }
    
    if (**s && **s != ')') {
        unexpected(**s);
        destroy_tree(ret);
        return NULL;
    }
    return ret;
}

// Parse term: primary * primary * ...
node *parse_term(char **s) {
    node *ret = parse_primary(s);
    if (!ret) return NULL;
    
    while (accept(s, '*')) {
        node *r = parse_primary(s);
        if (!r) {
            destroy_tree(ret);
            return NULL;
        }
        ret = new_node(MULTI, 0, ret, r);
        if (!ret) {
            destroy_tree(r);
            return NULL;
        }
    }
    return ret;
}

// Parse primary: (expr) or digit
node *parse_primary(char **s) {
    if (accept(s, '(')) {
        node *ret = parse_expr(s);
        if (!ret) return NULL;
        if (!accept(s, ')')) {
            unexpected(**s);
            destroy_tree(ret);
            return NULL;
        }
        return ret;
    }
    
    if (isdigit((unsigned char)**s)) {
        int val = **s - '0';
        (*s)++;
        return new_node(VAL, val, NULL, NULL);
    }
    
    unexpected(**s);
    return NULL;
}

// Evaluate the expression tree
int eval_tree(node *tree) {
    switch (tree->type) {
        case ADD:
            return eval_tree(tree->left) + eval_tree(tree->right);
        case MULTI:
            return eval_tree(tree->left) * eval_tree(tree->right);
        case VAL:
            return tree->val;
        default:
            return 0;
    }
}

int main(int ac, char **av) {
    if (ac != 2) return 1;
    
    char *input = av[1];
    node *tree = parse_expr(&input);
    if (!tree) return 1;
    
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return 0;
} 