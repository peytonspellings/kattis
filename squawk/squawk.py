from collections import Counter


def main():
    n, m, s, t = map(int, input().split())
    edges = {}
    for _ in range(m):
        x, y = map(int, input().split())
        edges.setdefault(x, []).append(y)
        edges.setdefault(y, []).append(x)
    infected = Counter({s:1})
    for round in range(t):
        squawks_next = Counter()
        for squawker, squawks in infected.items():
            for target_node in edges[squawker]:
                squawks_next.update({target_node: squawks})
        infected = squawks_next
    try:
        print(sum(squawks_next.values()))
    except NameError:
        print(0)


if __name__ == '__main__':
    main()