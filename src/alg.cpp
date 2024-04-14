// Copyright 2021 NNTU-CS
#include <iostream>
#include <string>
#include <stack>
#include <queue>

int getPr(char inf) {
  switch (inf) {
  case '+':
  case '-':
    return 1;
    break;
  case '*':
  case '/':
    return 2;
    break;
  default:
    return 0;
    break;
  }
}
string infx2pstfx(string inf) {
  string str = "";
  stack<char> stack1;
  queue<char> queue;
  for (int i = 0; i < inf.length(); ++i) {
    if (inf[i] >= '0' && inf[i] <= '9') {
      queue.push(inf[i]);
      continue;
    }
    else {
      if (inf[i] == '(') {
        stack1.push(inf[i]);
        continue;
      }
      if (inf[i] == ')') {
        while ((!(stack1.empty()))) {
          if (stack1.top() == '(') {
            stack1.pop();
            continue;
          }
          queue.push(stack1.top());
          stack1.pop();
        }
        continue;
      }
      if (stack1.empty() || ((stack1.top()) == '(')) {
        stack1.push(inf[i]);
        continue;
      }
      if (getPr(inf[i]) > getPr(stack1.top())) {
        stack1.push(inf[i]);
        continue;
      }
      if (getPr(inf[i]) <= getPr(stack1.top())) {
        while (!(stack1.empty())) {
          if ((getPr(inf[i]) <= getPr(stack1.top())) || ((stack1.top()) == '(')) {
            queue.push(stack1.top());
            stack1.pop();
          }
        }
        stack1.push(inf[i]);
        continue;
      }
    }
  }
  while (!(stack1.empty())) {
    if ((stack1.top() == '(') || (stack1.top() == ')')) {
      stack1. pop();
    }
    queue.push(stack1.top());
    stack1.pop();
  }
  while ((!(queue.empty()))) {
    str += queue.front();
    queue.pop();
  }
  return str;
}
// вычисление выражения, записанного в постфиксной форме
int eval(string post) {
  int res = 0;
  stack<int> stack1;
  for (int i = 0; i < post.length(); ++i) {
    if (post[i] >= '0' && post[i] <= '9') {
      stack1.push(post[i]-48);
    }
    else {
      int b = stack1.top();
      stack1.pop();
      int a = stack1.top();
      stack1.pop();
      switch (post[i])
      {
      case '+':
        stack1.push(a + b);
        break;
      case '-':
        stack1.push(a - b);
        break;
      case '*':
        stack1.push(a * b);
        break;
      case '/':
        stack1.push(a / b);
        break;
      default:
        break;
      }
    }
  }
  res = stack1.top();
  return res;
}
