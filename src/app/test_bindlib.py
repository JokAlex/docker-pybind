import bindlib


def test_answer():
    assert(bindlib.answer() == 42)


def test_base():
    base = bindlib.Base()
    assert(base.greet() == "Hello from Base")
    assert(base.virtualMethod() == "Virtual method in Base")
    assert(base.staticMethod() == "Static method")


def test_derived():
    derived = bindlib.Derived()
    assert(derived.greet() == "Hello from Base")
    assert(derived.virtualMethod() == "Overridden method in Derived")
    assert(derived.staticMethod() == "Static method")


def test_list_operator():
    op = bindlib.DoubleListOperator([1.0, 2.0, 6.0, 24.0])
    assert(list(op) == [1.0, 2.0, 6.0, 24.0])
    op.map(lambda x: x ** 2)
    assert(list(op) == [1.0, 4.0, 36.0, 576.0])
    assert(op.reduce(1, lambda x, y: x * y) == 82944)


def test_dict_to_str():
    assert(bindlib.dictToStr({
        'a': 1,
        'b': 1,
        'c': 2,
        'd': 3
        }) == "{\n\t'a': 1,\n\t'b': 1,\n\t'c': 2,\n\t'd': 3,\n}\n")
