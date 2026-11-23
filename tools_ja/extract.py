import re,glob,json,sys,os
ROOT='/home/claude/hns2/'
syms=set(open('/tmp/syms.txt').read().split())
lab=re.compile(r'^([A-Za-z_][A-Za-z0-9_]*)::?\s*$')
st=re.compile(r'^\s*\.string\s+"((?:[^"\\]|\\.)*)"\s*$')
out={}
tot=0;totall=0
for f in sorted(glob.glob(ROOT+'data/**/*.inc',recursive=True)):
    rel=f[len(ROOT):]
    lines=open(f,encoding='utf-8').read().split('\n')
    cur=None;buf=[]
    def flush():
        global tot,totall
        if cur and buf:
            s=''.join(buf); totall+=len(s)
            if cur in syms:
                out.setdefault(rel,{})[cur]=s; tot+=len(s)
    for ln in lines:
        m=lab.match(ln)
        if m: flush(); cur=m.group(1); buf=[]; continue
        m=st.match(ln)
        if m and cur: buf.append(m.group(1))
        elif ln.strip() and not ln.strip().startswith('@'): 
            if buf: flush(); cur=None; buf=[]
    flush()
json.dump(out,open('/home/claude/work/strings_data.json','w'),ensure_ascii=False,indent=0)
print('files',len(out),'labels',sum(len(v) for v in out.values()),'chars linked',tot,'all',totall)
