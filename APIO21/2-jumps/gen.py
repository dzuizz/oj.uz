import random

T = 100
content = f"{T}\n"

for _ in range(T):
    N = random.randint(2, 100)
    Q = random.randint(1, 50)
    content += f"{N} {Q}\n"
    l = [i for i in range(N)]
    random.shuffle(l)
    for x in l[:-1]:
        content += f"{x} "
    content += f"{l[-1]}\n"
    for _ in range(Q):
        b = random.randint(0, N - 2)
        c = random.randint(b + 1, N - 1)
        while b == c:
            c = random.randint(b + 1, N - 1)
        a = random.randint(0, b)
        d = random.randint(c, N - 1)
        content += f"{a} {b} {c} {d}\n"


with open("gen.in", "w") as f:
    f.write(content)
