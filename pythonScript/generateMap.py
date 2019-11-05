import json


def myRange(n, m):
    return range(n, m + 1)


def make_pacgomme():
    return {
        "bonus": {
            "type": "pacgomme"
        }
    }


def make_super_pacgomme():
    return {
        "bonus": {
            "type": "super_pacgomme"
        }
    }


def make_no_bonus():
    return {
        "bonus": None
    }


def make_tunnel_args(x, y, orientation, destOrientation):
    return {
        "orientation": orientation,
        "destOrientation": destOrientation,
        "dest": {
            "x": x,
            "y": y
        }
    }


def make_pacman(orientation, x, y):
    return {
        "orientation": orientation,
        "position": {
            "x": x,
            "y": y
        }
    }


def make_ghost(typ, orientation, x, y):
    return {
        "type": typ,
        "orientation": orientation,
        "position": {
            "x": x,
            "y": y
        }
    }


def make_case(typ, x, y, args):
    return {
        "case": {
            "args": args,
            "type": typ
        },
        "position": {
            "x": x,
            "y": y
        },
    }


def make_game(cases, pacman, ghosts):
    return {
        "board": {
            "cases": cases
        },
        "pacman": pacman,
        "ghosts": ghosts
    }


cases = []

###### Border -> Done
# haut -> Done
cases.extend([
    make_case("wall", i, 10, {})
    for i in myRange(-10, 10)
])

# bas -> Done
cases.extend([
    make_case("wall", i, -11, {})
    for i in myRange(-10, 10)
])

# gauche -> Done
cases.extend([
    make_case("wall", -10, i, {})
    for i in myRange(-11, -3)
])
cases.extend([
    make_case("wall", -10, i, {})
    for i in myRange(3, 10)
])

# droite -> Done
cases.extend([
    make_case("wall", 10, i, {})
    for i in myRange(-11, -3)
])
cases.extend([
    make_case("wall", 10, i, {})
    for i in myRange(3, 10)
])

###### Interieur -> Done

cases.extend([
    make_case("floor", i, j, make_pacgomme())
    for i in myRange(-9, 9)
    for j in myRange(-10, 9)
])

## Bloc central sans pacGomme -> Done
cases.extend([
    make_case("floor", i, j, make_no_bonus())
    for i in myRange(-5, 5)
    for j in myRange(-3, 3)
])

###### SuperPac Gommes -> Done

cases.append(make_case("floor", 9, 8, make_super_pacgomme()))
cases.append(make_case("floor", 9, -6, make_super_pacgomme()))
cases.append(make_case("floor", -9, -6, make_super_pacgomme()))
cases.append(make_case("floor", -9, 8, make_super_pacgomme()))

###### Case solo a coté super pac gomme bas -> done
cases.extend([
    make_case("wall", -9, -7, {})
])
cases.extend([
    make_case("wall", 9, -7, {})
])

###### Ghosts -> done
ghosts = [
    make_ghost("blinky", "south", -1, 0),
    make_ghost("pinky", "north", -2, 0),
    make_ghost("inky", "east", 1, 0),
    make_ghost("clyde", "west", 2, 0)
]

###### Pacman -> Done

pacman = make_pacman("west", 0, -6)

###### MurBlocCentral Debut ghost -> Done
# Mur plein bas -> Done
cases.extend([
    make_case("wall", i, -1, {})
    for i in myRange(-3, 3)
])

# MurHaut gauche -> Done
cases.extend([
    make_case("wall", i, 1, {})
    for i in myRange(-3, -1)
])

# MurHaut droit -> Done
cases.extend([
    make_case("wall", i, 1, {})
    for i in myRange(1, 3)
])

# Bloc seul gauche -> Done
cases.extend([
    make_case("wall", -3, 0, {})
])
# Bloc seul droit -> Done
cases.extend([
    make_case("wall", 3, 0, {})
])

####### Bloc 4x4 sup gauche -> Done

cases.extend([
    make_case("wall", i, j, {})
    for i in myRange(-8, -7)
    for j in myRange(7, 8)
])

####### Bloc 2x1 sup gauche -> Done

cases.extend([
    make_case("wall", i, 5, {})
    for i in myRange(-8, -7)
])

####### Bloc 4x2 Sup gauche -> Done
cases.extend([
    make_case("wall", i, j, {})
    for i in myRange(-5, -2)
    for j in myRange(7, 8)
])

####### Bloc 1x3 Sup milieu -> Done
cases.extend([
    make_case("wall", 0, i, {})
    for i in myRange(7, 9)
])

######### Bloc 4x2 Sup droit -> Done
cases.extend([
    make_case("wall", i, j, {})
    for i in myRange(2, 5)
    for j in myRange(7, 8)
])

######### Bloc 4x4 sup droit -> Done
cases.extend([
    make_case("wall", i, j, {})
    for i in myRange(7, 8)
    for j in myRange(7, 8)
])

####### Bloc 2x1 sup droit -> Done

cases.extend([
    make_case("wall", i, 5, {})
    for i in myRange(7, 8)
])

####### Bloc T gauche sup -> Done
# Ligne coté vertical
cases.extend([
    make_case("wall", -5, i, {})
    for i in myRange(1, 5)
])
# Ligne centrale horizontal
cases.extend([
    make_case("wall", i, 3, {})
    for i in myRange(-4, -2)
])

####### Bloc T central sup -> Done
# Ligne du haut
cases.extend([
    make_case("wall", i, 5, {})
    for i in myRange(-3, 3)
])
# 2 Carrés milieux
cases.extend([
    make_case("wall", 0, i, {})
    for i in myRange(3, 4)
])

####### Bloc T droit sup -> Done
# Ligne coté vertical
cases.extend([
    make_case("wall", 5, i, {})
    for i in myRange(1, 5)
])
# Ligne centrale horizontal
cases.extend([
    make_case("wall", i, 3, {})
    for i in myRange(2, 4)
])

####### Bloc 1x2 gauche mid -> Done
cases.extend([
    make_case("wall", -5, i, {})
    for i in myRange(-3, -1)
])
####### Bloc 1x2 droit mid -> Done
cases.extend([
    make_case("wall", 5, i, {})
    for i in myRange(-3, -1)
])

####### Bloc T central inf -> Done
# Ligne du haut
cases.extend([
    make_case("wall", i, -3, {})
    for i in myRange(-3, 3)
])
# 2 Carrés milieux
cases.extend([
    make_case("wall", 0, i, {})
    for i in myRange(-5, -4)
])

####### Bloc T central inf2 -> Done
# Ligne du haut
cases.extend([
    make_case("wall", i, -7, {})
    for i in myRange(-3, 3)
])
# 2 Carrés milieux
cases.extend([
    make_case("wall", 0, i, {})
    for i in myRange(-9, -8)
])

####### Bloc T gauche inf -> Done
# Ligne du haut
cases.extend([
    make_case("wall", i, -9, {})
    for i in myRange(-8, -2)
])
# 2 Carrés milieux
cases.extend([
    make_case("wall", -5, i, {})
    for i in myRange(-8, -7)
])

####### Bloc T droit inf -> Done
# Ligne du haut
cases.extend([
    make_case("wall", i, -9, {})
    for i in myRange(2, 8)
])
# 2 Carrés milieux
cases.extend([
    make_case("wall", 5, i, {})
    for i in myRange(-8, -7)
])

####### Bloc 3x1 gauche inf -> Done
cases.extend([
    make_case("wall", i, -5, {})
    for i in myRange(-5, -2)
])

####### Bloc 3x1 droite inf -> Done
cases.extend([
    make_case("wall", i, -5, {})
    for i in myRange(2, 5)
])

####### Bloc movCava gauche inf -> done
# Ligne haut
cases.extend([
    make_case("wall", i, -5, {})
    for i in myRange(-8, -7)
])
# Colonne
cases.extend([
    make_case("wall", -7, i, {})
    for i in myRange(-7, -6)
])

####### Bloc movCava droite inf -> done
# Ligne haut
cases.extend([
    make_case("wall", i, -5, {})
    for i in myRange(7, 8)
])
# Colonne
cases.extend([
    make_case("wall", 7, i, {})
    for i in myRange(-7, -6)
])

###### Tunnel gauche -> done
###Bloc superieur
# Ligne haut
cases.extend([
    make_case("wall", i, 3, {})
    for i in myRange(-9, -7)
])
# Ligne bas
cases.extend([
    make_case("wall", i, 1, {})
    for i in myRange(-12, -7)
])

cases.extend([
    make_case("wall", -7, 2, {})
])

cases.extend([
    make_case("floor", i, 2, make_no_bonus())
    for i in myRange(-9, -8)
])
###Bloc inferieur
# Ligne haut
cases.extend([
    make_case("wall", i, -1, {})
    for i in myRange(-12, -7)
])
# Ligne bas
cases.extend([
    make_case("wall", i, -3, {})
    for i in myRange(-9, -7)
])
cases.extend([
    make_case("wall", -7, -2, {})
])

cases.extend([
    make_case("floor", i, -2, make_no_bonus())
    for i in myRange(-9, -8)
])

# Chemin
cases.extend([
    make_case("floor", i, 0, make_no_bonus())
    for i in myRange(-13, -7)
])

cases.append(make_case("tunnel", -13, 0, make_tunnel_args(13, 0, "west", "west")))

###### Tunnel droit
###Bloc superieur
# Ligne haut
cases.extend([
    make_case("wall", i, 3, {})
    for i in myRange(7, 9)
])
# Ligne bas
cases.extend([
    make_case("wall", i, 1, {})
    for i in myRange(7, 12)
])

cases.extend([
    make_case("wall", 7, 2, {})
])

cases.extend([
    make_case("floor", i, 2, make_no_bonus())
    for i in myRange(8, 9)
])
###Bloc inferieur
# Ligne haut
cases.extend([
    make_case("wall", i, -1, {})
    for i in myRange(7, 12)
])
# Ligne bas
cases.extend([
    make_case("wall", i, -3, {})
    for i in myRange(7, 9)
])
cases.extend([
    make_case("wall", 7, -2, {})
])

cases.extend([
    make_case("floor", i, -2, make_no_bonus())
    for i in myRange(8, 9)
])
# Chemin
cases.extend([
    make_case("floor", i, 0, make_no_bonus())
    for i in myRange(7, 13)
])
cases.append(make_case("tunnel", 13, 0, make_tunnel_args(-13, 0, "east", "east")))

jsonGame = json.dumps(make_game(cases, pacman, ghosts), sort_keys=True, indent=4)

f = open('gameRealBoard.json', 'w')
f.write(jsonGame)
f.close()
