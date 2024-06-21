#include <iostream>
#include <vector>
#include <queue>
#include <ctime>

struct Node
{
    int data;
    std::vector<Node*> childrens;

    Node(const int&  value) : data(value)
    {
    }
};

Node* createTree(int depth)
{
    if (depth == 0)
    {
        return nullptr;
    }

    Node* root = new Node(rand() % 10);
    std::queue<Node*> q;
    q.push(root);
    --depth;

    while (depth > 0)
    {
        int size = q.size();
        while (size > 0)
        {
            Node* node = q.front();
            q.pop();
            int randChilds = rand() % 10;

            for (size_t i = 0; i < randChilds; ++i)
            {
                Node* child = new Node(rand() % 10);
                node->childrens.push_back(child);
                q.push(child);
            }
            --size;
        }
        --depth;
    }
    
    return root;
}


void levelOrderedTraversal(Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* node = q.front();
        q.pop();

        std::cout<<node->data<<" ";

        int childs = node->childrens.size();
        for (size_t i = 0; i < childs; ++i)
        {
            q.push(node->childrens[i]);
        }
        
    }
    
}

int main()
{
    srand(time(0));

    int depth = rand() % 10;

    Node* root = createTree(depth);
    levelOrderedTraversal(root);

    return 0;
}