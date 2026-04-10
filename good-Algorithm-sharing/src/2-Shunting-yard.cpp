#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 判断是否为运算符
bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

// 获取运算符优先级
int priority(char c) {
	if(c == '*' || c == '/') return 2;
	if(c == '+' || c == '-') return 1;
	return 0; // 代表这是括号，虽然括号优先级最高，但为了不同情况弹栈入栈操作逻辑的一致性，还是把括号的优先级设为了 0
}

// 调度场算法 ---> 中缀转为后缀
string Fix(string inf) {
	stack<char> op; 
	// 运算符栈
	string pos;
	// inf 为中缀表达式，pos 为后缀表达式结果
	
	for(char c : inf) {
		// 情况1：数字 → 直接加入结果
		if(isdigit(c)) {
			pos += c;
		}
		// 情况2：左括号 → 入栈
		else if(c == '(') {
			op.push(c);
		}
		// 情况3：右括号 → 弹出直到左括号
		else if(c == ')') {
			while(!op.empty() && op.top() != '(') {
				pos += op.top();
				op.pop();
			}
			op.pop(); // 丢弃左括号
		}
		// 情况4：运算符 → 按优先级处理
		else if(isOperator(c)) {
			while(!op.empty() && priority(op.top()) >= priority(c)) {
				pos += op.top();
				op.pop();
			}
			op.push(c);
		}
	}
	// 弹出栈中剩余运算符
	while(!op.empty()) {
		pos += op.top();
		op.pop();
	}
	return pos;
}

int main() {
	string inf = "1*3-4*2/(5-1)";
	cout << "后缀表达式：" << Fix(inf) << endl;
	// 输出：13*42*51-/-
	return 0;
}