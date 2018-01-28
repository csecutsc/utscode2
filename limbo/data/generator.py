from random import randint

def put_to_file(r, d, fil, out):
    with open(fil, 'w') as f:
        f.seek(0,0)
        f.write(str(r) + ' ' + str(d) + '\n')
        f.close()

    with open(out, 'w') as f:
        f.seek(0,0)
        f.write(str(int(r * (r + 1) / 2 + (d -1)*r + (d - 2)*(d - 1) / 2)) + '\n')
        f.close()

for i in range(30):
    if i > 10:
        r = randint(0, 2**31 - 1)
        d = randint(0, 2**31 - 1)
    else:
        r = randint(0, 2**8)
        d = randint(0, 2**8)
    put_to_file(r, d, 'secret/{testcase}.in'.format(testcase=i), 'secret/{testcase}.ans'.format(testcase=i))

put_to_file(3, 2, 'sample/{testcase}.in'.format(testcase=1), 'sample/{testcase}.ans'.format(testcase=1))
put_to_file(5, 8, 'sample/{testcase}.in'.format(testcase=2), 'sample/{testcase}.ans'.format(testcase=2))
