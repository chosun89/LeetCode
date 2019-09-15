class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = [[]]

        for c in s:
            if (c == '('):
                stack.append([])

            elif (c == ')'):
                last = stack[-1]
                stack.pop()
                for cc in reversed(last):
                    stack[-1].append(cc)

            else:
                stack[-1].append(c)

        ans = ""
        for c in stack[0]:
            ans += c
        return ans


s = Solution()
print(s.reverseParentheses("(u(love)i)"))
