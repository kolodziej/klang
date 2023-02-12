#pragma once

#include <istream>

namespace klang {

class LexerSource {
public:
  virtual ~LexerSource() = default;

  [[nodiscard]] virtual char get_character() = 0;
};

class StringLexerSource : public LexerSource {
private:
  const std::string Code;
  std::size_t Current;

public:
  explicit StringLexerSource(const std::string &Code)
      : Code{Code}, Current{0} {}

  [[nodiscard]] char get_character() override;
};

class StreamLexerSource : public LexerSource {
private:
  std::istream &Stream;

public:
  explicit StreamLexerSource(std::istream &Stream) : Stream{Stream} {}

  [[nodiscard]] char get_character() override;
};

} // namespace klang
