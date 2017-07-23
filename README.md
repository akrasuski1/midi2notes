
python makenotes.py samples/score.mid 0 > mus.inc
gcc play.c -lm -o play
./play | aplay
