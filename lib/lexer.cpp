#include "klang/lexer.hpp"
#include "klang/lexer_source.hpp"
#include "klang/token.hpp"

namespace klang {

Lexer::Lexer(const std::string &Code)
    : Source{std::make_unique<StringLexerSource>(Code)} {}

Lexer::Lexer(std::istream &Stream)
    : Source{std::make_unique<StreamLexerSource>(Stream)} {}

Lexer::Lexer(std::unique_ptr<LexerSource> &&Source)
    : Source{std::move(Source)} {}

Token Lexer::get_next_token() {

  char Next;
  while ((Next = Source->get_character())) {
    if (isspace(Next)) {
      consume_space(Next);
    } else if (isdigit(Next)) {
      consume_digit(Next);
    } else if (isalpha(Next)) {
      consume_alpha(Next);
    } else {
      consume_other(Next);
    }

    if (EmitToken && CurrentType != Token::Type::TOK_EMPTY) {
      return Token{CurrentType, CurrentValue};
    }
  }

  return Token{Token::Type::TOK_EOF};
}

void Lexer::consume_space(char Next) {
  if (!CurrentValue.empty()) {
    EmitToken = true;
  }
}

} // namespace klang
