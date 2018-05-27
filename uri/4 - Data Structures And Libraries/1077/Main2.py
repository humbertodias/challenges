prec = {'(':1, '+':2, '-':2, '*':3, '/':3, '^':4}
operand = '()+-*/^'

def split_equation(infix):
    equation = []
    num = ''
    for c in infix:
        if c in operand:
            if num != '':
                equation.append(num)
            num = ''
            equation.append(c)
        else:
            num += c
    if num != '':
        equation.append(num)

    return equation

def infix_to_posfix(infix):
    posfix = []
    stack = []
    for e in infix:
        if e in operand:
            if e == '(':
                stack.append(e)
            elif e == ')':
                while stack[-1] != '(':
                    posfix.append(stack.pop())
                stack.pop()
            else:
                while True:
                    if len(stack) == 0 or prec[e] > prec[stack[-1]]: break
                    posfix.append(stack.pop())
                stack.append(e)
        else:
            posfix.append(e)

    while len(stack) > 0:
        posfix.append(stack.pop())

    return ''.join(posfix)


nTests = int(raw_input())
for nt in xrange(nTests):
    infix = raw_input()
    print infix_to_posfix(infix)