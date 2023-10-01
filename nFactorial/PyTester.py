import random
import time

def arrayBuild(num):
    return [random.randint(0, 999) for _ in range(num)]

def rearangeArr(arr, start):
    for i in range(start, len(arr)):
        arr[start], arr[i] = arr[i], arr[start]
        rearangeArr(arr, start + 1)
        arr[start], arr[i] = arr[i], arr[start]

if __name__ == "__main__":
    array = arrayBuild(11)

start_time = time.time()
rearangeArr(array, 0)
end_time = time.time()

elapsed_time = end_time - start_time
print(f"{elapsed_time:.5f} sec")