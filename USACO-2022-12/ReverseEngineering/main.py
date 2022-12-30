def main():
    num_test_cases = int(input())

    responses = []

    for i in range(num_test_cases):
        input()
        input_array_size, num_input_arrays = [int(x) for x in input().split()]

        input_arrays = []
        outputs = []
        for j in range(num_input_arrays):
            input_array, output = input().split()
            input_arrays.append(input_array)
            outputs.append(output)

        responses.append(detect_discrepancies(input_arrays, outputs))

    for response in responses:
        print("OK" if response else "LIE")


def detect_discrepancies(input_arrays, outputs):

    where_discrepancy_found = None
    typical_output = {
        "0": None,
        "1": None
    }

    current_checking = [i[0] for i in input_arrays]
    current_checking_all_same = len(set(current_checking)) == 1

    for i, character in enumerate(current_checking):
        if typical_output[character] is None:
            typical_output[character] = outputs[i]
        elif outputs[i] != typical_output[character]:
            if current_checking_all_same:
                return False
            if where_discrepancy_found is None:
                where_discrepancy_found = character
            elif where_discrepancy_found != character:
                return False

    if len(input_arrays[0]) == 1:
        return True

    trimmed_input_arrays = [i[1:] for i in input_arrays]
    return detect_discrepancies(trimmed_input_arrays, outputs)


if __name__ == "__main__":
    main()
