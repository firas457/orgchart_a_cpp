
   #include<iostream>
   #include <vector>

   using namespace std;

   struct Node
    {
        string name;
        std::vector<Node> levels;
        int father;
    };