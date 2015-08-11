# C Algorithm Library [![Build Status](https://travis-ci.org/lekkas/c-algorithms.svg?branch=master)](https://travis-ci.org/lekkas/c-algorithms.svg?branch=master)

**C algorithms** is, as the name implies, a collection of common data structures
and algorithms implemented in C99.

## Motivation

Every now and then I find myself preparing for technical interviews which often
require at least some basic understanding of common data structures and
algorithms. These questions are supposed to assess a candidates' technical
background and ability to think on her feet. In real life, however, you should
definitely avoid re-inventing the wheel and use well-established, peer reviewed
libraries, like Boost for C++.

## ~~Why Header-Only?~~ Why *not* Header-Only?

The first version of the library was implemented as header only.

There are trade-offs between shipping a library in a header-only format and
using separate files for the API and implementation. The header-only approach,
though not very efficient when building large projects, has one big advantage;
the library does not need to be separately compiled and you only have to
`#include` the relevant header file in your source code.

However, I eventually settled down to use separate .h and .c files for API and
implementation because it think it is more intuitive in terms of code
structure.

## Testing

I have used the GoogleTest (gtest) framework. This has bloated the repository
a lot and might be an overkill for this small project but I wanted to give it
a try nevertheless. In order to run the tests simply execute `make test`

## Scope

This is an educational and experimental piece of code. Needless to say,
never use a random toy algorithm implementation like this in any
production setting.

## Author

[@lekkas](https://twitter.com/kwstasl)
