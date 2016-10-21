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

