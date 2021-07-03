Program snake;
label l1,l2,r1,r2;
var map:array[1..100,1..100] of integer;
    i,j,k,l,m,n,step,total,nx,ny,cc:integer;
Function w1(s:integer):integer;
begin
 if s=-1 then w1:=0;
 if s=0 then w1:=1;
 if s=1 then w1:=2;
 if s=2 then w1:=-1;
end;
Function w2(s:integer):integer;
begin
 if s=1 then w2:=0;
 if s=0 then w2:=-1;
 if s=-1 then w2:=2;
 if s=2 then w2:=1;
end;
begin
assign(input,'snake.in');
reset(input);
assign(output,'snake.out');
rewrite(output);
 readln(n);
 map[1,1]:=n*n; step:=-1; nx:=1; ny:=1; cc:=n*n;

if (n mod 2 <>0) then begin
{w1}
 repeat
  if step=-1 then begin nx:=nx+1;
                        cc:=cc-1;
                        map[nx,ny]:=cc;
                        step:=w1(step); goto l1; end;
  if step=0 then begin nx:=nx-1;
                       ny:=ny+1;
                       cc:=cc-1;
                       map[nx,ny]:=cc;
                       if nx=1 then step:=w1(step); goto l1; end;
  if step=1 then begin ny:=ny+1;
                       cc:=cc-1;
                       map[nx,ny]:=cc;
                       step:=w1(step); goto l1; end;
  if step=2 then begin nx:=nx+1;
                       ny:=ny-1;
                       cc:=cc-1;
                       map[nx,ny]:=cc;
                       if ny=1 then step:=w1(step); goto l1; end;
l1:
until(nx=n)and(ny=1);
{w2}
step:=1;
repeat
 if step=1 then begin ny:=ny+1;
                       cc:=cc-1;
                       map[nx,ny]:=cc;
                       step:=w2(step); goto l2; end;
 if step=0 then begin ny:=ny+1;
                       nx:=nx-1;
                       cc:=cc-1;
                       map[nx,ny]:=cc;
                       if (ny=n)or(nx=n+1) then step:=w2(step); goto l2; end;
 if step=-1 then begin nx:=nx+1;
                        cc:=cc-1;
                        map[nx,ny]:=cc;
                        step:=w2(step); goto l2; end;
 if step=2 then begin nx:=nx+1;
                       ny:=ny-1;
                       cc:=cc-1;
                       map[nx,ny]:=cc;
                       if nx=n then step:=w2(step); goto l2; end;
l2:
until (cc=1)or(cc=0);
end;

if (n mod 2 =0) then begin
{w1}
 repeat
  if step=-1 then begin nx:=nx+1;
                        cc:=cc-1;
                        map[nx,ny]:=cc;
                        step:=w1(step); goto r1; end;
  if step=0 then begin nx:=nx-1;
                       ny:=ny+1;
                       cc:=cc-1;
                       map[nx,ny]:=cc;
                       if nx=1 then step:=w1(step); goto r1; end;
  if step=1 then begin ny:=ny+1;
                       cc:=cc-1;
                       map[nx,ny]:=cc;
                       step:=w1(step); goto r1; end;
  if step=2 then begin nx:=nx+1;
                       ny:=ny-1;
                       cc:=cc-1;
                       map[nx,ny]:=cc;
                       if ny=1 then step:=w1(step); goto r1; end;
r1:
until (ny=n)and(nx=1);
{w2}
step:=-1;
repeat
 if step=1 then begin ny:=ny+1;
                       cc:=cc-1;
                       map[nx,ny]:=cc;
                       step:=w2(step); goto r2; end;
 if step=0 then begin ny:=ny+1;
                       nx:=nx-1;
                       cc:=cc-1;
                       map[nx,ny]:=cc;
                       if (ny=n)or(nx=n+1) then step:=w2(step); goto r2; end;
 if step=-1 then begin nx:=nx+1;
                        cc:=cc-1;
                        map[nx,ny]:=cc;
                        step:=w2(step); goto r2; end;
 if step=2 then begin nx:=nx+1;
                       ny:=ny-1;
                       cc:=cc-1;
                       map[nx,ny]:=cc;
                       if nx=n then step:=w2(step); goto r2; end;
r2:
until (cc=1)or(cc=0);
end;

for i:=1 to n do begin
  for j:=1 to n do write(map[i,j],' '); writeln; end;

close(input);
close(output);

end.
