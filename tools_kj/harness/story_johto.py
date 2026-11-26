# story_johto.py : 3ねんごの　ジョウト編（ハート＆ソウルの　ジョウト）
ROM = '/tmp/play/rom.gba'
START_STATE = '/tmp/dbg/johto1.ss'; START_SAV = '/tmp/dbg/johto1.sav'
BOOST = 100
TEST_MOVES = [57, 89, 58, 85]
CAPTURE = 'cap'

STEPS = [
    ('map', 'MAP_NEW_BARK_TOWN_PLAYERS_HOUSE_1F_HNS'),
    ('busy',),
    ('map', 'MAP_NEW_BARK_TOWN_LAB_HNS'),
    ('talk', 'Elm'),
    ('busy',),
    ('talk', 'CyndaquilBall'),
    ('busy',),
    ('talk', 'Elm'),
    ('busy',),
    ('map', 'MAP_ROUTE30_MR_POKEMONS_HOUSE_HNS'),
    ('talk', 'MrPokemon'),
    ('busy',),
    ('map', 'MAP_NEW_BARK_TOWN_LAB_HNS'),
    ('busy',),
    ('talk', 'Elm'),
    ('busy',),
    ('flag', 'FLAG_RECEIVED_POKEDEX_FROM_ELM') if False else ('busy',),
]
