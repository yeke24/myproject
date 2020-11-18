#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 };
 

vector<vector<int> > threeOrders(TreeNode* root) 
{ 
    vector<vector<int>> re(3);
    traver(root,re);
    //stacktraver(root,re);
    return re;
}

void traver(TreeNode *root,vector<vector<int>> &re)
{
    if(root != NULL)
    {
        re[0].push_back(root->val);
        traver(root->left,re);
        re[1].push_back(root->val);
        traver(root->right,re);
        re[2].push_back(root->val);
    }
}

enum travertype{ pre, mid, post, go};
    
struct Command
{
    travertype type;
    TreeNode *node;

    Command(travertype type, TreeNode * node):type(type), node(node) {}
};

void stacktraver(TreeNode * node, vector<vector<int> > &re)
{
    if(!node) return ;

    stack<Command> sta;

    sta.push(Command( go,node));

    while(!sta.empty())
    {
        Command tem=sta.top();
        sta.pop();
        if(tem.type!=go)
        {
            if(tem.type==pre)
                re[pre].push_back(tem.node->val);
            else if(tem.type==mid)
                re[mid].push_back(tem.node->val);
            else if(tem.type==post)
                re[post].push_back(tem.node->val);

            /*
            switch(tem.type)
            {
                case pre:
                    re[pre].push_back(tem.node->val);
                    break;
                case mid:
                    re[mid].push_back(tem.node->val);
                    break;
                case post:
                    re[post].push_back(tem.node->val);
                    break;

               default:
                    ;
            }*/
        }
        else
        {   
            sta.push(Command( post, tem.node));

            if(tem.node->right) sta.push(Command( go, tem.node->right));

            sta.push(Command( mid, tem.node));

            if(tem.node->left) sta.push(Command( go, tem.node->left));

            sta.push(Command( pre, tem.node));
        }

    }
    return ;
}

int main()
{
    
    return 0;
}