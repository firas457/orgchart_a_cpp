#pragma once
#include <iostream>
#include <vector>
#include "node.hpp"

using namespace std;

namespace ariel
{
    class OrgChart
    {
        Node root;

    public:
        OrgChart();
        ~OrgChart();
        ariel::OrgChart &add_root(string name);
        ariel::OrgChart &add_sub(string upper_level, string under_level);
        std::string *begin_reverse_order();
        std::string *begin_preorder();
        std::string *reverse_order();
        std::string *begin_level_order();
        std::string *end_level_order();
        std::string *end_preorder();
        std::string *begin();
        string *end();
        friend ostream &operator<<(ostream &out, OrgChart &root);
    };
}
