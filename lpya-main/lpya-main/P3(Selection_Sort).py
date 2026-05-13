arr = [64, 25, 12, 22, 11]

def print_array(arr):
    for i in range(len(arr)):
        print(arr[i]," ")

for i in range(len(arr)):
    min_index = i
    for j in range(i+1,len(arr)):
        if(arr[j] < arr[min_index]):
            min_index = j
    arr[i],arr[min_index] = arr[min_index],arr[i]
    print(f'{i+1}th iteration : \n')
    print_array(arr)

print("Sorted Array is : \n")
print_array(arr)
