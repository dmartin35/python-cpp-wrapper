import demo


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
    assert type(sum) in (int, long)
    assert sum == 11
