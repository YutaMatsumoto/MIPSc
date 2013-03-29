#
#       Compiles MIPSc And Comes Back To Compiler/ Directory
#
function compile()
{
	./regen.bash &&  cd ../../Debug/ && make clean && make 
	cd -
}

# 
#       Runs A Test File
#
# Example
#
# $ run ts_good1.c
#
function test() 
{
	../../Debug/MIPSc -d ../Tests/$1
}

function mktags()
{
	ctags -R .	
}

#
#       Regenerate
#
function regen()
{
	bisonc++ --debug parser.y
	flexc++ scanner.lex
}
