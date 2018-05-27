while True:
    try:
        x, y = map(int, raw_input().split())
        print abs(x - y)
    except EOFError:
        break