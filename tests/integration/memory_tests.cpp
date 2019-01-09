#include <boost/test/unit_test.hpp>
#include <eosio/testing/tester.hpp>
#include <eosio/chain/abi_serializer.hpp>

#include <Runtime/Runtime.h>

#include <fc/variant_object.hpp>

#include <contracts.hpp>

using namespace eosio;
using namespace eosio::testing;
using namespace eosio::chain;
using namespace eosio::testing;
using namespace fc;

BOOST_AUTO_TEST_SUITE(memory_tests)

BOOST_FIXTURE_TEST_CASE( malloc_tests, tester ) try {
   create_accounts( { N(test) } );
   produce_block();

   set_code( N(test), contracts::malloc_tests_wasm() );
   set_abi( N(test), contracts::malloc_tests_abi().data() );
   produce_blocks();
   push_action(N(test), N(test1), N(test), {});

} FC_LOG_AND_RETHROW()

/*
BOOST_FIXTURE_TEST_CASE( rope_tests, tester ) try {
   create_accounts( { N(test) } );
   produce_block();

   set_code( N(test), contracts::rope_tests_wasm() );
   set_abi( N(test), contracts::rope_tests_abi().data() );
   produce_blocks();
   uint64_t t0 = __builtin_readcyclecounter();
   push_action(N(test), N(test1), N(test), {});
   uint64_t t1 = __builtin_readcyclecounter();
   uint64_t t2 = __builtin_readcyclecounter();
   push_action(N(test), N(test2), N(test), {});
   uint64_t t3 = __builtin_readcyclecounter();
   std::cout << "1 : " << t1 - t0 << '\n';
   std::cout << "2 : " << t3 - t2 << '\n';
} FC_LOG_AND_RETHROW() }
*/
}
