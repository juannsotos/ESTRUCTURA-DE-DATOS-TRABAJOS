class ShellSort:
    @staticmethod
    def displayArr(inputArr):
        for k in inputArr:
            print(k, end=" ")
        print()

    def sort(self, inputArr):
        size = len(inputArr)
        gapSize = size // 2

        while gapSize > 0:
            for j in range(gapSize, size):
                val = inputArr[j]
                k = j
                while k >= gapSize and inputArr[k - gapSize] > val:
                    inputArr[k] = inputArr[k - gapSize]
                    k -= gapSize
                inputArr[k] = val
            gapSize //= 2
        return 0

if __name__ == "__main__":
    inputArr = [36, 34, 43, 11, 15, 20, 28, 45]
    print("Arreglo antes de ser ordenado:")
    ShellSort.displayArr(inputArr)

    obj = ShellSort()
    obj.sort(inputArr)

    print("Arreglo después de ser ordenado:")
    ShellSort.displayArr(inputArr)