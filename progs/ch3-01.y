%token NAME NUMBER
%%
statement:	NAME '=' expression
	|	expression		{ printf("= %d\n", $1); }
	;

expression:	expression '+' NUMBER	{ $$ = $1 + $3; printf("plus expression found\n"); }
	|	expression '-' NUMBER	{ $$ = $1 - $3; printf("minus expression found\n");}
	|	NUMBER			{ $$ = $1; printf("number expression found\n");}
	;
