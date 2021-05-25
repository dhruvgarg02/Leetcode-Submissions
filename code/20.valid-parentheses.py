class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        ref = {
            ")":"(",
            "}":"{",
            "]":"["
        }
        for i in s:
            if i in ref.values():
                stack.append(i)
            elif i in ref.keys():
                if not stack or ref[i] != stack.pop():
                    return False
        return not stack