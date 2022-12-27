int k = n/2;

void shiftnode(node,k)
{
    if(k<node->value) //if the k is less than the value of node
    {
        shiftnode(LeftChildNode,k); //this is the recursive call being recalled
        //shift node ot rightr subtree
        //shift the left child to the root
        //rebalance the tree except the root
    }
    else if(k>node->value) //if the k is more than the value of the node
    {
        shiftnode(RightChildNode,k); //The other recursive call
        //shift node to left subtree
        //shift the right child to the root
        //rebalance the tree except the root
    }
    else
    return; //if returns -> means no nodes to shift / complete
}