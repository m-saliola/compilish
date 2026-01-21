#include <vector>
#include <string>
#include <memory>

enum class NodeType {
    Program,
    NumericLiteral,
    Identifier,
    BinaryExpr,
};

class Stmt {
public:
    const NodeType kind;

    inline explicit Stmt(NodeType kind) : kind(kind) { }
    virtual ~Stmt() = default;
};

class Program : public Stmt {
public:
    std::vector<std::unique_ptr<Stmt>> body;

    inline Program() : Stmt(NodeType::Program) { }
};

class Expr : public Stmt {
protected:
    explicit Expr(NodeType kind) : Stmt(kind) {}
};

class BinaryExpr : public Expr {
public:
    std::unique_ptr<Expr> left;
    std::unique_ptr<Expr> right;
    std::string op;

    inline BinaryExpr(std::unique_ptr<Expr> left, std::unique_ptr<Expr> right, std::string op) : Expr(NodeType::BinaryExpr), left(std::move(left)), right(std::move(right)), op(op) { }
};

class Identifier : public Expr {
public:
    std::string symbol;

    inline Identifier() : Expr(NodeType::Identifier) { }
};

class NumericLiteral : public Expr {
public:
    std::string value;

    inline NumericLiteral() : Expr(NodeType::NumericLiteral) { }
};
