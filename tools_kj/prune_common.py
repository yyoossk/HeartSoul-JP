# 共通スクリプトから、カントー編に入れないマップ（セブンアイランド）のものを除く（何度動かしても同じ）
import re
SEVII = re.compile(r'\b(?:One|Two|Three|Four|Five|Six|Seven)Island_\w+')
# fame checker: セブンアイランドのテキストは ダミーにする
p = 'data/scripts/fame_checker_frlg.inc'; s = open(p).read()
undef = {'FourIsland_Mart_Text_LoreleiGrewUpOnThisIsland', 'SevenIsland_SevaultCanyon_Text_BrunoTrainedWithBrawly', 'SixIsland_Mart_Text_AgathaOldestEverEliteFourMember'}
s2 = re.sub(r'\b(' + '|'.join(undef) + r')\b(?!::)', 'KJ_Text_Dummy', s)
if 'KJ_Text_Dummy::' not in s2:
    s2 += '\nKJ_Text_Dummy::\n\t.string "$"\n'
open(p, 'w').write(s2)
# move tutors: セブンアイランドの教え人（ボディプレス・だいばくはつ・つるぎのまい・究極技・ふっかつ）を除く
p = 'data/scripts/move_tutors_frlg.inc'; s = open(p).read()
defined = set()
import glob, sys, os
sys.path.insert(0, os.path.dirname(__file__)); import symscan as S
for f in S.files():
    if f != p: defined |= set(re.findall(r'(?m)^(\w+)::?', open(f).read()))
bad = set('''Text_BodySlamDeclined Text_BodySlamTaught Text_ExplosionDeclined Text_ExplosionTaught Text_JustMistaken Text_MakeBestUseOfMove Text_PassedOnEverythingIKnow Text_SwordsDanceDeclined Text_SwordsDanceTaught Text_TaughtMove Text_YouRejectIt Text_BodySlamTeach Text_ExplosionTeach Text_SwordsDanceTeach Text_LetMeConferUltimateMove Text_AllowMeToTeachMonUltimateMove Text_FeelRejuvenated'''.split())
while True:
    parts = re.split(r'(?m)^(?=\w+::)', s)
    keep = [x for x in parts if not any(re.search(r'\b' + b + r'\b', x) for b in bad)]
    gone = [re.match(r'(\w+)::', x).group(1) for x in parts if x not in keep and re.match(r'\w+::', x)]
    s = ''.join(keep)
    new = set(gone) - bad
    if not new: break
    bad |= new
open(p, 'w').write(s)
print('removed', len(bad))
