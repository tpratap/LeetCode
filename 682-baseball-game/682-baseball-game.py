class Solution:
    def calPoints(self, ops: List[str]) -> int:
        stack = []
        for s in ops:
            if s == 'C':
                stack.pop(-1)
            elif s == 'D':
                stack.append(2*stack[-1])
            elif s == '+':
                stack.append(stack[-1] + stack[-2])
            else:
                stack.append(int(s))
        return sum(stack)