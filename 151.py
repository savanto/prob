def cut(a2, a3, a4, a5):
    sheets = float(a2+a3+a4+a5)
    if sheets==0: return 0
    singles = 1 if sheets==1 and a5==0 else 0
    if a2: singles += a2*cut(a2-1, a3+1, a4+1, a5+1)
    if a3: singles += a3*cut(a2  , a3-1, a4+1, a5+1)
    if a4: singles += a4*cut(a2  , a3  , a4-1, a5+1)
    if a5: singles += a5*cut(a2  , a3  , a4  , a5-1)
    return singles/sheets
print round(cut(1, 1, 1, 1), 6)
