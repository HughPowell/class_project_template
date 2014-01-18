ROOT_DIR=$1

# Export all the variables

CONFIG="CONFIG"
SED_FILE=`mktemp`
while read LINE
do
    # Ignore lins starting with #
    if [[ $LINE == \#* ]]; then
        continue
    fi
    # Ignore emtpy lines
    if [[ -z "$LINE" ]]; then
        continue
    fi

    # Get the name=value pairs
    set -- `echo $LINE | tr '=' ' '`
    NAME=$1
    VALUE="${@:2}"
    echo "s;\${$NAME};$VALUE;g;" >> $SED_FILE
    if [ "$NAME" == "PROJECT_SHORT_NAME" ]; then
        PROJECT_SHORT_NAME=$VALUE

        # Create upper cased version of the project short name
        PROJECT_NAME_UPPER=`echo $VALUE | tr '[:lower:]' '[:upper:]'`
        echo "s;\${PROJECT_NAME_UPPER};$PROJECT_NAME_UPPER;g;" >> $SED_FILE

        # Create the project directory
        PROJECT_DIR="$ROOT_DIR$VALUE"
        if ! mkdir $PROJECT_DIR; then
            rm $SED_FILE
            echo -e "\e[1;31mDirectory $PROJECT_DIR already exists!\e[0m"
            exit 1
        fi
        echo "s;\${PROJECT_DIR};$PROJECT_DIR;g;" >> $SED_FILE
    fi
done <"$CONFIG"

# Add the current year
YEAR=`date +%Y`
echo "s;\${YEAR};$YEAR;g;" >> $SED_FILE

# Generate new files

copy_files () {
    SOURCE_DIR=$1
    TARGET_DIR=$2
    FILES=$SOURCE_DIR/*
    for FILE in $FILES; do
        echo "Processing $FILE ..."
        FILENAME=${FILE##*/}
        if [ "$FILENAME" == "generate.sh" ]; then
            continue
        fi
        if [ "$FILENAME" == "CONFIG" ]; then
            continue
        fi
        if [ "$FILENAME" == "README.md" ]; then
            continue
        fi
        NEW_FILE=$TARGET_DIR/$FILENAME
        NEW_FILE=${NEW_FILE/template/$PROJECT_SHORT_NAME}
        if [[ -d $FILE ]]; then
            mkdir $NEW_FILE
            ORIGINAL_SOURCE_DIR=$SOURCE_DIR
            ORIGINAL_TARGET_DIR=$TARGET_DIR
            copy_files $FILE $NEW_FILE
            SOURCE_DIR=$ORIGINAL_SOURCE_DIR
            TARGET_DIR=$ORIGINAL_TARGET_DIR
            continue
        fi
        # Move the README file to README.md
        if [ "$FILENAME" == "README" ]; then
            NEW_FILE=$NEW_FILE.md
        fi
        echo "NEW_FILE: $NEW_FILE"
        sed -f $SED_FILE $FILE > $NEW_FILE
        chmod --reference $FILE $NEW_FILE
    done
}

copy_files $PWD $PROJECT_DIR

rm $SED_FILE
