class StatisticsCalculator:
    def __init__(self, data):
        self.data = data

    def calculate_mean(self):
        return sum(self.data) / len(self.data)

    def calculate_median(self):
        sorted_data = sorted(self.data)
        n = len(sorted_data)
        if n % 2 == 0:
            return (sorted_data[n // 2 - 1] + sorted_data[n // 2]) / 2
        else:
            return sorted_data[n // 2]

    def calculate_mode(self):
        frequency = {}
        for num in self.data:
            frequency[num] = frequency.get(num, 0) + 1

        if not frequency:
            return []

        max_freq = max(frequency.values())
        if max_freq == 1:
            return []

        modes = [num for num, freq in frequency.items() if freq == max_freq]
        return sorted(modes)

    def get_statistics(self):
        return {
            "mean": self.calculate_mean(),
            "median": self.calculate_median(),
            "mode": self.calculate_mode()
        }


def main():
    print("Enter integers separated by spaces:")
    try:
        data = list(map(int, input().split()))
    except ValueError:
        print("Invalid input. Please enter integers only.")
        return

    if not data:
        print("No data entered.")
        return

    calculator = StatisticsCalculator(data)
    stats = calculator.get_statistics()

    print(f"Mean: {stats['mean']:.2f}")
    print(f"Median: {stats['median']:.2f}")

    modes = stats['mode']
    if not modes:
        print("Mode: No mode (all numbers occur equally)")
    else:
        print("Mode:", " ".join(map(str, modes)))


if __name__ == "__main__":
    main()