/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode *_flatten(struct TreeNode *root){

 if (root == NULL){
  return NULL;
 }
//right part
 if(root->right != NULL)
  root->right = _flatten(root->right);
//left part
 if(root->left != NULL){
  struct TreeNode *temp = root->right;
  root->right = root->left;
  struct TreeNode *t = _flatten(root->right);

  while(t->right != NULL)
   t = t->right;

  t->right = temp;
  root->left = NULL;
 }

//final
 return root;
}

void flatten(struct TreeNode * root){

 _flatten(root);

}

