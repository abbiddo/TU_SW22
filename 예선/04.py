j,n,m = map(int, input().split())
a = input().split()
b = input().split()

a.reverse()
b.reverse()

a_sum = int(a[0])
b_sum = int(b[0])

a.pop(0)
b.pop(0)

k = j
for i in a:
    a_sum += k * int(i)
    k *= j
    
k = j
for i in b:
    b_sum += k * int(i)
    k *= j
    
a_sum *= b_sum


re = []
while (a_sum):
    re.insert(0, a_sum % j)
    a_sum //= j

print(len(re))
for i in range(len(re)):
    print(re[i], end=' ')
