#include "string.hpp"
#include "int_array.hpp"
#include "string"

struct Number;
struct BinaryOperation;

struct Visitor {
	virtual void visitNumber(Number const * number) = 0;
	virtual void visitBinaryOperation(BinaryOperation const * binary) = 0;
	virtual ~Visitor() { }
};

struct PrintBinaryOperationsVisitor : Visitor {
	void visitNumber(Number const * number)
	{ }

	void visitBinaryOperation(BinaryOperation const * bop)
	{
		bop->get_left()->visit(this);
		std::cout << bop->get_op() << " ";
		bop->get_right()->visit(this);
	}
};

struct Expression
{
	virtual void visit(Visitor * visitor) const  = 0;
	virtual ~Expression() {};
};

struct Number : Expression
{
	Number(double value)
		: value(value)
	{}
	~Number()
	{}
	double get_value() const { return value; }
	void visit(Visitor * visitor) const { visitor->visitNumber(this); }
private:
	double value;
};

struct BinaryOperation : Expression
{
	BinaryOperation(Expression const * left, char op, Expression const * right)
		: left(left), right(right), op(op)
	{ }
	void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }
	Expression const * get_left()  const { return left; }
	Expression const * get_right() const { return right; }
	char get_op() const { return op; }
	~BinaryOperation()
	{
		delete this->left;
		delete this->right;
	}
private:
	Expression const * left;
	Expression const * right;
	char op;
};

int main()
{
	Expression const * expr = new BinaryOperation(new Number(4.5), '+', new Number(4.5));
	PrintBinaryOperationsVisitor visitor;
	expr->visit(&visitor);
	return (0);
}
