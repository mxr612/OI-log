program fence(input,output);

var board:array[1..30] of longint;
    rail,sum:array[1..1024] of longint;
    nr,nb,boardtot,trashtot,havedelay,left,right,dfsid:longint;
    okey:boolean;

procedure swap(var a,b:longint);
var temp:longint;
begin
  temp:=a;a:=b;b:=temp;
end;

procedure qsort(start,stop:longint);
var i,j,k:longint;
begin
  if stop-start<=10 then begin
     for i:=start to stop-1 do
       for j:=i+1 to stop do
         if rail[i]>rail[j] then swap(rail[i],rail[j]);
     exit;
  end;
  k:=rail[(start+stop) div 2];
  i:=start;j:=stop;
  repeat
    while rail[i]<k do inc(i);
    while rail[j]>k do dec(j);
    if i<=j then begin
       swap(rail[i],rail[j]);
       inc(i);dec(j);
    end;
  until i>j;
  if start<j then qsort(start,j);
  if stop>i  then qsort(i,stop);
end;

procedure init;
var i,j:longint;
begin
  readln(nb);
  for i:=1 to nb do readln(board[i]);
  for i:=1 to nb-1 do
    for j:=i+1 to nb do
      if board[i]<board[j] then swap(board[i],board[j]);
  readln(nr);
  for i:=1 to nr do readln(rail[i]);
  qsort(1,nr);
end;

procedure find(k,x:longint);
var i,start:longint;
begin
  if k=0 then begin
     okey:=true;
     exit;
  end;
  if havedelay>trashtot then exit;
  if rail[k]=rail[k+1] then start:=x else start:=1;
  for i:=start to nb do
    if rail[k]<=board[i] then begin
       dec(board[i],rail[k]);
       if board[i]<rail[1] then inc(havedelay,board[i]);
       find(k-1,i);
       if board[i]<rail[1] then dec(havedelay,board[i]);
       inc(board[i],rail[k]);
       if okey=true then exit;
    end;
end;

procedure solve;
var i,k:longint;
begin
  boardtot:=0;
  for i:=1 to nb do inc(boardtot,board[i]);
  sum[1]:=rail[1];
  for i:=2 to nr do sum[i]:=sum[i-1]+rail[i];
  right:=nr;
  while rail[right]>board[1] do dec(right);
  while sum[right]>boardtot do dec(right);
  left:=1;
  while rail[left]<board[left] do inc(left);
  dec(left);
  k:=0;
  for i:=1 to nb do
    if board[i]<rail[1] then inc(k,board[i]);
  while left<right do begin
    dfsid:=(left+right+1) div 2;
    havedelay:=k;
    trashtot:=boardtot-sum[dfsid];
    okey:=false;
    find(dfsid,1);
    if not okey then dec(right) else left:=dfsid;
  end;
  writeln(left);
end;

begin
  assign(input,'fence.in');
  assign(output,'fence.out');
  reset(input);rewrite(output);
  init;
  solve;
  close(input);close(output);
end.

