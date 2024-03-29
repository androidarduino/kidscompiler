%{
/*
 * A lexer for the basic grammar to use for recognizing english sentences.
 */
#include <stdio.h>
#include "y.tab.h"
%}

%token NOUN PRONOUN VERB ADVERB ADJECTIVE PREPOSITION CONJUNCTION

%%
sentence: subject VERB object	{ printf("Sentence is valid.\n"); }
	;

subject:	NOUN
	|	PRONOUN
	;

object:		NOUN
	;
%%

extern FILE *yyin;

main()
{
        do
        {
		yyparse();
	}
	while(!feof(yyin)); 
}

yyerror(s)
char *s;
{
    fprintf(stderr, "%s\n", s);
}
