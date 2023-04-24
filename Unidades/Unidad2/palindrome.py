def is_palindrome(s):
    if len(s) <= 1:
        return True
    if s[0] == s[-1]:
        return is_palindrome(s[1:-1])
    return False


input_str = input("Enter a word or phrase: ")
if is_palindrome(input_str):
    print(input_str, "is a palindrome")
else:
    print(input_str, "is not a palindrome")



