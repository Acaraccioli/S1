#include  <vector>
enum class Symbol: unsigned {
    input = 0,
    stmlist = 1,
    expr = 2,
    stmlistprime = 3,
    term = 4,
    exprprime = 5,
    factor = 6,
    termprime = 7,
    Eof = 8,
    Semicolon = 9,
    OpAdd = 10,
    exprprimerime = 11,
    OpSub = 12,
    OpMul = 13,
    OpDiv = 14,
    Number = 15,
    Ident = 16,
    OpenPar = 17,
    ClosePar = 18,
    Epsilon = 19
};

static inline unsigned indexOf(Symbol s) {
    unsigned index = static_cast<unsigned>(s);
    if (index < 8) return index;
    else return (index - 8);
}

static inline bool isTerminal(Symbol s) {
    return static_cast<unsigned>(s) >= 8;
}

struct Rule {
    Symbol lhs;
    std::vector<Symbol> rhs;
    bool isEmpty() const { return rhs.empty(); }
};

Rule none;
std::vector<std::vector<Rule>> ll1_table = {
    /* input */ { none, none, none, none, none, none, none, {Symbol::input, {Symbol::stmlist, Symbol::Semicolon, }}, {Symbol::input, {Symbol::stmlist, Symbol::Semicolon, }}, {Symbol::input, {Symbol::stmlist, Symbol::Semicolon, }}, none, },
    /* stmlist */ { none, none, none, none, none, none, none, {Symbol::stmlist, {Symbol::expr, Symbol::stmlistprime, }}, {Symbol::stmlist, {Symbol::expr, Symbol::stmlistprime, }}, {Symbol::stmlist, {Symbol::expr, Symbol::stmlistprime, }}, none, },
    /* expr */ { none, none, none, none, none, none, none, {Symbol::expr, {Symbol::term, Symbol::exprprime, }}, {Symbol::expr, {Symbol::term, Symbol::exprprime, }}, {Symbol::expr, {Symbol::term, Symbol::exprprime, }}, none, },
    /* stmlistprime */ { none, {Symbol::stmlistprime, {Symbol::Semicolon, Symbol::expr, Symbol::stmlistprime, }}, none, none, none, none, none, none, none, none, none, },
    /* term */ { none, none, none, none, none, none, none, {Symbol::term, {Symbol::factor, Symbol::termprime, }}, {Symbol::term, {Symbol::factor, Symbol::termprime, }}, {Symbol::term, {Symbol::factor, Symbol::termprime, }}, none, },
    /* exprprime */ { none, none, {Symbol::exprprime, {Symbol::OpAdd, Symbol::term, Symbol::exprprimerime, }}, none, {Symbol::exprprime, {Symbol::OpSub, Symbol::term, Symbol::exprprime, }}, {Symbol::exprprime, {Symbol::OpMul, Symbol::term, Symbol::exprprime, }}, {Symbol::exprprime, {Symbol::OpDiv, Symbol::term, Symbol::exprprime, }}, none, none, none, none, },
    /* factor */ { none, none, none, none, none, none, none, {Symbol::factor, {Symbol::Number, }}, {Symbol::factor, {Symbol::Ident, }}, {Symbol::factor, {Symbol::OpenPar, Symbol::expr, Symbol::ClosePar, }}, none, },
    /* termprime */ { none, none, none, none, none, {Symbol::termprime, {Symbol::OpMul, Symbol::factor, Symbol::termprime, }}, none, none, none, none, none, },
};
