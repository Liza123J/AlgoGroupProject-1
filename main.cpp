#include "login.h"

void startTest(List *mainList, loginList *loginList) {
  int inputInt;
  testTakerMenu();
  cout << "Enter your choice >>>>> ";
  cin >> inputInt;
  switch (inputInt) {
  case 1:
    // Register
    signUp(loginList);
    saveLoginFile(loginList);
    _getch();
    startTest(mainList, loginList);
    break; 
  case 2:
    // Login
    Login(loginList);  
    studentOpt(mainList);
    _getch();
    startTest(mainList, loginList);
    break;
  case 3:
    exit("Going back to menu");
    break;
  default:
    invalidOpt();
    startTest(mainList, loginList);
    break;
  }
}

void home(List *mainList, loginList *loginList, List *scoreList) {
  int inputInt;
  mainMenu();
  cout << "Enter your choice >>>>> ";
  cin >> inputInt;
  switch (inputInt) {
  case 1:
    system("cls");
    loginAdmin();
    adminOpt(mainList, loginList, scoreList);
    home(mainList, loginList, scoreList);
    break;
  case 2:
    system("cls");
    startTest(mainList, loginList);
    home(mainList, loginList, scoreList);
    break;
  case 3:
    exit("You have successfully exit the program");
    exit(0);
    break;
  default:
    invalidOpt();

    _getch();
    home(mainList, loginList, scoreList);

    break;
  }
}

int main() {

  List *mainList;
  mainList = createEmptyList();

  loginList *loginList;
  loginList = createEmptyLoginList();





  List *scoreList;
  scoreList = createEmptyList();

  readLoginInfo(loginList);
  readQuestionFromFile(mainList);
  loadingBar();
  home(mainList, loginList, scoreList);

  
  return 0;
}
