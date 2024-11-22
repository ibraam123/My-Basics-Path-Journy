// project one one course 5 Algorthims

/*
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h> // For Beep function and system("color")

using namespace std;

// Enum for game choices
enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };

// Enum for round winners
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

// Structure to hold information about a single round
struct stRoundInfo {
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

// Structure to hold game results
struct stGameResults {
    short GameRounds = 0;
    short Player1WinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

// Function to generate a random number between From and To (inclusive)
int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

// Function to get the name of the winner as a string
string WinnerName(enWinner Winner) {
    string arrWinnerName[3] = { "Player1", "Computer", "No Winner" };
    return arrWinnerName[Winner - 1];
}

// Function to determine who won the round
enWinner WhoWonTheRound(stRoundInfo RoundInfo) {
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice) {
        return enWinner::Draw;
    }
    switch (RoundInfo.Player1Choice) {
        case enGameChoice::Stone:
            if (RoundInfo.ComputerChoice == enGameChoice::Paper) {
                return enWinner::Computer;
            }
            break;
        case enGameChoice::Paper:
            if (RoundInfo.ComputerChoice == enGameChoice::Scissors) {
                return enWinner::Computer;
            }
            break;
        case enGameChoice::Scissors:
            if (RoundInfo.ComputerChoice == enGameChoice::Stone) {
                return enWinner::Computer;
            }
            break;
    }
    return enWinner::Player1;
}

// Function to get the name of the choice as a string
string ChoiceName(enGameChoice Choice) {
    string arrGameChoices[3] = { "Stone", "Paper", "Scissors" };
    return arrGameChoices[Choice - 1];
}

// Function to set the screen color based on the winner
void SetWinnerScreenColor(enWinner Winner) {
    switch (Winner) {
        case enWinner::Player1:
            system("color 2F"); // Green background, black text
            break;
        case enWinner::Computer:
            system("color 4F"); // Red background, white text
            cout << "\a"; // Ring sound
            break;
        default:
            system("color 6F"); // Yellow background, black text
            break;
    }
}

// Function to print round results
void PrintRoundResults(stRoundInfo RoundInfo) {
    cout << "\n____________Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
    cout << "Player1  Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner   : [" << RoundInfo.WinnerName << "] \n";
    cout << "__________________________________\n" << endl;
    SetWinnerScreenColor(RoundInfo.Winner);
}

// Function to determine the overall game winner
enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes) {
    if (Player1WinTimes > ComputerWinTimes) return enWinner::Player1;
    if (ComputerWinTimes > Player1WinTimes) return enWinner::Computer;
    return enWinner::Draw;
}

// Function to fill game results
stGameResults FillGameResults(short GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes) {
    stGameResults GameResults;
    GameResults.GameRounds = GameRounds;
    GameResults.Player1WinTimes = Player1WinTimes;
    GameResults.ComputerWinTimes = ComputerWinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
    GameResults.WinnerName = WinnerName(GameResults.GameWinner);
    return GameResults;
}

// Function to read player's choice
enGameChoice ReadPlayer1Choice() {
    short Choice = 1;
    do {
        cout << "\nYour Choice: [1]: Stone, [2]: Paper, [3]: Scissors? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);
    return (enGameChoice)Choice;
}

// Function to get computer's choice
enGameChoice GetComputerChoice() {
    return (enGameChoice)RandomNumber(1, 3);
}

// Function to play the game
stGameResults PlayGame(short HowManyRounds) {
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++) {
        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        // Increase win/Draw counters
        if (RoundInfo.Winner == enWinner::Player1)
            Player1WinTimes++;
        else if (RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;

        PrintRoundResults(RoundInfo);
    }

    return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

// Function to generate tabs
string Tabs(short NumberOfTabs) {
    string t = "";
    for (int i = 1; i < NumberOfTabs; i++) {
        t += "\t";
    }
    return t;
}

// Function to show the game over screen
void ShowGameOverScreen() {
    cout << Tabs(2) << "__________________________________________________________\n\n";
    cout << Tabs(2) << "                 +++ G a m e  O v e r +++\n";
    cout << Tabs(2) << "__________________________________________________________\n\n";
}

// Function to show the final game results
void ShowFinalGameResults(stGameResults GameResults) {
    cout << Tabs(2) << "_____________________ [Game Results ]_____________________\n\n";
    cout << Tabs(2) << "Game Rounds        : " << GameResults.GameRounds << endl;
    cout << Tabs(2) << "Player1 won times  : " << GameResults.Player1WinTimes << endl;
    cout << Tabs(2) << "Computer won times : " << GameResults.ComputerWinTimes << endl;
    cout << Tabs(2) << "Draw times         : " << GameResults.DrawTimes << endl;
    cout << Tabs(2) << "Final Winner       : " << GameResults.WinnerName << endl;
    cout << Tabs(2) << "___________________________________________________________\n";
    SetWinnerScreenColor(GameResults.GameWinner);
}

// Function to read the number of rounds
short ReadHowManyRounds() {
    short GameRounds = 1;
    do {
        cout << "How Many Rounds (1 to 10)? \n";
        cin >> GameRounds;
    } while (GameRounds < 1 || GameRounds > 10);
    return GameRounds;
}

// Function to reset the screen
void ResetScreen() {
    system("cls"); // Clear the console
    system("color 0F"); // Reset color to default
}

// Function to start the game
void StartGame() {
    char PlayAgain = 'Y';
    do {
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyRounds());
        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);
        cout << endl << Tabs(3) << "Do you want to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

// Main function
int main() {
    srand((unsigned)time(NULL)); // Seed the random number generator
    StartGame(); // Start the game
    return 0;
}
*/

// project two math game

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Enumeration for question levels
enum QuestionsLevel {
    EasyLevel = 1,
    MedLevel = 2,
    HardLevel = 3,
    Mix = 4
};

// Enumeration for operation types
enum OperationType {
    Add = 1,
    Sub = 2,
    Mult = 3,
    Div = 4,
    MixOp = 5
};

// Function to get operation type symbol
string GetOpTypeSymbol(OperationType opType) {
    switch (opType) {
        case Add: return "+";
        case Sub: return "-";
        case Mult: return "x";
        case Div: return "/";
        default: return "Mix";
    }
}

// Function to get question level text
string GetQuestionLevelText(QuestionsLevel questionLevel) {
    const string arrQuestionLevelText[4] = { "Easy", "Med", "Hard", "Mix" };
    return arrQuestionLevelText[questionLevel - 1];
}

// Function to generate a random number between From and To (inclusive)
int RandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

// Function to set screen color based on answer correctness
void SetScreenColor(bool right) {
    system(right ? "color 2F" : "color 4F"); // Green for correct, Red for incorrect
    if (!right) cout << "\a"; // Play beep sound for wrong answers
}

// Function to read the number of questions
short ReadHowManyQuestions() {
    short numberOfQuestions;
    do {
        cout << "How many questions do you want to answer? ";
        cin >> numberOfQuestions;
    } while (numberOfQuestions < 1 || numberOfQuestions > 10);
    return numberOfQuestions;
}

// Function to read the question level
QuestionsLevel ReadQuestionsLevel() {
    short questionLevel;
    do {
        cout << "Enter question level [1] Easy, [2] Med, [3] Hard, [4] Mix? ";
        cin >> questionLevel;
    } while (questionLevel < 1 || questionLevel > 4);
    return static_cast<QuestionsLevel>(questionLevel);
}

// Function to read the operation type
OperationType ReadOpType() {
    short opType;
    do {
        cout << "Enter operation type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix? ";
        cin >> opType;
    } while (opType < 1 || opType > 5);
    return static_cast<OperationType>(opType);
}

// Structure for a question
struct Question {
    int number1 = 0;
    int number2 = 0;
    OperationType operationType;
    QuestionsLevel questionLevel;
    int correctAnswer = 0;
    int playerAnswer = 0;
    bool answerResult = false;
};

// Structure for a quiz
struct Quiz {
    Question questionList[100];
    short numberOfQuestions;
    QuestionsLevel questionsLevel;
    OperationType opType;
    short numberOfWrongAnswers = 0;
    short numberOfRightAnswers = 0;
    bool isPass = false;
};

// Function for simple calculator operations
int SimpleCalculator(int number1, int number2, OperationType opType) {
    switch (opType) {
        case Add: return number1 + number2;
        case Sub: return number1 - number2;
        case Mult: return number1 * number2;
        case Div: return number1 / number2;
        default: return number1 + number2;
    }
}

// Function to get a random operation type
OperationType GetRandomOperationType() {
    return static_cast<OperationType>(RandomNumber(1, 4));
}

// Function to generate a question
Question GenerateQuestion(QuestionsLevel questionLevel, OperationType opType) {
    Question question;

    if (questionLevel == Mix) {
        questionLevel = static_cast<QuestionsLevel>(RandomNumber(1, 3));
    }

    if (opType == MixOp) {
        opType = GetRandomOperationType();
    }

    question.operationType = opType;

    switch (questionLevel) {
        case EasyLevel:
            question.number1 = RandomNumber(1, 10);
            question.number2 = RandomNumber(1, 10);
            break;
        case MedLevel:
            question.number1 = RandomNumber(10, 50);
            question.number2 = RandomNumber(10, 50);
            break;
        case HardLevel:
            question.number1 = RandomNumber(50, 100);
            question.number2 = RandomNumber(50, 100);
            break;
        default:
            break;
    }

    question.correctAnswer = SimpleCalculator(question.number1, question.number2, question.operationType);
    question.questionLevel = questionLevel;

    return question;
}

// Function to generate quiz questions
void GenerateQuizQuestions(Quiz &quiz) {
    for (short i = 0; i < quiz.numberOfQuestions; ++i) {
        quiz.questionList[i] = GenerateQuestion(quiz.questionsLevel, quiz.opType);
    }
}

// Function to read the answer from the user
int ReadQuestionAnswer() {
    int answer;
    cin >> answer;
    return answer;
}

// Function to print a question
void PrintTheQuestion(const Quiz &quiz, short questionNumber) {
    cout << "\nQuestion [" << questionNumber + 1 << "/" << quiz.numberOfQuestions << "] \n\n";
    cout << quiz.questionList[questionNumber].number1 << endl;
    cout << quiz.questionList[questionNumber].number2 << " ";
    cout << GetOpTypeSymbol(quiz.questionList[questionNumber].operationType);
    cout << "\n_________\n";
}

// Function to correct the question answer
void CorrectTheQuestionAnswer(Quiz &quiz, short questionNumber) {
    if (quiz.questionList[questionNumber].playerAnswer != quiz.questionList[questionNumber].correctAnswer) {
        quiz.questionList[questionNumber].answerResult = false;
        quiz.numberOfWrongAnswers++;
        cout << "Wrong Answer :-( \n";
        cout << "The right answer is: " << quiz.questionList[questionNumber].correctAnswer << "\n";
    } else {
        quiz.questionList[questionNumber].answerResult = true;
        quiz.numberOfRightAnswers++;
        cout << "Right Answer :-) \n";
    }
    cout << endl;
    SetScreenColor(quiz.questionList[questionNumber].answerResult);
}

// Function to ask questions and correct answers
void AskAndCorrectQuestionListAnswers(Quiz &quiz) {
    for (short i = 0; i < quiz.numberOfQuestions; ++i) {

        PrintTheQuestion(quiz, i);
        quiz.questionList[i].playerAnswer = ReadQuestionAnswer();
        CorrectTheQuestionAnswer(quiz, i);
        
    }
    quiz.isPass = (quiz.numberOfRightAnswers >= quiz.numberOfWrongAnswers);
}

// Function to get final results text
string GetFinalResultsText(bool pass) {
    return pass ? "PASS :-)" : "Fail :-(";
}

// Function to print quiz results
void PrintQuizResults(const Quiz &quiz) {
    cout << "\n______________________________\n\n";
    cout << "Final Results: " << GetFinalResultsText(quiz.isPass) << "\n";
    cout << "______________________________\n\n";
    cout << "Number of Questions: " << quiz.numberOfQuestions << endl;
    cout << "Questions Level    : " << GetQuestionLevelText(quiz.questionsLevel) << endl;
    cout << "OpType             : " << GetOpTypeSymbol(quiz.opType) << endl;
    cout << "Number of Right Answers: " << quiz.numberOfRightAnswers << endl;
    cout << "Number of Wrong Answers: " << quiz.numberOfWrongAnswers << endl;
    cout << "______________________________\n";
}

// Function to play the math game
void PlayMathGame() {
    Quiz quiz;
    quiz.numberOfQuestions = ReadHowManyQuestions();
    quiz.questionsLevel = ReadQuestionsLevel();
    quiz.opType = ReadOpType();
    GenerateQuizQuestions(quiz);
    AskAndCorrectQuestionListAnswers(quiz);
    PrintQuizResults(quiz);
}

// Function to reset the screen
void ResetScreen() {
    system("cls");
    system("color 0F"); // Reset to default color
}

// Function to start the game loop
void StartGame() {
    char playAgain = 'Y';
    do {
        ResetScreen();
        PlayMathGame();
        cout << "\nDo you want to play again? Y/N? ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');
}

// Main function
int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Seed the random number generator
    StartGame();
    return 0;
}
