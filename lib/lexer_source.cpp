#include "klang/lexer_source.hpp"

namespace klang {

char StreamLexerSource::get_character() { return Stream.get(); }

char StringLexerSource::get_character() {
  if (Current >= Code.size()) {
    return 0;
  }

  return Code[Current++];
}

} // namespace klang
