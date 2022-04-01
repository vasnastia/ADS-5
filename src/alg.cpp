// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prioritet(char operat) {
    switch (operat) {
    case '(': return 0;
    case ')': return 1;
    case '+': return 2;
    case '-': return 2;
    case '/': return 3;
    case '*': return 3;
    case ' ': return 5;
    default: return 4;
    }
}
int calc(char operat, int m, int n) {
    switch (operat) {
    case '+': return (n + m);
    case '-': return (n - m);
    case '*': return (n * m);
    case '/':
        if (m != 0)
            return n / m;
    default: return 0;
    }
}
std::string infx2pstfx(std::string inf) {
    std::string output;
    char space = ' ';
    TStack <char, 100> stack;
    for (int i = 0; i < inf.size(); i++) {
        if (prioritet(inf[i]) == 4) {
            output.push_back(inf[i]);
            output.push_back(space);
        } else {
            if (prioritet(inf[i]) == 0) {
                stack.push(inf[i]);
            } else if (stack.isEmpty()) {
                stack.push(inf[i]);
            } else if ((prioritet(inf[i]) > prioritet(stack.get()))) {
                stack.push(inf[i]);
            } else if (prioritet(inf[i]) == 1) {
                while (prioritet(stack.get()) != 0) {
                    output.push_back(stack.get());
                    output.push_back(space);
                    stack.pop();
                }
                stack.pop();
            } else {
                while (!stack.isEmpty() && (prioritet(inf[i]) <= prioritet(stack.get()))) {
                    output.push_back(stack.get());
                    output.push_back(space);
                    stack.pop();
                }
                stack.push(inf[i]);
            }
        }
    }
    while (!stack.isEmpty()) {
        output.push_back(stack.get());
        output.push_back(space);
        stack.pop();
    }
    for (int j = 0; j < output.size(); j++) {
        if (output[output.size() - 1] == ' ')
            output.erase(output.size() - 1);
    }
    return output;
}
int eval(std::string pref) {
    TStack <int, 100> stack1;
    int result = 0;

    for (int k = 0; k < pref.size(); k++) {
        if (prioritet(pref[k]) == 4) {
            stack1.push(pref[k] - '0');
        } else if (prioritet(pref[k]) < 4) {
            int a = stack1.get();
            stack1.pop();
            int b = stack1.get();
            stack1.pop();
            stack1.push(calc(pref[k], a, b));
        }
    }
    result = stack1.get();
    return result;
}
