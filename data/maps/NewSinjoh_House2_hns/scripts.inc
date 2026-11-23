NewSinjoh_House2_hns_MapScripts::
	.byte 0


NewSinjoh_House2_EventScripts_DeskLady::
    lock
	msgbox NewSinjoh_House2_DeskLady_Text MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_DeskLady_Text::
	.string "こんにちは　ぼうや‥\pここは　ニューシンジョウの‥\nまあ　としょかん　みたいな\lところ　かしら\pむらの　れきしの　きろくや\nほかの　ちほうから　とりよせた\lほんを　しまって\lあるのよ‥$"

NewSinjoh_House2_EventScript_Torkoal::
	lock
	faceplayer
	playmoncry SPECIES_TORKOAL, 0
	msgbox NewSinjoh_Hosue2_Text_CryTorkoal, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

NewSinjoh_Hosue2_Text_CryTorkoal:
	.string "コー？$"

NewSinjoh_House2_EventScript_BookShelf_North::
    lock
	msgbox NewSinjoh_House2_Text_Bookshelf_North MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_Text_Bookshelf_North:
	.string "かわで　とじた　ふるい\nほんが　ぎっしり　つまっている\pしらない　ことばで\nかかれている$"

NewSinjoh_House2_EventScript_BookShelf_South::
    lock
	msgbox NewSinjoh_House2_Text_Bookshelf_South MSGBOX_DEFAULT
	release
	end

NewSinjoh_House2_Text_Bookshelf_South:
	.string "ポケモンの　ほんが\nぎっしり　つまっている\pこっちは　あたらしくて\nみおぼえが　ある$"
