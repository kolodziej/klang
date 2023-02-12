#include "klang/token.hpp"

namespace klang {

Token::Type Token::type() const { return TokenType; }

Token::OptValue Token::value() const { return Value; }

} // namespace klang
