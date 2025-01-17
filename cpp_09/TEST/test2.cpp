#include <deque>
#include <iostream>


void printContainer(std::string msg, int groupSize, std::deque<int> sequence) {
    // std::cout << msg << ": " << groupSize << std::endl;

    size_t fullGroups = sequence.size() / groupSize; // Number of full groups
    size_t remainder = sequence.size() % groupSize; // Remaining elements

    size_t index = 0;
	std::cout << msg;
    for (size_t group = 0; group < fullGroups; ++group) {
        std::cout << "[ ";
        for (size_t i = 0; i < groupSize; ++i, ++index) {
            std::cout << sequence[index] << " ";
        }
        std::cout << "] ";
    }

    // Print remaining elements (not part of a full group)
    if (remainder > 0) {
        for (size_t i = 0; i < remainder; ++i, ++index) {
            std::cout << sequence[index] << " ";
        }
    }
    std::cout << std::endl;
}

size_t calculateGroupSize(size_t depth) {
    size_t groupSize = 1;
    for (size_t i = 0; i < depth; ++i) {
        groupSize *= 2; // Multiply by 2 for each level of depth
    }
std::cout << "groupSize = " << groupSize << std::endl;
    return groupSize;
}

void sortPairs(std::deque<int>& src, size_t groupSize) {
    size_t tail = groupSize - 1;

    while (tail + groupSize < src.size()) {
        std::deque<int>::iterator first = src.begin();
        std::advance(first, tail);

        std::deque<int>::iterator second = src.begin();
        std::advance(second, tail + groupSize);

        if (*first > *second) {
            std::deque<int>::iterator trueFirst = src.begin();
            std::advance(trueFirst, tail - groupSize + 1);

            std::deque<int>::iterator trueSecond = src.begin();
            std::advance(trueSecond, tail + 1);

            std::advance(first, 1);
            std::swap_ranges(trueFirst, first, trueSecond);
        }
        tail += groupSize * 2;
    }
}

std::deque<int> buildJacobsthalVec(size_t len)
{
    std::deque<int>	JacobsthalSeq;
    size_t			num;
std::cout << "buildJacobsthal(): len received is " << len << std::endl;
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

std::deque<int> getPickingOrder(const std::deque<int> & jacobsthalSeq, size_t seqSize) {
    std::deque<int> result;
    std::deque<bool> inserted(seqSize, false); // Track inserted indices

    // Always add index 0 first
    if (seqSize > 0) {
        result.push_back(0);
        inserted[0] = true;
    }

    size_t current = 1; // Start interleaving from index 1

    // Process each Jacobsthal boundary
    for (size_t i = 0; i < jacobsthalSeq.size(); ++i) {
        int boundary = jacobsthalSeq[i];

        if (boundary >= static_cast<int>(seqSize)) {
            break; // Ignore out-of-bounds Jacobsthal indices
        }

        // Add the current boundary
        if (!inserted[boundary]) {
            result.push_back(boundary);
            inserted[boundary] = true;
        }

        // Insert interleaved indices between `current` and `boundary` in descending order
        for (size_t j = boundary; j >= static_cast<size_t>(current); --j) {
            if (!inserted[j]) {
                result.push_back(j);
                inserted[j] = true;
            }
        }

        current = boundary + 1; // Move to the next range
    }

    for (size_t i = seqSize; i > current; --i) {
        if (!inserted[i]) {
            result.push_back(i);
        }
    }

    return result;
}

void binarySearchInsertion(std::deque<int> & sequence, size_t groupSize) {
    // Placeholder for binary search insertion logic
	size_t numberOfGroups = sequence.size() / groupSize;
	
	if (numberOfGroups > 1) {
		std::cout << "\nPerforming binary search insertion for group size: " << groupSize;
		std::cout << " | Number of groups: " << numberOfGroups << std::endl;

	}

	// Generate insertion order using Jacobsthal sequence
	std::deque<int> jacobsthalSeq = buildJacobsthalVec(numberOfGroups);
	std::deque<int> pickingIndexes = getPickingOrder(jacobsthalSeq, numberOfGroups);
	std::cout << "Number of groups =  " << numberOfGroups << std::endl;
	printContainer("Jacobsthal sequence = ", numberOfGroups, jacobsthalSeq);
	printContainer("Picking order seq   = ", numberOfGroups, pickingIndexes);
}

void mergeInsertionSort(std::deque<int>& sequence, size_t depth) {
    size_t groupSize = calculateGroupSize(depth); // Calculate group size as 2^depth

    if (groupSize >= sequence.size()) {
        return; // Base case: No more groups to sort
    }

    // Step 1: Sort pairs of elements at this depth
    sortPairs(sequence, groupSize);
	printContainer("", groupSize, sequence);

    // Step 2: Recursively sort larger groups
    mergeInsertionSort(sequence, depth + 1);

    // Step 3: Insert remaining elements into the sorted sequence
    binarySearchInsertion(sequence, groupSize);
}

// int main() {
// 	std::cout << "--------------------- TEST 2 ---------------------------\n";
//     std::deque<int> sequence = {6, 14, 17, 5, 12, 1, 3, 7, 13, 8, 2, 11, 15, 4, 10, 9, 16, 18};

// 	for (int i = 1; i < sequence.size(); i *= 2) 
// 	{
		
// 		size_t	recursionDepth = 0;
// 		printContainer("Group size", i, sequence);
// 		// In each recursive call we calculate the group size as 2^depth
// 		// Recursion stops when the group size becomes larger than sequence size
// 		// 
// 		mergeInsertionSort(sequence, recursionDepth);
// 	}

//     return 0;
// }

int main() {
    // std::deque<int> sequence = {6, 14, 17, 5, 12, 1, 3, 7, 13, 8, 2, 11, 15, 4, 10, 9, 16, 18};
    std::deque<int> sequence = {1, 7, 4, 11, 5, 16, 19, 8, 14, 20, 23, 9, 15, 22, 24, 2, 10, 3, 12, 13, 18, 17, 25, 21};

    std::cout << "Original sequence: ";
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
    std::cout << "\n";

	size_t	recursionDepth = 0;

	// In each recursive call we calculate the group size as 2^depth
	// Recursion stops when the group size becomes larger than sequence size
    mergeInsertionSort(sequence, recursionDepth);

    std::cout << "Sorted sequence: ";
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
    std::cout << "\n";

	// for (int i = 1; i < sequence.size(); i *= 2) 
	// 	printContainer("Group size", i, sequence);

    return 0;
}