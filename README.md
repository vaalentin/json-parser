# json-parser 0.0.1

A simple json parser written in C

![Alt text](./screenshots/lexer.png "Lexer")

## Compile

* Execute the makefile with `make`
* Clean the folder with `make clean`
* Open build

## Lexer

include `"lexer.h"` and `"Tokenlist.h"`

And gives the path to the file to process:

```cpp
Tokenlist tokens;
tokens = lex("example.json");
dumpTokenlist(&tokens);
```

Returns a list of tokens:

```cpp
typedef struct Token {
	char *type, *value;
	int line, start, end;
} Token;
```

### Example

#### Input

```javascript
{
	"name": "Once upon a time",
	"author": "Henry",
	"version": "0.0.1",
	"elements": [
		{ "name": "cover" },
		{ "name": "pages" }
  	]
}
```

#### Output

| Type          | Value              | Line | Start | End |
| ------------- | ------------------ | ---- | ----- | --- |
| LEFT_BRACKET  | (null)             | 0    | 0     | 0   |
| QUOTE         | (null)             | 1    | 2     | 2   |
| VALUE         | `name`             | 1    | 3     | 7   |
| QUOTE         | (null)             | 1    | 7     | 7   |
| ASSIGNATION   | (null)             | 1    | 8     | 8   |
| QUOTE         | (null)             | 1    | 10    | 10  |
| VALUE         | `Once upon a time` | 1    | 11    | 27  |
| QUOTE         | (null)             | 1    | 27    | 27  |
| COMA          | (null)             | 1    | 28    | 28  |
| QUOTE         | (null)             | 2    | 2     | 2   |
| VALUE         | `author`           | 2    | 3     | 9   |
| QUOTE         | (null)             | 2    | 9     | 9   |
| ASSIGNATION   | (null)             | 2    | 10    | 10  |
| QUOTE         | (null)             | 2    | 12    | 12  |
| VALUE         | `Henry`            | 2    | 13    | 18  |
| QUOTE         | (null)             | 2    | 18    | 18  |
| COMA          | (null)             | 2    | 19    | 19  |
| QUOTE         | (null)             | 3    | 2     | 2   |
| VALUE         | `version`          | 3    | 3     | 10  |
| QUOTE         | (null)             | 3    | 10    | 10  |
| ASSIGNATION   | (null)             | 3    | 11    | 11  |
| QUOTE         | (null)             | 3    | 13    | 13  |
| VALUE         | `0.0.1`            | 3    | 14    | 19  |
| QUOTE         | (null)             | 3    | 19    | 19  |
| COMA          | (null)             | 3    | 20    | 20  |
| QUOTE         | (null)             | 4    | 2     | 2   |
| VALUE         | `elements`         | 4    | 3     | 11  |
| QUOTE         | (null)             | 4    | 11    | 11  |
| ASSIGNATION   | (null)             | 4    | 12    | 12  |
| LEFT_SQUARE   | (null)             | 4    | 14    | 14  |
| LEFT_BRACKET  | (null)             | 5    | 3     | 3   |
| QUOTE         | (null)             | 5    | 5     | 5   |
| VALUE         | `name`             | 5    | 6     | 10  |
| QUOTE         | (null)             | 5    | 10    | 10  |
| ASSIGNATION   | (null)             | 5    | 11    | 11  |
| QUOTE         | (null)             | 5    | 13    | 13  |
| VALUE         | `cover`            | 5    | 14    | 19  |
| QUOTE         | (null)             | 5    | 19    | 19  |
| RIGHT_BRACKET | (null)             | 5    | 21    | 21  |
| COMA          | (null)             | 5    | 22    | 22  |
| LEFT_BRACKET  | (null)             | 6    | 3     | 3   |
| QUOTE         | (null)             | 6    | 5     | 5   |
| VALUE         | `name`             | 6    | 6     | 10  |
| QUOTE         | (null)             | 6    | 10    | 10  |
| ASSIGNATION   | (null)             | 6    | 11    | 11  |
| QUOTE         | (null)             | 6    | 13    | 13  |
| VALUE         | `pages`            | 6    | 14    | 19  |
| QUOTE         | (null)             | 6    | 19    | 19  |
| RIGHT_BRACKET | (null)             | 6    | 21    | 21  |
| RIGHT_SQUARE  | (null)             | 7    | 2     | 2   |
| RIGHT_BRACKET | (null)             | 8    | 1     | 1   |