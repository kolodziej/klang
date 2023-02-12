set(KLANG_HEADERS
    include/klang/lexer.hpp
    include/klang/fwd_decls.hpp
    include/klang/lexer_source.hpp
)

set(KLANG_SOURCES
    token.cpp
    lexer.cpp
    lexer_source.cpp
)

add_library(klang SHARED ${KLANG_SOURCES} ${KLANG_HEADERS})
