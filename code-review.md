# How to pass code-review

1. To write the code, use [Google C++ Style Guide].
2. Before sending code, check the code using [clang-format] and [clang-tidy].
3. If you want to use STL library data structures, such as std::vector, std::stack, std:: unordered_map etc in any task of the course, you have to implement them in the theoretical contest to get points.
4. Using namespace std is not allowed, instead write concrete namespace member, for example, using std::cin;
5. Constraints is very important, use minimal count of bytes to save the premitive type or if there is no constraints, use primitive type with maximal count of bytes.
6. Points for the task will leak if memory leaks are found on the code-review.
7. If a similar code is found, we will be forced to give the cheater a negative score for the problem

## Code-review passing algorithm

 1. Pass tests in the contest.
 2. Create your **own** repository with readme if it doesn't exist
 3. Create a branch ***NameOfTheProblem*** in the repository
 4. Clone your repository
 5. Commit and push your solution to the ***NameOfTheProblem*** branch
 6. Create a pull-request to merge the ***NameOfTheProblem*** branch with the main branch
 7. Do not approve the pull-request.
 8. Add Islam and me to collaborators
 9. Fix the remarks and **send the fixed solution again to the contest**. If the solution is not sent to the contest, it will not be checked.
 10. In pull request comments send the **link to the successfully passed solution**, example:

https://contest.yandex.ru/contest/47619/run-report/1234567890

## Assessment

## Tips for passing code-review & contest verification
### Using linters

[//]: #
[Google C++ Style Guide]: <https://google.github.io/styleguide/cppguide.html>
[adress sanitazer]: https://github.com/google/sanitizers/wiki/AddressSanitizer
[CLion]: https://www.jetbrains.com/clion
[CLion clang-tidy]: https://www.jetbrains.com/help/clion/clang-tidy-checks-support.html
[CLion clang-format]: https://www.jetbrains.com/help/clion/clangformat-as-alternative-formatter.html
[clang-format]: https://clang.llvm.org/docs/ClangFormat.html
[clang-tidy]: https://clang.llvm.org/extra/clang-tidy.html

