# **42_filler**
This project is about creating a player for the filler board.

## Descripton
Two players gain points by placing random figures 
on a board, one after the other, the game piece obtained by the game master (in the form of an executable Ruby program). The game ends when the game piece cannot be placed anymore. 

## Required resources
- vm
- maps
- players

All necessary resources are located in the **`resources`** directory

## Cloning the repo
```
git clone https://github.com/aspyltsov65/filler.git
cd filler
```
## Usage
```
Usage: ./resources/filler_vm -f path [-i | -p1 path | -p2 path] [-s | -q | -t time]

   -t  --time           set timeout in second
   -q  --quiet          quiet mode
   -i  --interactive    interactive mode(default)
   -p1 --player1        use filler binary as a first player
   -p2 --player2        use filler binary as a second player
   -f  --file           use a map file (required)
   -s  --seed           use the seed number (initialization random) (man srand)
```
## Run
```
./resources/filler_vm -f resources/maps/map00 -p1 resources/players/carli.filler -p2 ./apyltsov.filler
```
#### Running the program with visualization
```
./resources/filler_vm -f resources/maps/map00 -p1 resources/players/carli.filler -p2 ./apyltsov.filler | ./bonus
```
## Map example & explanation 
```
.................
.................
.................
.................
.................
.................
.................
.................
..O..............
.................
.................
.................
..............X..
.................
.................
```
Map consist of:
- **`O`** - start position for the first player
- **`X`** - start position for the second player
- **`.`** - avaliable place to put your figure

## Output example
```
Plateau 15 17:
    01234567890123456
000 XXX.........X..xx
001 XXXXXXXXXXXXXXXXX
002 XXXXXXXXXXXXXXXXX
003 XXXXXXXXOOOXXXXXX
004 XXXXXXOOOOOXXXXXX
005 XXXXXXOOOOOXXXXXX
006 XXXXXOOOOOOXXXXXX
007 XXXXXOOOOOOOXXXXX
008 XOOOOOOOOOXXXXXXX
009 OOOOOOOOOOXXXXXXX
010 OOOOOOOOOXXXXXXXX
011 OOOOOOOOOXXXXXXXX
012 OOOOOOOOOOXXXXXXX
013 OOOOOOOOOOXXXXXXX
014 OOOOOOOOOOOOXXXXX
Piece 2 2:
**
**
<got (X): [0, 0]
== O fin: 65
== X fin: 101
```
- `== O fin: 65` - final score for the first player (in this case for `carli.filler`) 
- `== X fin: 101` - final score for the second player (`apyltsov.filler`)

## Example filler game
[![Example filler game](http://img.youtube.com/vi/QkK8mOULKZ8/0.jpg)](https://www.youtube.com/watch?v=QkK8mOULKZ8 "Filler game")



