if [ -z "$1" ] || [ -z "$2" ]; 
then 
	echo "./test.sh <player> <nb of cycle>"; 
	echo "Player must be just 'Car' and not 'Car.cor'"
else
	./../resources/corewar -d $2 -v 30 .champs/$1.cor | tail -n 64 > .b
	if [[ $(cat .b | grep cycles | wc -l) -eq 0 ]]
	then
		./corewar -dump $2 .champs/$1.cor | grep -A 63 0000 > .a
		res=$(diff .a .b)
		rm .a .b
		if [[ -z "$res" ]]
		then echo "Output are the same, congrats"
		else
			echo "$res"
		fi
	else echo "Cant compare dump because game is over, try decreasing nb cycle"
	fi
fi
