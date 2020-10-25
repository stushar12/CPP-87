vector<int> abc(Node * root,vector<int> &v)
{
    if(root!=NULL)
    {
        abc(root->left,v);
        v.push_back(root->data);
        abc(root->right,v);
    }
    else
    return v;
    return v;
}
int isPairPresent(struct Node *root, int k)
{
vector<int> v;
v=abc(root,v);
int start=0,end=v.size()-1;
while(start<=end)
{
    if((v[start]+v[end])==k)
    return 1;
    else if((v[start]+v[end])>k)
    end=end-1;
    else
    start=start+1;
}
return 0;
}