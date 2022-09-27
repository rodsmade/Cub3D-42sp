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
INPUT_FILE='./maps/valid/00_valid_texture_parameters.cub'
EXPECTED_EXIT_CODE=0
LOG_FILE='test_00_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 00_test_texture_params_format_ID_space_VALID_PATH_must_return_exit_code_0\n"
else
	printf "$BRED[NOK]$RESET 00_test_texture_params_format_ID_space_VALID_PATH_must_return_exit_code_0\n"
fi
}

01_test_texture_params_format_ID_many_spaces_VALID_PATH_must_return_exit_code_0() {
# ARRANGE
INPUT_FILE='./maps/valid/01_texture_ids_separated_by_many_spaces.cub'
EXPECTED_EXIT_CODE=0
LOG_FILE='test_01_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 01_test_texture_params_format_ID_many_spaces_VALID_PATH_must_return_exit_code_0\n"
else
	printf "$BRED[NOK]$RESET 01_test_texture_params_format_ID_many_spaces_VALID_PATH_must_return_exit_code_0\n"
fi
}

02_test_NO_texture_param_format_ID_space_VALID_PATH_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/02_valid_NO_texture_parameter.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_02_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 02_test_NO_texture_param_format_ID_space_VALID_PATH_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 02_test_NO_texture_param_format_ID_space_VALID_PATH_must_return_exit_code_1\n"
fi
}

03_test_SO_texture_param_format_ID_space_VALID_PATH_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/03_valid_SO_texture_parameter.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_03_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 03_test_SO_texture_param_format_ID_space_VALID_PATH_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 03_test_SO_texture_param_format_ID_space_VALID_PATH_must_return_exit_code_1\n"
fi
}

04_test_EA_texture_param_format_ID_space_VALID_PATH_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/04_valid_EA_texture_parameter.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_04_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 04_test_EA_texture_param_format_ID_space_VALID_PATH_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 04_test_EA_texture_param_format_ID_space_VALID_PATH_must_return_exit_code_1\n"
fi
}

05_test_WE_texture_param_format_ID_space_VALID_PATH_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/05_valid_WE_texture_parameter.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_05_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 05_test_WE_texture_param_format_ID_space_VALID_PATH_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 05_test_WE_texture_param_format_ID_space_VALID_PATH_must_return_exit_code_1\n"
fi
}

06_test_floor_colour_format_F_space_255_comma_255_comma_255_must_return_exit_code_0() {
# ARRANGE
INPUT_FILE='./maps/valid/06_valid_floor_colour_parameters.cub'
EXPECTED_EXIT_CODE=0
LOG_FILE='test_06_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 06_test_floor_colour_format_F_space_255_comma_255_comma_255_must_return_exit_code_0\n"
else
	printf "$BRED[NOK]$RESET 06_test_floor_colour_format_F_space_255_comma_255_comma_255_must_return_exit_code_0\n"
fi
}

07_test_floor_colour_format_F_many_spaces_255_space_comma_255_space_comma_255_must_return_exit_code_0() {
# ARRANGE
INPUT_FILE='./maps/valid/07_floor_colour_elements_separated_by_many_spaces.cub'
EXPECTED_EXIT_CODE=0
LOG_FILE='test_07_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 07_test_floor_colour_format_F_many_spaces_255_space_comma_255_space_comma_255_must_return_exit_code_0\n"
else
	printf "$BRED[NOK]$RESET 07_test_floor_colour_format_F_many_spaces_255_space_comma_255_space_comma_255_must_return_exit_code_0\n"
fi
}

08_test_floor_colour_format_F_space_255_comma_255_comma_255_comma_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/08_floor_colour_elements_with_trailing_commas.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_08_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 08_test_floor_colour_format_F_space_255_comma_255_comma_255_comma_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 08_test_floor_colour_format_F_space_255_comma_255_comma_255_comma_must_return_exit_code_1\n"
fi
}

09_test_floor_colour_format_F_space_255_comma_255_comma_256_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/09_floor_colour_elements_value_above_range.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_09_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 09_test_floor_colour_format_F_space_255_comma_255_comma_256_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 09_test_floor_colour_format_F_space_255_comma_255_comma_256_must_return_exit_code_1\n"
fi
}

10_test_floor_colour_format_F_space_255_comma_255_comma_negative_1_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/10_floor_colour_elements_value_bellow_range.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_10_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 10_test_floor_colour_format_F_space_255_comma_255_comma_negative_1_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 10_test_floor_colour_format_F_space_255_comma_255_comma_negative_1_must_return_exit_code_1\n"
fi
}

11_test_floor_colour_format_F_space_255_comma_255_comma_2SS_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/11_floor_colour_elements_value_alfanumeric.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_11_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 11_test_floor_colour_format_F_space_255_comma_255_comma_2SS_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 11_test_floor_colour_format_F_space_255_comma_255_comma_2SS_must_return_exit_code_1\n"
fi
}

12_test_ceiling_colour_format_C_space_255_comma_255_comma_255_must_return_exit_code_0() {
# ARRANGE
INPUT_FILE='./maps/valid/12_valid_ceiling_colour_parameters.cub'
EXPECTED_EXIT_CODE=0
LOG_FILE='test_12_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 12_test_ceiling_colour_format_C_space_255_comma_255_comma_255_must_return_exit_code_0\n"
else
	printf "$BRED[NOK]$RESET 12_test_ceiling_colour_format_C_space_255_comma_255_comma_255_must_return_exit_code_0\n"
fi
}

13_test_ceiling_colour_format_C_many_spaces_255_space_comma_255_space_comma_255_must_return_exit_code_0() {
# ARRANGE
INPUT_FILE='./maps/valid/13_ceiling_colour_elements_separated_by_many_spaces.cub'
EXPECTED_EXIT_CODE=0
LOG_FILE='test_13_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 13_test_ceiling_colour_format_C_many_spaces_255_space_comma_255_space_comma_255_must_return_exit_code_0\n"
else
	printf "$BRED[NOK]$RESET 13_test_ceiling_colour_format_C_many_spaces_255_space_comma_255_space_comma_255_must_return_exit_code_0\n"
fi
}

14_test_ceiling_colour_format_C_space_255_comma_255_comma_255_comma_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/14_ceiling_colour_elements_with_trailing_commas.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_14_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 14_test_ceiling_colour_format_C_space_255_comma_255_comma_255_comma_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 14_test_ceiling_colour_format_C_space_255_comma_255_comma_255_comma_must_return_exit_code_1\n"
fi
}

15_test_ceiling_colour_format_C_space_255_comma_255_comma_256_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/15_ceiling_colour_elements_value_above_range.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_15_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 15_test_ceiling_colour_format_C_space_255_comma_255_comma_256_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 15_test_ceiling_colour_format_C_space_255_comma_255_comma_256_must_return_exit_code_1\n"
fi
}

16_test_ceiling_colour_format_C_space_255_comma_255_comma_negative_1_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/16_ceiling_colour_elements_value_bellow_range.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_16_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 16_test_ceiling_colour_format_C_space_255_comma_255_comma_negative_1_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 16_test_ceiling_colour_format_C_space_255_comma_255_comma_negative_1_must_return_exit_code_1\n"
fi
}

17_test_ceiling_colour_format_C_space_255_comma_255_comma_2SS_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/17_ceiling_colour_elements_value_alfanumeric.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_17_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 17_test_ceiling_colour_format_C_space_255_comma_255_comma_2SS_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 17_test_ceiling_colour_format_C_space_255_comma_255_comma_2SS_must_return_exit_code_1\n"
fi
}

18_test_missing_NO_texture_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/18_missing_NO_texture.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_18_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 18_test_missing_NO_texture_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 18_test_missing_NO_texture_must_return_exit_code_1\n"
fi
}

19_test_misplaced_NO_texture_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/19_misplaced_NO_texture.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_19_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 19_test_misplaced_NO_texture_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 19_test_misplaced_NO_texture_must_return_exit_code_1\n"
fi
}

20_test_missing_SO_texture_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/20_missing_SO_texture.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_20_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 20_test_missing_SO_texture_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 20_test_missing_SO_texture_must_return_exit_code_1\n"
fi
}

21_test_misplaced_SO_texture_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/21_misplaced_SO_texture.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_21_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 21_test_misplaced_SO_texture_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 21_test_misplaced_SO_texture_must_return_exit_code_1\n"
fi
}

22_test_missing_EA_texture_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/22_missing_EA_texture.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_22_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 22_test_missing_EA_texture_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 22_test_missing_EA_texture_must_return_exit_code_1\n"
fi
}

23_test_misplaced_EA_texture_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/23_misplaced_EA_texture.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_23_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 23_test_misplaced_EA_texture_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 23_test_misplaced_EA_texture_must_return_exit_code_1\n"
fi
}

24_test_missing_WE_texture_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/24_missing_WE_texture.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_24_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 24_test_missing_WE_texture_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 24_test_missing_WE_texture_must_return_exit_code_1\n"
fi
}

25_test_misplaced_WE_texture_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/25_misplaced_WE_texture.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_25_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 25_test_misplaced_WE_texture_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 25_test_misplaced_WE_texture_must_return_exit_code_1\n"
fi
}

26_test_missing_F_colour_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/26_missing_F_colour.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_26_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 26_test_missing_F_colour_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 26_test_missing_F_colour_must_return_exit_code_1\n"
fi
}

27_test_misplaced_F_colour_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/27_misplaced_F_colour.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_27_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 27_test_misplaced_F_colour_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 27_test_misplaced_F_colour_must_return_exit_code_1\n"
fi
}

28_test_missing_C_colour_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/28_missing_C_colour.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_28_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 28_test_missing_C_colour_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 28_test_missing_C_colour_must_return_exit_code_1\n"
fi
}

29_test_misplaced_C_colour_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/29_misplaced_C_colour.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_29_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 29_test_misplaced_C_colour_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 29_test_misplaced_C_colour_must_return_exit_code_1\n"
fi
}

30_test_scrambled_parameters_order_must_return_exit_code_0() {
# ARRANGE
INPUT_FILE='./maps/valid/30_scrambled_parameters_order.cub'
EXPECTED_EXIT_CODE=0
LOG_FILE='test_30_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 30_test_scrambled_parameters_order_must_return_exit_code_0\n"
else
	printf "$BRED[NOK]$RESET 30_test_scrambled_parameters_order_must_return_exit_code_0\n"
fi
}

31_test_many_line_breaks_between_parameters_must_return_exit_code_0() {
# ARRANGE
INPUT_FILE='./maps/valid/31_many_line_breaks_between_parameters.cub'
EXPECTED_EXIT_CODE=0
LOG_FILE='test_31_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 31_test_many_line_breaks_between_parameters_must_return_exit_code_0\n"
else
	printf "$BRED[NOK]$RESET 31_test_many_line_breaks_between_parameters_must_return_exit_code_0\n"
fi
}

32_test_too_many_F_colour_elements_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/32_too_many_floor_colour_elements.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_32_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 32_test_too_many_F_colour_elements_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 32_test_too_many_F_colour_elements_must_return_exit_code_1\n"
fi
}

33_test_too_few_F_colour_elements_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/33_too_few_floor_colour_elements.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_33_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 33_test_too_few_F_colour_elements_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 33_test_too_few_F_colour_elements_must_return_exit_code_1\n"
fi
}

34_test_empty_F_colour_element_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/34_empty_floor_colour_element.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_34_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 34_test_empty_F_colour_element_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 34_test_empty_F_colour_element_must_return_exit_code_1\n"
fi
}

35_test_all_empty_F_colour_elements_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/35_all_empty_floor_colour_elements.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_35_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 35_test_all_empty_F_colour_elements_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 35_test_all_empty_F_colour_elements_must_return_exit_code_1\n"
fi
}

36_test_too_many_C_colour_elements_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/36_too_many_ceiling_colour_elements.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_36_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 36_test_too_many_C_colour_elements_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 36_test_too_many_C_colour_elements_must_return_exit_code_1\n"
fi
}

37_test_too_few_C_colour_elements_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/37_too_few_ceiling_colour_elements.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_37_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 37_test_too_few_C_colour_elements_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 37_test_too_few_C_colour_elements_must_return_exit_code_1\n"
fi
}

38_test_empty_C_colour_element_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/38_empty_ceiling_colour_element.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_38_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 38_test_empty_C_colour_element_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 38_test_empty_C_colour_element_must_return_exit_code_1\n"
fi
}

39_test_all_empty_C_colour_elements_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/39_all_empty_ceiling_colour_elements.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_39_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 39_test_all_empty_C_colour_elements_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 39_test_all_empty_C_colour_elements_must_return_exit_code_1\n"
fi
}

40_test_duplicate_NO_texture_parameter_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/40_duplicate_NO_parameter.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_40_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 40_test_duplicate_NO_texture_parameter_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 40_test_duplicate_NO_texture_parameter_must_return_exit_code_1\n"
fi
}

41_test_duplicate_SO_texture_parameter_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/41_duplicate_SO_parameter.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_41_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 41_test_duplicate_SO_texture_parameter_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 41_test_duplicate_SO_texture_parameter_must_return_exit_code_1\n"
fi
}

42_test_duplicate_EA_texture_parameter_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/42_duplicate_EA_parameter.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_42_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 42_test_duplicate_EA_texture_parameter_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 42_test_duplicate_EA_texture_parameter_must_return_exit_code_1\n"
fi
}

43_test_duplicate_WE_texture_parameter_must_return_exit_code_1() {
# ARRANGE
INPUT_FILE='./maps/invalid/43_duplicate_WE_parameter.cub'
EXPECTED_EXIT_CODE=1
LOG_FILE='test_43_err'

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
if [[ $? -eq EXPECTED_EXIT_CODE ]]; then
	printf "$BGRN[OK]$RESET 43_test_duplicate_WE_texture_parameter_must_return_exit_code_1\n"
else
	printf "$BRED[NOK]$RESET 43_test_duplicate_WE_texture_parameter_must_return_exit_code_1\n"
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
		printf "\n${BGRN}Cub3D successfully built!\n\n${RESET}"
	fi
fi

# RUN TESTS
00_test_texture_params_format_ID_space_VALID_PATH_must_return_exit_code_0
01_test_texture_params_format_ID_many_spaces_VALID_PATH_must_return_exit_code_0
02_test_NO_texture_param_format_ID_space_VALID_PATH_must_return_exit_code_1
03_test_SO_texture_param_format_ID_space_VALID_PATH_must_return_exit_code_1
04_test_EA_texture_param_format_ID_space_VALID_PATH_must_return_exit_code_1
05_test_WE_texture_param_format_ID_space_VALID_PATH_must_return_exit_code_1
06_test_floor_colour_format_F_space_255_comma_255_comma_255_must_return_exit_code_0
07_test_floor_colour_format_F_many_spaces_255_space_comma_255_space_comma_255_must_return_exit_code_0
08_test_floor_colour_format_F_space_255_comma_255_comma_255_comma_must_return_exit_code_1
09_test_floor_colour_format_F_space_255_comma_255_comma_256_must_return_exit_code_1
10_test_floor_colour_format_F_space_255_comma_255_comma_negative_1_must_return_exit_code_1
11_test_floor_colour_format_F_space_255_comma_255_comma_2SS_must_return_exit_code_1
12_test_ceiling_colour_format_C_space_255_comma_255_comma_255_must_return_exit_code_0
13_test_ceiling_colour_format_C_many_spaces_255_space_comma_255_space_comma_255_must_return_exit_code_0
14_test_ceiling_colour_format_C_space_255_comma_255_comma_255_comma_must_return_exit_code_1
15_test_ceiling_colour_format_C_space_255_comma_255_comma_256_must_return_exit_code_1
16_test_ceiling_colour_format_C_space_255_comma_255_comma_negative_1_must_return_exit_code_1
17_test_ceiling_colour_format_C_space_255_comma_255_comma_2SS_must_return_exit_code_1
18_test_missing_NO_texture_must_return_exit_code_1
17_test_ceiling_colour_format_C_space_255_comma_255_comma_2SS_must_return_exit_code_1
18_test_missing_NO_texture_must_return_exit_code_1
19_test_misplaced_NO_texture_must_return_exit_code_1
20_test_missing_SO_texture_must_return_exit_code_1
21_test_misplaced_SO_texture_must_return_exit_code_1
22_test_missing_EA_texture_must_return_exit_code_1
23_test_misplaced_EA_texture_must_return_exit_code_1
24_test_missing_WE_texture_must_return_exit_code_1
25_test_misplaced_WE_texture_must_return_exit_code_1
26_test_missing_F_colour_must_return_exit_code_1
27_test_misplaced_F_colour_must_return_exit_code_1
28_test_missing_C_colour_must_return_exit_code_1
29_test_misplaced_C_colour_must_return_exit_code_1
30_test_scrambled_parameters_order_must_return_exit_code_0
31_test_many_line_breaks_between_parameters_must_return_exit_code_0
32_test_too_many_F_colour_elements_must_return_exit_code_1
33_test_too_few_F_colour_elements_must_return_exit_code_1
34_test_empty_F_colour_element_must_return_exit_code_1
35_test_all_empty_F_colour_elements_must_return_exit_code_1
36_test_too_many_C_colour_elements_must_return_exit_code_1
37_test_too_few_C_colour_elements_must_return_exit_code_1
38_test_empty_C_colour_element_must_return_exit_code_1
39_test_all_empty_C_colour_elements_must_return_exit_code_1
40_test_duplicate_NO_texture_parameter_must_return_exit_code_1
41_test_duplicate_SO_texture_parameter_must_return_exit_code_1
42_test_duplicate_EA_texture_parameter_must_return_exit_code_1
43_test_duplicate_WE_texture_parameter_must_return_exit_code_1