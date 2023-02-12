#pragma once

#include <optional>
#include <string>

namespace klang {

class Token {
public:
  enum class Type {
    TOK_EMPTY,
    TOK_EOF,
    TOK_DEF,
    TOK_EXTERN,
    TOK_IDENTIFIER,
    TOK_NUMBER
  };
  using OptValue = std::optional<std::string>;

private:
  const Type TokenType = Type::TOK_EMPTY;
  const OptValue Value;

public:
  explicit Token() = default;

  Token(Type TokenType, OptValue Value = std::nullopt)
      : TokenType{TokenType}, Value{Value} {};

  bool operator==(const Token &RHS) const {
    return TokenType == RHS.TokenType && Value == RHS.Value;
  }

  [[nodiscard]] Type type() const;
  [[nodiscard]] OptValue value() const;
};

} // namespace klang

