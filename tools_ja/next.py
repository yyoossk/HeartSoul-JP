import subprocess,sys
maxc=sys.argv[1] if len(sys.argv)>1 else '12000'
rels=['data/maps/%s/scripts.inc'%l.split()[0] for l in open('/home/claude/work/map_order.txt').read().split('\n') if l]
extra=[l for l in open('/home/claude/work/extra_order.txt').read().split('\n') if l] if __import__('os').path.exists('/home/claude/work/extra_order.txt') else []
subprocess.run(['python3','-I','/home/claude/work/idump.py']+rels+extra+[maxc])
