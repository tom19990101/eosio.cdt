#include <eosiolib/eosio.hpp>
#include <eosiolib/memory.hpp>

using namespace eosio;

CONTRACT simple_malloc_tests : public contract{
   public:
      using contract::contract;

      ACTION test1() {
         void* ret = malloc(0);

         //print_f("PTR : %\n", (size_t)ret);
         check(ret == NULL, "malloc(0) should return null");
         ret = malloc(72317);
         check(ret != NULL, "malloc(0) should return null");
         //ret = malloc(1024);
         //print_f("PTR : %\n", (size_t)ret);
         //check(ret != NULL, "malloc(1024) should return 0");
      }
};

#ifdef EOSIO_NATIVE
#include <eosio/native/tester.hpp>

using namespace eosio::native;

EOSIO_TEST_BEGIN(malloc_test)
   malloc_tests mt(""_n, ""_n, datastream<const char*>(nullptr, 0));
   mt.test1();
EOSIO_TEST_END

int main(int argc, char** argv) {
   EOSIO_TEST(malloc_test);
   return has_failed();
}
#else
EOSIO_DISPATCH(simple_malloc_tests, (test1))
#endif
