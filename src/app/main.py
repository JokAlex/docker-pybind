import bindlib


def test_answer():
    print(bindlib.answer())
    help(bindlib.answer)


def test_print_map():
    bindlib.printMap({
        'a': 1,
        'b': 1,
        'c': 2,
        'd': 3
    })


def test_base():
    b = bindlib.Base()
    print(b.greet(), type(b))
    print(b.virtualMethod())
    print(bindlib.Base.staticMethod())


def test_derived():
    d = bindlib.Derived()
    print(d.greet(), type(d))
    print(d.virtualMethod())
    print(bindlib.Derived.staticMethod())


def test_list_operator():
    op = bindlib.DoubleListOperator([1.0, 2.0, 6.0, 24.0])
    for e in op:
        print(e)
    op.map(lambda x: x ** 2)
    for e in op:
        print(e)
    print(list(op))
    print("reduction =", op.reduce(1, lambda x, y: x * y))


def main():
    test_answer()
    print("-" * 30)
    test_base()
    print("-" * 30)
    test_derived()
    print("-" * 30)
    test_list_operator()
    print("-" * 30)
    test_print_map()


if __name__ == '__main__':
    main()
