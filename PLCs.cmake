################ UPSafePi ################
set(UPSAFEPI_VERSIONS_LIST UPSAFEPI_V6)
set(UPSAFEPI_MODELS_LIST UPSAFEPI)
##########################################


############# Raspberry PLC ##############
set(RPIPLC_VERSIONS_LIST RPIPLC_V3 RPIPLC_V4 RPIPLC_V6)
set(RPIPLC_MODELS_LIST
    RPIPLC
    RPIPLC_19R
    RPIPLC_21
    RPIPLC_38AR
    RPIPLC_38R
    RPIPLC_42
    RPIPLC_50RRA
    RPIPLC_53ARR
    RPIPLC_54ARA
    RPIPLC_57AAR
    RPIPLC_57R
    RPIPLC_58
)
##########################################

function(check_version_and_model VERSION MODEL)
	if(${VERSION} STREQUAL "ALL" AND ${MODEL} STREQUAL "ALL")
		set(CHECK_RESULT TRUE PARENT_SCOPE)
	elseif(${MODEL} STREQUAL "ALL")
		function(check_version_in_list VERSION_LIST)
			list(FIND ${VERSION_LIST}_VERSIONS_LIST ${VERSION} VERSION_INDEX)
			if(VERSION_INDEX GREATER -1)
				set(CHECK_RESULT TRUE PARENT_SCOPE)
			endif()
		endfunction()

		check_version_in_list(RPIPLC)
		if (NOT CHECK_RESULT)
			check_version_in_list(UPSAFEPI)
		endif()

		set(CHECK_RESULT ${CHECK_RESULT} PARENT_SCOPE)
	else()
		function(check_in_lists LIST_NAME)
			list(FIND ${LIST_NAME}_VERSIONS_LIST ${VERSION} VERSION_INDEX)
			list(FIND ${LIST_NAME}_MODELS_LIST ${MODEL} MODEL_INDEX)
			if(VERSION_INDEX GREATER -1 AND MODEL_INDEX GREATER -1)
				set(CHECK_RESULT TRUE PARENT_SCOPE)
			endif()
		endfunction()

		check_in_lists(RPIPLC)
		if (NOT CHECK_RESULT)
			check_in_lists(UPSAFEPI)
		endif()

		set(CHECK_RESULT ${CHECK_RESULT} PARENT_SCOPE)
	endif()
endfunction()
