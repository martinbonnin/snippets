#include <stdlib.h>
#include <stdio.h>

typedef struct node node;

struct node {
	node *first_child;
	node *next;
	const char *name;
};

static node * _add_child(node *parent, const char *name)
{
	node *child = malloc(sizeof(node));
	child->first_child = NULL;
	child->next = NULL;
	child->name = name;

	if (!parent) {
		goto end;
	} else if (!parent->first_child) {
		parent->first_child = child;
	} else {
		node *previous = parent->first_child;
		while (previous && previous->next)
			previous = previous->next;
		previous->next = child;
	}
end:
	return child;
}

static node *queue_data[100];
static int queue_write;

static void queue_node(node *node)
{
	queue_data[queue_write++] = node;
}
static node *dequeue_node(void)
{
	node *node;
	int i;
	if (queue_write == 0)
		return NULL;

	node = queue_data[0];

	for (i = 0; i < queue_write - 1; i++)
		queue_data[i] = queue_data[i+1];

	queue_write--;
	return node;
}

static int queue_is_empty(void) 
{
	return (queue_write == 0);
}

static void print_tree(node *root)
{
	queue_node(root);

	while (!queue_is_empty()) {
		node *current;
		node *next;
		current = dequeue_node();	
		next = current->first_child;
		printf("%s ", current->name);
		while (next) {
			queue_node(next);
			next = next->next;
		}
	}
}

int main(int argc, char *argv[])
{
	node *ceo;
	node *vp1;
	node *d11;
	node *d12;
	node *vp2;
	node *d21;
	node *d22;
	node *vp3;
	node *d31;
	node *d32;

	ceo = _add_child(NULL, "ceo");
	vp1 = _add_child(ceo, "vp1");
	d11 = _add_child(vp1, "d11");
	d12 = _add_child(vp1, "d12");
	vp2 = _add_child(ceo, "vp2");
	d21 = _add_child(vp2, "d21");
	d22 = _add_child(vp2, "d22");
	vp3 = _add_child(ceo, "vp3");
	d31 = _add_child(vp3, "d31");
	d32 = _add_child(vp3, "d32");

	print_tree(ceo);

	return 0;
}
