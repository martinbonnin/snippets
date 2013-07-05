hi
power set 

{a,b,c} 
{}, {a}, {b}, {c}, {a,b}, {a,c}, {b,c}, {a,b, c}

hi

v[N]

list powerset(int *v, int n) {
	list l = empty_list;
	for each e in powerset(v, n -1) {
		l.append(e);
e.append(v[n]);
		l.append(e);
}

	return l;
}

struct element {
	struct element *next;
	int v;
};

struct set {
	struct set *next;
	struct element *e;
};

struct element *powerset(int *v, int  n){
	struct set *s = malloc(sizeof(struct set));
	struct set *l = powerset(v, n-1);
	while (
}

=============================




a -> b
a -> c
b->c

a, b, c
==============================
V1 = 1,5, 4, 7

V2 = 4, 3, 4, 1, 8

1,1
4,4
4,4

if (ACC1[i] > 1 && ACC2[i] > 1) {
}

sort(V1);
sort(V2);

j = 0;
for (i = 0; i< sizeof(V1); i++) {
	if (V1[i] == V2[j]) {
printf(“%d - %d\n”, V1[i], V2[j])	

} else if (V1[i] < V2[j]) {
	i++;
} else {
}
}
=====
