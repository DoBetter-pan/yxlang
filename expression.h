/** 
 * @file expression.h
 * @brief calc expression 
 * @author yingxue
 * @date 2023-10-26
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include <ostream>
#include <stdexcept>
#include <cmath>

class CNCustomFunction;

/** base Yxlang node */
class YxlangNode {
public:
    typedef std::map<std::string, double> variablemap_type;
    static variablemap_type		variables;
    typedef std::map<std::string, CNCustomFunction*> functionmap_type;
    static functionmap_type		functions;

public:
    virtual ~YxlangNode() {
    }

    virtual double	evaluate() const = 0;

    virtual void	print(std::ostream &os, unsigned int depth=0) const = 0;
    static inline std::string indent(unsigned int d) {
        return std::string(d * 2, ' ');
    }

    void setVariable(const std::string &varname, double value) const {
        variables[varname] = value;
    }
    bool existsVariable(const std::string &varname) const {
        return variables.find(varname) != variables.end();
    }
    double getVariable(const std::string &varname) const {
        variablemap_type::const_iterator vi = variables.find(varname);
        if (vi == variables.end())
            return 0;
        else
            return vi->second;
    }

    void setFunction(const std::string &funcname, const CNCustomFunction* value) const {
        functions[funcname] = const_cast<CNCustomFunction*>(value);
    }
    bool existsFunction(const std::string &funcname) const {
        return functions.find(funcname) != functions.end();
    }
    CNCustomFunction* getFunction(const std::string &funcname) const {
        functionmap_type::const_iterator vi = functions.find(funcname);
        if (vi == functions.end())
            return NULL;
        else
            return vi->second;
    }
};

/** constant Yxlang node  */
class CNConstant : public YxlangNode {
    double	value;
    
public:
    explicit CNConstant(double _value) : YxlangNode(), value(_value) {
    }

    virtual double evaluate() const {
        return value;
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << value << std::endl;
    }
};

/** variable Yxlang node  */
class CNVariable : public YxlangNode {
    double	value;
    std::string* name;

public:
    explicit CNVariable(std::string* _name) : YxlangNode(), name(_name) {
    }

    virtual ~CNVariable() {
        delete name;
    }

    virtual double evaluate() const {
        double v = 0;
        if (existsVariable(*name)) {
            v = getVariable(*name);
        }
        return v;
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << *name << ":" << value << std::endl;
    }
};

/** negate Yxlang node  */
class CNNegate : public YxlangNode {
    YxlangNode* 	node;

public:
    explicit CNNegate(YxlangNode* _node) : YxlangNode(), node(_node) {
    }

    virtual ~CNNegate() {
        delete node;
    }

    virtual double evaluate() const {
        return - node->evaluate();
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << "- negate" << std::endl;
        node->print(os, depth+1);
    }
};

/** add Yxlang node */
class CNAdd : public YxlangNode {
    YxlangNode* 	left;
    YxlangNode* 	right;
    
public:
    explicit CNAdd(YxlangNode* _left, YxlangNode* _right) : YxlangNode(), left(_left), right(_right) {
    }

    virtual ~CNAdd() {
        delete left;
        delete right;
    }

    virtual double evaluate() const {
        return left->evaluate() + right->evaluate();
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << "+ add" << std::endl;
        left->print(os, depth+1);
        right->print(os, depth+1);
    }
};

/** subtract Yxlang node */
class CNSubtract : public YxlangNode {
    YxlangNode* 	left;
    YxlangNode* 	right;
    
public:
    explicit CNSubtract(YxlangNode* _left, YxlangNode* _right) : YxlangNode(), left(_left), right(_right) {
    }

    virtual ~CNSubtract() {
        delete left;
        delete right;
    }

    virtual double evaluate() const {
        return left->evaluate() - right->evaluate();
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << "- subtract" << std::endl;
        left->print(os, depth+1);
        right->print(os, depth+1);
    }
};

/** multiply Yxlang node */
class CNMultiply : public YxlangNode {
    YxlangNode* 	left;
    YxlangNode* 	right;
    
public:
    explicit CNMultiply(YxlangNode* _left, YxlangNode* _right) : YxlangNode(), left(_left), right(_right) {
    }

    virtual ~CNMultiply() {
        delete left;
        delete right;
    }

    virtual double evaluate() const {
        return left->evaluate() * right->evaluate();
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << "* multiply" << std::endl;
        left->print(os, depth+1);
        right->print(os, depth+1);
    }
};

/** divide Yxlang node */
class CNDivide : public YxlangNode {
    YxlangNode* 	left;
    YxlangNode* 	right;
    
public:
    explicit CNDivide(YxlangNode* _left, YxlangNode* _right) : YxlangNode(), left(_left), right(_right) {
    }

    virtual ~CNDivide() {
        delete left;
        delete right;
    }

    virtual double evaluate() const {
        return left->evaluate() / right->evaluate();
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << "/ divide" << std::endl;
        left->print(os, depth+1);
        right->print(os, depth+1);
    }
};

/** modulo Yxlang node */
class CNModulo : public YxlangNode {
    YxlangNode* 	left;
    YxlangNode* 	right;
    
public:
    explicit CNModulo(YxlangNode* _left, YxlangNode* _right) : YxlangNode(), left(_left), right(_right) {
    }

    virtual ~CNModulo() {
        delete left;
        delete right;
    }

    virtual double evaluate() const {
        return std::fmod(left->evaluate(), right->evaluate());
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << "% modulo" << std::endl;
        left->print(os, depth+1);
        right->print(os, depth+1);
    }
};

/** power Yxlang node */
class CNPower : public YxlangNode {
    YxlangNode* 	left;
    YxlangNode* 	right;
    
public:
    explicit CNPower(YxlangNode* _left, YxlangNode* _right) : YxlangNode(), left(_left), right(_right) {
    }

    virtual ~CNPower() {
        delete left;
        delete right;
    }

    virtual double evaluate() const {
        return std::pow(left->evaluate(), right->evaluate());
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << "^ power" << std::endl;
        left->print(os, depth+1);
        right->print(os, depth+1);
    }
};

/** compare Yxlang node */
class CNCompare : public YxlangNode {
    int             fn;
    YxlangNode* 	left;
    YxlangNode* 	right;
    
public:
    explicit CNCompare(int _fn, YxlangNode* _left, YxlangNode* _right) : YxlangNode(), fn(_fn), left(_left), right(_right) {
    }

    virtual ~CNCompare() {
        delete left;
        delete right;
    }

    virtual double evaluate() const {
        int v = 0;
        double leftValue = left->evaluate();
        double rightValue = right->evaluate();
        switch (fn) {
            case 1: {
                v = leftValue > rightValue ? 1 : 0;
                break;
            }
            case 2: {
                v = leftValue < rightValue ? 1 : 0;
                break;
            }
            case 3: {
                v = leftValue != rightValue ? 1 : 0;
                break;
            }
            case 4: {
                v = leftValue == rightValue ? 1 : 0;
                break;
            }
            case 5: {
                v = leftValue >= rightValue ? 1 : 0;
                break;
            }
            case 6: {
                v = leftValue <= rightValue ? 1 : 0;
                break;
            }
        }
        return v;
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << fn << " compare" << std::endl;
        left->print(os, depth+1);
        right->print(os, depth+1);
    }
};

/** unary function Yxlang node */
class CNUnaryFunction : public YxlangNode {
    int             fn;
    YxlangNode* 	left;
    YxlangNode* 	right;
    
public:
    explicit CNUnaryFunction(int _fn, YxlangNode* _left, YxlangNode* _right = NULL) : YxlangNode(), fn(_fn), left(_left), right(_right) {
    }

    virtual ~CNUnaryFunction() {
        delete left;
    }

    virtual double evaluate() const {
        double v = 0;
        double leftValue = left->evaluate();
        switch (fn) {
            case 1: {
                v = sqrt(leftValue);
                break;
            }
            case 2: {
                v = exp(leftValue);
                break;
            }
            case 3: {
                v = log(leftValue);
                break;
            }
            case 4: {
                std::cout << "= " << v << std::endl;
                v = leftValue;
                break;
            }
        }
	    return v;
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << fn << " unaryfunction" << std::endl;
        left->print(os, depth+1);
    }
};

/** baniry function Yxlang node */
class CNBinaryFunction : public YxlangNode {
    int             fn;
    YxlangNode* 	left;
    YxlangNode* 	right;
    
public:
    explicit CNBinaryFunction(int _fn, YxlangNode* _left, YxlangNode* _right ) : YxlangNode(), fn(_fn), left(_left), right(_right) {
    }

    virtual ~CNBinaryFunction() {
        delete left;
        delete right;
    }

    virtual double evaluate() const {
        double leftValue = left->evaluate();
        double rightValue = right->evaluate();
        double v = 0;
        switch (fn) {
            case 1: {
                v = pow(leftValue, rightValue);
                break;
            }
        }

	    return v;
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << fn << " binaryfunction" << std::endl;
        left->print(os, depth+1);
        right->print(os, depth+1);
    }
};

/** exprlist Yxlang node */
class CNExprlist : public YxlangNode {
public:
    YxlangNode* 	left;
    YxlangNode* 	right;
    
public:
    explicit CNExprlist(YxlangNode* _left, YxlangNode* _right = NULL) : YxlangNode(), left(_left), right(_right) {
    }

    virtual ~CNExprlist() {
        delete left;
        delete right;
    }

    virtual double evaluate() const {
        double leftValue = left->evaluate();
        //double rightValue = right->evaluate();
	    return leftValue;
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << " exprlist" << std::endl;
        left->print(os, depth+1);
        if (right) {
            right->print(os, depth+1);
        }
    }
};

/** assignment Yxlang node */
class CNAssignment : public YxlangNode {
    std::string* 	name;
    YxlangNode* 	left;
    YxlangNode* 	right;
    
public:
    explicit CNAssignment(std::string* _name, YxlangNode* _left = NULL) : YxlangNode(), name(_name), left(_left) {
    }

    virtual ~CNAssignment() {
        delete name;
        delete left;
    }

    virtual double evaluate() const {
        double v = 0;
        v = left->evaluate();
        setVariable(*name, v);
        return v;
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << " assignment:" << *name << std::endl;
        left->print(os, depth+1);
    }
};

/** condition Yxlang node */
class CNCondition : public YxlangNode {
    YxlangNode* 	cond;
    YxlangNode* 	left;
    YxlangNode* 	right;
    
public:
    explicit CNCondition(YxlangNode* _cond, YxlangNode* _left, YxlangNode* _right = NULL) : YxlangNode(), cond(_cond), left(_left), right(_right) {
    }

    virtual ~CNCondition() {
        delete cond;
        delete left;
        delete right;
    }

    virtual double evaluate() const {
        double v = 0;
        int k = cond->evaluate();
        if (k != 0) {
            v = left->evaluate();
        } else {
            if (right) {
                v = right->evaluate();
            }
        }
        return v;
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << " condition" << std::endl;
        cond->print(os, depth+1);
        left->print(os, depth+1);
        if (right) {
            right->print(os, depth+1);
        }
    }
};

/** statement Yxlang node */
class CNStatement : public YxlangNode {
    YxlangNode* 	left;
    YxlangNode* 	right;
    
public:
    explicit CNStatement(YxlangNode* _left, YxlangNode* _right = NULL) : YxlangNode(), left(_left), right(_right) {
    }

    virtual ~CNStatement() {
        delete left;
        delete right;
    }

    virtual double evaluate() const {
        double v = 0;
        v = left->evaluate();
        v = right->evaluate();
        return v;
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << " statement" << std::endl;
        left->print(os, depth+1);
        right->print(os, depth+1);
    }
};

/** paramlist Yxlang node */
class CNParamlist : public YxlangNode {
public:
    std::string* 	name;
    YxlangNode* 	left;
    YxlangNode* 	right;
    
public:
    explicit CNParamlist(std::string* _name, YxlangNode* _left,  YxlangNode* _right = NULL) : YxlangNode(), name(_name), left(_left), right(_right) {
    }

    virtual ~CNParamlist() {
        delete name;
        delete left;
        delete right;
    }

    virtual double evaluate() const {
        double v = 0;
        return v;
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << " paramlist: " << *name << std::endl;
        if (left){
            left->print(os, depth+1);
        }
        if (right) {
            right->print(os, depth+1);
        }
    }
};

/** custom function Yxlang node */
class CNCustomFunction : public YxlangNode {
public:
    std::string*     name;
    /// paramlist
    YxlangNode* 	left;
    /// sentencelist
    YxlangNode* 	right;
    
public:
    explicit CNCustomFunction(std::string* _name, YxlangNode* _left, YxlangNode* _right) : YxlangNode(), name(_name), left(_left), right(_right) {
    }

    virtual ~CNCustomFunction() {
        /// delete name;
        /// delete left;
        /// delete right;
    }

    virtual double evaluate() const {
        double v = 0;
        CNCustomFunction* copy = new CNCustomFunction(name, left, right);
        setFunction(*name, copy);
        return v;
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << " function:" << *name << std::endl;
        left->print(os, depth+1);
        right->print(os, depth+1);
    }
};

/** call UDF Yxlang node */
class CNCallUDF : public YxlangNode {
    std::string*     name;
    /// exprlist
    YxlangNode* 	left;
    YxlangNode* 	right;
    
public:
    explicit CNCallUDF(std::string* _name, YxlangNode* _left, YxlangNode*  _right = NULL) : YxlangNode(), name(_name), left(_left), right(_right) {
    }

    virtual ~CNCallUDF() {
        delete name;
        delete left;
        delete right;
    }

    virtual double evaluate() const {
        double v = 0;
        CNCustomFunction* func = getFunction(*name);
        if (func) {
            std::map<std::string, double> oldVal;
            CNParamlist* paramnode = dynamic_cast<CNParamlist*>(func->left);
            CNExprlist* exprnode = dynamic_cast<CNExprlist*>(left);
            while (paramnode) {
                std::string* varname = paramnode->name;
                oldVal[*varname] = getVariable(*varname);
                double val = 0;
                if (exprnode) {
                    val = exprnode->left->evaluate();
                    exprnode = dynamic_cast<CNExprlist*>(exprnode->right);
                }
                setVariable(*varname, val);
                paramnode = dynamic_cast<CNParamlist*>(paramnode->left);
            }

            v = func->right->evaluate();
            /* restore old values */
            paramnode = dynamic_cast<CNParamlist*>(func->left);
            while (paramnode) {
                std::string* varname = paramnode->name;
                setVariable(*varname, oldVal[*varname]);
                paramnode = dynamic_cast<CNParamlist*>(paramnode->right);
            }
        }
        return v;
    }

    virtual void print(std::ostream &os, unsigned int depth) const {
        os << indent(depth) << " call UDF:" << *name << std::endl;
        left->print(os, depth+1);
        if (right) {
            right->print(os, depth+1);
        }
    }
};

/** Yxlang context  */
class YxlangContext {
public:
    typedef std::map<std::string, double> variablemap_type;
    variablemap_type		variables;
    std::vector<YxlangNode*>	expressions;

    ~YxlangContext() {
        clearExpressions();
    }

    void clearExpressions() {
        for(unsigned int i = 0; i < expressions.size(); ++i) {
            delete expressions[i];
        }
        expressions.clear();
    }

    bool existsVariable(const std::string &varname) const {
        return variables.find(varname) != variables.end();
    }
    double	getVariable(const std::string &varname) const {
        variablemap_type::const_iterator vi = variables.find(varname);
        if (vi == variables.end())
            return 0;
        else
            return vi->second;
    }
};

#endif // EXPRESSION_H
