#include <stdio.h>

double scoreFunc(char *type) {
    double score = 0.0;
    printf("Enter %s score: ", type);

    if (scanf("%lf", &score) != 1) {
        printf("Invalid input! Defaulting score to 0.0\n");
        while (getchar() != '\n');
        return 0.0;
    }

    if (score < 0.0 || score > 100.0) {
        printf("Score out of range! Defaulting to 0.0\n");
        return 0.0;
    }

    return score;
}

double calculateFinalGrade(double quiz, double exam) {
    return (quiz * 0.4) + (exam * 0.6);
}

char getLetterGrade(double score) {
    if (score >= 90) return 'A';
    if (score >= 80) return 'B';
    if (score >= 70) return 'C';
    if (score >= 60) return 'D';
    return 'F';
}

void displayFunc(double quiz, double exam, double finalGrade, char letterGrade) {
    printf("\n--- Elena Report ---\n");
    printf("Quiz:  %.2f\n", quiz);
    printf("Exam:  %.2f\n", exam);
    printf("Final: %.2f\n", finalGrade);
    printf("Grade: %c\n", letterGrade);
    printf("--------------------\n");
}

int main(void) {
    double quiz = scoreFunc("Quiz");
    double exam = scoreFunc("Exam");
    double finalGrade = calculateFinalGrade(quiz, exam);
    char letterGrade = getLetterGrade(finalGrade);

    displayFunc(quiz, exam, finalGrade, letterGrade);

    return 0;
}
