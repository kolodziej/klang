#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <memory>

#include "klang/lexer.hpp"
#include "klang/magic_enum.hpp"

TEST_CASE("Returns only TOK_EOF when code is empty") {
  klang::Lexer Lexer{""};

  auto next_token = Lexer.get_next_token();
  INFO("next_token type = " << magic_enum::enum_name(next_token.type()));
  REQUIRE(klang::Token(klang::Token::Type::TOK_EOF) == next_token);
}
