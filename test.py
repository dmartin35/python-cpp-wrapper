import demo

msg = 'This is a simple message!'
echoed = demo.echo(msg)
assert type(echoed) == str
assert echoed == msg

today = demo.now()
assert type(today) == dict

sum = demo.addition(5, 6)
assert type(sum) == int
assert sum == 11
