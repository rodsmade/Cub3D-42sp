#!/bin/bash

##########################################################	PRINT COLOURS	####
#Regular bold text
BRED="\e[1;31m"
BGRN="\e[1;32m"
BYEL="\e[1;33m"
BBLU="\e[1;34m"
BWHT="\e[1;37m"

#Regular background
REDB="\e[41m"
YELB="\e[43m"

#High intensty text
HRED="\e[0;91m"
HYEL="\e[0;93m"
HWHT="\e[0;97m"

#High intensty background
YELHB="\e[0;103m"

#Bold high intensity text
BHYEL="\e[1;93m"
BHWHT="\e[1;97m"

RESET="\033[0m"

############################################################	VARIABLES	####
# LINES
div1="=================================================="
div2="--------------------------------------------------"

############################################	TEST FUNCTIONS DEFINITION	####
test_texture_params_exact_format_ID_space_VALID_PATH_must_return_OK() {
# ARRANGE
INPUT_FILE='./valid_maps/valid_texture_parameters.cub'
EXPECTED_EXIT_CODE=0

# ASSERT
../cub3D $INPUT_FILE
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET test_texture_params_exact_format_ID_space_VALID_PATH_must_return_OK"
else
	printf "$BRED[NOK]$RESET test_texture_params_exact_format_ID_space_VALID_PATH_must_return_OK"
fi
}


##########################################################	EXECUTE TESTS	####
# CLEAR INITIAL TERMINAL WINDOW
clear

# PRINT HEADER
printf "\n\t${BYEL}+%.36s+" $div1
printf "\n\t${BYEL}+%.36s+" $div2
printf "\n\t${BYEL}+---------${REDB} ${BHWHT}CUB3D DESTROYER ${RESET}${BYEL}----------+"
printf "\n\t${BYEL}+-----${REDB} ${BHWHT}LET'S BREAK YOUR PARSER! ${RESET}${BYEL}-----+"
printf "\n\t${BYEL}+--------${REDB} ${BHWHT}42 São Paulo 2022 ${RESET}${BYEL}---------+"
printf "\n\t${BYEL}+-----------${REDB} ${BHWHT}by roaraujo ${RESET}${BYEL}------------+"
printf "\n\t${BYEL}+%.36s+" $div2
printf "\n\t${BYEL}+%.36s+\n${RESET}" $div1

# COMPILE cub3D
printf "\n${BHWHT}Attempting to make cub3D in parent directory...\n"
echo "$ make -C ../ &>/dev/null" && make -C ../ &>/dev/null

if [[ $? -ne 0 ]]; then
	printf "\n${BYEL}${REDB}${BHWHT}Error: Failed to make cub3D in parent directory!${BYEL}\n${RESET}"
	exit 1
else
	ls .. | grep -q "cub3D$"
	if [[ $? -ne 0 ]]; then
		printf "\n${BYEL}${REDB}${BHWHT}Error: Name of executable is wrong! [Correct naming \"cub3D\"]${BYEL}\n${RESET}"
		exit 1
	else
		printf "\n${BGRN}Cub3D successfully made!\n${RESET}"
	fi
fi

# RUN TESTS
test_texture_params_exact_format_ID_space_VALID_PATH_must_return_OK