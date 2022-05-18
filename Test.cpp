#include <iostream>
#include "doctest.h"
#include "OrgChart.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("root check")
{
    OrgChart organization;

    CHECK_NOTHROW(organization.add_root("firas")); // firas is the root now

    CHECK_NOTHROW(organization.add_root("sari")); // sari is the root now

    CHECK_NOTHROW(organization.add_root("moshe")); // moshe is the root now

    CHECK_NOTHROW(organization.add_root("ariel")); // ariel is the root now
}

TEST_CASE("add_sub function check")
{
    OrgChart organization2;

    CHECK_NOTHROW(organization2.add_root("firas"));
    CHECK_NOTHROW(organization2.add_sub("firas", "sari"));   // Now sari is subordinate to firas
    CHECK_NOTHROW(organization2.add_sub("firas", "saleem")); // Now saleem is subordinate to firas
    CHECK_NOTHROW(organization2.add_sub("firas", "tal"));    // Now tal COO is subordinate to firas
    CHECK_NOTHROW(organization2.add_sub("firas", "amit"));   // Now amit is subordinate to firas

    CHECK_THROWS(organization2.add_sub("kalild", "kal"));
    CHECK_THROWS(organization2.add_sub("dali", "bad"));
    CHECK_THROWS(organization2.add_sub("mflih", "mafi"));
    CHECK_THROWS(organization2.add_sub("monzer", "khel"));

    CHECK_NOTHROW(organization2.add_sub("firas", "firas"));

    /* the organization looks like :
           firas
           |--------|--------|--------|
           saleem   amit      tal     sari

     */

    CHECK_NOTHROW(organization2.add_sub("tal", "kali") // Now kali is subordinate to tal
                      .add_sub("tal", "khaled")        // Now saleem is subordinate to tal
                      .add_sub("amit", "faris")        // Now faris COO is subordinate to amit
                      .add_sub("amit", "mali"));       // Now mali is subordinate to amit

    /* the organization looks like :
           firas
           |--------|---------|-------------|
           saleem   amit      tal          sari
                    |-------- |
                    |         |
              mali----faris   khaled---kali

     */

    CHECK_THROWS(organization2.add_sub("kasi", "kal"));
    CHECK_THROWS(organization2.add_sub("dsaf", "kal"));
    CHECK_THROWS(organization2.add_sub("falih", "kal"));
    CHECK_THROWS(organization2.add_sub("made", "kal"));
    CHECK_NOTHROW(organization2.add_sub("firas", "firas"));

    SUBCASE("iterators")
    {
        string ans;

        for (auto i = organization2.begin_level_order(); i != organization2.end_level_order(); ++i)
        {
            ans += (*i);
            ans += " ";
        }
        CHECK(ans == "firas saleem amit tal sari mali faris khaled kali");

        string ans2;

        for (auto i = organization2.begin_reverse_order(); i != organization2.reverse_order(); ++i)
        {
            ans2 += (*i);
            ans2 += " ";
        }
        CHECK(ans2 == "mali faris khaled kali saleem amit tal sari firas");

        string ans3;

        for (auto i = organization2.begin_preorder(); i != organization2.end_preorder(); ++i)
        {
            ans3 += (*i);
            ans3 += " ";
        }
        CHECK(ans3 == "firas saleem amit mali faris tal khaled kali sari");
    }
}
