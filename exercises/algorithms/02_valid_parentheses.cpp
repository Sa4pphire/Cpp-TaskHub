#include <cassert>
#include <stack>
#include <string>

bool is_valid_parentheses(const std::string& text) {
    std::stack<char> opened;

    for (const char bracket : text) {
        if (bracket == '(' || bracket == '[' || bracket == '{' ){
            opened.push(bracket);
        }
        if (bracket == ')'){
            if (opened.empty()) 
                return false;
            else
            {
                if (opened.top() == '(')
                    opened.pop();
            }
                        
        }
        if (bracket == ']'){
            if (opened.empty()) 
                return false;
            else
            {
                if (opened.top() == '[')
                    opened.pop();
            }
                        
        }
        if (bracket == '}'){
            if (opened.empty()) 
                return false;
            else
            {
                if (opened.top() == '{')
                    opened.pop();
            }
                        
        }
        // TODO 1：
        // 遇到 '('、'['、'{' 时，将字符放入 opened。
        // TODO 2：
        // 遇到右括号时，先检查 opened 是否为空。

        // TODO 3：
        // 检查 opened.top() 是否与当前右括号匹配。

        // TODO 4：
        // 匹配成功后调用 opened.pop()。
    }
    if (opened.empty())
        return true;
    else  return false;
    
    // TODO 5：
    // 只有栈最终为空，括号才完整匹配。
}

int main() {
    assert(is_valid_parentheses(""));
    assert(is_valid_parentheses("()"));
    assert(is_valid_parentheses("()[]{}"));
    assert(is_valid_parentheses("{[]}"));

    assert(!is_valid_parentheses("(]"));
    assert(!is_valid_parentheses("([)]"));
    assert(!is_valid_parentheses("("));
    assert(!is_valid_parentheses("]"));

    return 0;
}