#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node node;

struct node {
	node *left;
	node *right;
	const char *name;
};

static node * _add_left(node *parent, const char *name)
{
	node *child = malloc(sizeof(node));
	memset(child, 0, sizeof(*child));
	
	child->name = name;
	if (!parent)
	    goto end;
	    
	if (parent->left) {
        printf("%s already has left: %s\n", parent->name, parent->left->name);
	}
	parent->left = child;

end:
	return child;
}

static node * _add_right(node *parent, const char *name)
{
	node *child = malloc(sizeof(node));
	memset(child, 0, sizeof(*child));
	
	child->name = name;
	if (!parent)
	    goto end;
	    
	if (parent->right) {
        printf("%s already has right: %s\n", parent->name, parent->left->name);
	}
	parent->right = child;

end:
	return child;
}

static void print_tree(node *node)
{
	static int num = 0;
	
	if (!node)
	    return;
	    
    print_tree(node->right);
    
    num++;

    printf("%d. %s\n", num, node->name);
    
    print_tree(node->left);
}

int main(int argc, char *argv[])
{
	node *eight;
	node *ten;
	node *fourteen;
	node *thirteen;
	node *three;
	node *one;
	node *six;
	node *four;
	node *seven;

	eight = _add_right(NULL, "8");
	ten = _add_right(eight, "10");
	fourteen = _add_right(ten, "14");
	thirteen = _add_left(fourteen, "13");
	three = _add_left(eight, "3");
	one = _add_left(three, "1");
	six = _add_right(three, "6");
	four = _add_left(six, "4");
	seven = _add_right(six, "7");

	print_tree(eight);

	return 0;
}
