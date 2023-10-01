import random
import time
import itertools

def arrayBuild(num):
    return [random.randint(0, 999) for _ in range(num)]

if __name__ == "__main__":
    array = arrayBuild(11)

    start_time = time.time()
    all_permutations = list(itertools.permutations(array))
    end_time = time.time()

    elapsed_time = end_time - start_time
    print(f"{elapsed_time:.5f} sec")