import demo
import sys


if sys.version_info < (3,):
    integer_types = (int, long,)
else:
    integer_types = (int,)


def test_echo():
    msg = 'This is a simple message!'
    echoed = demo.echo(msg)
    assert type(echoed) == str
    assert echoed == msg


def test_now():
    today = demo.now()
    assert type(today) == dict


def test_addition():
    sum = demo.addition(5, 6)
    assert type(sum) in integer_types
    assert sum == 11
