#!/bin/bash

############################################################	VARIABLES	####
# PATHS
LOGS_PATH='./logs'

# LINES
div1="=================================================="


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

############################################	TEST FUNCTIONS DEFINITION	####
00_test_texture_params_format_ID_space_VALID_PATH_must_return_exit_code_0() {
# ARRANGE
INPUT_FILE='./valid_maps/00_valid_texture_parameters.cub'
EXPECTED_EXIT_CODE=0
LOG_FILE='test_00_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
# ../cub3D $INPUT_FILE
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 00_test_texture_params_format_ID_space_VALID_PATH_must_return_exit_code_0\n"
else
	printf "$BRED[NOK]$RESET 00_test_texture_params_format_ID_space_VALID_PATH_must_return_exit_code_0\n"
fi
}

01_test_texture_params_format_ID_many_spaces_VALID_PATH_must_return_exit_code_0() {
# ARRANGE
INPUT_FILE='./valid_maps/01_texture_ids_separated_by_many_spaces.cub'
EXPECTED_EXIT_CODE=0
LOG_FILE='test_01_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
# ../cub3D $INPUT_FILE
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 01_test_texture_params_format_ID_many_spaces_VALID_PATH_must_return_exit_code_0\n"
else
	printf "$BRED[NOK]$RESET 01_test_texture_params_format_ID_many_spaces_VALID_PATH_must_return_exit_code_0\n"
fi
}

02_test_NO_texture_param_format_ID_space_INVALID_PATH_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./valid_maps/02_invalid_NO_texture_parameter.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_02_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
# ../cub3D $INPUT_FILE
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 02_test_NO_texture_param_format_ID_space_INVALID_PATH_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 02_test_NO_texture_param_format_ID_space_INVALID_PATH_must_return_exit_code_1\n"
fi
}


##########################################################	EXECUTE TESTS	####
# CLEAR INITIAL TERMINAL WINDOW
clear

# PRINT HEADER
printf "\n${BYEL}+%.50s+" $div1
printf "\n${BYEL}+               ${REDB} ${BHWHT}CUB3D DESTROYER ${RESET}${BYEL}                  +"
printf "\n${BYEL}+          ${REDB} ${BHWHT}LET'S BREAK YOUR PARSER! ${RESET}${BYEL}              +"
printf "\n${BYEL}+              ${REDB} ${BHWHT}42 São Paulo 2022 ${RESET}${BYEL}                 +"
printf "\n${BYEL}+                ${REDB} ${BHWHT}by roaraujo ${RESET}${BYEL}                     +"
printf "\n${BYEL}+%.50s+\n${RESET}" $div1

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
		printf "\n${BGRN}Cub3D successfully made!\n\n${RESET}"
	fi
fi

# RUN TESTS
00_test_texture_params_format_ID_space_VALID_PATH_must_return_exit_code_0
01_test_texture_params_format_ID_many_spaces_VALID_PATH_must_return_exit_code_0
02_test_NO_texture_param_format_ID_space_INVALID_PATH_must_return_exit_code_1