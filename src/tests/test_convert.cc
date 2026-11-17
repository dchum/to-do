// #include <iostream>
// #include <assert.h>

// #include "key_input.h"

// int main()
// {
//     using namespace cui;

//     assert( parse_key_spec("Ctrl+Shift+p") == KeyEvent('p', ModifierKey::Ctrl | ModifierKey::Shift) );
//     assert( parse_key_spec("Ctrl+p") == KeyEvent('p', ModifierKey::Ctrl) );
//     assert( parse_key_spec("p+Ctrl") == KeyEvent('p', ModifierKey::Ctrl) );
//     assert( parse_key_spec("Shift+p") == KeyEvent('p', ModifierKey::Shift) );
//     assert( parse_key_spec("p") == KeyEvent('p', ModifierKey::None) );
//     assert( parse_key_spec("P") == KeyEvent('p', ModifierKey::Shift) );
//     assert( parse_key_spec("Down") == KeyEvent(NamedKey::Down, ModifierKey::None) );
//     assert( parse_key_spec("Insert") == KeyEvent(NamedKey::Insert, ModifierKey::None) );

//     try {
//         parse_key_spec("Ctrl+fjrn"); // Invalid key spec, should throw an exception
//         assert(false); // Should not reach here
//     } catch (const std::exception& e) {
//         std::cout << "Caught expected exception: " << e.what() << std::endl;
//     }

//     try {
//         parse_key_spec("Ctrl+Shift+"); // Invalid key spec, should throw an exception
//         assert(false); // Should not reach here
//     } catch (const std::exception& e) {
//         std::cout << "Caught expected exception: " << e.what() << std::endl;
//     }

//     try {
//         parse_key_spec("+"); // Invalid key spec, should throw an exception
//         assert(false); // Should not reach here
//     } catch (const std::exception& e) {
//         std::cout << "Caught expected exception: " << e.what() << std::endl;
//     }

//     try {
//         parse_key_spec(""); // Invalid key spec, should throw an exception
//         assert(false); // Should not reach here
//     } catch (const std::exception& e) {
//         std::cout << "Caught expected exception: " << e.what() << std::endl;
//     }

//     try {
//         parse_key_spec("++"); // Invalid key spec, should throw an exception
//         assert(false); // Should not reach here
//     } catch (const std::exception& e) {
//         std::cout << "Caught expected exception: " << e.what() << std::endl;
//     }

//     try {
//         parse_key_spec("Ctrl+Shift+Ctrl+p"); // Invalid key spec, should throw an exception
//         assert(false); // Should not reach here
//     } catch (const std::exception& e) {
//         std::cout << "Caught expected exception: " << e.what() << std::endl;
//     }
    
//     try {
//         parse_key_spec("pp"); // Invalid key spec, should throw an exception
//         assert(false); // Should not reach here
//     } catch (const std::exception& e) {
//         std::cout << "Caught expected exception: " << e.what() << std::endl;
//     }

//     assert( true );
//     std::cout << "All tests passed!" << std::endl;
//     return 0;
// }

#include <gtest/gtest.h>

#include "key_input.h"
#include "keyevent.h"

using namespace cui;

// Проверка корректного разбора клавиш
TEST(ParseKeySpecTest, ParsesCharacterWithModifiers)
{
    EXPECT_EQ(parse_key_spec("Ctrl+Shift+p"), KeyEvent('p', ModifierKey::Ctrl | ModifierKey::Shift));

    EXPECT_EQ(parse_key_spec("Ctrl+p"), KeyEvent('p', ModifierKey::Ctrl));

    EXPECT_EQ(parse_key_spec("p+Ctrl"), KeyEvent('p', ModifierKey::Ctrl));

    EXPECT_EQ(parse_key_spec("Shift+p"),KeyEvent('p', ModifierKey::Shift));

    EXPECT_EQ(parse_key_spec("p"), KeyEvent('p', ModifierKey::None));

    EXPECT_EQ(parse_key_spec("P"), KeyEvent('p', ModifierKey::Shift));
}

// Проверка именованных клавиш
TEST(ParseKeySpecTest, ParsesNamedKeys)
{
    EXPECT_EQ(parse_key_spec("Down"), KeyEvent(NamedKey::Down, ModifierKey::None));

    EXPECT_EQ(parse_key_spec("Insert"), KeyEvent(NamedKey::Insert, ModifierKey::None));
}

// Проверка некорректных комбинаций
TEST(ParseKeySpecTest, RejectsInvalidSpecifications)
{
    EXPECT_THROW(parse_key_spec("Ctrl+fjrn"), std::exception);
    EXPECT_THROW(parse_key_spec("Ctrl+Shift+"), std::exception);
    EXPECT_THROW(parse_key_spec("+"), std::exception);
    EXPECT_THROW(parse_key_spec(""), std::exception);
    EXPECT_THROW(parse_key_spec("++"), std::exception);
    EXPECT_THROW(parse_key_spec("Ctrl+Shift+Ctrl+p"), std::exception);
    EXPECT_THROW(parse_key_spec("pp"), std::exception);
}