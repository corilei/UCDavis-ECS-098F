#!/usr/bin/bash

taget_dir=$1
mode=$2
shift 2

appendMode() {
    # Appends a new field to a given section with a field name and value
    # 
    # Args
    # $1: Section name
    # $2: New field name
    # $3: New field value

    section_name=$1
    new_field_name=$2
    # https://github.com/koalaman/shellcheck/wiki/SC2124
    shift 2
    new_field_value=$*

    # ref: https://math2001.github.io/article/bashs-find-command/
    # ref: https://www.thegeekstuff.com/2009/11/unix-sed-tutorial-append-insert-replace-and-count-file-lines/
    # ref: https://www.cnblogs.com/exmyth/p/14582067.html
    find . -path "$taget_dir/*.ini" -exec sed -i  "/$section_name/a $new_field_name=$new_field_value" \ {} \;
    # find . -path "$taget_dir/*.ini" -exec sed -i  "s/totally_not_secret_user_data_collection/mac/g" {} \;


}

deleteMode() {
    # Removes a field from the config file
    #
    # Args
    # $1: field_name
    ls
}

subMode() {
    # Replaces the value of a particular field with a new one
    #
    # Args
    # $1: field name
    # $2: new_value
    ls
}

case $mode in
    '-a')
        appendMode "$@"
        ;;
    '-d')
        deleteMode "$@"
        ;;
    '-s')
        subMode "$@"
        ;;
    *)
        echo 'Unrecongized flag for first argument'
        exit 2
        ;;
esac

# What command can we use to recursively find all files with an ini extenstion?
# Furthermore, how can we make that command call sed for each file it finds?
