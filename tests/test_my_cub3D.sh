#!/bin/bash

############################################################	VARIABLES	####
# PATHS
LOGS_PATH='./logs'

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

############################################	TEST FUNCTION DEFINITION	####
test_case() {
# ARRANGE
TEST_NAME=$1
INPUT_FILE=$2
EXPECTED_EXIT_CODE=$3
LOG_FILE=$4

# ASSERT
../cub3D $INPUT_FILE > $LOGS_PATH/$LOG_FILE 2>&1
ACTUAL_EXIT_CODE=$(($? != 0))
if [[ ACTUAL_EXIT_CODE -eq EXPECTED_EXIT_CODE ]]; then
	sleep .1 && printf "$BGRN [OK] $RESET"
else
	sleep .1 && printf "$BRED[NOK] $RESET"
fi
VALGRIND_RESULT=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck ../cub3D $INPUT_FILE 2>&1 >/dev/null | grep "==" | wc -l)
if [[ VALGRIND_RESULT -gt 0 ]]; then
	sleep .1 && printf "$BRED [NOK] $RESET"
else
	sleep .1 && printf "$BGRN [OK] $RESET"
fi
printf "\t$TEST_NAME\n"
}

##########################################################	EXECUTE TESTS	####
# CLEAR INITIAL TERMINAL WINDOW
clear

# PRINT HEADER
sleep .1 && printf "\n${BYEL}~                                                                           ~"
sleep .1 && printf "\n${BYEL}~                             ${YELB} ${BHWHT}TEST_MY_CUB3D ${RESET}${BYEL}                               ~"
sleep .1 && printf "\n${BYEL}~                       ${YELB} ${BHWHT}A tester written à la TDD ${RESET}${BYEL}                         ~"
sleep .1 && printf "\n${BYEL}~                            ${YELB} ${BHWHT}42 São Paulo 2022 ${RESET}${BYEL}                            ~"
sleep .1 && printf "\n${BYEL}~                              ${YELB} ${BHWHT}by roaraujo ${RESET}${BYEL}                                ~"
sleep .1 && printf "\n${BYEL}~                                                                           ~\n${RESET}"

# COMPILE cub3D
sleep .1 && printf "\n${BHWHT}Attempting to make cub3D in parent directory...\n"
sleep .1 && echo "$ make -C ../ &>/dev/null" && make -C ../ &>/dev/null

if [[ $? -ne 0 ]]; then
	sleep .1 && printf "\n${BYEL}${REDB}${BHWHT}Error: Failed to make cub3D in parent directory!${BYEL}\n${RESET}"
	exit 1
else
	ls .. | grep -q "cub3D$"
	if [[ $? -ne 0 ]]; then
		sleep .1 && printf "\n${BYEL}${REDB}${BHWHT}Error: Name of executable is wrong! [Correct naming \"cub3D\"]${BYEL}\n${RESET}"
		exit 1
	else
		sleep .1 && printf "\n${BGRN}Cub3D successfully built!${RESET}"
	fi
fi

sleep .1 && printf "\n\n${BHWHT}Copying cub3D binary to current directory...${RESET}"
sleep .1 && printf "\n$ cp ../cub3D ./cub3D" && cp ../cub3D ./cub3D

# CREATE LOGS FOLDER
sleep .1 && printf "\n\n${BHWHT}Making logs directory...${RESET}"
sleep .1 && printf "\n$ mkdir -p logs" && mkdir -p logs

# RUN TESTS
sleep .1 && printf "\n\n${BHWHT}Running tests...${RESET}"
sleep .1 && printf "\n  EC    VG  \n" && mkdir -p logs

## test_case 'test_description' 'input_path' expected_return_code 'log_path'
test_case '00_test_texture_params_format_ID_space_VALID_PATH_must_return_exit_code_0' './maps/valid/00_valid_texture_parameters.cub' 0 'test_00_err'
test_case '01_test_texture_params_format_ID_many_spaces_VALID_PATH_must_return_exit_code_0' './maps/valid/01_texture_ids_separated_by_many_spaces.cub' 0 'test_01_err'
test_case '02_test_NO_texture_param_format_ID_space_INVALID_PATH_must_return_exit_code_1' './maps/invalid/02_invalid_NO_texture_parameter.cub' 1 'test_02_err'
test_case '03_test_SO_texture_param_format_ID_space_INVALID_PATH_must_return_exit_code_1' './maps/invalid/03_invalid_SO_texture_parameter.cub' 1 'test_03_err'
test_case '04_test_EA_texture_param_format_ID_space_INVALID_PATH_must_return_exit_code_1' './maps/invalid/04_invalid_EA_texture_parameter.cub' 1 'test_04_err'
test_case '05_test_WE_texture_param_format_ID_space_INVALID_PATH_must_return_exit_code_1' './maps/invalid/05_invalid_WE_texture_parameter.cub' 1 'test_05_err'
test_case '06_test_floor_colour_format_F_space_255_comma_255_comma_255_must_return_exit_code_0' './maps/valid/06_valid_floor_colour_parameters.cub' 0 'test_06_err'
test_case '07_test_floor_colour_format_F_many_spaces_255_space_comma_255_space_comma_255_must_return_exit_code_0' './maps/valid/07_floor_colour_elements_separated_by_many_spaces.cub' 0 'test_07_err'
test_case '08_test_floor_colour_format_F_space_255_comma_255_comma_255_comma_must_return_exit_code_1' './maps/invalid/08_floor_colour_elements_with_trailing_commas.cub' 1 'test_08_err'
test_case '09_test_floor_colour_format_F_space_255_comma_255_comma_256_must_return_exit_code_1' './maps/invalid/09_floor_colour_elements_value_above_range.cub' 1 'test_09_err'
test_case '10_test_floor_colour_format_F_space_255_comma_255_comma_negative_1_must_return_exit_code_1' './maps/invalid/10_floor_colour_elements_value_bellow_range.cub' 1 'test_10_err'
test_case '11_test_floor_colour_format_F_space_255_comma_255_comma_2SS_must_return_exit_code_1' './maps/invalid/11_floor_colour_elements_value_alfanumeric.cub' 1 'test_11_err'
test_case '12_test_ceiling_colour_format_C_space_255_comma_255_comma_255_must_return_exit_code_0' './maps/valid/12_valid_ceiling_colour_parameters.cub' 0 'test_12_err'
test_case '13_test_ceiling_colour_format_C_many_spaces_255_space_comma_255_space_comma_255_must_return_exit_code_0' './maps/valid/13_ceiling_colour_elements_separated_by_many_spaces.cub' 0 'test_13_err'
test_case '14_test_ceiling_colour_format_C_space_255_comma_255_comma_255_comma_must_return_exit_code_1' './maps/invalid/14_ceiling_colour_elements_with_trailing_commas.cub' 1 'test_14_err'
test_case '15_test_ceiling_colour_format_C_space_255_comma_255_comma_256_must_return_exit_code_1' './maps/invalid/15_ceiling_colour_elements_value_above_range.cub' 1 'test_15_err'
test_case '16_test_ceiling_colour_format_C_space_255_comma_255_comma_negative_1_must_return_exit_code_1' './maps/invalid/16_ceiling_colour_elements_value_bellow_range.cub' 1 'test_16_err'
test_case '17_test_ceiling_colour_format_C_space_255_comma_255_comma_2SS_must_return_exit_code_1' './maps/invalid/17_ceiling_colour_elements_value_alfanumeric.cub' 1 'test_17_err'
test_case '18_test_missing_NO_texture_must_return_exit_code_1' './maps/invalid/18_missing_NO_texture.cub' 1 'test_18_err'
test_case '19_test_misplaced_NO_texture_must_return_exit_code_1' './maps/invalid/19_misplaced_NO_texture.cub' 1 'test_19_err'
test_case '20_test_missing_SO_texture_must_return_exit_code_1' './maps/invalid/20_missing_SO_texture.cub' 1 'test_20_err'
test_case '21_test_misplaced_SO_texture_must_return_exit_code_1' './maps/invalid/21_misplaced_SO_texture.cub' 1 'test_21_err'
test_case '22_test_missing_EA_texture_must_return_exit_code_1' './maps/invalid/22_missing_EA_texture.cub' 1 'test_22_err'
test_case '23_test_misplaced_EA_texture_must_return_exit_code_1' './maps/invalid/23_misplaced_EA_texture.cub' 1 'test_23_err'
test_case '24_test_missing_WE_texture_must_return_exit_code_1' './maps/invalid/24_missing_WE_texture.cub' 1 'test_24_err'
test_case '25_test_misplaced_WE_texture_must_return_exit_code_1' './maps/invalid/25_misplaced_WE_texture.cub' 1 'test_25_err'
test_case '26_test_missing_F_colour_must_return_exit_code_1' './maps/invalid/26_missing_F_colour.cub' 1 'test_26_err'
test_case '27_test_misplaced_F_colour_must_return_exit_code_1' './maps/invalid/27_misplaced_F_colour.cub' 1 'test_27_err'
test_case '28_test_missing_C_colour_must_return_exit_code_1' './maps/invalid/28_missing_C_colour.cub' 1 'test_28_err'
test_case '29_test_misplaced_C_colour_must_return_exit_code_1' './maps/invalid/29_misplaced_C_colour.cub' 1 'test_29_err'
test_case '30_test_scrambled_parameters_order_must_return_exit_code_0' './maps/valid/30_scrambled_parameters_order.cub' 0 'test_30_err'
test_case '31_test_many_line_breaks_between_parameters_must_return_exit_code_0' './maps/valid/31_many_line_breaks_between_parameters.cub' 0 'test_31_err'
test_case '32_test_too_many_F_colour_elements_must_return_exit_code_1' './maps/invalid/32_too_many_floor_colour_elements.cub' 1 'test_32_err'
test_case '33_test_too_few_F_colour_elements_must_return_exit_code_1' './maps/invalid/33_too_few_floor_colour_elements.cub' 1 'test_33_err'
test_case '34_test_empty_F_colour_element_must_return_exit_code_1' './maps/invalid/34_empty_floor_colour_element.cub' 1 'test_34_err'
test_case '35_test_all_empty_F_colour_elements_must_return_exit_code_1' './maps/invalid/35_all_empty_floor_colour_elements.cub' 1 'test_35_err'
test_case '36_test_too_many_C_colour_elements_must_return_exit_code_1' './maps/invalid/36_too_many_ceiling_colour_elements.cub' 1 'test_36_err'
test_case '37_test_too_few_C_colour_elements_must_return_exit_code_1' './maps/invalid/37_too_few_ceiling_colour_elements.cub' 1 'test_37_err'
test_case '38_test_empty_C_colour_element_must_return_exit_code_1' './maps/invalid/38_empty_ceiling_colour_element.cub' 1 'test_38_err'
test_case '39_test_all_empty_C_colour_elements_must_return_exit_code_1' './maps/invalid/39_all_empty_ceiling_colour_elements.cub' 1 'test_39_err'
test_case '40_test_duplicate_NO_texture_parameter_must_return_exit_code_1' './maps/invalid/40_duplicate_NO_parameter.cub' 1 'test_40_err'
test_case '41_test_duplicate_SO_texture_parameter_must_return_exit_code_1' './maps/invalid/41_duplicate_SO_parameter.cub' 1 'test_41_err'
test_case '42_test_duplicate_EA_texture_parameter_must_return_exit_code_1' './maps/invalid/42_duplicate_EA_parameter.cub' 1 'test_42_err'
test_case '43_test_duplicate_WE_texture_parameter_must_return_exit_code_1' './maps/invalid/43_duplicate_WE_parameter.cub' 1 'test_43_err'
test_case '44_test_valid_square_map_surrounded_by_ones_must_return_exit_code_0' './maps/valid/44_valid_square_map.cub' 0 'test_44_err'
test_case '45_test_invalid_square_map_not_surrounded_by_ones_must_return_exit_code_1' './maps/invalid/45_invalid_square_map.cub' 1 'test_45_err'
test_case '46_test_if_line_starts_with_spaces_must_return_exit_code_0' './maps/valid/46_valid_T_map.cub' 0 'test_46_err'
test_case '47_test_valid_irregular_map_surrounded_by_ones_at_right_angles_must_return_exit_code_0' './maps/valid/47_valid_irregular_map_surrounded_by_ones.cub' 0 'test_47_err'
test_case '48_test_invalid_map_with_invalid_character_must_return_exit_code_1' './maps/invalid/48_invalid_map_with_invalid_character.cub' 1 'test_48_err'
test_case '49_test_map_with_no_starting_position_character_must_return_exit_code_1' './maps/invalid/49_invalid_map_with_no_starting_position_character.cub' 1 'test_49_err'
test_case '50_test_map_with_two_starting_position_characters_must_return_exit_code_1' './maps/invalid/50_invalid_map_with_two_starting_position_characters.cub' 1 'test_50_err'
test_case '51_test_bumpy_map_with_starting_position_within_must_return_exit_code_0' './maps/valid/51_starting_position_within_bumpy_map.cub' 0 'test_51_err'
test_case '52_test_circle_map_with_hole_and_starting_position_within_must_return_exit_code_0' './maps/valid/52_starting_position_within_map_with_hole.cub' 0 'test_52_err'
test_case '53_test_bumpy_map_with_starting_position_outside_must_return_exit_code_1' './maps/invalid/53_starting_position_outside_bumpy_map.cub' 1 'test_53_err'
test_case '54_test_passing_no_args_must_return_exit_code_1' '' 1 'test_54_err'
test_case '55_test_passing_non_existing_input_file_must_return_exit_code_1' 'void.cub' 1 'test_55_err'
test_case '56_test_passing_wrong_file_format_must_return_exit_code_1' 'cube.pdf' 1 'test_56_err'
test_case '57_test_passing_misleading_file_format_must_return_exit_code_1' 'cube.cube' 1 'test_57_err'

# ESQUECI DE ESCREVER TESTE DE FORMATO ERRADO D: .cub

# CLEAN UP
printf "\nCleaning up...\n"
rm ./cub3D

printf "\nTests completed.\n"
