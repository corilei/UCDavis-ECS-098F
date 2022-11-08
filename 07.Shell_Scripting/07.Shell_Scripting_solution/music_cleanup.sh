#!/usr/bin/bash
# usage: bash field_validator.sh sample_test_cases/purchase_9

current_file=""
artistName=""
songName=""

getArtistName() {
    # I wrote this one to take one argument and set a global variable to the
    # artist's name with whitespace removed
    # Note that this is where you'll want/need to use ffprobe
    output=$(ffprobe -show_entries format_tags=artist -of csv=p=0 -loglevel quiet "${current_file}")

    artistName=${output//" "/""}

#    echo "artist: ${artistName}"
}

getSongName() {
    # Same deal as getArtistName but with the song name
    # Note that this is where you'll want/need to use ffprobe
    output=$(ffprobe -show_entries format_tags=title -of csv=p=0 -loglevel quiet "${current_file}")

    songName=${output//" "/""}
    songName=${songName//"\""/""}

#    echo "title: ${songName}"
}

doConversion() {
    # This function performs the conversion on a single file
    ffmpeg -loglevel error -i "${current_file}" "${TARGET_DIR}"/"${artistName}"_"${songName}".mp3
}

# Takes one argument, that being a directory
TARGET_DIR=$1

# Now we should iterate over every file in the directory and do the conversion
# for each file
for file in "${TARGET_DIR}"/*
do
  current_file=${file}

  getArtistName
  getSongName
  doConversion
  rm "${current_file}"
#  echo "remove ${current_file}"
done

exit 0
