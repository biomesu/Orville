# Orville

The **Orville** team is building a game based on the TV series and hired you to implement its characters in C++. Below are the ones targeted for the initial release.

1. **Eevak** - Eevaks are four-legged equines that can run.
1. **Gelatin** - These are gelatinous creatures able to morph to any form and reproduce.
1. **Human** - These are regular humans.
1. **Kaylon** - Kaylons are robots that are humanoid in shape and can fire at will.
1. **Moclan** - They are also humanoid but reproduce through eggs.

To precisely document their required behavior and test your implementation, the Orville development team has provided you a test suite that your code must pass. Implement these characters using a C++ class hierarchy, making sure that all the given tests pass (this is called *Test Driven Development or TDD*), building your code as a library.

**NOTE**:
1. Make all your changes only within the **species/** folder. Specifically, do NOT edit the tests.
1. Add header guards to the header files and copyright messages to all your files.
1. Run the tests with **bazel test test/species_test --test_output=all** from the top project folder. You must have **bazel** installed (see [Installing Bazel](https://docs.bazel.build/versions/master/install.html)).
1. One of the tests in *species_test* checks for inequality of Gelatin instances, for which you will need to implement operator overloading.
1. Use **double** for values like **height** and **weight** because they can be fractional (don't use **float** as it can cause issues with checking equality).
1. Note that **species_test.cpp** expects all string parameters to be **const char \*** (NOT **std::string**).
