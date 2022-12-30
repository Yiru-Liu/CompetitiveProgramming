from random import randint


def main():
    output = ""
    num_test_cases = randint(1, 10)
    output += f"{num_test_cases}\n\n"

    for i in range(num_test_cases):
        input_array_size = randint(1, 100)
        num_input_arrays = randint(1, 100)


def generate_random_input_array(size):
    array = ""
    for i in range(size):
        array += f"{randint(0, 1)}"
    return array


if __name__ == '__main__':
    main()
