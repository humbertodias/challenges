def conjuntos(y):
    if ((y["um"] == 1 and y["dois"] and 1 and y["tres"] == 1) or (y["um"] == 3 or y["dois"] == 3 or y["tres"] == 3)):
        y["conj"] += 1
        y["um"] = y["dois"] = y["tres"] = 0
        return y
    return y
    

if __name__ == "__main__":
    try:
        while True:
            lista = ["um","dois","tres"]
            dic = {"um": 0,"dois": 0,"tres":0, "conj": 0}
            vezes = int(input())
            if vezes == 0: break
            for x in range(vezes):
                carta = input().split()
                dic[carta[0]] += 1
                if ((x + 1) % 3 == 0):
                    dic = conjuntos(dic)
            print(dic["conj"])
    except EOFError:
        pass