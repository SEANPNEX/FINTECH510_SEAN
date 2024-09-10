def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]  # Current element to be inserted at the correct position
        j = i - 1  # Index of the previous element
        print(f"key:{key},i:{i},j:{j}")
        # Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while j >= 0 and key < arr[j]:
            print(f"before: arr[j+1]:{arr[j+1]},arr[j]:{arr[j]}")
            arr[j + 1] = arr[j]
            print(f"now the array is:{arr}")
            j -= 1
            print(f"now j is {j}")
        arr[j + 1] = key  # Insert the current element at its correct position
        print(f"arr[j+1]:{arr[j+1]}")
        print(f"array now:{arr}\n")

input_array = [12, 11, 13, 5]
print("Original Array:", input_array)
    
insertion_sort(input_array)
    
print("Sorted Array:", input_array)