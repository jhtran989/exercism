#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>
#include <tuple>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // TODO: Implement round_down_scores
    std::vector<int> result{};
    std::transform(student_scores.cbegin(), student_scores.cend(), std::back_inserter(result), 
    [](double value){
        return static_cast<int>(value);
    });
    return result;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // TODO: Implement count_failed_students
    return std::count_if(student_scores.cbegin(), student_scores.cend(), 
    [](int value){
        return value <= 40;
    });
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // TODO: Implement letter_grades
    std::array<int, 4> letter_thresholds{};
    letter_thresholds[0] = 41;

    int spacing = (highest_score - 40) / 4;

    // typedef std::array<int, 4>::size_type arr_size;
    for (int i = 1; i < 4; i++) {
        letter_thresholds[i] = letter_thresholds[i-1] + spacing;
    }

    return letter_thresholds;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement student_ranking
    std::vector<std::string> result{};
    // FIXME: use zip?
    // for (std::tuple<int&, std::string&> element : std::views::zip(student_scores, student_names))) {

    // }

    typedef std::vector<int>::size_type vec_size;
    for (vec_size i = 0; i < student_scores.size(); i++) {
        result.push_back(std::to_string(i+1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]));
    }

    return result;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    // TODO: Implement perfect_score
    
    std::vector<int>::const_iterator perfect_iter = std::find(student_scores.cbegin(), student_scores.cend(), 100);
    if (perfect_iter == student_scores.end()) {
        return "";
    } else {
        return student_names[perfect_iter - student_scores.begin()];
    }
}
