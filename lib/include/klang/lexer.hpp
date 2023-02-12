#pragma once

#include <memory>
#include <string>

#include "klang/lexer_source.hpp"
#include "klang/token.hpp"

namespace klang {

class Lexer {
private:
  std::unique_ptr<LexerSource> Source;
  std::string CurrentValue;
  Token::Type CurrentType;
  bool EmitToken = false;

public:
  explicit Lexer(const std::string &Code);

  explicit Lexer(std::istream &Stream);

  explicit Lexer(std::unique_ptr<LexerSource> &&Source);

  [[nodiscard]] Token get_next_token();

private:
  void consume_space(char Next);

  void consume_digit(char Next) {}

  void consume_alpha(char Next) {}

  void consume_other(char Next) {}
};
} // namespace klang
