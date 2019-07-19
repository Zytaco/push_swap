# !/bin/bash
make all

# tput setaf 1; echo "\n\n\n10 x random array of 5 integers (0 to 4)"
# i="0"
# while [ $i -lt 10 ]
# do
# 	arg=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`
# 	# echo $arg
# 	./push_swap $arg | ./checker $arg
# i=$[i+1]
# done

# sleep 1
# tput setaf 2; echo "\n\n\n10 x random array of 5 integers (-4 to 0)"
# i="0"
# while [ $i -lt 10 ]
# do
# 	arg=`ruby -e "puts (-4..0).to_a.shuffle.join(' ')"`
# 	# echo $arg
# 	./push_swap $arg | ./checker $arg
# i=$[i+1]
# done

sleep 1
tput setaf 3; echo "\n\n\n10 x random array of 100 integers (-99 to 0)"
i="0"
while [ $i -lt 10 ]
do
	arg=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
	echo $arg
	./push_swap $arg | ./checker $arg
i=$[i+1]
done

# sleep 1
# tput setaf 4; echo "\n\n\n10 x random array of 100 integers (0 to 99)"
# i="0"
# while [ $i -lt 10 ]
# do
# 	arg=`ruby -e "puts (-99..0).to_a.shuffle.join(' ')"`
# 	echo $arg
# 	./push_swap $arg | ./checker $arg
# i=$[i+1]
# done

sleep 1
tput setaf 5; echo "\n\n\n10 x random array of 500 integers"
i="0"
while [ $i -lt 10 ]
do
	arg=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
	echo $arg
	./push_swap $arg | ./checker $arg
i=$[i+1]
done

# sleep 1
# tput setaf 6; echo "\n\n\n10 x random array of 500 integers (-500 to -0)"
# i="0"
# while [ $i -lt 10 ]
# do
# 	arg=`ruby -e "puts (-499..0).to_a.shuffle.join(' ')"`
# 	# echo $arg
# 	./push_swap $arg | ./checker $arg
# i=$[i+1]
# done
