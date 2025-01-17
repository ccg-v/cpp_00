#include <vector>
#include <algorithm>
#include <iostream>

void printContainer(const std::vector<int>& container) {
    if (!container.empty()) {
        std::cout << "{ ";
        for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "}" << std::endl;
    }
}

class PmergeMe {
private:

    void sortPairs(std::vector<int>& seq) {
        if (seq.size() <= 1) return;
        for (size_t i = 0; i < seq.size() - 1; i += 2) {
            if (seq[i] > seq[i + 1]) {
                std::swap(seq[i], seq[i + 1]);
            }
        }
    }

    void divideSequence(std::vector<int>& seq, std::vector<int>& smaller) {
        if (seq.size() <= 1) return;

        std::vector<int> larger;
        for (size_t i = 0; i < seq.size() - 1; i += 2) {
            smaller.push_back(seq[i]);
            larger.push_back(seq[i + 1]);
        }
        if (seq.size() % 2 == 1) {
            larger.push_back(seq.back());
        }

        seq = larger;

        std::cout << "larger  = ";
        printContainer(seq);
        std::cout << "smaller = ";
        printContainer(smaller);
        std::cout << "--------------------------" << std::endl;
    }

    // std::vector<int> generateJacobsthalSeq(size_t len) {
    //     std::vector<int> JacobsthalSeq = {0, 1};
    //     while (JacobsthalSeq.back() < len) {
    //         size_t next = JacobsthalSeq.back() + 2 * JacobsthalSeq[JacobsthalSeq.size() - 2];
    //         if (next >= len) break;
    //         JacobsthalSeq.push_back(next);
    //     }
	// 	// Remove the first two elements if the sequence has at least two elements
	// 	if (JacobsthalSeq.size() > 2) {
	// 		JacobsthalSeq.erase(JacobsthalSeq.begin(), JacobsthalSeq.begin() + 2);
	// 	}
    //     return JacobsthalSeq;
    // }

	std::vector<int> generateJacobsthalSeq(size_t len)
	{
		std::vector<int>	JacobsthalSeq;
		size_t				num;

		JacobsthalSeq.push_back(0);
		JacobsthalSeq.push_back(1);
		for (size_t i = 2; i < len; i++) {
			num = JacobsthalSeq[i - 1] + (2 * JacobsthalSeq[i - 2]);
			JacobsthalSeq.push_back(num);
		}
		// Remove the first two elements if the sequence has at least two elements
		if (JacobsthalSeq.size() > 2) {
			JacobsthalSeq.erase(JacobsthalSeq.begin(), JacobsthalSeq.begin() + 2);
		}
		return JacobsthalSeq;
	}

    size_t binarySearch(const std::vector<int>& seq, int value, size_t end) {
        size_t left = 0;
        size_t right = end;
        while (left < right) {
            size_t mid = (left + right) / 2;
            if (seq[mid] > value)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    // void insertElement(std::vector<int>& seq, int value, size_t pos) {
    //     seq.insert(seq.begin() + pos, value);
    // }

	std::vector<int> getInsertionOrder(const std::vector<int>& jacobsthalSeq, size_t size) {
		std::vector<int> insertionOrder;


		// Add all Jacobsthal-indexed elements and interleave non-Jacobsthal elements in reverse order
		for (size_t i = 0; i < jacobsthalSeq.size(); i++) {
			size_t currentJacobIndex = jacobsthalSeq[i];

			// Stop if the current Jacobsthal index exceeds the given size
			if (currentJacobIndex >= size) break;

			// Add current Jacobsthal-indexed element
			insertionOrder.push_back(currentJacobIndex);

			// If there's a previous Jacobsthal index, add interleaved indices in reverse order
			if (i > 0) {
				size_t prevJacobIndex = jacobsthalSeq[i - 1];
				for (size_t j = currentJacobIndex - 1; j > prevJacobIndex; --j) {
					if (j < size) {
						insertionOrder.push_back(j);
					}
				}
			}
		}

		// For any remaining values past the last Jacobsthal index, add them in reverse order
		size_t lastJacobIndex = jacobsthalSeq.back();
		for (size_t k = size - 1; k > lastJacobIndex; --k) {
			insertionOrder.push_back(k);
		}

		// Ensure '0' is included as the first index if it's missing
		if (!insertionOrder.empty() && insertionOrder[0] != 0) {
			insertionOrder.insert(insertionOrder.begin(), 0);
		}

		return insertionOrder;
	}


public:

	void fordJohnsonSort(std::vector<int>& seq) {
		if (seq.size() <= 1) return;
		if (seq.size() == 2) {
			if (seq[0] > seq[1]) std::swap(seq[0], seq[1]);
			return;
		}

		// Step 1: Pair and sort
		std::vector<int> smaller;
		sortPairs(seq);
		divideSequence(seq, smaller);
		fordJohnsonSort(seq);

		// Step 2: Generate insertion order using Jacobsthal sequence
		std::vector<int> jacobsthalOrder = generateJacobsthalSeq(smaller.size());
		std::vector<int> insertionOrder = getInsertionOrder(jacobsthalOrder, smaller.size());

		std::cout << "\nLarger (main chain)    :\t";
		printContainer(seq);		
		std::cout << "Smaller (pend elements):\t";
		printContainer(smaller);
		std::cout << "Jacobsthal numbers     :\t";
		printContainer(jacobsthalOrder);
		std::cout << "Insertion indexes      :\t";
		printContainer(insertionOrder);

		// Step 3: Insert smaller elements into seq based on insertionOrder
		for (size_t i = 0; i < insertionOrder.size(); ++i) {
			int insertIndex = insertionOrder[i];
			if (insertIndex < smaller.size()) {
				int valueToInsert = smaller[insertIndex];
				size_t position = binarySearch(seq, valueToInsert, seq.size());
				// insertElement(seq, valueToInsert, pos);
				seq.insert((seq.begin() + position), valueToInsert);
				// debug
				std::cout << "\n   Inserting value " << valueToInsert << " at position " << position << std::endl;
				std::cout << "      Updated larger sequence:\t";
				printContainer(seq);
			}
		}
	}
};

int main() {

    std::vector<int> numbers = { 5, 3, 9, 2, 1, 7, 8, 10, 4, 6};
    PmergeMe sorter;
    sorter.fordJohnsonSort(numbers);
	std::cout << "\nSorted sequence: ";
    printContainer(numbers);
    return 0;
}
