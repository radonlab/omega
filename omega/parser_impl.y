/**
 * Omega grammar definition.
 * Refer to the
 * <a href="https://github.com/antlr/grammars-v4/blob/master/golang/GoParser.g4">Go grammar</a>.
 */

%name omgParse

%token_prefix TK_

%token
    EOF
    NEWLINE
    COMMA
    SEMI
    L_PAREN
    R_PAREN
    L_BRACKET
    R_BRACKET
    L_BRACE
    R_BRACE
    STRING_LIT
    RAW_STRING_LIT
    IDENTIFIER
    PACKAGE
    IMPORT
    VAR
    CONST
    TYPE
    STRUCT
    FUNC
    RETURN
    FOR
    BREAK
    CONTINUE
    IF
    ELSE
    SWITCH
    CASE
    DEFAULT
    .

%start_symbol compile_unit

compile_unit ::= declarations.

declarations ::= declarations declaration.

declaration ::= function_decl.
declaration ::= method_decl.

function_decl ::= FUNC IDENTIFIER parameters.

method_decl ::= FUNC L_PAREN R_PAREN IDENTIFIER parameters.

parameters ::= L_PAREN R_PAREN.

// parameter_pair
