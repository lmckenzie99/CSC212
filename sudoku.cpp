bool rowCheck(const std::vector<std::vector<int>>& matrix) {
    for (int row = 0; row < 9; row++) {
        for (int num = 1; num <= 9; num++) {
            int count = 0;
            for (int col = 0; col < 9; col++) {
                if (matrix[row][col] == num) {
                    count++;
                }
            }
            // Each number should appear exactly once in each row
            if (count != 1) {
                return false;
            }
        }
    }
    return true;
}

