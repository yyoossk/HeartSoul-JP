NewBarkTown_House1_hns_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Mother::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_Neighbor, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_EventScript_Daughter::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_NeighborsDaughter, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_Text_NeighborsDaughter:
	.string "ピカチュウは　しんかした\nポケモン　なの\pウツギはかせの　はっけんには\nびっくり　したわ\pポケモンの　しんかの　けんきゅうで\nとても　ゆうめい　なのよ\p‥はあ‥\pわたしも　はかせ　みたいな\nけんきゅうしゃに　なりたいなあ‥$"


NewBarkTown_House1_Text_Neighbor:
	.string "むすめは　どうしても\nウツギはかせの　じょしゅに\lなりたいって　いうの\pほんとうに　ポケモンが\nすきなのね！\pまあ　わたしも\nだいすき　だけど！$"

