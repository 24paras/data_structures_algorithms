size = int(input("Enter size of array: "))
print(size)

array = []

print("Enter the array elements: ")
element = input().split(' ')
for i in range(0, size):
    array.append(int(element[i]))

for j in range(0, size):
    for l in range(size-1, 0, -1):
        if array[l] < array[l-1]:
            array[l], array[l-1] = array[l-1], array[l]
print(array)
