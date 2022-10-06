// handling duplicate keys by incrementing count value of every key
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int key;
	int count;
	struct node *left, *right;
};

//  Create a new BST node
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	temp->count = 1;
	return temp;
}

//  Inorder traversal of BST
void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		//printf("%d(%d)", root->key,root->count);
		printf(" %d(%d)--> %u , ", root->key, root->count,&root->key);
		inorder(root->right);
	
	}
}

// insertion of  a new node with given key in Binary search tree 
struct node* insert(struct node* node, int key)
{
	// If the tree is empty, return a new node 
	if (node == NULL) return newNode(key);

	// If key already exists in BST, increment count and return
	if (key == node->key)
	{
	(node->count)++;
		return node;
	}

	/* Otherwise, insert key */
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	/* return the unchanged node pointer */
	return node;
    }

/* Given a non-empty binary search tree, return the node with
minimum key value found in that tree. Note that the entire
tree does not need to be searched. */
struct node * minValueNode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

/* Given a binary search tree and a key, this function
deletes a given key and returns root of modified tree */
struct node* deleteNode(struct node* root, int key)
{
	// base case
	if (root == NULL) return root;

	// If the key to be deleted is smaller than the
	// root's key, then it lies in left subtree
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key
	else
	{
		// If key is present more than once, simply decrement
		// count and return
		if (root->count > 1)
		{
		(root->count)--;
		return root;
		}

		// ElSE, delete the node

		// node with only one child or no child
		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		struct node* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node
		root->key = temp->key;
		root->count = temp->count;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

void main()
{
	
	struct node *root = NULL;
	root = insert(root, 20);
	root = insert(root, 25);
	root = insert(root, 11);
	root = insert(root, 38);
	root = insert(root, 23);
	printf("Inorder traversal of the given tree \n");
	inorder(root);
//  duplicate keys 23 and 25
	root = insert(root, 23);
	root = insert(root, 25);
	printf("\n Inorder traversal after insertion duplicate keys 23 and 25\n");
	inorder(root);

	printf("\nDelete 23\n");
	root = deleteNode(root, 23);
	printf("\n Inorder traversal after deletion of 23 \n");
	inorder(root);

	printf("\nDelete 25\n");
	root = deleteNode(root, 25);
	printf("\n Inorder traversal after deletion of 25 \n");
	inorder(root);
        getch();
}
