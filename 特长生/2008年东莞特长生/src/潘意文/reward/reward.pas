program reward(input,output);
var ed:array[1..20000,1..2] of longint;
    money:array[1..10000] of longint;
    used:array[1..10000] of boolean;
    i,j,n,m,k,sum:longint;
    f:boolean;

function check:boolean;
var i,j:integer;
begin
  check:=false;
  for i:=1 to n do
      if used[i]=false then  exit(true);
end;

begin
  assign(input,'reward.in');
  assign(output,'reward.out');
  reset(input);rewrite(output);
  readln(n,m);
  fillchar(used,sizeof(used),false);
  for i:=1 to m do begin
      readln(ed[i,2],ed[i,1]);
      //used[ed[i,1]]:=true;
      //used[ed[i,2]]:=true;
  end;
  for i:=1 to n do money[i]:=100;
  while check do begin
    for i:=1 to n do begin
        f:=false;
        k:=i;
        if used[k]=false then begin
           f:=true;
           for j:=1 to m do
             if ed[j,2]=i then begin f:=false;break;end;
        end;
        if f then break;
    end;
    if f=false then begin write(-1);close(input);close(output);halt;end;
    for i:=1 to m do
      if ed[i,1]=k then begin
         money[ed[i,2]]:=money[k]+1;
         ed[i,1]:=0;ed[i,2]:=0;
      end;
    used[k]:=true;
  end;
  sum:=0;
  for i:=1 to n do sum:=sum+money[i];
  write(sum);
  close(input);close(output);
end.