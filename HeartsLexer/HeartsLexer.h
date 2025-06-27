#pragma once // Ensures this file is included only once per compilation unit
#include <string>
#include <vector>
#include <stdexcept> // Good for error handling

// ====================== ENUM ======================
enum class TokenType {
    // Keywords
    IF, ELSE, ELSIF, FOR, FN, ENTITY, BITS, GENERIC, ALWAYS, PIPELINE, REG, SINT, UINT, SIGNAL,
    
    // Operators
    OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD, OP_BITAND, OP_BITOR, OP_BITXOR,
    OP_BITNOT, OP_LSHIFT, OP_RSHIFT, OP_EQ, OP_NEQ, OP_LT, OP_GT, OP_LTE, OP_GTE,
    OP_AND, OP_OR, OP_XOR, OP_NOT, OP_ASSIGN, OP_ADD_ASSIGN, OP_SUB_ASSIGN,
    OP_MUL_ASSIGN, OP_DIV_ASSIGN, OP_MOD_ASSIGN, OP_LSHIFT_ASSIGN, OP_RSHIFT_ASSIGN,

    // Delimiters
    LEFTPAREN, RIGHTPAREN, LEFTBRACE, RIGHTBRACE, LEFTBRACKET, RIGHTBRACKET, SEMICOLON,
    COLON, COMMA, DOT, AT, QUESTION, HASH,

    // Literals
    IDENTIFIER, STRING_LITERAL, NUMBER_LITERAL, BOOLEAN_LITERAL, BINARY_LITERAL, HEX_LITERAL,
    FLOAT_LITERAL, CHAR_LITERAL,

    UNKNOWN, EoF
};

// ====================== STRUCT ======================
struct Token {
    TokenType type;
    std::string value;
    int line;
    int column;

    // Constructor definition can be here because it's short and inline
    Token(TokenType type, const std::string& value, int line, int column)
        : type(type), value(value), line(line), column(column) {}
};

// ====================== CLASS DECLARATION ======================
class Lexer {
public:
    // Constructor declaration
    Lexer(const std::string& source_code);

    // Main lexing function declaration
    std::vector<Token> tokenize();

    // (Optional) Function to get the next token one by one
    // Token getNextToken(); 

private:
    std::string source;
    int current_pos;
    int current_line;
    int current_column;
    std::vector<Token> tokens; // Added to store tokens during tokenization

    // Helper function declarations
    char peek() const; // Added const because it doesn't modify state
    char advance();
    void skipWhitespace();
    void skipComment();
    Token readIdentifier();
    Token readNumber();
    Token readString();
    Token readChar();
    Token readOperator();
    Token readDelimiter();
    Token readBoolean();
    Token readBinaryLiteral();
    Token readHexLiteral();
    Token readFloatLiteral();
    Token readToken(); // This will likely be the main loop function
    void addToken(TokenType type, const std::string& value); // This will add to 'tokens' vector
    void error(const std::string& message);
    // void resetPosition(); // This might not be needed if state is managed correctly
    void updatePosition(char c);
    bool isAtEnd() const; // Added const because it doesn't modify state
};
