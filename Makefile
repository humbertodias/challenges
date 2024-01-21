FILE_NAME=Main

STIME = @date '+%s' > $@_time
ETIME = @read st < $@_time ; st=$$((`date '+%s'`-$$st-68400)) ; echo  Elapsed time: `date -r $$st '+%H:%M:%S'`

run: run_c run_cs run_cpp run_java run_python2 run_python3 run_ruby run_go

run_c: compile_c

	@echo -n 'C = '
	@./"$(FILE_NAME)_c" < in.txt > out.txt
	@-diff ok.txt out.txt &> diff.txt
	@[ -s diff.txt ] || echo "OK"

run_go: compile_go

	@echo -n 'GO = '
	@./"$(FILE_NAME)_go" < in.txt > out.txt
	@-diff ok.txt out.txt &> diff.txt
	@[ -s diff.txt ] || echo "OK"

run_cs: compile_cs

	@echo -n 'C# = '
	@mono "$(FILE_NAME)_cs" < in.txt > out.txt
	@-diff ok.txt out.txt &> diff.txt
	@[ -s diff.txt ] || echo "OK"

run_cpp: compile_cpp
	@echo -n 'CPP = '
	@./"$(FILE_NAME)_cpp" < in.txt > out.txt
	@-diff ok.txt out.txt &> diff.txt
	@[ -s diff.txt ] || echo "OK" 

run_java: compile_java

	@echo -n 'Java = '
	@java "$(FILE_NAME)" < in.txt > out.txt 
	@-diff ok.txt out.txt &> diff.txt
	@[ -s diff.txt ] || echo "OK"

run_python2: compile_python2

	@echo -n 'Python2 = '
	@which python2 && @python2 "$(FILE_NAME)2.pyc" < in.txt > out.txt || echo "Skip"
	@-diff ok.txt out.txt &> diff.txt
	@[ -s diff.txt ] || echo "OK"

run_python3: compile_python3

	@echo -n 'Python3 = '
	@python3 "$(FILE_NAME)3.py" < in.txt > out.txt
	@-diff ok.txt out.txt &> diff.txt
	@[ -s diff.txt ] || echo "OK"

run_ruby: compile_ruby

	@echo -n 'Ruby = '
	@ruby "$(FILE_NAME).rb" < in.txt > out.txt
	@-diff ok.txt out.txt &> diff.txt
	@[ -s diff.txt ] || echo "OK"

	
compile_c:
	@gcc "$(FILE_NAME).c" -o "$(FILE_NAME)_c" -O2 -lm

compile_go:
	@go build -o "$(FILE_NAME)_go" "$(FILE_NAME).go"

compile_cs:
	@mcs "$(FILE_NAME).cs" -out:"$(FILE_NAME)_cs"

compile_cpp:
	@g++ "$(FILE_NAME).cpp" -o "$(FILE_NAME)_cpp" -Wall -std=c++11 -O2 -lm

compile_java:
	@javac "$(FILE_NAME).java"

compile_python2:
	@which python2 && @python2 -m py_compile "$(FILE_NAME)2.py" || echo "Python2 not found"

compile_python3:
	@python3 -m py_compile "$(FILE_NAME)3.py"

compile_ruby:
# Ruby does not require compilation

compile: compile_c compile_cpp compile_java compile_python2 compile_python3 compile_ruby

clean:
	@rm -rf __pycache__ *.BAK out.txt diff.txt *.class *.pyc $(FILE_NAME)_cpp $(FILE_NAME)_c $(FILE_NAME)_cs $(FILE_NAME)_go

clean_all:
	find -L . \( -name "__pycache__" -or -name "*.BAK" -or -name "out.txt" -or -name "diff.txt" -or -name "*.pyc" -or -name "*.class" -or -name "$(FILE_NAME)_cpp" -or -name "$(FILE_NAME)_c" -or -name "$(FILE_NAME)_cs" -or -name "$(FILE_NAME)_go" \) -exec rm -rf {} \;

