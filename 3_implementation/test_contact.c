#include "cm.h"
#include "unity.h"

void setUp(){

}

void tearDown(){

}
void test_searchcontact(void){

    TEST_ASSERT_EQUAL_FLOAT(0,search_contact("Danesh",0,0,0));

}

void test_deletecontact(void){

    TEST_ASSERT_EQUAL_FLOAT(0,delete_contact("danesh",0,0,0,NULL,0));

}

int main()
{
    UNITY_BEGIN();

     RUN_TEST(test_searchcontact);
     RUN_TEST(test_deletecontact);

     
    return UNITY_END();
}