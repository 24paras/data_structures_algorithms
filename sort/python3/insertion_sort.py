size = int(input("Enter size of your array: "))
arr = []
element = input("Enter array elements: ").split(' ')
for i in range(0, size):
    arr.append(int(element[i]))

for j in range(1, size):
    key = arr[j]
    i = j-1
    while i>=0 and arr[i]>key:
        arr[i+1]=arr[i]
        i=i-1
    arr[i+1]=key    
        
print("After insertion sort, array is: ", arr)
