# ----------------------------------------------------------------------------
# 
#       Find Functions
#
function find_dir_from_top
{
	find $top -type d -name "$1"
}

function find_dir_in_src
{
	find $src_dir -type d -name "$1"
}

function find_file_from_top
{
	find $top -type f -name "$1"
}

# ----------------------------------------------------------------------------
# set variables

top=$(git rev-parse --show-toplevel)
src_dir="$top/src"
debug_dir=$top
compiler_dir=$(find_dir_in_src Compiler)
test_dir=$(find_dir_in_src Tests)
makefile=$debug_dir/makefile
mipsc=$debug_dir/mipsc

# ----------------------------------------------------------------------------
# 

#
#       Compiles MIPSc And Comes Back To Compiler/ Directory
#
function compile()
{
	backto=$(pwd)
	cd $compiler_dir	 
	# $compiler_dir/regen.bash $@ && cd $debug_dir && make 
	cd $debug_dir 
	rsync -r --progress --update $src_dir $debug_dir
	make
	retval=$?
	cd $backto
	return $retval
}

function clean()
{
	backto=$(pwd)
	cd $debug_dir && make clean
	cd $backto
}

# 
#       Runs A Test File
#
# Example
#
# $ test ts_good1.c
#
function run_test() 
{
	$mipsc -d $test_dir/$1 2>&1
	return $?
}

function make_tags()
{
	cd $top
	ctags -R .	
	cd -
}

#
#       Regenerate
#
function regen()
{
	cd $debug_dir
	bisonc++ --debug parser.y
	flexc++ scanner.lex
	cd -
}

# 
# test 
#

# test 
function t()
{
	echo "Executing Util2.sh t()"
	echo "on test_dir: $test_dir"
	echo "with mipsc $mipsc"

	for c in $( find $test_dir -name "*.c"); do
		# echo "Executing $mipsc $c >/dev/null 2>&1"
		$mipsc $c >/dev/null 2>&1
		if [ $? -ne 0 ]; then
			echo "$c does not compile"
		fi
	done
}

# test verbose
function tv()
{
	for c in $( find $test_dir -name "*.c"); do
		$mipsc $c >/dev/null 2>&1
		if [ $? -ne 0 ]; then
			echo "$c does not compile"
		else
			echo "$c compiles"
		fi
	done
}

