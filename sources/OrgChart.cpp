#include <iostream>
#include "OrgChart.hpp"

using namespace std;
using namespace ariel;

ariel::OrgChart::OrgChart()
{
}
ariel::OrgChart::~OrgChart()
{
}

ariel::OrgChart &ariel::OrgChart::add_root(string name)
{
    return *this;
}

ariel::OrgChart &ariel::OrgChart::add_sub(string upper_level, string under_level)
{
    return *this;
}

std::string *ariel::OrgChart::begin_level_order()
{

    std::string *s;
    return s;
}
std::string *ariel::OrgChart::end_level_order()
{

    std::string *s;
    return s;
}
std::string *ariel::OrgChart::begin_reverse_order()
{

    std::string *s;
    return s;
}
std::string *ariel::OrgChart::reverse_order()
{

    std::string *s;
    return s;
}
std::string *ariel::OrgChart::begin_preorder()
{
    std::string *s;
    return s;
}
std::string *ariel::OrgChart::end_preorder()
{

    std::string *s;
    return s;
}
std::string *ariel::OrgChart::begin()
{

    std::string *s;
    return s;
}

string *ariel::OrgChart::end()
{

    std::string *s;
    return s;
}

std::ostream &ariel::operator<<(ostream &out, OrgChart &root)
{
    out << "cc";
    return out;
}