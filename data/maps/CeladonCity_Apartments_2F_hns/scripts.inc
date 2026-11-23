CeladonCity_Apartments_2F_hns_MapScripts::
	.byte 0

CeladonCity_Apartments_2F_EventScript_Computer::
	lock
	playse SE_PC_ON
	msgbox CeladonMansion2F_Text_Computer
	playse SE_PC_OFF
	waitse
	release
	end

CeladonCity_Apartments_2F_EventScript_Sign::
	msgbox CeladonMansion2F_Text_DevOfficeSign, MSGBOX_SIGN
	end

CeladonMansion2F_Text_Computer:
	.string "{PLAYER}は　パソコンの\nスイッチを　いれた\p‥\pだれかが　メールを\nかいている　とちゅう　だった\p‥ぜひ　カントーへ\nあそびに　きてください\pずいぶん　かわったので\nおどろくと　おもいます\pジョウトに　いない\nポケモンも　たくさん　みられます\pプロデューサーへ\p‥$"

CeladonMansion2F_Text_DevOfficeSign:
	.string "ハートアンドソウル\nかいはつしつ$"

CeladonMansion2F_EventScript_LilDill::
	msgbox CeladonMansion2F_Text_LilDill, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_InfiniteBacon::
	msgbox CeladonMansion2F_Text_InfiniteBacon, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_TixoRebel::
	msgbox CeladonMansion2F_Text_TixoRebel, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Phant::
	msgbox CeladonMansion2F_Text_Phant, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Exclsior::
	msgbox CeladonMansion2F_Text_Exclsior, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_DaniRainbow::
    msgbox CeladonMansion2F_Text_DaniRaibow, MSGBOX_NPC
    end

CeladonMansion2F_Text_LilDill:
	.string "みなさん　こんにちは\nパッチ15‥\pじゃなくて‥\pやあ　ぼくが\nゲームディレクター！\pマップや　タイルセット\nスクリプトなどを　つくったよ\pでも　ほかの　かいはつしゃや\nテストプレイヤーが　いなければ\lできなかった\pあそんで　くれて　ありがとう！\nハートアンドソウルを\lたのしんで　くれたかな？$"

CeladonMansion2F_Text_InfiniteBacon:
	.string "この　ゲームを　ポケエメラルド\nエクスパンションで\lつくりなおして　いるんだ！$"

CeladonMansion2F_Text_TixoRebel:
	.string "タマゴかじけんって\nしってる？\pテストプレイで　みつかった\nバグで　ポケモンが　ランダムに\lタマゴに　なっちゃったんだ！\pその　しゅうせいは\nぼくが　したんだよ！$"

CeladonMansion2F_Text_Phant:
	.string "デメイクが　だいすき！\pソード　シールド　アルティメット\nプラスの　えいごばん\lあそんだ？　ぼくが\lほんやく　したんだ！\pつぎの　デメイクは\nアローラに　しようかな！$"

CeladonMansion2F_Text_Exclsior:
	.string "ポケモンごとの　なみのりの\nグラフィックは　ぼくが\lいれたんだ！\pオープンソースの　プロジェクト\nだから　きみも　きのうを\lついか　できるよ！$"

CeladonMansion2F_Text_DaniRaibow:
	.string "やあ！\pもんだいを　みつけるのが\nとくいで　ちいさな　ものなら\lなおせるよ\pジョーク　ききたい？\pワタルが　カイリューに\nりゅうのいぶきを　おしえようと\lした\pでも　カイリューは\nしんそくで　はやすぎて\lうけとれなかった！$"
