import random

def generate_random_numbers(num_numbers, min_value, max_value):
    return [random.randint(min_value, max_value) for _ in range(num_numbers)]

def write_numbers_to_file(numbers, file_name):
    with open(file_name, 'w') as file:
        file.write(' '.join(map(str, numbers)))

if __name__ == "__main__":
    num_numbers = 100000
    min_value = 1
    max_value = 100000000

    random_numbers = generate_random_numbers(num_numbers, min_value, max_value)

    file_name = "t1"
    write_numbers_to_file(random_numbers, file_name)
