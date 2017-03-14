#include<stdio.h>
#include<stdlib.h>
typedef struct nodes{
    int data;
    struct nodes* left;
    struct nodes* right;
} node;
node* root = NULL;
void insert(int data);
void inorder(node* root);
int main()
{
    int data , n , i;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter node data: ");
        scanf("%d",&data);
        insert(data);
    }
    printf("\nInorder traversal : ");
    inorder(root);
    return 0;
}
void insert(int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->left=temp->right = NULL;
    temp->data = data;
    if(root==NULL)
    {
        root=temp;
        return;
    }
    node* temp1 = root;
    while((temp1->left!=NULL)||(temp1->right!=NULL))
    {
        if(data<=temp1->data)
        {
            if(temp1->left==NULL)
            {
                temp1->left = temp;
                return;
            }
            temp1 = temp1->left;
        }
        else
        {
            if(temp1->right==NULL)
            {
                temp1->right = temp;
                return;
            }
            temp1 = temp1->right;
        }
    }
    if(data<=temp1->data)
        temp1->left = temp;
    else
        temp1->right = temp;
}
void inorder(node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d " , root->data);
    inorder(root->right);
}
