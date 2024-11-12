#ifndef PARSER_HPP
#define PARSER_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include "expr.hpp"

class Expression {
public:
    virtual ~Expression() {}
    virtual std::string toString() const = 0;
    virtual long evaluate() const = 0;
};

class NumExpression : public Expression {
private:
    long value;

public:
    explicit NumExpression(long val) : value(val) {}

    std::string toString() const override {
        return std::to_string(value);
    }

    long evaluate() const override {
        return value;
    }
};

class PlusExpression : public Expression {
private:
    Expression *lhs;
    Expression *rhs;

public:
    PlusExpression(Expression *left, Expression *right) : lhs(left), rhs(right) {}
    ~PlusExpression() override {
        delete lhs;
        delete rhs;
    }

    std::string toString() const override {
        return "(" + lhs->toString() + " + " + rhs->toString() + ")";
    }

    long evaluate() const override {
        return lhs->evaluate() + rhs->evaluate();
    }
};

class MinusExpression : public Expression {
private:
    Expression *lhs;
    Expression *rhs;

public:
    MinusExpression(Expression *left, Expression *right) : lhs(left), rhs(right) {}
    ~MinusExpression() override {
        delete lhs;
        delete rhs;
    }

    std::string toString() const override {
        return "(" + lhs->toString() + " - " + rhs->toString() + ")";
    }

    long evaluate() const override {
        return lhs->evaluate() - rhs->evaluate();
    }
};

class TimesExpression : public Expression {
private:
    Expression *lhs;
    Expression *rhs;

public:
    TimesExpression(Expression *left, Expression *right) : lhs(left), rhs(right) {}
    ~TimesExpression() override {
        delete lhs;
        delete rhs;
    }

    std::string toString() const override {
        return "(" + lhs->toString() + " * " + rhs->toString() + ")";
    }

    long evaluate() const override {
        return lhs->evaluate() * rhs->evaluate();
    }
};

class DivExpression : public Expression {
private:
    Expression *lhs;
    Expression *rhs;

public:
    DivExpression(Expression *left, Expression *right) : lhs(left), rhs(right) {}
    ~DivExpression() override {
        delete lhs;
        delete rhs;
    }

    std::string toString() const override {
        return "(" + lhs->toString() + " / " + rhs->toString() + ")";
    }

    long evaluate() const override {
        return lhs->evaluate() / rhs->evaluate();
    }
};



Expression * parse(std::string &line);

extern const std::string OPERATORS;

static inline void ltrim(std::string &s);

void consumeInput(std::string &s, size_t length);

Expression * makeExpr(char op, Expression * lhs, Expression * rhs);

bool isValidOp(char c);

Expression * parseOp(std::string &line);

#endif 
